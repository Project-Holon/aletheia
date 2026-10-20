#ifndef GAME_OV134_NET_PARTY_COMMAND_H
#define GAME_OV134_NET_PARTY_COMMAND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_party_command.c, prototypes copied from their definitions. */

struct NetPartyEntryTable;
struct NetPartyArgs;
struct NetPartyParam;
typedef struct NetPartyEntryTable NetPartyEntryTable;
typedef struct NetPartyArgs NetPartyArgs;
typedef struct NetPartyParam NetPartyParam;

#include "../types.h"
#include "../ov131/p_status_types.h"

int NET_PARTY_COMMAND_GetEntry(int index, NetPartyEntryTable *table);
void NET_PARTY_COMMAND_IsHandleFor(u32 value, u32 a, u32 b, u32 c, void *expected);
int NET_PARTY_COMMAND_Init(void *sys, int unused, const NetPartyArgs *args);
int NET_PARTY_COMMAND_Exit(void *proc, u32 unused0, u32 unused1, char *work);
int NET_PARTY_COMMAND_Main(void *unused0, void *unused1, u8 *listProc, u8 *work);
void NET_PARTY_COMMAND_BuildPartyList(NetPartyArgs *args, void *unused, NetPartyParam *param);
void NET_PARTY_COMMAND_BuildStatusParam(NetPartyArgs *args, void *unused, PStatusProcParam *statusParam);
/* END mkheaders: generated region */

#endif
