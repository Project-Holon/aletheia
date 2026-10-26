#ifndef GAME_OV021_SCRCMD_PROC_FLD_H
#define GAME_OV021_SCRCMD_PROC_FLD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_proc_fld.c, prototypes copied from their definitions. */

struct ScriptVm;
struct ScrcmdWork;
struct GameSystem;
struct MsgBank;
struct PrintQueue;
struct Bmp;
struct Strbuf;
struct GfFont;
struct BmpMenuList;
struct BmpWin;

#include "../ov021/scrcmd_proc_fld_types.h"
#include "../types.h"

int SCRCMD_PROC_FLD_StepShopTask(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_PROC_FLD_InitShop(struct GameSystem *gameSystem, ShopWork *shop, int shopKind, int shopVariant);
void SCRCMD_PROC_FLD_LoadShopMessages(ShopWork *shop, int usesBattlePoints);
u32 SCRCMD_PROC_FLD_GetShopCurrency(ShopWork *shop);
void SCRCMD_PROC_FLD_PickQuantityOutcome(ShopWork *shop);
void SCRCMD_PROC_FLD_PollItemList(ShopWork *shop);
u8 SCRCMD_PROC_FLD_PollMessageEnd(ShopWork *shop);
void SCRCMD_PROC_FLD_PayPrice(ShopWork *shop, u32 cost);
int SCRCMD_PROC_FLD_StepShop(struct GameSystem *gameSystem, ShopWork *shop, u32 shopKind, u8 shopVariant);
u32 SCRCMD_PROC_FLD_LoadItemRows(ShopItem *items, int count);
void SCRCMD_PROC_FLD_SetItemSlot(ShopWork *shop, int slotIndex, int isTmShop, int itemId, struct MsgBank *msgBank);
void SCRCMD_PROC_FLD_BuildItemListByBadges(ShopWork *shop, int shopKind, int shopVariant, int tierIndex);
void SCRCMD_PROC_FLD_BuildItemListFixed(ShopWork *shop, int tableIndex);
void SCRCMD_PROC_FLD_BuildItemListFromRange(ShopWork *shop, int kind);
void SCRCMD_PROC_FLD_FreeItemSlots(ShopWork *shop);
int SCRCMD_PROC_FLD_AllocShopResources(ShopWork *shop, int shopKind);
void SCRCMD_PROC_FLD_FreeShopResources(ShopWork *shop);
void SCRCMD_PROC_FLD_InitShopGraphics(ShopWork *shop);
void SCRCMD_PROC_FLD_ExitShopGraphics(ShopWork *shop);
void SCRCMD_PROC_FLD_LoadCursorResources(ShopWork *shop);
void SCRCMD_PROC_FLD_LoadIconResources(ShopWork *shop);
void SCRCMD_PROC_FLD_UpdateItemIcon(ShopWork *shop, u32 itemId);
void SCRCMD_PROC_FLD_CreateShopActors(ShopWork *shop);
void SCRCMD_PROC_FLD_InitShopCells(ShopWork *shop);
void SCRCMD_PROC_FLD_FreeShopCells(ShopWork *shop);
void SCRCMD_PROC_FLD_InitShopWindows(ShopWork *shop);
void SCRCMD_PROC_FLD_FreeShopWindows(ShopWork *shop);
void SCRCMD_PROC_FLD_PrintMoneyWindow(ShopWork *shop);
void SCRCMD_PROC_FLD_PrintOwnedWindow(ShopWork *shop, u16 itemId);
void SCRCMD_PROC_FLD_PrintItemDescription(ShopWork *shop, u32 itemId);
void SCRCMD_PROC_FLD_PrintQuantityWindow(ShopWork *shop, u32 quantity, u32 price);
void SCRCMD_PROC_FLD_CreateItemListMenu(ShopWork *shop);
void SCRCMD_PROC_FLD_PrintListText(struct PrintQueue *printSys, struct Bmp *bitmap, int x, int y, struct Strbuf *text, struct GfFont *fontInfo, u16 colorBits);
void SCRCMD_PROC_FLD_PrintPriceEntry(struct BmpMenuList *listMenu, int row, u8 y);
void SCRCMD_PROC_FLD_PrintUniqueItemEntry(struct BmpMenuList *listMenu, int row, u8 y);
void SCRCMD_PROC_FLD_OnListCursorMove(struct BmpMenuList *listMenu, u32 row);
void SCRCMD_PROC_FLD_FreeItemListMenu(ShopWork *shop);
u8 SCRCMD_PROC_FLD_ReturnZero(u32 arg);
void SCRCMD_PROC_FLD_ShowItemMessage(ShopWork *shop, u32 messageId, u32 itemId, u32 plural);
void SCRCMD_PROC_FLD_ShowConfirmMessage(ShopWork *shop, u32 isTmShop);
void SCRCMD_PROC_FLD_PrepareMessageWindow(struct BmpWin *window);
void SCRCMD_PROC_FLD_ShowMessage(ShopWork *shop, u32 messageId);
void SCRCMD_PROC_FLD_ShowBuyConfirm(ShopWork *shop, u32 messageId, u16 itemId, u32 price, u16 quantity);
void SCRCMD_PROC_FLD_ShowTmBuyConfirm(ShopWork *shop, u32 messageId, u32 itemId, u32 price);
int SCRCMD_PROC_FLD_AdjustQuantity(s16 *value, int maxValue, int step);
int SCRCMD_PROC_FLD_StepQuantitySelect(ShopWork *shop);
void SCRCMD_PROC_FLD_SetQuantityMask(int i);
int SCRCMD_PROC_FLD_StoreCommKind(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StoreWifiProfileValid(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StoreWifiFriendCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallWifiClubEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallWorldTradeEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallGtsNegoEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_PROC_FLD_FinishOv170Event(void *arg);
int SCRCMD_PROC_FLD_CallOv170Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartNameInMode5(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartNameInMode6(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SetGameClearEventAndEnd(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_ObtainCGearAndCallCommResetEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallOv219Event(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallShortcutEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallGameManual(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartScriptedWildBattle(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StartFieldMapFadeIn(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StoreBattleResult(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_CallCatchTutorial(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_StoreEffectEncountItemId(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_PROC_FLD_SpawnMovePokemonIfInactive(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
u16 SCRCMD_PROC_FLD_AddUniqueU16(u16 *values, u16 count, u16 value);
/* END mkheaders: generated region */

#endif
