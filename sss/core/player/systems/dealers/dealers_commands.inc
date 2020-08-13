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

ACMD:[4]createdealer(playerid, const params[])
{
    new
        Float: x,
        Float: y,
        Float: z,
        Float: a
    ;

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);

    Dealer_Create(playerid, x, y, z, a);

    return 1;
}


ACMD:[4]deletedealer(playerid, const params[])
{
    if (isnull(params))
    {
        return HelpMsg(playerid, "/deletedealer [dealer id]");
    }


    if (!isnumeric(params))
    {
        return ErrorMsg(playerid, "Invalid input!");
    }


    static dID = strval(params);


    task_await
    (
        MySQL_QueryS
        (
            str_format
            (
                "SELECT * FROM "TABLE_DEALERS" WHERE "dealer_field_id" = '%d'",
                dID
            )
        )
    );


    if (!cache_num_rows())
    {
        ErrorMsg(playerid, "Invalid dealer ID!");
        return 1;
    }

    new String: Query = str_format
    (
        "DELETE FROM "TABLE_DEALERS" WHERE "dealer_field_id" = '%d'",
        dID
    );
    mysql_tquery_s(MySQL_GetHandle(), Query);

    return 1;
}


ACMD:[1]gotodealer(playerid, const params[])
{
    if (isnull(params))
    {
        return HelpMsg(playerid, "/gotodealer [dealer id]");
    }


    if (!isnumeric(params))
    {
        return ErrorMsg(playerid, "Invalid input!");
    }


    static dID = strval(params);


    task_await
    (
        MySQL_QueryS
        (
            str_format
            (
                "SELECT * FROM "TABLE_DEALERS" WHERE "dealer_field_id" = '%d'", dID
            )
        )
    );


    if (!cache_num_rows())
    {
        ErrorMsg(playerid, "Invalid dealer ID!");
        return 1;
    }

    SetPlayerPos(playerid, (dealer_PosX[(dID - 1)] + 4.0), dealer_PosY[(dID - 1)], dealer_PosZ[(dID - 1)]);

    return 1;
}


// Player commands
CMD:dealer(playerid, const params[])
{
    if (!Dealer_Nearby(playerid))
    {
        return ErrorMsg(playerid, "You need to be close to the dealer!");
    }
    

    UI_CreateDealerOffers(playerid, true);

    return 1;
}