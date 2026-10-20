#ifndef GAME_OV122_INTRUDE_COMM_VIEW_H
#define GAME_OV122_INTRUDE_COMM_VIEW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intrude_comm_view.c, prototypes copied from their definitions. */

struct IntrudeCommView;
typedef struct IntrudeCommView IntrudeCommView;

#include "../types.h"

void INTRUDE_COMM_VIEW_StoreCallback(u32 *slot, u32 value);
void INTRUDE_COMM_VIEW_SetCallback(void *p, u32 callback, int id);
void INTRUDE_COMM_VIEW_SetupBackgrounds(void *unused);
void INTRUDE_COMM_VIEW_DeleteRowSlot(u32 i,u32 p);
void INTRUDE_COMM_VIEW_ResetRowSlot(u32 i,u32 p);
void INTRUDE_COMM_VIEW_DeleteRows(char *p);
void INTRUDE_COMM_VIEW_InvokeCallback(int value, int index, u32 *p);
void INTRUDE_COMM_VIEW_BrightenPalette(u16 *p, const u16 *add, int count);
void INTRUDE_COMM_VIEW_CreateActors(char *p);
void INTRUDE_COMM_VIEW_CreateResources(char *p);
void INTRUDE_COMM_VIEW_InitMenu(char *p);
void INTRUDE_COMM_VIEW_DeleteResources(char *p);
void INTRUDE_COMM_VIEW_WaitExitWipe(char *p);
void INTRUDE_COMM_VIEW_BeginExit(char *p);
void INTRUDE_COMM_VIEW_StartExit(char *p);
void INTRUDE_COMM_VIEW_Noop(void);
void INTRUDE_COMM_VIEW_AnimateSelectedRow(char *p);
int INTRUDE_COMM_VIEW_SelectRow(int value, char *p);
void INTRUDE_COMM_VIEW_DrawRowText(int i, int value, int force, int mode, IntrudeCommView *p);
void INTRUDE_COMM_VIEW_UpdatePeerList(char *p);
void INTRUDE_COMM_VIEW_Update(char *p);
void INTRUDE_COMM_VIEW_InitStatusText(char *p);
void INTRUDE_COMM_VIEW_UpdateActorAnim(char *p);
void INTRUDE_COMM_VIEW_SetFoundPeerMac(char *p, u32 peerIndex);
void INTRUDE_COMM_VIEW_ClearFoundPeerMac(char *p);
void INTRUDE_COMM_VIEW_OnScanResult(char *p);
void INTRUDE_COMM_VIEW_StorePeerRecord(IntrudeCommView *p, const char *data, int value, int tag);
void INTRUDE_COMM_VIEW_TickPeerTimers(u8 *p);
u32 INTRUDE_COMM_VIEW_SumPeerTimers(u8 *p);
void INTRUDE_COMM_VIEW_VBlankHandler(void);
int INTRUDE_COMM_VIEW_Create(void *owner, void *unused, char *args);
int INTRUDE_COMM_VIEW_Main(void *owner, void *unused1, void *unused2, char *p);
int INTRUDE_COMM_VIEW_Exit(void *owner, void *unused, char *out, char *p);
/* END mkheaders: generated region */

#endif
