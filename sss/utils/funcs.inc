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

// Forwards

forward [MAX_PLAYER_NAME + 1]PlayerName(playerid);

// Natives

native STREAMER_TAG_3D_TEXT_LABEL:CreateFormattedLabel(ConstAmxString:text, color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0) = CreateDynamic3DTextLabel;
native Update3DLabelString(STREAMER_TAG_3D_TEXT_LABEL:id, color, ConstAmxString:text) = UpdateDynamic3DTextLabelText;

// Functions

stock PlayerName(playerid)
{
	#assert MAX_PLAYER_NAME + 1 == 25
	#emit PUSH.C 25
	#emit PUSH.S 16
	#emit PUSH.S playerid
	#emit PUSH.C 12
	#emit SYSREQ.C GetPlayerName
	#emit STACK 16
	#emit RETN
}


stock randomEx (min, max)
{
	return random((max - min + 1)) + min;
}


stock IsValidEmailAddress(const address[])
{
    new Regex:r = Regex_New("[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+");
    new check = Regex_Check(address, r);
    
    Regex_Delete(r);

    return check;
}


stock Dialog_ShowCallbackF(const playerid, Func:callback<iiiis>, style, const string:title[], const string:caption[], const string:button1[], const string:button2[] = "", {Float,_}:...)
{
	static string[4096];

	va_format(string, sizeof string, caption, ___(7));
	Dialog_ShowCallback(playerid, callback, style, title, string, button1, button2);
    
	return 1;
}


stock LoadStaticVehiclesFromFile(const filename[])
{
    new File:file_ptr;
    new line[256];
    new var_from_line[64];
    new vehicletype;
    new Float:SpawnX;
    new Float:SpawnY;
    new Float:SpawnZ;
    new Float:SpawnRot;
    new Color1, Color2;
    new index;
    new vehicles_loaded;

    file_ptr = fopen(filename,filemode:io_read);
    if(!file_ptr) return 0;

    vehicles_loaded = 0;

    while(fread(file_ptr,line,256) > 0)
    {
        index = 0;

        // Read type
        index = token_by_delim(line,var_from_line,',',index);
        if(index == (-1)) continue;
        vehicletype = strval(var_from_line);
        if(vehicletype < 400 || vehicletype > 611) continue;

        // Read X, Y, Z, Rotation
        index = token_by_delim(line,var_from_line,',',index+1);
        if(index == (-1)) continue;
        SpawnX = floatstr(var_from_line);

        index = token_by_delim(line,var_from_line,',',index+1);
        if(index == (-1)) continue;
        SpawnY = floatstr(var_from_line);

        index = token_by_delim(line,var_from_line,',',index+1);
        if(index == (-1)) continue;
        SpawnZ = floatstr(var_from_line);

        index = token_by_delim(line,var_from_line,',',index+1);
        if(index == (-1)) continue;
        SpawnRot = floatstr(var_from_line);

        // Read Color1, Color2
        index = token_by_delim(line,var_from_line,',',index+1);
        if(index == (-1)) continue;
        Color1 = strval(var_from_line);

        index = token_by_delim(line,var_from_line,';',index+1);
        Color2 = strval(var_from_line);
        
        //printf("%d,%.2f,%.2f,%.2f,%.4f,%d,%d",vehicletype,SpawnX,SpawnY,SpawnZ,SpawnRot,Color1,Color2);

        AddStaticVehicleEx(vehicletype,SpawnX,SpawnY,SpawnZ,SpawnRot,Color1,Color2,(30*60)); // respawn 30 minutes
        
        /*new numplate_test[32+1];
        format(numplate_test,32,"GRLC{44AA33}%d",vid);
        SetVehicleNumberPlate(vid, numplate_test);*/
        
        vehicles_loaded++;
    }

    fclose(file_ptr);
    printf("Loaded %d vehicles from: %s",vehicles_loaded,filename);
    return vehicles_loaded;
}


stock token_by_delim(const string[], return_str[], delim, start_index)
{
    new x=0;
    while(string[start_index] != EOS && string[start_index] != delim) {
        return_str[x] = string[start_index];
        x++;
        start_index++;
    }
    return_str[x] = EOS;
    if(string[start_index] == EOS) start_index = (-1);
    return start_index;
}