#ifndef GAME_OV135_WORLDTRADE_BOX_H
#define GAME_OV135_WORLDTRADE_BOX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_box.c, prototypes copied from their definitions. */

#include "../ov135/worldtrade_types.h"
#include "../types.h"

int WORLDTRADE_BOX_Init(WorldtradeWork *p);
void WORLDTRADE_BOX_Main(u8 *p);
int WORLDTRADE_BOX_Exit(WorldtradeWork *p);
void WORLDTRADE_BOX_SetupBgPlanes(void);
void WORLDTRADE_BOX_ExitBgPlanes(void);
void WORLDTRADE_BOX_LoadBgGraphics(WorldtradeWork *p);
void WORLDTRADE_BOX_CreateActors(WorldtradeWork *p);
void WORLDTRADE_BOX_DeleteActors(WorldtradeWork *p);
void WORLDTRADE_BOX_CreateWindows(WorldtradeWork *p);
void WORLDTRADE_BOX_DeleteWindows(WorldtradeWork *p);
void WORLDTRADE_BOX_CreateStrings(WorldtradeWork *p);
void WORLDTRADE_BOX_DeleteStrings(WorldtradeWork *p);
int WORLDTRADE_BOX_StateWaitWipeIn(WorldtradeWork *p);
void WORLDTRADE_BOX_SelectMonForOffer(WorldtradeWork *p);
void WORLDTRADE_BOX_SelectMonForRequest(WorldtradeWork *p);
int WORLDTRADE_BOX_CheckArrowTouch(WorldtradeWork *p);
void WORLDTRADE_BOX_FinishByKind(WorldtradeWork *p, u32 kind);
int WORLDTRADE_BOX_StateMainInput(WorldtradeWork *p);
void WORLDTRADE_BOX_UpdateKeyCursor(WorldtradeWork *p);
void WORLDTRADE_BOX_MoveCursorToSlot(u32 cursor, int slot);
int WORLDTRADE_BOX_GetColumnIndex(int index, int count, int delta);
int WORLDTRADE_BOX_StateCreateOfferMenu(WorldtradeWork *p);
int WORLDTRADE_BOX_StateOfferMenuInput(WorldtradeWork *p);
int WORLDTRADE_BOX_StateCreateRequestMenu(WorldtradeWork *p);
int WORLDTRADE_BOX_StateRequestMenuInput(WorldtradeWork *p);
int WORLDTRADE_BOX_StateStartWipeOut(WorldtradeWork *p);
int WORLDTRADE_BOX_StateOpenCancelConfirm(WorldtradeWork *p);
int WORLDTRADE_BOX_StateCancelConfirmInput(WorldtradeWork *p);
int WORLDTRADE_BOX_StatePrintDepositPrompt(WorldtradeWork *p);
int WORLDTRADE_BOX_StateOpenDepositConfirm(WorldtradeWork *p);
int WORLDTRADE_BOX_StateDepositConfirmInput(WorldtradeWork *p);
int WORLDTRADE_BOX_TryConfirmDeposit(WorldtradeWork *p);
int WORLDTRADE_BOX_StatePrintSelectPrompt(WorldtradeWork *p);
int WORLDTRADE_BOX_StateOpenSelectConfirm(WorldtradeWork *p);
int WORLDTRADE_BOX_StateSelectConfirmInput(WorldtradeWork *p);
int WORLDTRADE_BOX_StateWaitCursorAnim(WorldtradeWork *p);
int WORLDTRADE_BOX_StateWaitMessage(WorldtradeWork *p);
int WORLDTRADE_BOX_StateWaitMessageOrKey(WorldtradeWork *p);
void WORLDTRADE_BOX_PrintMessage(WorldtradeWork *p, u32 msgId, u32 unused1, u32 unused2, u32 unused3, u32 sel);
u32 WORLDTRADE_BOX_LoadPokeIconChar(u32 arc, u32 memberId, u32 outData, u32 heapId);
void WORLDTRADE_BOX_LoadPokeIcon(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 spr, u32 arc, IconRec *rec);
void WORLDTRADE_BOX_CalcLevel(u32 mon, u8 *out);
void WORLDTRADE_BOX_TransferIconPalette(WorldtradeWork *p);
void WORLDTRADE_BOX_SetupIconActor(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, void *arc, WorldtradeInfo *info, IconRec *rec);
void WORLDTRADE_BOX_LoadBoxIcons(WorldtradeWork *p, int box);
int WORLDTRADE_BOX_IsPartyBox(int box);
void *WORLDTRADE_BOX_GetPartyMon(void *party, void *save, int box, int slot);
u32 WORLDTRADE_BOX_GetMonCount(u8 *party, u32 save, u32 box);
int WORLDTRADE_BOX_CanRemoveMon(void *party, void *save, int box, int slot);
u32 WORLDTRADE_BOX_GetBoxCount(void *sav);
int WORLDTRADE_BOX_CheckMonRestrictionA(u32 handle);
int WORLDTRADE_BOX_CheckMonRestrictionB(u32 handle);
int WORLDTRADE_BOX_GetMonTradeState(void *party, void *save, int box, int slot);
int WORLDTRADE_BOX_TagMatchesRequest(MonTag *have, WantTag *want);
int WORLDTRADE_BOX_MonMatchesRequest(void *mon, WantTag *want);
void WORLDTRADE_BOX_BuildDepositFromWork(Deposit *dst, WorldtradeWork *p);
int WORLDTRADE_BOX_IsHoldingMail(u32 handle);
void WORLDTRADE_BOX_UnlockBoxIfAllFull(WorldtradeWork *p);
/* END mkheaders: generated region */

#endif
