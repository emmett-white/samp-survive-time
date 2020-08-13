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

hook OnPlayerConnect(playerid)
{
    // Default value of hunger is 100.0
    HungerValue[playerid] = 100.0;

    HungerBar[playerid] = CreatePlayerProgressBar(playerid, 628.000000, 445.000000, 8.000000, 68.699996, -16777046, 100.0, 2);
    SetPlayerProgressBarValue(playerid, HungerBar[playerid], HungerValue[playerid]);

    return 1;
}


hook OnPlayerUpdate(playerid)
{
	static
		animIndex = GetPlayerAnimationIndex(playerid),
		Float: food = GetPlayerProgressBarValue(playerid, HungerBar[playerid]),
	
		k,
		ud,
		lr
	;

	GetPlayerKeys(playerid, k, ud, lr);

	// No animation applied
	if (animIndex == 0)
	{
		food -= IDLE_FOOD_RATE;
		SetPlayerProgressBarValue(playerid, HungerBar[playerid], food);
	}

	// Sitting animation
	else if (animIndex == 43)
	{
		food -= (IDLE_FOOD_RATE * 0.2);
		SetPlayerProgressBarValue(playerid, HungerBar[playerid], food);
	}

	// Crouch animation
	else if (animIndex == 1159)
	{
		food -= (IDLE_FOOD_RATE * 1.1);
		SetPlayerProgressBarValue(playerid, HungerBar[playerid], food);
	}

	// Jump animation
	else if (animIndex == 1195)
	{
		food -= (IDLE_FOOD_RATE * 3.2);
		SetPlayerProgressBarValue(playerid, HungerBar[playerid], food);
	}

	// Run animation
	else if(animIndex == 1231)
	{
		// Walk animation
		if(k & KEY_WALK)
		{
			food -= IDLE_FOOD_RATE * 1.2;
			SetPlayerProgressBarValue(playerid, HungerBar[playerid], food);
		}

		// Sprint animation
		else if(k & KEY_SPRINT)
		{
			food -= IDLE_FOOD_RATE * 2.2;
			SetPlayerProgressBarValue(playerid, HungerBar[playerid], food);
		}

		// Jump animation
		else if(k & KEY_JUMP)
		{
			food -= IDLE_FOOD_RATE * 3.2;
			SetPlayerProgressBarValue(playerid, HungerBar[playerid], food);
		}

		else
		{
			food -= IDLE_FOOD_RATE * 2.0;
			SetPlayerProgressBarValue(playerid, HungerBar[playerid], food);
		}
	}

	if(food > 100.0)
	{
		food = 100.0;
	}

	return 1;
}