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


// Variables
static
    bool: vehicle_lockedDoor[MAX_VEHICLES],
    bool: vehicle_lightsStatus[MAX_VEHICLES]
;


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_SUBMISSION) && IsPlayerInAnyVehicle(playerid))
    {
        static
            vehicleid = GetPlayerVehicleID(playerid),

            engine,
            lights,
            alarm,
            doors,
            bonnet,
            boot,
            objective
        ;

        vehicle_lockedDoor[vehicleid] = (vehicle_lockedDoor[vehicleid]) ? (false) : (true);

        GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
        SetVehicleParamsEx(vehicleid, engine, lights, alarm, vehicle_lockedDoor[vehicleid], bonnet, boot, objective);

        HelpMessage(playerid, (vehicle_lockedDoor[vehicleid]) ? ("~r~LOCKED") : ("~g~UNLOCKED"));
    }

    if (PRESSED(KEY_CROUCH) && IsPlayerInAnyVehicle(playerid))
    {
        static
            vehicleid = GetPlayerVehicleID(playerid),

            engine,
            lights,
            alarm,
            doors,
            bonnet,
            boot,
            objective
        ;

        vehicle_lightsStatus[vehicleid] = (vehicle_lightsStatus[vehicleid]) ? (false) : (true);

        GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
        SetVehicleParamsEx(vehicleid, engine, vehicle_lightsStatus[vehicleid], alarm, doors, bonnet, boot, objective);

        HelpMessage(playerid, (vehicle_lightsStatus[vehicleid]) ? ("~r~LIGHTS OFF") : ("~g~LIGHTS ON"));
    }

    return 1;
}


hook OnPlayerExitVehicle(playerid, vehicleid)
{
    new
        engine,
        lights,
        alarm,
        doors,
        bonnet,
        boot,
        objective
    ;

    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(vehicleid, engine, lights, alarm, 0, bonnet, boot, objective);

    SetVehicleNumberPlate(vehicleid, PlayerName(playerid));
    
    return 1;
}