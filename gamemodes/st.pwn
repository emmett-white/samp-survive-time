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

#include <a_samp>

#undef MAX_PLAYERS
#define MAX_PLAYERS             (32)

// samp-logger
#define SAMP_LOGGER_COMPAT

// // Libraries and respective links to their release pages

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

#include <Pawn.RegEx>

#include <logger>                                   // https://github.com/Southclaws/samp-logger
#include <formatex>                                 // https://github.com/Southclaws/formatex

#include <callbacks>                                // https://github.com/emmet-jones/New-SA-MP-callbacks
#include <shooting-textdraw>                        // https://github.com/emmett-white/shooting-textdraw

#include <samp_bcrypt>                              // https://github.com/Sreyas-Sreelal/samp-bcrypt

#include <samp-profiler>                            // https://github.com/Zeex/samp-plugin-profiler

#include <another-chat>                             // https://github.com/emmett-white/samp-another-chat

// Modules

#include "sss/core/shortcuts.inc"
#include "sss/utils/funcs.inc"
#include "sss/utils/timers.inc"
#include "sss/core/server/setup.inc"

// Command processor
#include "sss/cmd-process.inc"

// Database
#include "sss/database/database_initialise.inc"

// Player
#include "sss/core/account/accounts.inc"

// Admin
#include "sss/core/admin/admin_core.inc"

// UI
#include "sss/core/user-interface/help-message.inc"

// Vehicles
#include "sss/core/vehicle/adjustment.inc"

main()
{
    log("Gamemode successfully initialised.");
}

CMD:veh(playerid, const params[])
{
    new Float: x, Float: y, Float: z;
    GetPlayerPos(playerid, x, y, z);

    CreateVehicle(411, x, y, z, 0.0, 0, 0, 0, 0);

    return 1;
}
