#ifndef GAME_OV135_WORLDTRADE_DETAIL_H
#define GAME_OV135_WORLDTRADE_DETAIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_detail.c, prototypes copied from their definitions. */

#include "../ov135/worldtrade_types.h"
#include "../types.h"

int WORLDTRADE_DETAIL_Init(WorldtradeWork *p);
int WORLDTRADE_DETAIL_CallStateHandler(u8 *p);
int WORLDTRADE_DETAIL_Exit(WorldtradeWork *p);
void WORLDTRADE_DETAIL_SetupBgPlanes(void);
void WORLDTRADE_DETAIL_ExitBgPlanes(void);
void WORLDTRADE_DETAIL_LoadBgGraphics(WorldtradeWork *p);
void WORLDTRADE_DETAIL_CreateActors(WorldtradeWork *p);
void WORLDTRADE_DETAIL_DeleteActors(WorldtradeWork *p);
void WORLDTRADE_DETAIL_CreateWindows(WorldtradeWork *p);
void WORLDTRADE_DETAIL_DeleteWindows(char *p);
void WORLDTRADE_DETAIL_CreateStrings(WorldtradeWork *p);
void WORLDTRADE_DETAIL_DeleteStrings(WorldtradeWork *p);
int WORLDTRADE_DETAIL_StateStart(WorldtradeWork *p);
int WORLDTRADE_DETAIL_StateMainInput(WorldtradeWork *p);
int WORLDTRADE_DETAIL_StateStartWipeOut(WorldtradeWork *p, int unused1);
int WORLDTRADE_DETAIL_StateOpenConfirm(WorldtradeWork *p);
int WORLDTRADE_DETAIL_StateConfirmYesNoInput(WorldtradeWork *p);
int WORLDTRADE_DETAIL_StateCreateMenu(WorldtradeWork *p);
int WORLDTRADE_DETAIL_StateMenuInput(WorldtradeWork *p);
int WORLDTRADE_DETAIL_StateWaitMessage(u8 *p);
int WORLDTRADE_DETAIL_StateWaitMessageTimed(u8 *p);
void WORLDTRADE_DETAIL_PrintMessage(u8 *p, u32 msgId, u32 unused1, u32 unused2, u32 unused3, void *mon);
u16 WORLDTRADE_DETAIL_GetModeColor(int mode);
void WORLDTRADE_DETAIL_PrintMonInfo(void *bank, void *names, void *words, void **win, void *mon, WorldtradeRec *rec, void *printer);
void WORLDTRADE_DETAIL_PrintMonName(void *bank, Pane2 *pane, const u16 *name, void *mon, Pane2 *pane2, void *printer);
void WORLDTRADE_DETAIL_LoadMonGraphics(void *mon);
void WORLDTRADE_DETAIL_DrawRequestWindow(WorldtradeWork *p);
/* END mkheaders: generated region */

#endif
