#ifndef GAME_OV135_WORLDTRADE_SEARCH_H
#define GAME_OV135_WORLDTRADE_SEARCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_search.c, prototypes copied from their definitions. */

#include "../ov135/worldtrade_types.h"
#include "../types.h"

int WORLDTRADE_SEARCH_Init(WorldtradeWork *p);
int WORLDTRADE_SEARCH_Main(WorldtradeWork *p);
int WORLDTRADE_SEARCH_Exit(WorldtradeWork *p);
void WORLDTRADE_SEARCH_SetupBgPlanes(void);
void WORLDTRADE_SEARCH_ExitBgPlanes(void);
void WORLDTRADE_SEARCH_LoadBgGraphics(WorldtradeWork *p);
void WORLDTRADE_SEARCH_CreateActors(WorldtradeWork *p);
void WORLDTRADE_SEARCH_DeleteActors(WorldtradeWork *p);
void WORLDTRADE_SEARCH_CreateWindows(WorldtradeWork *p);
void WORLDTRADE_SEARCH_DeleteWindows(unsigned char *p);
void WORLDTRADE_SEARCH_CreateStrings(WorldtradeWork *p);
void WORLDTRADE_SEARCH_DeleteStrings(WorldtradeWork *p);
int WORLDTRADE_SEARCH_UpdateCursorVisibility(WorldtradeWork *p);
int WORLDTRADE_SEARCH_HitTestButtons(void);
void WORLDTRADE_SEARCH_HandleButton(WorldtradeWork *p, int mode);
int WORLDTRADE_SEARCH_StateMainInput(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateConfirmSearch(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StartDownloadMatchData(WorldtradeWork *p);
int WORLDTRADE_SEARCH_WaitDownloadResult(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateUpdateHistorySlots(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateShowEmptyHistoryMessage(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateCountdownMessage(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateShowClearedMessage(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StatePrintMessage171(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StatePrintMessage172(WorldtradeWork *p);
int WORLDTRADE_SEARCH_GetSelectedButton(WorldtradeWork *p);
void WORLDTRADE_SEARCH_UpdateKeyCursor(WorldtradeWork *p);
void WORLDTRADE_SEARCH_SelectButton(WorldtradeWork *p, int button);
int WORLDTRADE_SEARCH_StateStartWipeOutPage(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateStartWipeOutDisconnect(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StatePrintNamePrompt(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateOpenNameMenu(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateNameMenuInput(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StatePrintGenderPrompt(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateOpenGenderMenu(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateGenderMenuInput(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StatePrintLevelPrompt(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateOpenLevelMenu(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateLevelMenuInput(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StatePrintConditionPrompt(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateOpenConditionMenu(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateConditionMenuInput(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateOpenClearConfirm(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateClearConfirmInput(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateReturnToMain(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StatePrintMessage9E(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateWaitMessage(u8 *p);
int WORLDTRADE_SEARCH_StateWaitMessageOrKey(u8 *p);
int WORLDTRADE_SEARCH_StateWaitMessageTimed(u8 *p);
int WORLDTRADE_SEARCH_StateScrollOut(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateWaitWipeIn(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateHistoryInput(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateCursorAnimA(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateCursorAnimB(WorldtradeWork *p);
int WORLDTRADE_SEARCH_StateCursorAnimC(WorldtradeWork *p);
void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 msgId, int unused1, int unused2, int unused3);
void WORLDTRADE_SEARCH_DrawFormLabels(void **win, void **win2, void *bank, void *printer);
void WORLDTRADE_SEARCH_DrawHistoryHeader(void *win, void *bank, int flag, void *printer);
int WORLDTRADE_SEARCH_CompareRecords(WorldtradeRec *x, WorldtradeRec *y, int m, int n);
void WORLDTRADE_SEARCH_ScrollBgs(WorldtradeWork *p);
void WORLDTRADE_SEARCH_SetBlendEffect(u32 brightness);
/* END mkheaders: generated region */

#endif
