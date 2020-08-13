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

CMD:takejob(playerid, const params[])
{
    if (char_Job[playerid])
    {
        return ErrorMsg(playerid, "You already have a job.");
    }


    // Hospital
    if (IsPlayerInRangeOfPoint(playerid, 3.0, -28.2635, 152.7430, 999.0621))
    {
        char_Job[playerid] = PARAMEDIC_JOB;

        ChatMsg(playerid, X11_SERVER, "You are now working as an paramedic.");
        ChatMsg(playerid, X11_SERVER, "Now you can use your equipment (/equipment).");
    }

    return 1;
}


CMD:equipment(playerid, const params[])
{
    if (!char_Job[playerid])
    {
        return ErrorMsg(playerid, "You don't have any job!");
    }


    if (takenEquipment[playerid])
    {
        return ChatMsg(playerid, X11_SERVER, "You've already taken the equipment.");
    }


    if (IsPlayerInRangeOfPoint(playerid, 3.0, -28.3253, 151.2038, 999.0620))
    {
        paramedicEquipment[playerid] = (paramedicEquipment[playerid]) ? (false) : (true);
        SetPlayerSkin(playerid, (paramedicEquipment[playerid]) ? (275) : char_Skin[playerid]);
    }

    return 1;
}


CMD:jobhelp(playerid, const params[])
{
    if (!char_Job[playerid])
    {
        return ErrorMsg(playerid, "You don't have any job!");
    }
    

    switch (char_Job[playerid])
    {
        case PARAMEDIC_JOB:
        {
            ChatMsg(playerid, X11_SERVER, "/equipment, /job");
        }
    }

    return 1;
}


