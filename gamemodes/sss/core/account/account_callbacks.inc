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

forward OnPlayerAccountCheck(const playerid);
public OnPlayerAccountCheck(const playerid)
{
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

    ShowHungerBar(playerid);

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