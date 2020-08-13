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

#include <a_samp>

#undef MAX_PLAYERS
#define MAX_PLAYERS             (32)

// samp-logger
#define SAMP_LOGGER_COMPAT

// Libraries and respective links to their release pages

#include <a_mysql>                                  // https://github.com/pBlueG/SA-MP-MySQL
#include <env>

#include <streamer>                                 // https://github.com/dakyskye/pawn-env

#define YSI_NO_HEAP_MALLOC
#define FOREACH_NO_BOTS
#define FOREACH_NO_STREAMED

#include <YSI_Data\y_iterate>                       // https://github.com/pawn-lang/YSI-Includes
#include <YSI_Coding\y_timers>
#include <YSI_Data\y_bit>
#include <YSI_Server\y_colours>
#include <YSI_Coding\y_inline>
#include <YSI_Visual\y_dialog>

#include <sscanf2>                                  // https://github.com/maddinat0r/sscanf

#include <PawnPlus>                                 // https://github.com/IllidanS4/PawnPlus
#include <pp-mysql>                                 // https://github.com/AGraber/pawn-plus-mysql

// #include <Pawn.RegEx>

#include <logger>                                   // https://github.com/Southclaws/samp-logger
#include <formatex>                                 // https://github.com/Southclaws/formatex
#include <progress2>                                // https://github.com/Southclaws/progress3

#include <callbacks>                                // https://github.com/emmet-jones/New-SA-MP-callbacks
#include <shooting-textdraw>                        // https://github.com/emmett-white/shooting-textdraw

#include <samp_bcrypt>                              // https://github.com/Sreyas-Sreelal/samp-bcrypt

#include <samp-profiler>                            // https://github.com/Zeex/samp-plugin-profiler

#include <another-chat>                             // https://github.com/emmett-white/samp-another-chat

// Modules

#include <shortcuts>
#include <funcs>
#include <timers>
#include <setup>
#include <server-time>

// Command processor
#include <cmd-process>

// Database
#include <database_initialise>

// Player
#include <accounts>
#include <chat>
#include <animations>
#include <hunger>
#include <drugs>
#include <death>

// Admin
#include <admin_core>

// UI
#include <help-message>
#include <user-bar>

// Vehicles
#include <adjustment>

// Jobs
#include <jobs>

// Systems
#include <dealers>

// World
#include <maps>
#include <map-icons>


main()
{
    log("Gamemode successfully initialised.");
    
    log("Asserting MAX_PLAYERS definition and server's max players slot...");
    assert(GetMaxPlayers() == MAX_PLAYERS);
    log("Assertion succeed.");
}


// For testing

CMD:veh(playerid, const params[])
{
    new Float: x, Float: y, Float: z;
    GetPlayerPos(playerid, x, y, z);

    CreateVehicle(411, x, y, z, 0.0, 0, 0, 0, 0);

    return 1;
}

CMD:xyz(playerid, const params[])
{
    new Float: x, Float: y, Float: z;

    if (sscanf(params, "fff", x, y, z))
        return 0;

    SetPlayerPos(playerid, x, y, z);

    return 1;
}


public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    SetPlayerPos(playerid, fX, fY, fZ);
    return 1;
}
