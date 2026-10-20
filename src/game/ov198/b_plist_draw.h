#ifndef GAME_OV198_B_PLIST_DRAW_H
#define GAME_OV198_B_PLIST_DRAW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of b_plist_draw.c, prototypes copied from their definitions. */

struct ClactVec2;

#include "../types.h"

void B_PLIST_DRAW_CreateStateWindows(u8 *p,u32 state);
void B_PLIST_DRAW_ToggleAuxWindow(u8 *p);
void B_PLIST_DRAW_DeleteAuxWindow(u8 *p);
void B_PLIST_DRAW_ClearWindowBitmaps(u8 *p);
void B_PLIST_DRAW_DeleteStateWindows(char *p);
void B_PLIST_DRAW_DeleteAllWindows(u8 *p);
void B_PLIST_DRAW_DrawModePage(char *a, int idx);
void B_PLIST_DRAW_PrintRowName(u8 *p, int slot, u16 rowIndex, u8 xPos, u8 extra);
void B_PLIST_DRAW_PrintSlotValue(u8 *p,int slot,int index,s16 value,u8 extra);
void B_PLIST_DRAW_PrintNameWithValues(u8 *p, int slot, int index, u8 x0, u8 extra);
void B_PLIST_DRAW_FillTypeBar(u8 *p,int slot,int index,u16 value,u8 extra);
void B_PLIST_DRAW_PrintRowValue(u8 *p,int slot,int index);
void B_PLIST_DRAW_PrintItemOrName(char *p, int i, int index);
void B_PLIST_DRAW_PrintNumberAt(char *p,int value,int slot,int id,u16 x,s16 y,u32 color);
void B_PLIST_DRAW_PrintTextAt(char *p, int i, s16 x, s16 y);
void B_PLIST_DRAW_PrintHeader(char *p, int id);
void B_PLIST_DRAW_PrintHeader9(char *p);
void B_PLIST_DRAW_PrintHeader10(char *p);
void B_PLIST_DRAW_PrintCenteredText(char *p, int i, int id);
void B_PLIST_DRAW_PrintStatsFields(u8 *p,int index);
void B_PLIST_DRAW_PrintAttackStat(char *obj, int i);
void B_PLIST_DRAW_PrintDefenseStat(char *p, int i);
void B_PLIST_DRAW_PrintSpeedStat(char *p, int i);
void B_PLIST_DRAW_PrintSpAttackStat(char *p, int i);
void B_PLIST_DRAW_PrintSpDefenseStat(char *p, int i);
void B_PLIST_DRAW_PrintDualValue(u8 *p,int index);
void B_PLIST_DRAW_PrintBankEntry(char *p, int index);
void B_PLIST_DRAW_PrintAccuracyLabel(char *p, int i);
void B_PLIST_DRAW_PrintAccuracyValue(char *p, int winIndex, int value);
void B_PLIST_DRAW_PrintPowerLabel(char *p, int i);
void B_PLIST_DRAW_PrintPowerValue(char *p, int winIndex, u32 value);
void B_PLIST_DRAW_PrintMoveDescription(char *p, int i, int id);
void B_PLIST_DRAW_PrintCategoryLabel(char *p, int i);
void B_PLIST_DRAW_PrintCategoryName(char *p, int i, int selector);
void B_PLIST_DRAW_PrintPpPair(u8 *p, int slot, int leftValue, int rightValue);
void B_PLIST_DRAW_PrintMoveRowLabel(char *p, int i);
void B_PLIST_DRAW_PrintWordAndRefresh(u8 *p);
void B_PLIST_DRAW_PrintMoveRowValues(char *p,u8 *record,int slot);
void B_PLIST_DRAW_DrawRows(u8 *p);
void B_PLIST_DRAW_DrawRowValueBars(u8 *p, int i);
void B_PLIST_DRAW_PrintValueIfUnset(u8 *p,int a);
void B_PLIST_DRAW_DrawMonMenuPage(char *p);
void B_PLIST_DRAW_DrawRowCenteredName(u8 *p, int idx);
void B_PLIST_DRAW_DrawMoveListPage(char *p);
void B_PLIST_DRAW_DrawSummaryPage(char *p);
void B_PLIST_DRAW_DrawMoveDetailPage(char *p);
void B_PLIST_DRAW_DrawMoveListWithNewMovePage(char *p);
void B_PLIST_DRAW_DrawMoveDetailWithNewMovePage(char *p);
void B_PLIST_DRAW_DrawMoveListForItemPage(char *p);
void B_PLIST_DRAW_ClearAndPrintStream(u8 *p);
void B_PLIST_DRAW_PrintStream(char *p);
void B_PLIST_DRAW_FormatRowWord(u8 *p);
void B_PLIST_DRAW_UpdateToolWindows(u8 *p);
void B_PLIST_DRAW_ShowToolWindows(u8 *p);
void B_PLIST_DRAW_ShowSubWindow(u8 *p);
void B_PLIST_DRAW_Init(char *p);
void B_PLIST_DRAW_ClearIds(char *p);
void B_PLIST_DRAW_RegisterRowCharacters(u8 *p);
void B_PLIST_DRAW_RegisterIconSet1(char *p);
void B_PLIST_DRAW_RegisterIconSet2(char *p);
void B_PLIST_DRAW_RegisterIconSet3(char *p);
void B_PLIST_DRAW_RegisterIconSet4(char *p);
void B_PLIST_DRAW_RegisterIconSet5(char *p);
unsigned B_PLIST_DRAW_CreateActorFromParams(char *p,const int *q);
void B_PLIST_DRAW_CreateActors(char *p);
void B_PLIST_DRAW_DeleteActors(char *p);
void B_PLIST_DRAW_PlaceActor(u8 *p, u32 b);
void B_PLIST_DRAW_TransferCharacter(char *p,void *obj,int index,int which);
void B_PLIST_DRAW_TransferCharacterToggle(char *p,int first,int index,int which);
void B_PLIST_DRAW_SetActorAnim(int mode,u8 *p,const struct ClactVec2 *q);
void B_PLIST_DRAW_SetActorAnimByMode(u32 mode,u8 *p,const struct ClactVec2 *q);
void B_PLIST_DRAW_LayoutActors(char *p,unsigned mode);
void B_PLIST_DRAW_LayoutSummaryPage(u8 *p);
void B_PLIST_DRAW_LayoutMoveListPage(u8 *p);
void B_PLIST_DRAW_LayoutMoveDetailPage(u8 *p);
void B_PLIST_DRAW_LayoutMoveListWithNewMovePage(u8 *p);
void B_PLIST_DRAW_LayoutMoveDetailWithNewMovePage(u8 *p);
void B_PLIST_DRAW_LayoutMoveListForItemPage(u8 *p);
/* END mkheaders: generated region */

#endif
