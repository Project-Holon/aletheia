#ifndef GAME_OV135_WORLDTRADE_ENTER_H
#define GAME_OV135_WORLDTRADE_ENTER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_enter.c, prototypes copied from their definitions. */

#include "../ov135/worldtrade_types.h"
#include "../types.h"

int WORLDTRADE_ENTER_Init(WorldtradeWork *p);
int WORLDTRADE_ENTER_CallStateHandler(WorldtradeWork *p);
u32 WORLDTRADE_ENTER_Exit(WorldtradeWork *p);
void WORLDTRADE_ENTER_EmptyInitHook(WorldtradeWork *p);
void WORLDTRADE_ENTER_EmptyExitHook(void);
int WORLDTRADE_ENTER_SetState(WorldtradeWork *p);
int WORLDTRADE_ENTER_StateStartServerCheck(WorldtradeWork *p);
int WORLDTRADE_ENTER_StatePollServerCheck(WorldtradeWork *p);
int WORLDTRADE_ENTER_InitDwcTrade(WorldtradeWork *p);
int WORLDTRADE_ENTER_StateStartConnect(WorldtradeWork *p);
int WORLDTRADE_ENTER_WaitServerCheck(WorldtradeWork *p);
int WORLDTRADE_ENTER_SendProfile(WorldtradeWork *p);
int WORLDTRADE_ENTER_WaitProfileResult(WorldtradeWork *p);
int WORLDTRADE_ENTER_PushWifiSetup(WorldtradeWork *p);
int WORLDTRADE_ENTER_StateWaitWifiSetup(WorldtradeWork *p);
int WORLDTRADE_ENTER_PushWifiError(WorldtradeWork *p);
int WORLDTRADE_ENTER_StateWaitWifiError(WorldtradeWork *p);
int WORLDTRADE_ENTER_RunDialog(void *dialog, WorldtradeWork *p);
u32 WORLDTRADE_ENTER_StateAbortConnect(WorldtradeWork *p);
int WORLDTRADE_ENTER_StateExit(WorldtradeWork *p);
int WORLDTRADE_ENTER_ShowErrorMessage(WorldtradeWork *p, void *dialog);
int WORLDTRADE_ENTER_ShutdownDwcStep(WorldtradeWork *p, void *dialog);
/* END mkheaders: generated region */

#endif
