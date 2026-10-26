#ifndef GAME_OV069_BSUBWAY_RECORD_LIST_H
#define GAME_OV069_BSUBWAY_RECORD_LIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bsubway_record_list.c, prototypes copied from their definitions. */

struct Strbuf;

#include "../types.h"
#include "../ov069/bsubway_record_list_types.h"

int BSUBWAY_RECORD_LIST_Init(void *proc, u32 unusedSeq, BsubwayRecordListArgs *args);
int BSUBWAY_RECORD_LIST_Main(void *proc, u32 unusedSeq, u32 unusedArgs, BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_Exit(void *proc, u32 unusedSeq, u32 unusedArgs, BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_VBlankTask(void);
void BSUBWAY_RECORD_LIST_InitWork(BsubwayRecordListWork *work, BsubwayRecordListArgs *args);
void BSUBWAY_RECORD_LIST_FreeWork(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_SetupVramBanks(void);
void BSUBWAY_RECORD_LIST_SetupBgLayers(BsubwayRecordListWork *unusedWork);
void BSUBWAY_RECORD_LIST_ReleaseBgLayers(BsubwayRecordListWork *unusedWork);
void BSUBWAY_RECORD_LIST_LoadGraphics(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_DeleteFrames(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_SetupActors(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_CreateActors(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_DeleteActors(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_CreateWindows(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_DeleteWindows(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_InitText(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_ExitText(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_UpdateText(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_RunInputState(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_StateFadeIn(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_StateInput(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_StateBackAnim(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_StateFadeOutStart(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_StateFadeOutWait(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_InitCursor(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_DeleteCursor(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_CursorCallbackNop0(void);
void BSUBWAY_RECORD_LIST_CursorCallbackNop1(void);
void BSUBWAY_RECORD_LIST_CursorCallbackMoved(BsubwayRecordListWork *work, int row);
void BSUBWAY_RECORD_LIST_CursorCallbackMovedAlt(BsubwayRecordListWork *work, int row);
void BSUBWAY_RECORD_LIST_PlaceCursorActor(BsubwayRecordListWork *work, int row);
void BSUBWAY_RECORD_LIST_ShowRecordDetails(BsubwayRecordListWork *work, BsubwayWifiRecord *records, int index);
int BSUBWAY_RECORD_LIST_PollTouchAndCancel(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_HandleAction(BsubwayRecordListWork *work, int action);
void BSUBWAY_RECORD_LIST_InitPageCount(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_UpdateArrowVisibility(BsubwayRecordListWork *work, int page, int pageCount);
int BSUBWAY_RECORD_LIST_ChangePage(BsubwayRecordListWork *work, int direction);
void BSUBWAY_RECORD_LIST_ShowPage(BsubwayRecordListWork *work, int page);
int BSUBWAY_RECORD_LIST_GetRowCountOnPage(int page, int pageCountUnused, int entryCount);
void BSUBWAY_RECORD_LIST_DrawPageRows(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_DrawRowName(BsubwayRecordListWork *work, int row, struct Strbuf *name, int isFemale);
/* END mkheaders: generated region */

#endif
