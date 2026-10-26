#ifndef GAME_ARM9_WIPE_H
#define GAME_ARM9_WIPE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wipe.c, prototypes copied from their definitions. */

struct WipeSys;
struct WipePanel;
struct WipeHBlankSlots;
struct Node;

#include "../types.h"
#include "../arm9/wipe_types.h"

void WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u16 color, u32 frames, u32 wait, u32 heapId);
void WIPE_SYS_Main(void);
u32 WIPE_SYS_EndCheck(void);
void WIPE_SYS_ExeEnd(void);
void WIPE_ResetWndMask(u32 screen);
void WIPE_ResetBrightness(u32 which);
void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
void WIPE_SetMstBrightColor(u32 color);
void WIPE_SetBackColor(u32 a);
void WIPE_SetBrightness(u32 which, int brightness);
void WIPE_SYS_Finish(struct WipeSys *p);
u32 WIPE_SYS_MainPanels(struct WipeSys *p, void *top, void *bottom);
void WIPE_SYS_MainPanel(u32 *obj, void *arg);
u32 WIPE_SYS_CallPattern(void *p);
void WIPE_SYS_SetDivision(u32 mode, struct WipeSys *p);
void WIPE_SYS_InitPanel(struct WipePanel *panel, u32 pattern, u32 frames, s32 wait, u32 phase, void *work, u32 screen, void *windowRequests, struct WipeHBlankSlots *hblank, u32 heapId, u16 color);
void WIPE_InitHBlankSlots(struct WipeHBlankSlots *p);
void WIPE_HBlankSlotsTask(struct TcbTask * taskArg, void * pArg);
void WIPE_SetHBlankSlot(struct WipeHBlankSlots *p, void *ctx, Handler fn, u32 idx);
void WIPE_ClearHBlankSlot(struct WipeHBlankSlots *p, u32 idx);
void WIPE_RequestSetHBlankSlot(struct WipeHBlankSlots *slots, void *ctx, Handler fn, u32 slotIdx, u32 heapId);
void WIPE_RequestClearHBlankSlot(struct WipeHBlankSlots *slots, u32 slotIdx, u32 heapId);
void WIPE_SetHBlankSlotTask(void *task, struct WipeSetSlotReq *args);
void WIPE_ClearHBlankSlotTask(struct Node *task, struct WipeClearSlotReq *args);
void WIPE_DummyHBlank(void *ctx);
/* END mkheaders: generated region */

#endif
