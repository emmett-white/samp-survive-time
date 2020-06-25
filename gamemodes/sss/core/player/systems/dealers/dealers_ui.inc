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

stock UI_CreateDealerOffers(const playerid, bool: status)
{
    if (status)
    {
        dealer_TextDraws[playerid][0] = CreatePlayerTextDraw(playerid, 180.000000, 332.116638, "~y~DEALER_OFFERS");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][0], 0.890000, 3.239165);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][0], 1);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][0], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][0], 1);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][0], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][0], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][0], 3);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][0], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][0], 1);

        dealer_TextDraws[playerid][1] = CreatePlayerTextDraw(playerid, 183.074920, 354.632598, "box");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][1], 0.000000, 6.951321);
        PlayerTextDrawTextSize(playerid, dealer_TextDraws[playerid][1], 536.000000, 0.000000);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][1], 1);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][1], -1);
        PlayerTextDrawUseBox(playerid, dealer_TextDraws[playerid][1], 1);
        PlayerTextDrawBoxColor(playerid, dealer_TextDraws[playerid][1], 128);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][1], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][1], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][1], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][1], 1);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][1], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][1], 0);

        dealer_TextDraws[playerid][2] = CreatePlayerTextDraw(playerid, 195.000000, 347.500030, "");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][2], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, dealer_TextDraws[playerid][2], 88.000000, 97.000000);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][2], 1);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][2], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][2], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][2], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][2], 0);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][2], 5);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][2], 0);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][2], 0);
        PlayerTextDrawSetPreviewModel(playerid, dealer_TextDraws[playerid][2], 346);
        PlayerTextDrawSetPreviewRot(playerid, dealer_TextDraws[playerid][2], 0.000000, 0.000000, 0.000000, 1.000000);
        PlayerTextDrawSetSelectable(playerid, dealer_TextDraws[playerid][2], true);

        dealer_TextDraws[playerid][3] = CreatePlayerTextDraw(playerid, 289.375000, 362.666717, "");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][3], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, dealer_TextDraws[playerid][3], 72.000000, 56.000000);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][3], 1);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][3], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][3], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][3], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][3], 0);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][3], 5);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][3], 0);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][3], 0);
        PlayerTextDrawSetPreviewModel(playerid, dealer_TextDraws[playerid][3], 335);
        PlayerTextDrawSetPreviewRot(playerid, dealer_TextDraws[playerid][3], 0.000000, 40.000000, 0.000000, 1.000000);
        PlayerTextDrawSetSelectable(playerid, dealer_TextDraws[playerid][3], true);

        dealer_TextDraws[playerid][4] = CreatePlayerTextDraw(playerid, 372.399993, 361.350067, "");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][4], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, dealer_TextDraws[playerid][4], 76.000000, 71.000000);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][4], 1);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][4], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][4], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][4], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][4], 0);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][4], 5);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][4], 0);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][4], 0);
        PlayerTextDrawSetPreviewModel(playerid, dealer_TextDraws[playerid][4], 355);
        PlayerTextDrawSetPreviewRot(playerid, dealer_TextDraws[playerid][4], 0.000000, -20.000000, 0.000000, 2.000000);
        PlayerTextDrawSetSelectable(playerid, dealer_TextDraws[playerid][4], true);

        dealer_TextDraws[playerid][5] = CreatePlayerTextDraw(playerid, 460.450103, 353.816589, "");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][5], 0.000000, 0.000000);
        PlayerTextDrawTextSize(playerid, dealer_TextDraws[playerid][5], 58.000000, 54.000000);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][5], 1);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][5], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][5], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][5], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][5], 0);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][5], 5);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][5], 0);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][5], 0);
        PlayerTextDrawSetPreviewModel(playerid, dealer_TextDraws[playerid][5], 1575);
        PlayerTextDrawSetPreviewRot(playerid, dealer_TextDraws[playerid][5], 90.000000, 0.000000, 0.000000, 1.000000);
        PlayerTextDrawSetSelectable(playerid, dealer_TextDraws[playerid][5], true);

        dealer_TextDraws[playerid][6] = CreatePlayerTextDraw(playerid, 226.649871, 410.500061, "COLT");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][6], 0.228749, 0.888333);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][6], 2);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][6], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][6], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][6], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][6], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][6], 1);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][6], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][6], 0);

        dealer_TextDraws[playerid][7] = CreatePlayerTextDraw(playerid, 318.928100, 410.500061, "KNIFE");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][7], 0.228749, 0.888333);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][7], 2);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][7], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][7], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][7], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][7], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][7], 1);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][7], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][7], 0);

        dealer_TextDraws[playerid][8] = CreatePlayerTextDraw(playerid, 405.803100, 410.500061, "AK-47");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][8], 0.228749, 0.888333);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][8], 2);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][8], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][8], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][8], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][8], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][8], 1);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][8], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][8], 0);

        dealer_TextDraws[playerid][9] = CreatePlayerTextDraw(playerid, 491.727966, 410.500061, "DRUG");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][9], 0.228749, 0.888333);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][9], 2);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][9], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][9], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][9], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][9], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][9], 1);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][9], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][9], 0);

        dealer_TextDraws[playerid][10] = CreatePlayerTextDraw(playerid, 222.477630, 363.583312, "~w~50ammo - ~g~($130)");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][10], 0.196874, 0.835833);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][10], 2);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][10], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][10], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][10], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][10], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][10], 1);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][10], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][10], 0);

        dealer_TextDraws[playerid][11] = CreatePlayerTextDraw(playerid, 314.827545, 363.583312, "~w~1 - ~g~($40)");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][11], 0.196874, 0.835833);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][11], 2);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][11], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][11], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][11], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][11], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][11], 1);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][11], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][11], 0);

        dealer_TextDraws[playerid][12] = CreatePlayerTextDraw(playerid, 402.477630, 363.583312, "~w~50ammo - ~g~($200)");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][12], 0.196874, 0.835833);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][12], 2);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][12], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][12], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][12], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][12], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][12], 1);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][12], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][12], 0);

        dealer_TextDraws[playerid][13] = CreatePlayerTextDraw(playerid, 488.102630, 363.583312, "~w~20g - ~g~($80)");
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][13], 0.196874, 0.835833);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][13], 2);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][13], -1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][13], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][13], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][13], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][13], 1);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][13], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][13], 0);

        dealer_TextDraws[playerid][14] = CreatePlayerTextDraw(playerid, 536.250000, 345.316558, "X");
        PlayerTextDrawTextSize(playerid, dealer_TextDraws[playerid][14], 8.0, 20.0);
        PlayerTextDrawLetterSize(playerid, dealer_TextDraws[playerid][14], 0.494375, 1.611666);
        PlayerTextDrawAlignment(playerid, dealer_TextDraws[playerid][14], 2);
        PlayerTextDrawColor(playerid, dealer_TextDraws[playerid][14], -1523963137);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][14], 0);
        PlayerTextDrawSetOutline(playerid, dealer_TextDraws[playerid][14], 0);
        PlayerTextDrawBackgroundColor(playerid, dealer_TextDraws[playerid][14], 255);
        PlayerTextDrawFont(playerid, dealer_TextDraws[playerid][14], 1);
        PlayerTextDrawSetProportional(playerid, dealer_TextDraws[playerid][14], 1);
        PlayerTextDrawSetShadow(playerid, dealer_TextDraws[playerid][14], 0);
        PlayerTextDrawSetSelectable(playerid, dealer_TextDraws[playerid][14], true);

        for (new i = 0; i < 15; ++i)
            PlayerTextDrawShow(playerid, dealer_TextDraws[playerid][i]);

        SelectTextDraw(playerid, 0xFFFFFFAA);
    } else {
        for (new i = 0; i < 15; ++i)
            PlayerTextDrawDestroy(playerid, dealer_TextDraws[playerid][i]);

        CancelSelectTextDraw(playerid);
    }

    return 1;
}