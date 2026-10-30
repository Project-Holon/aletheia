#ifndef GAME_OV210_ZKNSEARCH_MAIN_H
#define GAME_OV210_ZKNSEARCH_MAIN_H

typedef enum { YCoordMin = -2147483647, YCoordMax = 2147483647 } YCoord;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zknsearch_main.c, prototypes copied from their definitions. */

struct Strbuf;

#include "../version.h"
#include "../types.h"
#include "../ov210/zknsearch_types.h"

void ZKNSEARCH_MAIN_InitBackgrounds(void);
void ZKNSEARCH_MAIN_DeleteBackgrounds(u32 work);
void ZKNSEARCH_MAIN_ShowLayerSetA(u32 work);
void ZKNSEARCH_MAIN_ShowLayerSetB(void);
void ZKNSEARCH_MAIN_LoadCommonGraphics(void);
void ZKNSEARCH_MAIN_InitPaletteAnim(ZknSearchWork *work);
void ZKNSEARCH_MAIN_DeletePaletteAnim(ZknSearchWork *work);
void ZKNSEARCH_MAIN_RequestPaletteFade(ZknSearchWork *work,u8 startLevel,u8 endLevel);
void ZKNSEARCH_MAIN_SetBrightness(int mode);
void ZKNSEARCH_MAIN_ConfigureWindow(void);
void ZKNSEARCH_MAIN_ResetWindow(u32 work);
void ZKNSEARCH_MAIN_InitTextSystem(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_DeleteTextSystem(ZknSearchWork *work);
void ZKNSEARCH_MAIN_InitBlinkPalette(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_UpdateBlinkPalette(ZknSearchWork *work);
void ZKNSEARCH_MAIN_InitScrollWindow(ZknSearchWork *work);
void ZKNSEARCH_MAIN_DeleteScrollWindow(ZknSearchWork *work);
void ZKNSEARCH_MAIN_LoadBgTile93(ZknSearchWork *work);
void ZKNSEARCH_MAIN_LoadBgTile89(ZknSearchWork *work);
void ZKNSEARCH_MAIN_LoadBgTile88(ZknSearchWork *work);
void ZKNSEARCH_MAIN_LoadBgTile90(ZknSearchWork *work);
void ZKNSEARCH_MAIN_LoadBgTile86(ZknSearchWork *work);
void ZKNSEARCH_MAIN_LoadBgTile87(ZknSearchWork *work);
void ZKNSEARCH_MAIN_LoadResultGraphics(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_DeleteResultGraphics(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ShowResultLayout(ZknSearchWork *work);
void ZKNSEARCH_MAIN_HideResultLayout(ZknSearchWork *work);
void ZKNSEARCH_MAIN_SetFadeStateA(ZknSearchWork *work);
void ZKNSEARCH_MAIN_SetFadeStateB(ZknSearchWork *work);
void ZKNSEARCH_MAIN_EnterResultLayout(ZknSearchWork *work);
void ZKNSEARCH_MAIN_StartScrollMove(ZknSearchWork *work, int delta);
int ZKNSEARCH_MAIN_UpdateScrollMove(ZknSearchWork *work);
#if LANGUAGE != LANGUAGE_JAPANESE
u32 ZKNSEARCH_MAIN_GetListIndexA(ZknSearchWork *work, u32 index);
u32 ZKNSEARCH_MAIN_GetListIndexB(ZknSearchWork *work, u32 index);
#endif
#if LANGUAGE == LANGUAGE_JAPANESE
u32 ZKNSEARCH_MAIN_LookupEntryId(ZknSearchWork *work, int index);
#else
u16 ZKNSEARCH_MAIN_LookupEntryId(ZknSearchWork *work, int index);
#endif
#if LANGUAGE == LANGUAGE_JAPANESE
u32 ZKNSEARCH_MAIN_LookupSavedEntryId(ZknSearchWork *work, u32 value);
#else
u16 ZKNSEARCH_MAIN_LookupSavedEntryId(ZknSearchWork *work, int index);
#endif
void ZKNSEARCH_MAIN_NormalizeRecordByte(ZknSearchWork *work);
void ZKNSEARCH_MAIN_DenormalizeRecordByte(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_RunState(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_InitSearchScreen(ZknSearchWork *work);
int ZKNSEARCH_MAIN_ExitSearchScreen(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_WaitFadeDone(ZknSearchWork *work);
int ZKNSEARCH_MAIN_EnterSearchResult(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_UpdateSearchResult(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_ExitState(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_EnterSearchEngine(ZknSearchWork *work);
int ZKNSEARCH_MAIN_UpdateSearchEngine(ZknSearchWork *work);
int ZKNSEARCH_MAIN_UpdateListInput(ZknSearchWork *work);
int ZKNSEARCH_MAIN_EnterListPage1(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_UpdateListPage1(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_ExitListPage1(ZknSearchWork *work);
int ZKNSEARCH_MAIN_EnterListPage2(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_UpdateListPage2(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_ExitListPage2(ZknSearchWork *work);
int ZKNSEARCH_MAIN_EnterListPage3(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_UpdateListPage3(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_ExitListPage3(ZknSearchWork *work);
int ZKNSEARCH_MAIN_EnterListPage4(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_UpdateListPage4(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_ExitListPage4(ZknSearchWork *work);
int ZKNSEARCH_MAIN_EnterListPage5(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_UpdateListPage5(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_ExitListPage5(ZknSearchWork *work);
int ZKNSEARCH_MAIN_UpdateConfirmDialog(ZknSearchWork *work);
int ZKNSEARCH_MAIN_UpdateMessageDialog(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_EnterMessageDialog(ZknSearchWork *work);
void ZKNSEARCH_MAIN_SelectEntry1(ZknSearchWork *work, u32 index);
void ZKNSEARCH_MAIN_ClearEntry1(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ToggleEntry1(ZknSearchWork *work, int row);
void ZKNSEARCH_MAIN_ClearEntry2(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ToggleEntry2(ZknSearchWork *work, int row);
void ZKNSEARCH_MAIN_ClearEntry3(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ToggleEntry3(ZknSearchWork *work, int index);
void ZKNSEARCH_MAIN_ClearEntry4(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ToggleEntry4(ZknSearchWork *work, int index);
void ZKNSEARCH_MAIN_ClearEntry5(ZknSearchWork *work);
u32 ZKNSEARCH_MAIN_EnterMessageState(ZknSearchWork *work, u32 dialogKind, u32 messageId, u32 returnState);
u32 ZKNSEARCH_MAIN_EnterListState(ZknSearchWork *work, u32 returnState);
void ZKNSEARCH_MAIN_ToggleSaveFlag(ZknSearchWork *work);
void ZKNSEARCH_MAIN_InitBmpWindows(ZknSearchWork *work);
void ZKNSEARCH_MAIN_DeleteBmpWindows(ZknSearchWork *work);
void ZKNSEARCH_MAIN_UpdateBmpWindows(ZknSearchWork *work);
void ZKNSEARCH_MAIN_PrintWindowText(ZknSearchWork *work, int slot, u32 message, int x, int y, u16 color, u32 mode);
void ZKNSEARCH_MAIN_MakeWindowScreen(ZknSearchBmpWin *zknSearchBmpWin);
void ZKNSEARCH_MAIN_InitWindowTexts(ZknSearchWork *work);
void ZKNSEARCH_MAIN_UpdateResultTexts(ZknSearchWork *work);
void ZKNSEARCH_MAIN_PrintLabel1(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ClearLabel1(ZknSearchWork *work);
void ZKNSEARCH_MAIN_InitListTexts(ZknSearchWork *work);
void ZKNSEARCH_MAIN_PrintEntryCount(ZknSearchWork *work);
void ZKNSEARCH_MAIN_InitListTexts2(ZknSearchWork *work);
void ZKNSEARCH_MAIN_PrintEntryCount2(ZknSearchWork *work);
void ZKNSEARCH_MAIN_InitListTexts3(ZknSearchWork *work);
void ZKNSEARCH_MAIN_PrintEntryCount3(ZknSearchWork *work);
void ZKNSEARCH_MAIN_InitListTexts4(ZknSearchWork *work);
void ZKNSEARCH_MAIN_PrintEntryCount4(ZknSearchWork *work);
void ZKNSEARCH_MAIN_InitListTexts5(ZknSearchWork *work);
void ZKNSEARCH_MAIN_PrintListRow(ZknSearchWork *work, ZknSearchBmpWin *window, struct Strbuf *text);
void ZKNSEARCH_MAIN_TransferRowChars(ZknSearchWork *work, ZknSearchBmpWin *window);
void ZKNSEARCH_MAIN_PrintMessageText(ZknSearchWork *work, unsigned message);
void ZKNSEARCH_MAIN_PrintMessage11(ZknSearchWork *work);
void ZKNSEARCH_MAIN_PrintMessage9(ZknSearchWork *work);
void ZKNSEARCH_MAIN_PrintMessage10(ZknSearchWork *work);
void ZKNSEARCH_MAIN_RedrawSubWindow(ZknSearchWork *work);
void ZKNSEARCH_MAIN_InitActorSystem(ZknSearchWork *work);
void ZKNSEARCH_MAIN_DeleteActorSystem(ZknSearchWork *work);
void ZKNSEARCH_MAIN_UpdateActorAnims(ZknSearchWork *work);
void ZKNSEARCH_MAIN_SetActorAnim(ZknSearchWork *work, int idx, int animSeq);
void ZKNSEARCH_MAIN_SetActorAnimAuto(ZknSearchWork *work, int i, int animSeq);
int ZKNSEARCH_MAIN_GetActorAnimSeq(ZknSearchWork *work, int i);
int ZKNSEARCH_MAIN_IsActorAnimActive(ZknSearchWork *work, int actorIndex);
void ZKNSEARCH_MAIN_SetActorVisible(ZknSearchWork *work, int i, int visible);
int ZKNSEARCH_MAIN_GetActorVisible(ZknSearchWork *work, int i);
void ZKNSEARCH_MAIN_SetActorObjMode(ZknSearchWork *work, int idx, int flag);
void ZKNSEARCH_MAIN_SetActorSurfacePos(ZknSearchWork *work, int idx, int posX, short posY, unsigned short space);
void ZKNSEARCH_MAIN_GetActorSurfacePos(ZknSearchWork *work, int idx, short *outA, short *outB, unsigned short in);
void ZKNSEARCH_MAIN_SetActorBgPriority(ZknSearchWork *work, int i, unsigned bgPriority);
void ZKNSEARCH_MAIN_InitClact(void);
void ZKNSEARCH_MAIN_RegisterActorRes(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ReleaseActorRes(ZknSearchWork *work);
void ZKNSEARCH_MAIN_CreateActors(ZknSearchWork *work);
void ZKNSEARCH_MAIN_DeleteActorAt(ZknSearchWork *work, int i);
void ZKNSEARCH_MAIN_DeleteActors(ZknSearchWork *work);
void ZKNSEARCH_MAIN_HideAllActors(ZknSearchWork *work);
unsigned ZKNSEARCH_MAIN_ShowResultActors(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ShowActorsPage1(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ShowActorsPage2(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ShowActorsPage3(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ShowActorsPage4(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ShowActorsPage5(ZknSearchWork *work);
void ZKNSEARCH_MAIN_ShowEntry6Actor(ZknSearchWork *work);
void ZKNSEARCH_MAIN_LayoutScrollActors(ZknSearchWork *work);
void ZKNSEARCH_MAIN_UpdateScrollBarActor(ZknSearchWork *work);
void ZKNSEARCH_MAIN_UpdateCursorActors(ZknSearchWork *work, int force);
void ZKNSEARCH_MAIN_PlaceColumnActor(ZknSearchWork *work, int idx, int y, int flag);
void ZKNSEARCH_MAIN_HideColumnActors(ZknSearchWork *work);
void ZKNSEARCH_MAIN_PlaceColumnActor1(ZknSearchWork *work, int i, int flag);
void ZKNSEARCH_MAIN_PlaceColumnActors2(ZknSearchWork *work, u8 firstEntry, u8 secondEntry);
void ZKNSEARCH_MAIN_PlaceColumnActor3(ZknSearchWork *work, int y, int flag);
void ZKNSEARCH_MAIN_PlaceColumnActor4(ZknSearchWork *work, int i, int flag);
void ZKNSEARCH_MAIN_PlaceScrollActor(ZknSearchWork *ctx, int slot, int index);
void ZKNSEARCH_MAIN_PlaceScrollActor2(ZknSearchWork *ctx);
void ZKNSEARCH_MAIN_PlacePageActor(ZknSearchWork *ctx, unsigned long slot, YCoord y, int flag);
void ZKNSEARCH_MAIN_MoveColumnActors(ZknSearchWork *work, int deltaY);
void ZKNSEARCH_MAIN_MoveScrollActors(ZknSearchWork *work, int dx);
void ZKNSEARCH_MAIN_PlaceProgressActor(ZknSearchWork *work, int progress);
void ZKNSEARCH_MAIN_InitCursorMove(ZknSearchWork *ctx, int index);
void ZKNSEARCH_MAIN_DeleteCursorMove(ZknSearchWork *work);
void ZKNSEARCH_MAIN_SetCursorTile(ZknSearchWork *work, unsigned int index, unsigned int fill);
u32 ZKNSEARCH_MAIN_PollMenuInput(ZknSearchWork *work);
void ZKNSEARCH_MAIN_MoveCursor(ZknSearchWork *work, unsigned index);
void ZKNSEARCH_MAIN_SetCursor(ZknSearchWork *work, unsigned index);
void ZKNSEARCH_MAIN_DeselectCursor(ZknSearchWork *work, unsigned index, unsigned prevIndex);
void ZKNSEARCH_MAIN_SelectCursor(ZknSearchWork *work, unsigned index, unsigned prevIndex);
void ZKNSEARCH_MAIN_UpdateCursor(ZknSearchWork *work, unsigned index, unsigned prevIndex);
int ZKNSEARCH_MAIN_WaitConfirmInput(ZknSearchWork *ctx);
int ZKNSEARCH_MAIN_PollListInput(ZknSearchWork *ctx);
int ZKNSEARCH_MAIN_PollListInput2(ZknSearchWork *ctx);
/* END mkheaders: generated region */

#endif
