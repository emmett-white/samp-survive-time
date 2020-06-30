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

#include <YSI_Coding\y_hooks>


// Hooks
hook OnPlayerDeath(playerid)
{
    static
        Float: x,
        Float: y,
        Float: z,
        Float: a;


    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);

    SetPlayerPos(playerid, x, y, z);
    SetPlayerFacingAngle(playerid, a);

    // Injured animation
    ApplyAnimation(playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0);
    SendClientMessage(playerid, X11_SERVER, "Type /accceptdeath to die or type /ems to call paramedics.");

    __deathAnimation[playerid] = true;

    return 1;
}