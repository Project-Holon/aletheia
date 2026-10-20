#ifndef GAME_OV135_WORLDTRADE_H
#define GAME_OV135_WORLDTRADE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade.c, prototypes copied from their definitions. */

struct TcbTask;
struct DispVram;
struct ClactActor;

#include "../ov135/worldtrade_types.h"
#include "../types.h"

int WORLDTRADE_ProcInit(void *proc, int *seq, WorldtradeArgs *args);
int WORLDTRADE_ProcMain(void *unused0, int *state, void *unused2, WorldtradeWork *p);
int WORLDTRADE_ProcExit(void *ctx, int unused1, int unused2, WorldtradeWork *p);
void WORLDTRADE_VBlankTask(struct TcbTask *unused, void *work);
void WORLDTRADE_SetupVramBanks(const struct DispVram *vram);
void WORLDTRADE_CallStateHandler(WorldtradeWork *p, WorldtradeArgs *args);
void WORLDTRADE_Nop(WorldtradeWork *p);
void WORLDTRADE_SetupWindowPlanes(void);
void WORLDTRADE_InitClactSystem(WorldtradeWork *p, u32 mode);
void WORLDTRADE_SetPlaneVisibleAll(WorldtradeWork *p);
void WORLDTRADE_OpenTaskMenuYesNoDefault(WorldtradeWork *work, u32 y, u32 unused, u32 plttIdx, u8 flag);
void WORLDTRADE_OpenTaskMenuYesNo(WorldtradeWork *p,int y,int unused,int plttIdx,int bgLayer,u8 flag);
void WORLDTRADE_CloseTaskMenu(WorldtradeWork *p);
int WORLDTRADE_UpdateTaskMenuYesNo(WorldtradeWork *p);
void WORLDTRADE_OpenTaskMenuList(WorldtradeWork *p, u16 bgLayer, int count, int y);
u32 WORLDTRADE_UpdateTaskMenuList(WorldtradeWork *p);
void WORLDTRADE_CloseTaskMenuList(WorldtradeWork *p);
void WORLDTRADE_SetNextState(WorldtradeWork *p, u32 state, u32 returnState);
void WORLDTRADE_SetActorSurfacePos(struct ClactActor *obj, int x, int y);
int WORLDTRADE_GetWifiLinkLevel(void);
void WORLDTRADE_SetStateAndReturn(WorldtradeWork *p, u32 nextScreenId, u32 kind);
void WORLDTRADE_AdvanceScreenId(WorldtradeWork *p);
int WORLDTRADE_GetMessageWait(void);
void WORLDTRADE_SetupGraphics(WorldtradeWork *p);
void WORLDTRADE_ReleaseGraphics(WorldtradeWork *p);
void WORLDTRADE_DecrementTimer(WorldtradeWork *p);
void WORLDTRADE_ClearSelectedSpecies(WorldtradeWork *p);
void WORLDTRADE_CreateTimeIcon(WorldtradeWork *p);
void WORLDTRADE_DeleteTimeIcon(WorldtradeWork *p);
void WORLDTRADE_SetActorPos(u32 obj, u32 x, u32 y);
void WORLDTRADE_SetBrightnessIn(u32 isMain);
void WORLDTRADE_SetBrightnessOut(u32 isMain);
void WORLDTRADE_ClearBlendRegs(void);
void WORLDTRADE_ClearAndShowPlanes(WorldtradeWork *p);
void WORLDTRADE_ExitPlanes(WorldtradeWork *p);
void WORLDTRADE_CancelSave(WorldtradeWork *p);
/* END mkheaders: generated region */

#endif
