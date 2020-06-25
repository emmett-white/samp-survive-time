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

// Variables

new
    PlayerBar: UI_Bar[MAX_PLAYERS] = {INVALID_PLAYER_BAR_ID,...};


// Hooks

hook OnPlayerConnect(playerid)
{
    UI_Bar[playerid] = CreatePlayerProgressBar(playerid, 287.000000, 304.000000, 69.000000, 3.200000, -488447233, 100.0000, 0);

    return 1;
}


// Functions

stock UI_ShowPlayerBar(const playerid)
{
    ShowPlayerProgressBar(playerid, UI_Bar[playerid]);

    defer UI_UpdatePlayerBar(playerid);

    return 1;
}


// Timers

timer UI_UpdatePlayerBar[bar_delay](playerid)
{
    new
        Float: value = GetPlayerProgressBarValue(playerid, UI_Bar[playerid]);


    if (value == 100.0)
    {
        SetPlayerProgressBarValue(playerid, UI_Bar[playerid], 0.0);
        HidePlayerProgressBar(playerid, UI_Bar[playerid]);
        return 1;
    }


    value += 5.0;

    SetPlayerProgressBarValue(playerid, UI_Bar[playerid], (value + 5.0));
    defer UI_UpdatePlayerBar(playerid);

    return 1;
}