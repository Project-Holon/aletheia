#ifndef GAME_OV198_B_PLIST_DRAW_H
#define GAME_OV198_B_PLIST_DRAW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of b_plist_draw.c, prototypes copied from their definitions. */

struct ClactActor;
struct ClactVec2;

#include "../types.h"

void B_PLIST_DRAW_CreateStateWindows(struct B_PlistWork *p,u32 state);
void B_PLIST_DRAW_ToggleAuxWindow(struct B_PlistWork *p);
void B_PLIST_DRAW_DeleteAuxWindow(struct B_PlistWork *p);
void B_PLIST_DRAW_ClearWindowBitmaps(struct B_PlistWork *p);
void B_PLIST_DRAW_DeleteStateWindows(struct B_PlistWork *p);
void B_PLIST_DRAW_DeleteAllWindows(struct B_PlistWork *p);
void B_PLIST_DRAW_DrawModePage(struct B_PlistWork *a, int idx);
void B_PLIST_DRAW_PrintRowName(struct B_PlistWork *p, int slot, u16 rowIndex, u8 xPos, u8 extra);
void B_PLIST_DRAW_PrintSlotValue(struct B_PlistWork *p,int slot,int index,s16 value,u8 extra);
void B_PLIST_DRAW_PrintNameWithValues(struct B_PlistWork *p, int slot, int index, u8 x0, u8 extra);
void B_PLIST_DRAW_FillTypeBar(struct B_PlistWork *p,int slot,int index,u16 value,u8 extra);
void B_PLIST_DRAW_PrintRowValue(struct B_PlistWork *p,int slot,int index);
void B_PLIST_DRAW_PrintItemOrName(struct B_PlistWork *p, int i, int index);
void B_PLIST_DRAW_PrintNumberAt(struct B_PlistWork *p,int value,int slot,int id,u16 x,s16 y,u32 color);
void B_PLIST_DRAW_PrintTextAt(struct B_PlistWork *p, int i, s16 x, s16 y);
void B_PLIST_DRAW_PrintHeader(struct B_PlistWork *p, int id);
void B_PLIST_DRAW_PrintHeader9(struct B_PlistWork *p);
void B_PLIST_DRAW_PrintHeader10(struct B_PlistWork *p);
void B_PLIST_DRAW_PrintCenteredText(struct B_PlistWork *p, int i, int id);
void B_PLIST_DRAW_PrintStatsFields(struct B_PlistWork *p,int index);
void B_PLIST_DRAW_PrintAttackStat(struct B_PlistWork *obj, int i);
void B_PLIST_DRAW_PrintDefenseStat(struct B_PlistWork *p, int i);
void B_PLIST_DRAW_PrintSpeedStat(struct B_PlistWork *p, int i);
void B_PLIST_DRAW_PrintSpAttackStat(struct B_PlistWork *p, int i);
void B_PLIST_DRAW_PrintSpDefenseStat(struct B_PlistWork *p, int i);
void B_PLIST_DRAW_PrintDualValue(struct B_PlistWork *p,int index);
void B_PLIST_DRAW_PrintBankEntry(struct B_PlistWork *p, int index);
void B_PLIST_DRAW_PrintAccuracyLabel(struct B_PlistWork *p, int i);
void B_PLIST_DRAW_PrintAccuracyValue(struct B_PlistWork *p, int winIndex, int value);
void B_PLIST_DRAW_PrintPowerLabel(struct B_PlistWork *p, int i);
void B_PLIST_DRAW_PrintPowerValue(struct B_PlistWork *p, int winIndex, u32 value);
void B_PLIST_DRAW_PrintMoveDescription(struct B_PlistWork *p, int i, int id);
void B_PLIST_DRAW_PrintCategoryLabel(struct B_PlistWork *p, int i);
void B_PLIST_DRAW_PrintCategoryName(struct B_PlistWork *p, int i, int selector);
void B_PLIST_DRAW_PrintPpPair(struct B_PlistWork *p, int slot, int leftValue, int rightValue);
void B_PLIST_DRAW_PrintMoveRowLabel(struct B_PlistWork *p, int i);
void B_PLIST_DRAW_PrintWordAndRefresh(struct B_PlistWork *p);
void B_PLIST_DRAW_PrintMoveRowValues(struct B_PlistWork *p,u8 *record,int slot);
void B_PLIST_DRAW_DrawRows(struct B_PlistWork *p);
void B_PLIST_DRAW_DrawRowValueBars(struct B_PlistWork *p, int i);
void B_PLIST_DRAW_PrintValueIfUnset(struct B_PlistWork *p,int a);
void B_PLIST_DRAW_DrawMonMenuPage(struct B_PlistWork *p);
void B_PLIST_DRAW_DrawRowCenteredName(struct B_PlistWork *p, int idx);
void B_PLIST_DRAW_DrawMoveListPage(struct B_PlistWork *p);
void B_PLIST_DRAW_DrawSummaryPage(struct B_PlistWork *p);
void B_PLIST_DRAW_DrawMoveDetailPage(struct B_PlistWork *p);
void B_PLIST_DRAW_DrawMoveListWithNewMovePage(struct B_PlistWork *p);
void B_PLIST_DRAW_DrawMoveDetailWithNewMovePage(struct B_PlistWork *p);
void B_PLIST_DRAW_DrawMoveListForItemPage(struct B_PlistWork *p);
void B_PLIST_DRAW_ClearAndPrintStream(struct B_PlistWork *p);
void B_PLIST_DRAW_PrintStream(struct B_PlistWork *p);
void B_PLIST_DRAW_FormatRowWord(struct B_PlistWork *p);
void B_PLIST_DRAW_UpdateToolWindows(struct B_PlistWork *p);
void B_PLIST_DRAW_ShowToolWindows(struct B_PlistWork *p);
void B_PLIST_DRAW_ShowSubWindow(struct B_PlistWork *p);
void B_PLIST_DRAW_Init(struct B_PlistWork *p);
void B_PLIST_DRAW_ClearIds(struct B_PlistWork *p);
void B_PLIST_DRAW_RegisterRowCharacters(struct B_PlistWork *p);
void B_PLIST_DRAW_RegisterIconSet1(struct B_PlistWork *p);
void B_PLIST_DRAW_RegisterIconSet2(struct B_PlistWork *p);
void B_PLIST_DRAW_RegisterIconSet3(struct B_PlistWork *p);
void B_PLIST_DRAW_RegisterIconSet4(struct B_PlistWork *p);
void B_PLIST_DRAW_RegisterIconSet5(struct B_PlistWork *p);
struct ClactActor *B_PLIST_DRAW_CreateActorFromParams(struct B_PlistWork *p,const int *q);
void B_PLIST_DRAW_CreateActors(struct B_PlistWork *p);
void B_PLIST_DRAW_DeleteActors(struct B_PlistWork *p);
void B_PLIST_DRAW_PlaceActor(struct ClactActor *actor, const struct ClactVec2 *b);
void B_PLIST_DRAW_TransferCharacter(struct B_PlistWork *p,void *obj,int index,int which);
void B_PLIST_DRAW_TransferCharacterToggle(struct B_PlistWork *p,int first,int index,int which);
void B_PLIST_DRAW_SetActorAnim(int mode,struct ClactActor *actor,const struct ClactVec2 *q);
void B_PLIST_DRAW_SetActorAnimByMode(u32 mode,struct ClactActor *actor,const struct ClactVec2 *q);
void B_PLIST_DRAW_LayoutActors(struct B_PlistWork *p,unsigned mode);
void B_PLIST_DRAW_LayoutSummaryPage(struct B_PlistWork *p);
void B_PLIST_DRAW_LayoutMoveListPage(struct B_PlistWork *p);
void B_PLIST_DRAW_LayoutMoveDetailPage(struct B_PlistWork *p);
void B_PLIST_DRAW_LayoutMoveListWithNewMovePage(struct B_PlistWork *p);
void B_PLIST_DRAW_LayoutMoveDetailWithNewMovePage(struct B_PlistWork *p);
void B_PLIST_DRAW_LayoutMoveListForItemPage(struct B_PlistWork *p);
/* END mkheaders: generated region */

#endif
