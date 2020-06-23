/*================================================================================================


    ░██████╗██╗░░░██╗██████╗░██╗░░░██╗██╗██╗░░░██╗███████╗  ████████╗██╗███╗░░░███╗███████╗
    ██╔════╝██║░░░██║██╔══██╗██║░░░██║██║██║░░░██║██╔════╝  ╚══██╔══╝██║████╗░████║██╔════╝
    ╚█████╗░██║░░░██║██████╔╝╚██╗░██╔╝██║╚██╗░██╔╝█████╗░░  ░░░██║░░░██║██╔████╔██║█████╗░░
    ░╚═══██╗██║░░░██║██╔══██╗░╚████╔╝░██║░╚████╔╝░██╔══╝░░  ░░░██║░░░██║██║╚██╔╝██║██╔══╝░░
    ██████╔╝╚██████╔╝██║░░██║░░╚██╔╝░░██║░░╚██╔╝░░███████╗  ░░░██║░░░██║██║░╚═╝░██║███████╗
    ╚═════╝░░╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░░╚═╝░░░╚══════╝  ░░░╚═╝░░░╚═╝╚═╝░░░░░╚═╝╚══════╝


    Emmett & Crownshot's Survive Time Gamemode
    Git: github.com/emmett-white/samp-survive-time
    Discord: https://discord.gg/yGRhys2

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

stock Auth_DoRegister(const playerid, const type)
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

                printf("%s", inputtext);
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