#ifndef GAME_OV214_BTL_REC_SEL_H
#define GAME_OV214_BTL_REC_SEL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_rec_sel.c, prototypes copied from their definitions. */

struct BtlRecSel;
struct BtlRecSelMgr;

#include "../types.h"

int BTL_REC_SEL_Create(void *manager,char *state,char * const mgr);
int BTL_REC_SEL_Delete(void *mgr,int unused,int state,char *work);
int BTL_REC_SEL_Main(void *unused,u32 *state,const char *mgr,char *work);
void BTL_REC_SEL_StartFade(char *state, int unused, char *work, int nextState, int fadeType, int fadeStart, int fadeEnd, int fadeSpeed, int fadeInstant);
void BTL_REC_SEL_StartEntryA(unsigned *state,void *unused,char *work,unsigned nextStateA,unsigned entryA,unsigned flag3C);
void BTL_REC_SEL_SetEntryA(void *unused,char *work,unsigned nextStateA,unsigned entryA,unsigned flag3C);
void BTL_REC_SEL_StartEntryB(int *state, int unused, int work, int nextStateB, int entryB);
void BTL_REC_SEL_SetEntryB(int unused, char *work, int nextStateB, int entryB);
void BTL_REC_SEL_VBlank(void *unused, char *work);
void BTL_REC_SEL_InitWindows(void *unused, struct BtlRecSel *work);
void BTL_REC_SEL_DeleteWindows(int unused,char*work);
void BTL_REC_SEL_MainTcbl(int unused,char *work);
void BTL_REC_SEL_DrawWindow(int unused,char *work);
void BTL_REC_SEL_DrawWindowBorder(int unused,char *work);
void BTL_REC_SEL_ClearWindowWhite(int unused, char *work);
void BTL_REC_SEL_ClearWindowClear(int unused,char *work);
void BTL_REC_SEL_PrintEntry(int unused,char*work,unsigned entry,int v);
int BTL_REC_SEL_WaitPrint(int a,char *work);
int BTL_REC_SEL_PrintStep(int unused,char*work);
void BTL_REC_SEL_PrintQueEntry(void*mgr,char*work,unsigned entry);
u32 BTL_REC_SEL_TryShowEntry(int unused,u8 *work);
void BTL_REC_SEL_InitPalette(int unused,char*work);
void BTL_REC_SEL_Noop(int unused, char *work);
void BTL_REC_SEL_CreateYesNo(int unused,u8 *work);
void BTL_REC_SEL_CreateWindows(int unused,char*work);
void BTL_REC_SEL_DeleteWindowList(int unused, char *work);
void BTL_REC_SEL_TickTimer(struct BtlRecSelMgr *mgr,char*work);
void BTL_REC_SEL_ShowWindows(void *unused,struct BtlRecSel *work);
void BTL_REC_SEL_PrintList(void*mgr,char*work);
void BTL_REC_SEL_ClearList(int unused,char*work);
void BTL_REC_SEL_StartTimer(void *mgr, char *work, u32 v);
void BTL_REC_SEL_ResetTimer(void*mgr,char*work);
void BTL_REC_SEL_DrawCounter(struct BtlRecSelMgr *mgr, struct BtlRecSel *e, unsigned int v);
void BTL_REC_SEL_InitCells(void *unused,struct BtlRecSel *work);
void BTL_REC_SEL_DeleteCellActors(int unused, struct BtlRecSel *workAddr);
int BTL_REC_SEL_CreateActor(int sceneId,u16 heap,int mode,u8 shade,u32 gfxId0,u32 gfxId1,u32 gfxId2,u32 gfxId3,void*sceneWork,u8 x,u8 y,u8 flag,u8 bgPriority,u8 drawPriority);
void BTL_REC_SEL_DeleteActor(void*scene,void*actor);
void BTL_REC_SEL_SetMode(int unused,char*work);
void BTL_REC_SEL_InitBgRun(int unused, char *work);
void BTL_REC_SEL_DeleteBgRun(int unused,u8 *work);
void BTL_REC_SEL_InitBgGfx1(int unused,u8 *work);
void BTL_REC_SEL_InitBgGfx2(int unused,u8 *work);
void BTL_REC_SEL_InitBgGfx3(int unused,u8 *work);
void BTL_REC_SEL_ClearLayer(void *work, char *unused);
void BTL_REC_SEL_InitSubBg(void **mgrRef,char *work);
void BTL_REC_SEL_DeleteSubBg(int unused, char *work);
void BTL_REC_SEL_CreateUiActor(int unused,u8 *work);
void BTL_REC_SEL_DeleteUiActor(int unused,u8 *work);
void BTL_REC_SEL_InitPalanm(int unused,char *work);
void BTL_REC_SEL_DeletePalanm(int unused,u8 *work);
void BTL_REC_SEL_FadeMain(void *unused,struct BtlRecSel *work);
void BTL_REC_SEL_TransferPalettes(char *work);
void BTL_REC_SEL_InitG3dDisplay(void);
/* END mkheaders: generated region */

#endif
