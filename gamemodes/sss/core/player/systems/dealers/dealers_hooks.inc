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
    task_await
    (
        MySQL_QueryS
        (
            str_format
            (
                "SELECT * FROM "TABLE_DEALERS""
            )
        )
    );

    if (cache_num_rows())
    {
        for (new i; i < cache_num_rows(); ++i)
        {
            new
                id = Iter_Alloc(Iter_Dealers);

            cache_get_value_name_int(i, "dealer_id", dealer_UniqueID[id]);

            cache_get_value_name_float(i, "dealer_x", dealer_PosX[id]);
            cache_get_value_name_float(i, "dealer_y", dealer_PosY[id]);
            cache_get_value_name_float(i, "dealer_z", dealer_PosZ[id]);
            cache_get_value_name_float(i, "dealer_a", dealer_PosA[id]);

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