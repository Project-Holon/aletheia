#ifndef GAME_OV135_WORLDTRADE_LIST_H
#define GAME_OV135_WORLDTRADE_LIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_list.c, prototypes copied from their definitions. */

#include "../ov135/worldtrade_types.h"
#include "../types.h"

int WORLDTRADE_LIST_Init(WorldtradeWork *p);
int WORLDTRADE_LIST_Main(WorldtradeWork *p);
int WORLDTRADE_LIST_Exit(WorldtradeWork *p);
void WORLDTRADE_LIST_SetupBgPlanes(int unused1);
void WORLDTRADE_LIST_ExitBgPlanes(void);
void WORLDTRADE_LIST_LoadBgGraphics(WorldtradeWork *p);
void WORLDTRADE_LIST_CreateActors(WorldtradeWork *p);
void WORLDTRADE_LIST_DeleteActors(WorldtradeWork *p);
void WORLDTRADE_LIST_CreateWindows(WorldtradeWork *p);
void WORLDTRADE_LIST_DeleteWindows(u8 *p);
void WORLDTRADE_LIST_CreateStrings(WorldtradeWork *p);
void WORLDTRADE_LIST_DeleteStrings(WorldtradeWork *p);
int WORLDTRADE_LIST_StateWaitWipeIn(WorldtradeWork *p);
void WORLDTRADE_LIST_SelectCursorEntry(WorldtradeWork *p, int slot);
int WORLDTRADE_LIST_StateMainInput(WorldtradeWork *p);
int WORLDTRADE_LIST_StateStartWipeOut(WorldtradeWork *p);
int WORLDTRADE_LIST_StatePrintPrompt(WorldtradeWork *p);
int WORLDTRADE_LIST_StateConfirmYesNoInput(WorldtradeWork *p);
void WORLDTRADE_LIST_DrawSelectedRecord(WorldtradeWork *p);
int WORLDTRADE_LIST_StateRedrawRecord(WorldtradeWork *p);
int WORLDTRADE_LIST_StateWaitPageWipe(WorldtradeWork *p);
int WORLDTRADE_LIST_StateScrollIn(WorldtradeWork *p);
int WORLDTRADE_LIST_StateWaitMessage(u8 *p);
void WORLDTRADE_LIST_PrintMessage(u8 *p, u32 msgId, u32 unused1, u32 unused2, u32 unused3);
void WORLDTRADE_LIST_PrintNames(Pane2 *pane, void *s1, void *s2, void *printer);
void WORLDTRADE_LIST_VBlank(WorldtradeWork *p);
/* END mkheaders: generated region */

#endif
