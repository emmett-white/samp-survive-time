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


// Hooks
hook OnGameModeInit()
{
	AddStaticVehicleEx(416, 1178.0532000, -1338.8334000, 14.0885000, -90.0000000, -1, -1, 0); // Ambulance
	AddStaticVehicleEx(416, 1178.0532000, -1308.4641000, 14.0885000, -90.0000000, -1, -1, 0); // Ambulance
	AddStaticVehicleEx(416, 1183.5928000, -1331.3372000, 14.0885000, 0.0000000, -1, -1, 0); // Ambulance
	AddStaticVehicleEx(416, 1183.5928000, -1315.3890000, 14.0885000, 180.0000000, -1, -1, 0); // Ambulance
	AddStaticVehicleEx(416, 1188.1200000, -1344.7246000, 14.0885000, 0.0000000, -1, -1, 0); // Ambulance
	AddStaticVehicleEx(416, 1188.1200000, -1302.0371000, 14.0885000, 180.0000000, -1, -1, 0); // Ambulance

	// Enter & Exit pickups
	paramedicPickup[0] = CreatePickup(ENTER_EXIT_PICKUP, 1, 1172.7817, -1323.2935, 15.4007);
	paramedicPickup[1] = CreatePickup(ENTER_EXIT_PICKUP, 1, -62.8670, 153.6974, 999.0569);
	paramedicPickup[2] = CreatePickup(JOB_PICKUP, 1, -28.2635,152.7430,999.0621);
	paramedicPickup[3] = CreatePickup(EQUIPMENT_PICKUP, 1, -28.3253,151.2038,999.0620);

	return 1;
}


hook OnGameModeExit()
{
	for (new i = 0; i < sizeof(paramedicPickup); ++i)
	{
		DestroyPickup(paramedicPickup[i]);
	}

	return 1;
}


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (PRESSED(KEY_SECONDARY_ATTACK))
	{
		// Paramedic

	    if (IsPlayerInRangeOfPoint(playerid, 3.0, 1172.7817,-1323.2935,15.4007))
	    {
	        SetPlayerPos(playerid, -62.8670,153.6974,999.0569);
	    }

	    else if (IsPlayerInRangeOfPoint(playerid, 3.0, -62.8670,153.6974,999.0569))
	    {
	    	SetPlayerPos(playerid, 1172.7817,-1323.2935,15.4007);
	    }
	}

	return 1;
}