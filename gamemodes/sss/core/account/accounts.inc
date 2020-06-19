/*================================================================================================


    ░██████╗██╗░░░██╗██████╗░██╗░░░██╗██╗██╗░░░██╗███████╗  ████████╗██╗███╗░░░███╗███████╗
    ██╔════╝██║░░░██║██╔══██╗██║░░░██║██║██║░░░██║██╔════╝  ╚══██╔══╝██║████╗░████║██╔════╝
    ╚█████╗░██║░░░██║██████╔╝╚██╗░██╔╝██║╚██╗░██╔╝█████╗░░  ░░░██║░░░██║██╔████╔██║█████╗░░
    ░╚═══██╗██║░░░██║██╔══██╗░╚████╔╝░██║░╚████╔╝░██╔══╝░░  ░░░██║░░░██║██║╚██╔╝██║██╔══╝░░
    ██████╔╝╚██████╔╝██║░░██║░░╚██╔╝░░██║░░╚██╔╝░░███████╗  ░░░██║░░░██║██║░╚═╝░██║███████╗
    ╚═════╝░░╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░░╚═╝░░░╚══════╝  ░░░╚═╝░░░╚═╝╚═╝░░░░░╚═╝╚══════╝


    Emmett & Crownshot's Survive Time Gamemode
    Git: github.com/emmett-white/samp-survive-time

    Credits:
        Y-Less - YSI-Includes...
        Incognito - Streamer
        JustMichael - Discord help..
        maddinat0r - MySQL
        IllidanS4 - PawnPlus
        AGraber - pawn-plus-mysql
        urShadow - Pawn.RegEx
        ziggi - Protection
        Southclaws - sa-mp logger
        Emmet_ - New SA-MP callbacks
        oscar-broman - weapon-config | SKY
        kurta999's & IllidanS4 - YSF
        dakyskye - Pawn ENV

    Copyright (©) 2020 | 16th June

================================================================================================*/

#include <YSI_Coding\y_hooks>

// Tables

#define TABLE_ACCOUNTS                      "accounts"
#define TABLE_CHARACTER                     "characters"
#define TABLE_BANNED                        "banned"

// Fields

#define account_field_id                    "account_id"
#define account_field_name                  "account_name"
#define account_field_password              "account_password"
#define account_field_email                 "account_email"

#define char_field_id                       "char_id"
#define char_field_name                     "char_name"
#define char_field_country                  "char_country"
#define char_field_gender                   "char_gender"
#define char_field_money                    "char_money"
#define char_field_score                    "char_score"
#define char_field_skin                     "char_skin"
#define char_field_admin                    "char_admin"

#define banned_field_player                 "banned_pname"
#define banned_field_admin                  "banned_aname"
#define banned_field_reason                 "banned_reason"


// Variables

new
    player_UniqueID[MAX_PLAYERS],
    player_Password[MAX_PLAYERS][64],
    player_LoginAttempts[MAX_PLAYERS],

    char_UniqueID[MAX_PLAYERS],
    char_Country[MAX_PLAYERS][24],
    char_Gender[MAX_PLAYERS],
    char_Skin[MAX_PLAYERS],
    char_Score[MAX_PLAYERS],
    char_Money[MAX_PLAYERS],
    char_Admin[MAX_PLAYERS];


// Spawn Positions

new Float: randomSpawnPositions[][] =
{
    { 241.1621,-30.0135,1.5781,88.3188 },
    { 247.1662,-93.5233,2.2537,88.6577 },
    { 218.2654,-86.3072,1.5705,317.5236 },
    { -80.9023,-15.2646,3.1172,36.2880 },
    { 673.0425,-522.1229,16.3281,269.7150 },
    { 671.5831,-476.9319,16.3359,197.3150 },
    { 786.0263,-826.0399,70.2896,357.8026 },
    { 900.9971,-927.9954,42.6016,179.1949 },
    { 589.1715,-1238.8641,17.8381,307.1783 },
    { 1187.1113,-1323.9055,13.5591,272.8422 },
    { 1363.3134,-1279.3271,13.5469,85.5345 },
    { 1334.2605,-1059.6702,28.1037,262.1210 },
    { 1458.3473,-1025.9438,23.8281,178.0579 }
};


// Hooks

hook OnPlayerConnect(playerid)
{
    player_LoginAttempts[playerid] = 0;

    va_SendClientMessageToAll(X11_SERVER, "[JOIN]: %s "WHITE"connected.", PlayerName(playerid));

    task_await
    (
        MySQL_QueryS
        (
            str_format
            (
                "SELECT * FROM "TABLE_BANNED" WHERE "banned_field_player" = '%e' LIMIT 1",
                PlayerName(playerid)
            )
        )
    );

    if (cache_num_rows())
    {
        static
            banned_AdminName[MAX_PLAYER_NAME],
            banned_Reason[MESSAGE_MAX_LENGTH];

        cache_get_value_name(0, ""banned_field_admin"", banned_AdminName);
        cache_get_value_name(0, ""banned_field_reason"", banned_Reason);

        GameTextForPlayer(playerid, !"~r~BANNED!", 10000, 3);

        ChatMsgF(playerid, X11_SERVER, "%s, you're banned from this server.", PlayerName(playerid));
        ChatMsgF(playerid, X11_SERVER, "Admin: "SERVER"%s", banned_AdminName);
        ChatMsgF(playerid, X11_SERVER, "Reason: "SERVER"%s", banned_Reason);

        defer KickTimer(playerid);

        return 1;
    }

    task_await
    (
        MySQL_QueryS
        (
            str_format
            (
                "SELECT * FROM "TABLE_ACCOUNTS" WHERE "account_field_name" = '%e' LIMIT 1",
                PlayerName(playerid)
            )
        )
    );

    if (cache_num_rows())
    {
        // Loading account
        cache_get_value_name_int(0, ""account_field_id"", player_UniqueID[playerid]);
        cache_get_value_name(0, ""account_field_password"", player_Password[playerid]);

        // Loading character
        task_await
        (
            MySQL_QueryS
            (
                str_format
                (
                    "SELECT * FROM "TABLE_CHARACTER" WHERE "char_field_name" = '%e' LIMIT 1",
                    PlayerName(playerid)
                )
            )
        );

        if (cache_num_rows())
        {
            cache_get_value_name_int(0, ""char_field_id"", char_UniqueID[playerid]);
            cache_get_value_name_int(0, ""char_field_gender"", char_Gender[playerid]);
            cache_get_value_name_int(0, ""char_field_skin"", char_Skin[playerid]);
            cache_get_value_name_int(0, ""char_field_score"", char_Score[playerid]);
            cache_get_value_name_int(0, ""char_field_money"", char_Money[playerid]);
            cache_get_value_name_int(0, ""char_field_admin"", char_Admin[playerid]);
        
            Auth_PromptLogin(playerid);
        }

        return 1;
    }

    Auth_DoRegister(playerid, 1);

    ClearChat(playerid, 40);

    UI_CreateHelpMessage(playerid, true);

    return 1;
}


hook OnPlayerDisconnect(playerid, reason)
{
    va_SendClientMessageToAll(X11_ORANGE_1, "[LEFT]: %s "WHITE"disconnected.", PlayerName(playerid));
    return 1;
}

// Functions

static stock Auth_DoRegister(const playerid, const type)
{
    switch (type)
    {
        case 1:
        {
            inline dialog_register(id, dialogid, response, listitem, string: inputtext[])
            {
                #pragma unused id, dialogid, listitem

                if (!response)
                    return Kick(playerid);

                if (!(6 < strlen(inputtext) < 24))
                    return ErrorMsg(playerid, "Password is too short or too long!"), Auth_DoRegister(playerid, 1);

                bcrypt_hash(playerid, "OnPasswordHashed", inputtext, 12);
            }

            Dialog_ShowCallbackF
            (
                playerid, using inline dialog_register, DIALOG_STYLE_INPUT,
                D_TITLE,
                ""SERVER">> %s, "WHITE"please enter your desired password..\n\n\
                "SERVER">> "WHITE"Min. characters - "SERVER"6 "WHITE"| Max. characters - "SERVER"24",
                D_CONFIRM, D_CANCEL, PlayerName(playerid)
            );
        }

        case 2:
        {
            inline dialog_email(id, dialogid, response, listitem, string: inputtext[])
            {
                #pragma unused id, dialogid, listitem

                if (!response)
                    return Kick(playerid);

                if (!IsValidEmailAddress(inputtext))
                    return ErrorMsg(playerid, "Please enter your valid e-mail address.."), Auth_DoRegister(playerid, 2);

                new String: Query = str_format
                (
                    "UPDATE \
                        "TABLE_ACCOUNTS" \
                    SET \
                        "account_field_email" = '%e' \
                    WHERE \
                        "account_field_id" = '%d'",
                    inputtext, player_UniqueID[playerid]
                );
                mysql_tquery_s(MySQL_GetHandle(), Query);

                Auth_DoRegister(playerid, 3);
            }

            Dialog_ShowCallback
            (
                playerid, using inline dialog_email, DIALOG_STYLE_INPUT,
                D_TITLE,
                ""SERVER">> "WHITE"Please enter your valid e-mail address to "SERVER"protect "WHITE"your account:",
                D_CONFIRM, D_CANCEL
            );
        }

        case 3:
        {
            inline dialog_country(id, dialogid, response, listitem, string: inputtext[])
            {
                #pragma unused id, dialogid, listitem

                if (!response)
                    return Kick(playerid);

                if (isnumeric(inputtext) || isnull(inputtext))
                    return Auth_DoRegister(playerid, 2);

                strcpy(char_Country[playerid], inputtext);

                new String: Query = str_format
                (
                    "INSERT INTO \
                        "TABLE_CHARACTER" \
                    ("char_field_name", "char_field_country") \
                    VALUES \
                        ('%e', '%e')",
                    PlayerName(playerid), char_Country[playerid]
                );
                mysql_tquery_s(MySQL_GetHandle(), Query, "OnCharacterRegistered", "d", playerid);

                Auth_DoRegister(playerid, 4);
            }

            Dialog_ShowCallback
            (
                playerid, using inline dialog_country, DIALOG_STYLE_INPUT,
                D_TITLE, ""SERVER">> "WHITE"Where are you from?",
                D_CONFIRM, D_CANCEL
            );
        }

        case 4:
        {
            inline dialog_gender(id, dialogid, response, listitem, string: inputtext[])
            {
                #pragma unused id, dialogid, listitem, inputtext

                char_Gender[playerid] = response;
                char_Skin[playerid] = (char_Gender[playerid] == 1) ? (26) : (12);

                new String: Query = str_format
                (
                    "UPDATE \
                        "TABLE_CHARACTER" \
                    SET \
                        "char_field_gender" = '%d', "char_field_skin" = '%d' \
                    WHERE \
                        "char_field_id" = '%d'",
                    char_Gender[playerid], char_Skin[playerid], char_UniqueID[playerid]
                );
                mysql_tquery_s(MySQL_GetHandle(), Query);

                Auth_DoRegister(playerid, 5);
            }

            Dialog_ShowCallback
            (
                playerid, using inline dialog_gender, DIALOG_STYLE_MSGBOX,
                D_TITLE, ""SERVER">> "WHITE"Choose your gender",
                ""SERVER"Male", ""INDIAN_RED_3"Female"
            );
        }

        case 5:
        {
            ClearChat(playerid, 40);

            ChatMsgF(playerid, X11_SERVER, "%s, "WHITE"you've successfully registered on \""SERVER"Survive Time\""WHITE".", PlayerName(playerid));

            OnCharacterSpawned(playerid);
        }
    }

    return 1;
}


static stock Auth_PromptLogin(const playerid)
{
    inline dialog_login(id, dialogid, response, listitem, string: inputtext[])
    {
        #pragma unused id, dialogid, listitem

        if (!response)
            return Kick(playerid);


        bcrypt_verify(playerid, "OnPasswordVerify", inputtext, player_Password[playerid]);
    }

    Dialog_ShowCallbackF
    (
        playerid, using inline dialog_login, DIALOG_STYLE_PASSWORD,
        D_TITLE,
        ""SERVER">> %s, "WHITE"please enter your correct password..\n\n\
        "SERVER">> "WHITE"You have max %d/"SERVER"%d "WHITE"attempts!",
        D_CONFIRM, D_CANCEL, PlayerName(playerid), player_LoginAttempts[playerid],
        MAX_LOGIN_ATTEMPTS
    );

    return 1;
}


// Callbacks

forward OnAccountRegistered(const playerid);
public OnAccountRegistered(const playerid)
{
    player_UniqueID[playerid] = cache_insert_id();
    return 1;
}


forward OnCharacterRegistered(const playerid);
public OnCharacterRegistered(const playerid)
{
    char_UniqueID[playerid] = cache_insert_id();
    return 1;
}


forward OnCharacterSpawned(const playerid);
public OnCharacterSpawned(const playerid)
{
    new rand = random(sizeof randomSpawnPositions);
    SetSpawnInfo
    (
        playerid, 0, char_Skin[playerid],
        randomSpawnPositions[rand][0], randomSpawnPositions[rand][1], randomSpawnPositions[rand][2], randomSpawnPositions[rand][3],
        0, 0, 0, 0, 0, 0
    );
    SpawnPlayer(playerid);

    TogglePlayerControllable(playerid, 0);
    defer SpawnTimer(playerid);

    return 1;
}


// bcrypt callbacks
forward OnPasswordHashed(const playerid);
public OnPasswordHashed(const playerid)
{
    new hash[64 + 1];
    bcrypt_get_hash(hash);

    strcpy(player_Password[playerid], hash);

    new String: Query = str_format
    (
        "INSERT INTO `"TABLE_ACCOUNTS"` (`account_name`, `account_password`) \
        VALUES ('%e', '%e')", PlayerName(playerid), hash
    );
    mysql_tquery_s(MySQL_GetHandle(), Query, "OnAccountRegistered", "d", playerid);

    Auth_DoRegister(playerid, 2);

    return 1;
}


forward OnPasswordVerify(const playerid, bool: success);
public OnPasswordVerify(const playerid, bool: success)
{
    if (!success)
    {
        ++player_LoginAttempts[playerid];

        if (player_LoginAttempts[playerid] == MAX_LOGIN_ATTEMPTS)
            return Kick(playerid);

        Auth_PromptLogin(playerid);
        return 1;
    }

    OnCharacterSpawned(playerid);
    SetPlayerScore(playerid, char_Score[playerid]);
    GivePlayerMoney(playerid, char_Money[playerid]);

    return 1;
}


// Timer
timer SpawnTimer[2400](playerid)
{
    TogglePlayerControllable(playerid, 1);
    SetPlayerSkin(playerid, char_Skin[playerid]);
}