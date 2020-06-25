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

stock SetPlayerDrugsLevel(const playerid)
{
    static
        drugsLevel;


    if (char_Drugs[playerid] <= 20)
    {
        usingDrugs[playerid] = true;
        char_Drugs[playerid] -= 20;

        drugsLevel = 2009;
        bar_delay = 1000;

        SetPlayerWeather(playerid, drugsLevel);
        UI_ShowPlayerBar(playerid);

        defer DrugEffectFinished(playerid);
    }

    else if (char_Drugs[playerid] >= 40)
    {
        usingDrugs[playerid] = true;
        char_Drugs[playerid] -= 20;

        drugsLevel = 250;
        bar_delay = 1000;

        SetPlayerWeather(playerid, drugsLevel);
        UI_ShowPlayerBar(playerid);

        defer DrugEffectFinished(playerid);
    }

    else if (char_Drugs[playerid] >= 60)
    {
        usingDrugs[playerid] = true;
        char_Drugs[playerid] -= 20;

        drugsLevel = 100;
        bar_delay = 1000;

        SetPlayerWeather(playerid, drugsLevel);
        UI_ShowPlayerBar(playerid);

        defer DrugEffectFinished(playerid);
    }

    return 1;
}