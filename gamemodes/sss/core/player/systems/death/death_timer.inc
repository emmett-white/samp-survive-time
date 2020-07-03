timer WastedTimer[1000](playerid)
{
    new Float: wastedHealth;
    GetPlayerHealth(playerid, wastedHealth);
    SetPlayerHealth(playerid, wastedHealth - 0.90);
}