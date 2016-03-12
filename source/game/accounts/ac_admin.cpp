#include "ac_admin.h"

qboolean ac_adminLoggedOn[MAX_CLIENTS];
vmCvar_t ac_adminPassword;

void AC_Cmd_AdminLogin(gentity_t *ent)
{
    if (!ent || !ent->client)
    {
        return;
    }

    int playerNum = AC_ClientNumFromEnt(ent);
    if (playerNum < 0 || playerNum >= MAX_CLIENTS)
    {
        return;
    }

    if (trap_Argc() < 2)
    {
        AC_Print(ent, "^3ac_adminLogin: usage: /ac_adminLogin <password>");
        return;
    }

    if (AC_CheckAdmin(ent))
    {
        AC_Print(ent, "^3You are already logged on.");
        return;
    }

    char buffer[AC_ARGV_BUFFER_LEN] = { 0 };
    trap_Argv(1, buffer, sizeof(buffer));  // password

    if (strcmp(buffer, ac_adminPassword.string) != 0)
    {
        AC_Print(ent, "^3Bad password.");
        return;
    }

    ac_adminLoggedOn[playerNum] = qtrue;
    AC_Print(ent, "^2Logged on!");
}

void AC_Cmd_AdminLogout(gentity_t *ent)
{
    if (!ent || !ent->client)
    {
        return;
    }

    int playerNum = AC_ClientNumFromEnt(ent);
    if (playerNum < 0 || playerNum >= MAX_CLIENTS)
    {
        return;
    }

    if (!AC_CheckAdmin(ent))
    {
        AC_Print(ent, "^3You are not logged on.");
        return;
    }

    ac_adminLoggedOn[playerNum] = qfalse;
    AC_Print(ent, "^2Logged out.");
}

qboolean AC_CheckAdmin(gentity_t *ent)
{
    if (!ent)
    {
        return qfalse;
    }

    int playerNum = AC_ClientNumFromEnt(ent);
    if (playerNum < 0 || playerNum >= MAX_CLIENTS)
    {
        return qfalse;
    }

    return ac_adminLoggedOn[playerNum];
}