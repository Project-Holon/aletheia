#ifndef GAME_OV135_WORLDTRADE_INPUT_H
#define GAME_OV135_WORLDTRADE_INPUT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_input.c, prototypes copied from their definitions. */

struct Strbuf;
struct ZukanSave;

#include "../ov135/worldtrade_types.h"
#include "../types.h"
#include "../arm9/bmp_menuwork_shared_types.h"

void WORLDTRADE_INPUT_PrintStringTop(WorldtradeWork *work, void *bank, u32 msgId, u32 unused1, u16 unused2);
void WORLDTRADE_INPUT_PrintStringPlain(WorldtradeWork *work, void *bank, u32 msgId, u32 unused1, u16 unused2);
void WORLDTRADE_INPUT_PrintBankString(WorldtradeWork *p, void *bank, u32 index, int unused1, int unused2, int slow);
int WORLDTRADE_INPUT_PrintStringAligned(void *win, void *str, int x, int align, int unused, int font, void *ctx);
void WORLDTRADE_INPUT_PrintStringAlignedLine(void *win, struct Strbuf *str, u32 x, u32 y, u32 align, u16 color, Printer *printer);
void WORLDTRADE_INPUT_PrintStringAlignedWrapped(void *win, struct Strbuf *str, u32 x, u32 y, u32 align, u16 color, Printer *printer);
void WORLDTRADE_INPUT_PrintCentered(void *win, void *bank, int idx, void *printer);
void WORLDTRADE_ENTER_RestartNetTimeout(u8 *p);
void WORLDTRADE_INPUT_CreateModeWindows(WorldtradeMenu *p, u32 mode);
void WORLDTRADE_INPUT_MenuFinish(WorldtradeMenu *p, int mode);
WorldtradeMenu *WORLDTRADE_INPUT_MenuCreate(WorldtradeInputInit *init, u32 layer, u32 listKind);
void WORLDTRADE_INPUT_MenuSetMode(WorldtradeMenu *p, int mode);
void WORLDTRADE_INPUT_MenuDelete(WorldtradeMenu *p);
int WORLDTRADE_INPUT_MenuUpdate(WorldtradeMenu *p);
int WORLDTRADE_INPUT_CheckTouch(WorldtradeMenu *p, int mode);
int WORLDTRADE_INPUT_UpdateCategoryGrid(WorldtradeMenu *p, u8 *enable);
int WORLDTRADE_INPUT_ClampPageChoice(WorldtradeMenu *p, int choice);
int WORLDTRADE_INPUT_UpdateButtonRow(WorldtradeMenu *p, int base);
int WORLDTRADE_INPUT_GetPageCount(int total, int perPage);
int WORLDTRADE_INPUT_HandlePagedKey4(WorldtradeMenu *menu, int key);
void WORLDTRADE_INPUT_ScrollPage4(WorldtradeMenu *menu, int dir);
int WORLDTRADE_INPUT_UpdatePagedList4(WorldtradeMenu *menu);
int WORLDTRADE_INPUT_UpdateThreeOptionMenu(WorldtradeMenu *p);
void WORLDTRADE_INPUT_ScrollPage4Alt(WorldtradeMenu *menu, int dir);
int WORLDTRADE_INPUT_HandlePagedKey4Alt(WorldtradeMenu *menu, int key);
int WORLDTRADE_INPUT_UpdatePagedList4Alt(WorldtradeMenu *menu);
int WORLDTRADE_INPUT_MapModeToLabel(int unused, int mode);
int WORLDTRADE_INPUT_UpdateCategoryGridAlt(WorldtradeMenu *p, u8 *enable);
int WORLDTRADE_INPUT_HandlePagedKey5(WorldtradeMenu *menu, int key);
void WORLDTRADE_INPUT_ScrollPage5(WorldtradeMenu *menu, int dir);
int WORLDTRADE_INPUT_UpdatePagedList5(WorldtradeMenu *menu);
void WORLDTRADE_INPUT_DrawFrame(WorldtradeMenu *p, int mode, int pos);
void WORLDTRADE_INPUT_DrawThreeOptionScreen(WorldtradeMenu *p);
void WORLDTRADE_INPUT_DrawGenderListScreen(WorldtradeMenu *p);
void WORLDTRADE_INPUT_PutBmpWinString(void *mgr, void *win, void *str, u32 x, u16 color, void *printer);
int WORLDTRADE_INPUT_StateNone(void);
int WORLDTRADE_INPUT_StateWaitFrameIn(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateWaitFrameMove(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateStartFrameOutSlow(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateWaitFrameHide(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateStartFrameOut(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateStartCategoryScreen(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateCategoryInput(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateCategorySelected(WorldtradeMenu *p);
int WORLDTRADE_INPUT_DrawCategoryScreen(WorldtradeMenu *p);
int WORLDTRADE_INPUT_DrawSubCategoryScreen(WorldtradeMenu *menu);
int WORLDTRADE_INPUT_StateSubCategoryInput(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateSubCategorySelected(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateRestoreCursor(WorldtradeMenu *p);
int WORLDTRADE_INPUT_CountSeenSpecies(uptr unused, struct ZukanSave *item, u32 count, u16 *list, int start, int end);
int WORLDTRADE_INPUT_CreateSpeciesMenu(BmpMenuWork **menu, void *msg, void *bank, uptr speciesFlags, u32 kind, void *bag);
void WORLDTRADE_INPUT_PrintPageNumberA(WorldtradeMenu *menu, int page, int total);
void WORLDTRADE_INPUT_PrintPageNumberB(WorldtradeMenu *menu, int page, int total);
int WORLDTRADE_INPUT_DrawSpeciesListScreen(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateSpeciesListInput(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateSpeciesListSelected(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateSpeciesListClose(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateStartCategoryScreenAlt(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateCategoryInputAlt(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateCategorySelectedAlt(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateReturnToCategoryAlt(WorldtradeMenu *p);
int WORLDTRADE_INPUT_DrawSubCategoryScreenAlt(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateSubCategoryInputAlt(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateSubCategorySelectedAlt(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateRestoreCursorAlt(WorldtradeMenu *p);
int WORLDTRADE_INPUT_DrawConditionListScreen(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateConditionListInput(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateConditionListSelected(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateConditionListClose(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateStartThreeOptionScreen(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateThreeOptionInput(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateThreeOptionClose(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateStartGenderListScreen(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateGenderListInput(WorldtradeMenu *p);
int WORLDTRADE_INPUT_StateGenderListClose(WorldtradeMenu *p);
#if LANGUAGE == LANGUAGE_JAPANESE
void WORLDTRADE_INPUT_PrintFrameString(void *mgr, void *bank, void *win, u32 index, u16 color, void *printer);
#else
void WORLDTRADE_INPUT_PrintFrameString(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *printer);
#endif
void WORLDTRADE_INPUT_PrintFrameStringAlt(void *mgr, void *bank, void *win, u32 index, void *printer);
void WORLDTRADE_INPUT_PrintPageLabel(void *mgr, void *ctx, void *win, int page, u32 pages);
int WORLDTRADE_INPUT_CountSpeciesInList(WorldtradeMenu *menu, u32 idx);
int WORLDTRADE_INPUT_CategoryHasSpecies(void *p, int idx);
int WORLDTRADE_INPUT_GetListRangeCount(void *p, u32 id);
int WORLDTRADE_INPUT_CategoryHasListEntries(void *p, int idx);
/* END mkheaders: generated region */

#endif
