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

stock Dealer_Create(const playerid, Float: x, Float: y, Float: z, Float: a)
{
    new
        dID = Iter_Free(Iter_Dealers);

    new String: ActorLabelString = str_format
    (
        "Actor - "WHITE"%d\n"SERVER"Type /dealer",
        (dID + 1)
    );

    dealer_Label[dID] = CreateFormattedLabel(
        ActorLabelString, X11_SERVER,
        x, y, z,
        10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID,
        0, -1, -1, -1, 10.0, -1, 0
    );

    dealer_PosX[dID] = x;
    dealer_PosY[dID] = y;
    dealer_PosZ[dID] = z;
    dealer_PosA[dID] = a;

    CreateActor(29, dealer_PosX[dID], dealer_PosY[dID], dealer_PosZ[dID], dealer_PosA[dID]);

    new String: Query = str_format
    (
        "INSERT INTO \
            "TABLE_DEALERS" \
        ("dealer_field_x", "dealer_field_y", "dealer_field_z", "dealer_field_a") \
        VALUES \
            ('%f', '%f', '%f', '%f')",
        dealer_PosX[dID], dealer_PosY[dID], dealer_PosZ[dID], dealer_PosA[dID]
    );
    mysql_tquery_s(MySQL_GetHandle(), Query, "Dealer_InsertIntoDB", "di", playerid, dID);

    Iter_Add(Iter_Dealers, dID);

    return 1;
}

stock Dealer_Delete(const playerid, dID)
{
    task_await
    (
        MySQL_QueryS
        (
            str_format
            (
                "SELECT * FROM \
                    "TABLE_DEALERS" \
                WHERE \
                    "dealer_field_id" = '%d'",
                dID
            )
        )
    );


    if (!cache_num_rows())
        return ErrorMsg(playerid, "The dealer you are trying to delete was not found in database.");


    new String: Query = str_format
    (
        "DELETE FROM \
            "TABLE_DEALERS" \
        WHERE \
            "dealer_field_id" = '%d'",
        dID
    );
    mysql_tquery_s(MySQL_GetHandle(), Query);

    DestroyDynamic3DTextLabel(dealer_Label[dID]);
    DestroyActor(dealer_Actor[dID]);

    Iter_Remove(Iter_Dealers, dID);

    return 1;
}


stock Dealer_Nearby(const playerid)
{
    for (new i = 0; i < MAX_DEALERS; ++i)
    {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, dealer_PosX[i], dealer_PosY[i], dealer_PosZ[i]))
            return 1;
    }

    return 0;
}


stock Dealer_AcceptOffers(const playerid, const offer)
{
    switch (offer)
    {
        case E_DEALER_OFFER_COLT:
        {
            inline Dialog_BuyColt(id, dialogid, response, listitem, string: inputtext[])
            {
                #pragma unused id, dialogid, listitem, inputtext

                if (!response)
                    return 1;


                if (char_Money[playerid] < 130)
                    return ErrorMsg(playerid, "You don't have enough money!");

                GivePlayerWeapon(playerid, 22, 50);
                GivePlayerMoney(playerid, -130);

                char_Money[playerid] -= 130;

                ChatMsg(playerid, X11_SERVER, "You bought colt-45 with 50 ammo for $130!");
            }

            Dialog_ShowCallbackF
            (
                playerid, using inline Dialog_BuyColt, DIALOG_STYLE_MSGBOX,
                ""SERVER"Dealer "WHITE"Offers",
                ""SERVER">> %s, "WHITE"do you really want to buy colt-45 for "SERVER"$130"WHITE"?",
                ""SERVER"Buy", "Cancel", PlayerName(playerid)
            );
        }

        case E_DEALER_OFFER_KNIFE:
        {
            inline Dialog_BuyKnife(id, dialogid, response, listitem, string: inputtext[])
            {
                #pragma unused id, dialogid, listitem, inputtext

                if (!response)
                    return 1;


                if (char_Money[playerid] < 40)
                    return ErrorMsg(playerid, "You don't have enough money!");

                GivePlayerWeapon(playerid, 4, 1);
                GivePlayerMoney(playerid, -40);

                char_Money[playerid] -= 40;

                ChatMsg(playerid, X11_SERVER, "You bought knife for $40!");
            }

            Dialog_ShowCallbackF
            (
                playerid, using inline Dialog_BuyKnife, DIALOG_STYLE_MSGBOX,
                ""SERVER"Dealer "WHITE"Offers",
                ""SERVER">> %s, "WHITE"do you really want to buy colt-45 for "SERVER"$130"WHITE"?",
                ""SERVER"Buy", "Cancel", PlayerName(playerid)
            );
        }

        case E_DEALER_OFFER_AK47:
        {
            inline Dialog_BuyAk47(id, dialogid, response, listitem, string: inputtext[])
            {
                #pragma unused id, dialogid, listitem, inputtext

                if (!response)
                    return 1;


                if (char_Money[playerid] < 200)
                    return ErrorMsg(playerid, "You don't have enough money!");

                GivePlayerWeapon(playerid, 30, 50);
                GivePlayerMoney(playerid, -200);

                char_Money[playerid] -= 200;

                ChatMsg(playerid, X11_SERVER, "You bought ak47 with 50 ammo for $200!");
            }

            Dialog_ShowCallbackF
            (
                playerid, using inline Dialog_BuyAk47, DIALOG_STYLE_MSGBOX,
                ""SERVER"Dealer "WHITE"Offers",
                ""SERVER">> %s, "WHITE"do you really want to buy AK-47 for "SERVER"$130"WHITE"?",
                ""SERVER"Buy", "Cancel", PlayerName(playerid)
            );
        }

        case E_DEALER_OFFER_DRUG:
        {
            inline Dialog_BuyDrug(id, dialogid, response, listitem, string: inputtext[])
            {
                #pragma unused id, dialogid, listitem, inputtext

                if (!response)
                    return 1;


                if (char_Money[playerid] < 80)
                    return ErrorMsg(playerid, "You don't have enough money!");

                char_Drugs[playerid] += 20;
                GivePlayerMoney(playerid, -80);

                char_Money[playerid] -= 80;

                ChatMsg(playerid, X11_SERVER, "You bought 20g drugs $80!");
            }

            Dialog_ShowCallbackF
            (
                playerid, using inline Dialog_BuyDrug, DIALOG_STYLE_MSGBOX,
                ""SERVER"Dealer "WHITE"Offers",
                ""SERVER">> %s, "WHITE"do you really want to buy 20g drugs for "SERVER"$80"WHITE"?",
                ""SERVER"Buy", "Cancel", PlayerName(playerid)
            );
        }
    }

    return 1;
}