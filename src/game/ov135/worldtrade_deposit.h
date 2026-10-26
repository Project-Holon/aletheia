#ifndef GAME_OV135_WORLDTRADE_DEPOSIT_H
#define GAME_OV135_WORLDTRADE_DEPOSIT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_deposit.c, prototypes copied from their definitions. */

#include "../ov135/worldtrade_types.h"
#include "../types.h"

int WORLDTRADE_DEPOSIT_Init(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_Main(u8 *p);
int WORLDTRADE_DEPOSIT_Exit(WorldtradeWork *p);
void WORLDTRADE_DEPOSIT_PrintMessage(WorldtradeWork *p, u32 msgId, u32 unused1, u32 unused2, u32 unused3);
void WORLDTRADE_DEPOSIT_SetupBgPlanes(void);
void WORLDTRADE_DEPOSIT_ExitBgPlanes(void);
void WORLDTRADE_DEPOSIT_LoadBgGraphics(WorldtradeWork *p);
void WORLDTRADE_DEPOSIT_CreateWindows(WorldtradeWork *p);
void WORLDTRADE_DEPOSIT_DeleteWindows(WorldtradeWork *p);
void WORLDTRADE_DEPOSIT_CreateActors(WorldtradeWork *p);
void WORLDTRADE_DEPOSIT_DeleteActors(WorldtradeWork *p);
void WORLDTRADE_DEPOSIT_CreateStrings(WorldtradeWork *p);
void WORLDTRADE_DEPOSIT_DeleteStrings(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_WaitWipeIn(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateWaitCancel(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateOpenCategoryMenu(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateCategoryMenuInput(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateCreateSpeciesMenu(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_SetGenderFromEvent(u8 *p, int event);
int WORLDTRADE_DEPOSIT_StateSpeciesMenuInput(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StatePrintGenderPrompt(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateOpenGenderMenu(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateGenderMenuInput(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StatePrintLevelPrompt(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateOpenLevelMenu(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateLevelMenuInput(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StatePrintConfirmPrompt(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateOpenConfirmYesNo(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateConfirmYesNoInput(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateStartWipeOut(WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_StateWaitMessage(WorldtradeWork *p);
u16 WORLDTRADE_DEPOSIT_GetModeColor(int mode);
void WORLDTRADE_DEPOSIT_PrintName(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *printer);
void WORLDTRADE_DEPOSIT_PrintBankString(void *win, void *bank, u32 index, u32 y, u16 color, void *printer);
void WORLDTRADE_DEPOSIT_PrintMessageLine(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *printer);
u16 WORLDTRADE_DEPOSIT_GetModeFontColor(int mode, u16 color);
void WORLDTRADE_DEPOSIT_PrintModeLabelAligned(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *printer);
void WORLDTRADE_DEPOSIT_PrintModeLabel(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *printer);
void WORLDTRADE_DEPOSIT_PrintLevelRange(void *win, void *bank, int idx, u32 align, u32 y, u16 color, int alt, void *printer);
void WORLDTRADE_DEPOSIT_PrintConditionLabel(void *win, void *bank, int idx, u32 align, u32 x, u32 y, u16 color, int alt, void *printer);
void WORLDTRADE_DEPOSIT_DrawRequestWindow(void *bank, void *names, int unused, void **win, u32 index, int mode, int place, void *printer);
void WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(void *bank, void *names, void *unused, void **win, u32 index, int mode, int place, void *printer);
void WORLDTRADE_DEPOSIT_PrintMonSummary(void *bank, void *ws, void **win, void *mon, MonTag *out, void *printer);
u16 *WORLDTRADE_DEPOSIT_LoadSpeciesList(u32 heap, u32 unused, u32 *count);
void WORLDTRADE_DEPOSIT_GetSpeciesRange(u32 kind, int *start, int *end);
u8 *WORLDTRADE_DEPOSIT_CreateSpeciesFlagTable(u32 id);
void WORLDTRADE_DEPOSIT_BuildOffer(WorldtradeEntry *dst, WorldtradeWork *p);
void WORLDTRADE_DEPOSIT_StoreOfferInWork(Deposit *dst, WorldtradeWork *p);
int WORLDTRADE_DEPOSIT_CreateSpeciesMenu(void **menu, void *msg, void *endmsg, u16 *list, uptr unused4, u32 unused5, u32 kind, void *bag);
void *WORLDTRADE_DEPOSIT_CreateSpeciesMenuList(WorldtradeWork *p, void **menu, void *win, void *endmsg, void *msg, DepositState *cfg, void *bag);
int WORLDTRADE_DEPOSIT_CreateGenderMenu(void **menu, void *msg, int kind);
void WORLDTRADE_DEPOSIT_GetLevelBracket(u8 *dst, int index, int kind);
int WORLDTRADE_DEPOSIT_FindLevelBracketIndex(int key, int val, int which);
void WORLDTRADE_DEPOSIT_SetCountryFilter(WorldtradeWork *p,u32 index);
int WORLDTRADE_DEPOSIT_GetListRange(u32 id, u32 *start);
int WORLDTRADE_DEPOSIT_CreateListMenu(void **menu, void *msg, int id);
int WORLDTRADE_DEPOSIT_UpdateListMenu(void *p, u16 *old);
void WORLDTRADE_DEPOSIT_ClearListRange(SelTable *p);
void WORLDTRADE_DEPOSIT_SetListRangeEntry(SelTable *p, int index, u16 restoreScroll, u16 restoreRow);
/* END mkheaders: generated region */

#endif
