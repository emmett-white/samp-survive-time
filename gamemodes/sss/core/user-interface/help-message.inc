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

new
	PlayerText: HelpMsg_TD[MAX_PLAYERS];

stock UI_CreateHelpMessage(const playerid, bool: status)
{
	if (status)
	{
		HelpMsg_TD[playerid] = CreatePlayerTextDraw(playerid, 319.725250, 317.686828, " ");
		PlayerTextDrawLetterSize(playerid, HelpMsg_TD[playerid], 0.237499, 0.754166);
		PlayerTextDrawAlignment(playerid, HelpMsg_TD[playerid], 2);
		PlayerTextDrawColor(playerid, HelpMsg_TD[playerid], -1);
		PlayerTextDrawSetShadow(playerid, HelpMsg_TD[playerid], 0);
		PlayerTextDrawSetOutline(playerid, HelpMsg_TD[playerid], 1);
		PlayerTextDrawBackgroundColor(playerid, HelpMsg_TD[playerid], 255);
		PlayerTextDrawFont(playerid, HelpMsg_TD[playerid], 1);
		PlayerTextDrawSetProportional(playerid, HelpMsg_TD[playerid], 1);
		PlayerTextDrawSetShadow(playerid, HelpMsg_TD[playerid], 0);

		PlayerTextDrawShow(playerid, HelpMsg_TD[playerid]);
	} else PlayerTextDrawDestroy(playerid, HelpMsg_TD[playerid]);

	return 1;
}


HelpMessage(const playerid, const message[])
{
	PlayerTextDrawShow(playerid, HelpMsg_TD[playerid]);
    PlayerTextDrawSetString(playerid, HelpMsg_TD[playerid], message);

    defer DestroyHelpMessage(playerid);

    return 1;
}


timer DestroyHelpMessage[3000](playerid)
{
    PlayerTextDrawHide(playerid, HelpMsg_TD[playerid]);
}