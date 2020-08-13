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

CMD:heal(playerid, const params[])
{
    if (char_Job[playerid] != PARAMEDIC_JOB)
    {
        return ErrorMsg(playerid, "You're not a doctor!");
    }


    static
        targetID,

        Float: x,
        Float: y,
        Float: z
    ;


    if (sscanf(params, "r", targetID))
    {
        return HelpMsg(playerid, "/heal [playerid]");
    }


    if (takeCure[targetID])
    {
        return ErrorMsg(playerid, "That player is cured.");
    }


    GetPlayerPos(targetID, x, y, z);
    
    if (!IsPlayerInRangeOfPoint(playerid, 2.0, x, y, z))
    {
        return ErrorMsg(playerid, "You have to be close to a player!");
    }


    static Float: hp;

    GetPlayerHealth(targetID, hp);

    if (hp >= 40.0)
    {
        return ErrorMsg(playerid, "That player is in good health.");
    }


    bar_delay = 1000;
    UI_ShowPlayerBar(playerid);

    va_GameTextForPlayer(playerid, "~w~Healing player ~y~%s~w~...", 10000, 3, PlayerName(targetID));
    va_GameTextForPlayer(targetID, "~y~%s ~w~healing you...", 10000, 3, PlayerName(playerid));

    defer CuredPlayer(targetID, playerid);

    ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
    ApplyAnimation(targetID, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0);

    return 1;
}