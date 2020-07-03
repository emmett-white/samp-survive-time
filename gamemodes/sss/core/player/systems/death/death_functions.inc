stock CreateDeathTextDraws()
{
    __deathTextDraws[0] = TextDrawCreate(0.453909, 1.000005, "box");
    TextDrawLetterSize(__deathTextDraws[0], 0.000000, 65.771034);
    TextDrawTextSize(__deathTextDraws[0], 663.000000, 0.000000);
    TextDrawAlignment(__deathTextDraws[0], 1);
    TextDrawColor(__deathTextDraws[0], -16776961);
    TextDrawUseBox(__deathTextDraws[0], 1);
    TextDrawBoxColor(__deathTextDraws[0], 1677721855);
    TextDrawSetShadow(__deathTextDraws[0], 0);
    TextDrawSetOutline(__deathTextDraws[0], 0);
    TextDrawBackgroundColor(__deathTextDraws[0], 255);
    TextDrawFont(__deathTextDraws[0], 1);
    TextDrawSetProportional(__deathTextDraws[0], 1);
    TextDrawSetShadow(__deathTextDraws[0], 0);

    __deathTextDraws[1] = TextDrawCreate(0.922470, 179.619064, "box");
    TextDrawLetterSize(__deathTextDraws[1], 0.000000, -0.120056);
    TextDrawTextSize(__deathTextDraws[1], 643.000000, 0.000000);
    TextDrawAlignment(__deathTextDraws[1], 1);
    TextDrawColor(__deathTextDraws[1], -1);
    TextDrawUseBox(__deathTextDraws[1], 1);
    TextDrawBoxColor(__deathTextDraws[1], 255);
    TextDrawSetShadow(__deathTextDraws[1], 0);
    TextDrawSetOutline(__deathTextDraws[1], 0);
    TextDrawBackgroundColor(__deathTextDraws[1], 255);
    TextDrawFont(__deathTextDraws[1], 1);
    TextDrawSetProportional(__deathTextDraws[1], 1);
    TextDrawSetShadow(__deathTextDraws[1], 0);

    __deathTextDraws[2] = TextDrawCreate(0.922470, 264.640960, "box");
    TextDrawLetterSize(__deathTextDraws[2], 0.000000, -0.120056);
    TextDrawTextSize(__deathTextDraws[2], 643.000000, 0.000000);
    TextDrawAlignment(__deathTextDraws[2], 1);
    TextDrawColor(__deathTextDraws[2], -1); 
    TextDrawUseBox(__deathTextDraws[2], 1);
    TextDrawBoxColor(__deathTextDraws[2], 255);
    TextDrawSetShadow(__deathTextDraws[2], 0);
    TextDrawSetOutline(__deathTextDraws[2], 0);
    TextDrawBackgroundColor(__deathTextDraws[2], 255);
    TextDrawFont(__deathTextDraws[2], 1);
    TextDrawSetProportional(__deathTextDraws[2], 1);
    TextDrawSetShadow(__deathTextDraws[2], 0);

    __deathTextDraws[3] = TextDrawCreate(314.130401, 140.480529, "wasted");
    TextDrawLetterSize(__deathTextDraws[3], 0.886399, 3.354165);
    TextDrawAlignment(__deathTextDraws[3], 2);
    TextDrawColor(__deathTextDraws[3], -5963521);
    TextDrawSetShadow(__deathTextDraws[3], 0);
    TextDrawSetOutline(__deathTextDraws[3], 1);
    TextDrawBackgroundColor(__deathTextDraws[3], 255);
    TextDrawFont(__deathTextDraws[3], 3);
    TextDrawSetProportional(__deathTextDraws[3], 1);
    TextDrawSetShadow(__deathTextDraws[3], 0);

    __deathTextDraws[4] = TextDrawCreate(-0.951641, 183.166625, "box");
    TextDrawLetterSize(__deathTextDraws[4], 0.000000, 8.547583);
    TextDrawTextSize(__deathTextDraws[4], 638.000000, 0.000000);
    TextDrawAlignment(__deathTextDraws[4], 1);
    TextDrawColor(__deathTextDraws[4], -126);
    TextDrawUseBox(__deathTextDraws[4], 1);
    TextDrawBoxColor(__deathTextDraws[4], 150);
    TextDrawSetShadow(__deathTextDraws[4], 0);
    TextDrawSetOutline(__deathTextDraws[4], 0);
    TextDrawBackgroundColor(__deathTextDraws[4], 255);
    TextDrawFont(__deathTextDraws[4], 1);
    TextDrawSetProportional(__deathTextDraws[4], 1);
    TextDrawSetShadow(__deathTextDraws[4], 0);

    __deathTextDraws[5] = TextDrawCreate(305.000915, 186.999816, "You_are_dead~n~If_you_would_like_to_cancel_this_animation,_type_/acceptdeath~n~but_if_you_want_help_though");
    TextDrawLetterSize(__deathTextDraws[5], 0.325035, 1.512500);
    TextDrawAlignment(__deathTextDraws[5], 2);
    TextDrawColor(__deathTextDraws[5], -1);
    TextDrawSetShadow(__deathTextDraws[5], 0);
    TextDrawSetOutline(__deathTextDraws[5], 1);
    TextDrawBackgroundColor(__deathTextDraws[5], 255);
    TextDrawFont(__deathTextDraws[5], 1);
    TextDrawSetProportional(__deathTextDraws[5], 1);
    TextDrawSetShadow(__deathTextDraws[5], 0);

    __deathTextDraws[6] = TextDrawCreate(305.606475, 227.633163, "use_the_command_bellow~n~/911");
    TextDrawLetterSize(__deathTextDraws[6], 0.325035, 1.512500);
    TextDrawAlignment(__deathTextDraws[6], 2);
    TextDrawColor(__deathTextDraws[6], -1);
    TextDrawSetShadow(__deathTextDraws[6], 0);
    TextDrawSetOutline(__deathTextDraws[6], 1);
    TextDrawBackgroundColor(__deathTextDraws[6], 255);
    TextDrawFont(__deathTextDraws[6], 1);
    TextDrawSetProportional(__deathTextDraws[6], 1);
    TextDrawSetShadow(__deathTextDraws[6], 0);
}

stock HandleDeathTextDrawsForPlayer(playerid, bool:showorhide)
{
    if(!showorhide)
    {
        TextDrawHideForPlayer(playerid, __deathTextDraws[0]), TextDrawHideForPlayer(playerid, __deathTextDraws[1]), TextDrawHideForPlayer(playerid, __deathTextDraws[2]);
        TextDrawHideForPlayer(playerid, __deathTextDraws[3]), TextDrawHideForPlayer(playerid, __deathTextDraws[4]), TextDrawHideForPlayer(playerid, __deathTextDraws[5]);
        TextDrawHideForPlayer(playerid, __deathTextDraws[6]);
    }
    else
    {
        TextDrawShowForPlayer(playerid, __deathTextDraws[0]), TextDrawShowForPlayer(playerid, __deathTextDraws[1]), TextDrawShowForPlayer(playerid, __deathTextDraws[2]);
        TextDrawShowForPlayer(playerid, __deathTextDraws[3]), TextDrawShowForPlayer(playerid, __deathTextDraws[4]), TextDrawShowForPlayer(playerid, __deathTextDraws[5]);
        TextDrawShowForPlayer(playerid, __deathTextDraws[6]);
    }
}
