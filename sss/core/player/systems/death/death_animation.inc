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
hook OnGameModeInit()
{
    CreateDeathTextDraws();
    return 1;
}


hook OnPlayerDeath(playerid)
{
    new
        Float: x,
        Float: y,
        Float: z,
        Float: a
    ;


    if(__deathCommand[playerid] || deathTimerStatus[playerid] != 0)
    {
        new rand = random(sizeof randomSpawnPositions);
        SetSpawnInfo
        (
            playerid, 0, char_Skin[playerid],
            randomSpawnPositions[rand][0], randomSpawnPositions[rand][1], randomSpawnPositions[rand][2], randomSpawnPositions[rand][3],
            0, 0, 0, 0, 0, 0
        );

        TogglePlayerControllable(playerid, 0);
        defer SpawnTimer(playerid);

        HandleDeathTextDrawsForPlayer(playerid, false);
        stop deathTimer[playerid];

        deathTimerStatus[playerid] = 0;
        __deathCommand[playerid] = false;
        __deathAnimation[playerid] = false;

        return 0;
    }

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);

    SetSpawnInfo
    (
        playerid, NO_TEAM, char_Skin[playerid], 
        x, y, z, a, 0, 0, 0, 0, 0, 0
    );


    // Injured animation value setting
    SendClientMessage(playerid, X11_SERVER, "Type /accceptdeath to die or type /ems to call paramedics.");
    PreloadAnimLib(playerid, "SWEET");

    __deathAnimation[playerid] = true;

    
    return 1;
}


hook OnPlayerSpawn(playerid)
{
    if(__deathAnimation[playerid]) 
    {
        ApplyAnimation(playerid, "SWEET", "Sweet_injuredloop", 4.1, 1, 0, 0, 0, 0);
        HandleDeathTextDrawsForPlayer(playerid, true);

        deathTimer[playerid] = repeat WastedTimer(playerid);
        deathTimerStatus[playerid] = 1;
    }
    
    return 1;
}
