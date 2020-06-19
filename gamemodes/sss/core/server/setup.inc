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

// Server informations

#define SERVER_GAMEMODE	 		"Survive Time | v1.0"
#define SERVER_MAPNAME	 		"San Andreas"
#define SERVER_LANGUAGE	 		"English"
#define SERVER_WEBURL	 		"www.survive-time.com"

// Hooks

hook OnGameModeInit()
{
	SetGameModeText(SERVER_GAMEMODE);
	SendRconCommand("mapname "SERVER_MAPNAME"");
	SendRconCommand("language "SERVER_LANGUAGE"");
	SendRconCommand("weburl "SERVER_WEBURL"");

    DisableInteriorEnterExits();

    Profiler_Start();

    // Load vehicles
    LoadStaticVehiclesFromFile("vehicles/ls_airport.txt");
    LoadStaticVehiclesFromFile("vehicles/ls_gen_inner.txt");
    LoadStaticVehiclesFromFile("vehicles/ls_gen_outer.txt");
    LoadStaticVehiclesFromFile("vehicles/ls_law.txt");

	return 1;
}

hook OnGameModeExit()
{
    Profiler_Stop();
    return 1;
}