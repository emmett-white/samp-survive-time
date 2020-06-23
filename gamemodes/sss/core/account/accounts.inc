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

// Tables

#define TABLE_ACCOUNTS                      "accounts"
#define TABLE_CHARACTER                     "characters"
#define TABLE_BANNED                        "banned"

// Fields

#define account_field_id                    "account_id"
#define account_field_name                  "account_name"
#define account_field_password              "account_password"
#define account_field_email                 "account_email"

#define char_field_id                       "char_id"
#define char_field_name                     "char_name"
#define char_field_country                  "char_country"
#define char_field_gender                   "char_gender"
#define char_field_money                    "char_money"
#define char_field_score                    "char_score"
#define char_field_skin                     "char_skin"
#define char_field_admin                    "char_admin"

#define banned_field_player                 "banned_pname"
#define banned_field_admin                  "banned_aname"
#define banned_field_reason                 "banned_reason"


#include <account_vars>
#include <account_hooks>
#include <account_create>
#include <account_login>
#include <account_callbacks>
#include <account_timer>