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


hook OnGameModeInit()
{
    mysql_tquery(MySQL_GetHandle(), "SELECT * FROM "TABLE_DEALERS"", "OnDealersLoaded", "");

    return 1;
}


// Dealer offers
hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if (playertextid == dealer_TextDraws[playerid][2])
    {
        Dealer_AcceptOffers(playerid, E_DEALER_OFFER_COLT);
    }

    if (playertextid == dealer_TextDraws[playerid][3])
    {
        Dealer_AcceptOffers(playerid, E_DEALER_OFFER_KNIFE);
    }

    if (playertextid == dealer_TextDraws[playerid][4])
    {
        Dealer_AcceptOffers(playerid, E_DEALER_OFFER_AK47);
    }

    if (playertextid == dealer_TextDraws[playerid][5])
    {
        Dealer_AcceptOffers(playerid, E_DEALER_OFFER_DRUG);
    }

    if (playertextid == dealer_TextDraws[playerid][14])
    {
        UI_CreateDealerOffers(playerid, false);
    }

    return 1;
}