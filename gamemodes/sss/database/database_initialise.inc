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

static MySQL:database_Handle;

// Hooks

hook OnGameModeInit()
{
    MySQL_CreateConnection();
    return 1;
}

hook OnGameModeExit()
{
    if (!mysql_close(database_Handle)) {
        err("Failed to terminate the database connection. Please check this.");
    }

    return 1;
}

// Functions

static MySQL_CreateConnection()
{
    new hostname[24];
    if (Env_Has("MYSQL_HOST")) {
        Env_Get("MYSQL_HOST", hostname, sizeof hostname);
    }

    new username[24];
    if (Env_Has("MYSQL_USER")) {
        Env_Get("MYSQL_USER", username, sizeof username);
    }
 
    new password[24];
    if (Env_Has("MYSQL_PASSWORD")) {
        Env_Get("MYSQL_PASSWORD", password, sizeof password);
    }

    new database[24];
    if (Env_Has("MYSQL_DATABASE")) {
        Env_Get("MYSQL_DATABASE", database, sizeof database);
    }
 
    new MySQLOpt: options = mysql_init_options();
    mysql_set_option(options, AUTO_RECONNECT, true);
    mysql_set_option(options, MULTI_STATEMENTS, true);
    mysql_set_option(options, POOL_SIZE, 2);

    database_Handle = mysql_connect(hostname, username, password, database, options);

    if (mysql_errno(database_Handle) != 0) {
        err("[MySQL]: Can't connect to database!");
        
        SendRconCommand("exit");
        return 1;
    }
    
    log("[MySQL]: Successfully connected to database.");

    return 1;
}

// OnQueryError - REQUIRED
public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
    return 1;
}

stock MySQL: MySQL_GetHandle()
{
    return database_Handle;
}

stock Task: MySQL_Query(const query[])
{
    return mysql_aquery(MySQL_GetHandle(), query, true);
}

stock Task: MySQL_QueryS(ConstStringTag:query)
{
    return mysql_aquery_s(MySQL_GetHandle(), query, true);
}