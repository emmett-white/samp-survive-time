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

ACMD:[4 && !IsPlayerAdmin(playerid)]setadmin(playerid, const params[])
{
    static
        targetID,
        level;

    if (sscanf(params, "ri", targetID, level))
        return HelpMsg(playerid, "/setadmin [playerid] [level]");


    SetPlayerAdminLevel(targetID, playerid, level);
    return 1;
}

stock SetPlayerAdminLevel(const targetid, const playerid, const level)
{
    if (!(0 < level < 5))
        return ErrorMsg(playerid, "You can't go below 0 and above than 4!");

    if (level == char_Admin[targetid])
        return ErrorMsg(playerid, "That player is already that admin level!");

    char_Admin[targetid] = level;

    new String: Query = str_format
    (
        "UPDATE \
            "TABLE_CHARACTER" \
        SET \
            "char_field_admin" = '%d' \
        WHERE \
            "char_field_id" = '%d'",
        char_Admin[targetid], char_UniqueID[targetid]
    );
    mysql_tquery_s(MySQL_GetHandle(), Query);


    if (level == 0)
    {
        ChatMsgF(playerid, X11_INDIAN_RED, "Admin: "WHITE"You've removed player "INDIAN_RED"%s "WHITE"from administrator position.", PlayerName(targetid));
        ChatMsgF(targetid, X11_INDIAN_RED, "Admin: "WHITE"Administrator "INDIAN_RED"%s "WHITE"removed you frm administrator position.", PlayerName(playerid));

        SetPlayerColor(targetid, 0xFFFFFFAA);
        return 1;
    }

    ChatMsgF(playerid, X11_INDIAN_RED, "Admin: "WHITE"You have successfully set up an administrator "INDIAN_RED"%d "WHITE"for the player "INDIAN_RED"%s"WHITE".", level, PlayerName(targetid));

    ChatMsgF(targetid, X11_INDIAN_RED, "Admin: "WHITE"Owner "INDIAN_RED"%s "WHITE"has assigned you a level "INDIAN_RED"%d "WHITE"administrator.", PlayerName(playerid), level);

    char_Skin[targetid] = 294;

    SetPlayerColor(targetid, 0xFF0000AA);
    SetPlayerSkin(targetid, char_Skin[targetid]);

    return 1;
}


stock Player_GetAdminLevel(const playerid)
{
    return char_Admin[playerid];
}