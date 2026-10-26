#ifndef GAME_OV135_WORLDTRADE_TITLE_H
#define GAME_OV135_WORLDTRADE_TITLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_title.c, prototypes copied from their definitions. */

#include "../ov135/worldtrade_types.h"
#include "../types.h"

int WORLDTRADE_TITLE_Init(WorldtradeWork *p);
int WORLDTRADE_TITLE_CallStateHandler(u8 *p);
int WORLDTRADE_TITLE_Exit(WorldtradeWork *p);
void WORLDTRADE_TITLE_SetupBgPlanes(void);
void WORLDTRADE_TITLE_ScrollBg(WorldtradeWork *p, u32 scrollY, u32 keepLayer6);
void WORLDTRADE_TITLE_ExitBgPlanes(WorldtradeWork *p);
void WORLDTRADE_TITLE_ExitBgPlanesSub(void);
void WORLDTRADE_TITLE_SetBgVisible(WorldtradeWork *p);
void WORLDTRADE_TITLE_LoadBgGraphics(WorldtradeWork *p);
void WORLDTRADE_TITLE_CreateActors(WorldtradeWork *p);
void WORLDTRADE_TITLE_DeleteActors(WorldtradeWork *p);
void WORLDTRADE_TITLE_CreateWindows(u8 *p);
void WORLDTRADE_TITLE_DeleteWindows(u8 *p);
void WORLDTRADE_TITLE_CreateStrings(WorldtradeWork *p);
void WORLDTRADE_TITLE_DeleteStrings(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateHideForExit(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateAdvance(u8 *p);
int WORLDTRADE_TITLE_StateStartWipeIn(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateWaitWipeIn(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateWaitWipeInAlt(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateStartCursorAnim(WorldtradeWork *p);
int WORLDTRADE_TITLE_HitTestMenu(void);
void WORLDTRADE_TITLE_HandleSelection(WorldtradeWork *p, int mode);
int WORLDTRADE_TITLE_StateMainInput(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateRequestExit(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateWaitActive(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateStartWipeOut(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateOpenConfirm(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateConfirmYesNoInput(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateUpdateCursorAnim(WorldtradeWork *p);
int WORLDTRADE_TITLE_StateWaitMessage(u8 *p);
int WORLDTRADE_TITLE_StateWaitMessageTimed(u8 *p);
void WORLDTRADE_TITLE_DrawMenuLabels(WorldtradeWork *p);
void WORLDTRADE_TITLE_PrintMessage(u8 *p, u32 msgId, int unused1, int unused2, int unused3);
void WORLDTRADE_TITLE_PrintMessageSub(u8 *p, int msgId, int unused1, int unused2, int unused3);
void WORLDTRADE_TITLE_PrintBankString(void *win,void *bank,u32 unused1,u32 id,u32 unused2,void *printer,u16 color);
void WORLDTRADE_TITLE_LoadMainBgSwap(WorldtradeWork *p);
void WORLDTRADE_TITLE_LoadSubBgSwap(WorldtradeWork *p);
void WORLDTRADE_TITLE_CreateMenuWindow(WorldtradeWork *p, u32 labelIdx);
/* END mkheaders: generated region */

#endif
