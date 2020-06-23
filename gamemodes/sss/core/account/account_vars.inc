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

// Variables

new
    player_UniqueID[MAX_PLAYERS],
    player_Password[MAX_PLAYERS][64],
    player_LoginAttempts[MAX_PLAYERS],

    char_UniqueID[MAX_PLAYERS],
    char_Country[MAX_PLAYERS][24],
    char_Gender[MAX_PLAYERS],
    char_Skin[MAX_PLAYERS],
    char_Score[MAX_PLAYERS],
    char_Money[MAX_PLAYERS],
    char_Admin[MAX_PLAYERS];


// Spawn Positions

new Float: randomSpawnPositions[][] =
{
    { 241.1621,-30.0135,1.5781,88.3188 },
    { 247.1662,-93.5233,2.2537,88.6577 },
    { 218.2654,-86.3072,1.5705,317.5236 },
    { -80.9023,-15.2646,3.1172,36.2880 },
    { 673.0425,-522.1229,16.3281,269.7150 },
    { 671.5831,-476.9319,16.3359,197.3150 },
    { 786.0263,-826.0399,70.2896,357.8026 },
    { 900.9971,-927.9954,42.6016,179.1949 },
    { 589.1715,-1238.8641,17.8381,307.1783 },
    { 1187.1113,-1323.9055,13.5591,272.8422 },
    { 1363.3134,-1279.3271,13.5469,85.5345 },
    { 1334.2605,-1059.6702,28.1037,262.1210 },
    { 1458.3473,-1025.9438,23.8281,178.0579 }
};