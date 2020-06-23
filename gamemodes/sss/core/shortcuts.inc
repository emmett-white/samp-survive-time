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
// Colors

#define SERVER 	            "{e6c545}"
#define WHITE               "{FFFFFF}"

#define X11_SERVER          0xe6c545FF
#define X11_CHAT_GLOBAL     0x32a852FF

// Dialog

#define D_TITLE     ""SERVER"SURVIVE - "WHITE"TIME"
#define D_CONFIRM 	""SERVER"Submit"
#define D_CANCEL 	"Cancel"

// Messages

#define ChatMsg(%0,%1,%2) \
    SendClientMessage(%0, %1, "> "WHITE""%2)

#define ChatMsgF(%0,%1,%2) \
    va_SendClientMessage(%0, %1, "> "WHITE""%2)

#define ChatMsgAll(%0,%1) \
    SendClientMessageToAll(%0,""%1)

#define ChatMsgAllF(%0,%1) \
    va_SendClientMessageToAll(%0,""%1)

#define ErrorMsg(%0,%1) \
  	SendClientMessage(%0, X11_INDIAN_RED_3, ""%1)

#define HelpMsg(%0,%1) \
  	SendClientMessage(%0, X11_GRAY, "USAGE: "%1)

#define SendAdminMessage(%0,%1,%2) \
    foreach(new %0: Player) if (char_Admin[%0] >= 1) va_SendClientMessage(%0, %1, ""%2)    

#define ClearChat(%0,%1) \
  for(new i; i < %1; ++i) SendClientMessage(%0, -1, " ")

// Keys

#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

#define HOLDING(%0) \
    ((newkeys & (%0)) == (%0))

#define RELEASED(%0) \
    (((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))


// Limits

#undef MAX_COMMANDS
#define MAX_COMMANDS            (128)

#undef MAX_ACTORS
#define MAX_ACTORS              (24)

#define MESSAGE_MAX_LENGTH      124
#define ANNOUNCE_MAX_LENGTH     124

#define MAX_LOGIN_ATTEMPTS      3