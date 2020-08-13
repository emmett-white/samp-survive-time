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

hook OnPlayerConnect(playerid)
{
    va_SendClientMessageToAll(X11_SERVER, "[JOIN]: %s "WHITE"connected.", PlayerName(playerid));

    InterpolateCameraPos(playerid, 3.1435,-1955.6364,88.1194, 2106.8354,-1270.0221,100.7057, 1000 * 25, CAMERA_MOVE);
    InterpolateCameraLookAt(playerid, 2325.7061,-1063.7642,55.4202, 2325.7061,-1063.7642,45.4202, 1000 * 25, CAMERA_MOVE);

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
            banned_Reason[MESSAGE_MAX_LENGTH]
        ;

        cache_get_value_name(0, ""banned_field_admin"", banned_AdminName);
        cache_get_value_name(0, ""banned_field_reason"", banned_Reason);

        GameTextForPlayer(playerid, !"~r~BANNED!", 10000, 3);

        ChatMsgF(playerid, X11_SERVER, "%s, you're banned from this server.", PlayerName(playerid));
        ChatMsgF(playerid, X11_SERVER, "Admin: "SERVER"%s", banned_AdminName);
        ChatMsgF(playerid, X11_SERVER, "Reason: "SERVER"%s", banned_Reason);

        defer KickTimer(playerid);

        return 1;
    }

    OnPlayerAccountCheck(playerid);

    return 1;
}


hook OnPlayerDisconnect(playerid, reason)
{
    OnAccountSaved(playerid);
    va_SendClientMessageToAll(X11_ORANGE_1, "[LEFT]: %s "WHITE"disconnected.", PlayerName(playerid));
    
    return 1;
}