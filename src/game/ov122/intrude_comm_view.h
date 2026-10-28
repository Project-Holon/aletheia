#ifndef GAME_OV122_INTRUDE_COMM_VIEW_H
#define GAME_OV122_INTRUDE_COMM_VIEW_H
struct WhPipeEntry;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intrude_comm_view.c, prototypes copied from their definitions. */

struct IntrudeCommView;
typedef struct IntrudeCommView IntrudeCommView;

#include "../types.h"

struct TcbTask;

void INTRUDE_COMM_VIEW_StoreCallback(void (**slot)(IntrudeCommView *), void (*value)(IntrudeCommView *));
void INTRUDE_COMM_VIEW_SetCallback(IntrudeCommView *p, void (*callback)(IntrudeCommView *), int id);
void INTRUDE_COMM_VIEW_SetupBackgrounds(void *unused);
void INTRUDE_COMM_VIEW_DeleteRowSlot(u32 i,IntrudeCommView *p);
void INTRUDE_COMM_VIEW_ResetRowSlot(u32 i,IntrudeCommView *p);
void INTRUDE_COMM_VIEW_DeleteRows(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_InvokeCallback(u32 value, s32 index, void *);
void INTRUDE_COMM_VIEW_BrightenPalette(u16 *p, const u16 *add, int count);
void INTRUDE_COMM_VIEW_CreateActors(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_CreateResources(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_InitMenu(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_DeleteResources(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_WaitExitWipe(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_BeginExit(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_StartExit(void *param, u32 frame);
void INTRUDE_COMM_VIEW_Noop(IntrudeCommView *unused0);
void INTRUDE_COMM_VIEW_AnimateSelectedRow(IntrudeCommView *p);
int INTRUDE_COMM_VIEW_SelectRow(int value, IntrudeCommView *p);
void INTRUDE_COMM_VIEW_DrawRowText(int i, int value, int force, int mode, IntrudeCommView *p);
void INTRUDE_COMM_VIEW_UpdatePeerList(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_Update(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_InitStatusText(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_UpdateActorAnim(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_SetFoundPeerMac(IntrudeCommView *p, u32 peerIndex);
void INTRUDE_COMM_VIEW_ClearFoundPeerMac(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_OnScanResult(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_StorePeerRecord(void *arg, struct WhPipeEntry *entry, u32 kind, u32 connectedNum);
void INTRUDE_COMM_VIEW_TickPeerTimers(IntrudeCommView *p);
u32 INTRUDE_COMM_VIEW_SumPeerTimers(IntrudeCommView *p);
void INTRUDE_COMM_VIEW_VBlankHandler(struct TcbTask *unused0, void *unused1);
int INTRUDE_COMM_VIEW_Create(void *owner, void *unused, char *args);
int INTRUDE_COMM_VIEW_Main(void *owner, void *unused1, void *unused2, IntrudeCommView *p);
int INTRUDE_COMM_VIEW_Exit(void *owner, void *unused, char *out, IntrudeCommView *p);
/* END mkheaders: generated region */

#endif
