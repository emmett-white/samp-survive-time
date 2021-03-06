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

forward OnDealersLoaded();
public OnDealersLoaded()
{
    if (cache_num_rows())
    {
        for (new i; i < cache_num_rows(); ++i)
        {
            new id = Iter_Alloc(Iter_Dealers);

            cache_get_value_name_int(i, "dealer_id", dealer_UniqueID[id]);

            cache_get_value_name_float(i, "x", dealer_PosX[id]);
            cache_get_value_name_float(i, "y", dealer_PosY[id]);
            cache_get_value_name_float(i, "z", dealer_PosZ[id]);
            cache_get_value_name_float(i, "a", dealer_PosA[id]);

            dealer_Actor[id] = CreateActor(29, dealer_PosX[id], dealer_PosY[id], dealer_PosZ[id], dealer_PosA[id]);

            new String: ActorLabelString = str_format
            (
                "Actor - "WHITE"%d\n"SERVER"Type /dealer",
                dealer_UniqueID[id]
            );

            dealer_Label[id] = CreateFormattedLabel(
                ActorLabelString, X11_SERVER,
                dealer_PosX[id], dealer_PosY[id], dealer_PosZ[id],
                10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID,
                0, -1, -1, -1, 10.0, -1, 0
            );

            ++loadedDealers;
        }

        log("Dealers > loaded ", _i("dealers: ", loadedDealers));
    }

    return 1;
}


forward Dealer_InsertIntoDB(const playerid, dID);
public Dealer_InsertIntoDB(const playerid, dID)
{
    dealer_UniqueID[dID] = cache_insert_id();
    ChatMsgF(playerid, X11_SERVER, "You've successfully create dealer ID %d.", dealer_UniqueID[dID]);

    return 1;
}