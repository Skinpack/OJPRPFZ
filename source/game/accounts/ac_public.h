#ifndef AC_PUBLIC_H
#define AC_PUBLIC_H
#pragma once

#include "../g_local.h"

typedef void (*ac_cmdFunction)(gentity_t*);

qboolean AC_ExecuteCommand(const char *cmd, gentity_t *ent);

void AC_Init();
void AC_Shutdown();

void AC_ReadAccounts();
void AC_SaveAccounts();

// called after player's respawn
void AC_SetPlayerStats(gentity_t *ent);
// called when player's leaving the server
void AC_PlayerLeaving(int clientNum);

#endif  // AC_PUBLIC_H