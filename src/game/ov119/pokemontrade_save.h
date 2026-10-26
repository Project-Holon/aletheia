#ifndef GAME_OV119_POKEMONTRADE_SAVE_H
#define GAME_OV119_POKEMONTRADE_SAVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_save.c, prototypes copied from their definitions. */

struct Unit;
struct BmpWin;

#include "../ov119/pokemontrade_types.h"
#include "../types.h"

struct TcbTask;

void POKETRADE_SAVE_FreeIfSet(void *p);
void POKETRADE_SAVE_SetWaitCounter(TradeWork *p, u32 v);
void POKETRADE_SAVE_PopBgmFadeIn60(TradeWork *p);
void POKETRADE_SAVE_PopBgm(TradeWork *p);
void POKETRADE_SAVE_PopBgmFadeIn24(TradeWork *p);
void POKETRADE_SAVE_ResetClactAndBeginEvent(TradeWork *p);
void POKETRADE_SAVE_StepEventMessage1(TradeWork *p);
void POKETRADE_SAVE_StepEventMessage2(TradeWork *p);
void POKETRADE_SAVE_StepWaitFade1(TradeWork *p);
void POKETRADE_SAVE_StepWaitFade2(TradeWork *p);
void POKETRADE_SAVE_StepWaitSyncRange(TradeWork *p);
void POKETRADE_SAVE_SendTradeSummary(TradeWork *p);
void *POKETRADE_SAVE_BackupSaveControl(void *sys, u16 heapId);
void POKETRADE_SAVE_RestoreSaveControl(void *sys, void *buf);
void *POKETRADE_SAVE_BackupZukan(void *src, u16 heapId);
void POKETRADE_SAVE_RestoreZukan(void *h, void *buf);
void *POKETRADE_SAVE_BackupBlock1F(void *sys, u16 heapId);
void POKETRADE_SAVE_RestoreBlock1F(void **h, void *dst);
void POKETRADE_SAVE_FreeBackups(void *arg);
void POKETRADE_SAVE_RestoreBackups(TradeWork *p);
int POKETRADE_SAVE_ConsumePerapVoice(TradeWork *p, void *party, int idx);
void POKETRADE_SAVE_ApplyTradeResult(TradeWork *p);
void POKETRADE_SAVE_StepAfterTrade(TradeWork *p);
void POKETRADE_SAVE_StepWaitEvolutionMessage(TradeWork *p);
void POKETRADE_SAVE_StepRegisterReceived(TradeWork *p);
void POKETRADE_SAVE_StepCheckEvolution(TradeWork *p);
void POKETRADE_SAVE_StepSaveCancelNotice(TradeWork *p);
void POKETRADE_SAVE_StepBeginSyncRange24(TradeWork *p);
void POKETRADE_SAVE_StepWaitSyncRange24(TradeWork *p);
void POKETRADE_SAVE_StepStartSave(TradeWork *p);
void POKETRADE_SAVE_StepWaitSaveDone(TradeWork *p);
void POKETRADE_SAVE_StepBeginWipeOut(TradeWork *p);
void POKETRADE_SAVE_StepRebuildSceneAfterWipe(TradeWork *p);
void POKETRADE_SAVE_DeleteTypeIconActor(TradeIconSlot *p);
void POKETRADE_SAVE_CreateTypeIconActor(TradeIconSlot *p,void *mon,int index,struct Unit *slot,int x,int y,int a,u16 b);
void POKETRADE_SAVE_DeleteStatusIconActor(TradeIconSlot *p);
void POKETRADE_SAVE_CreateStatusIconActor(TradeIconSlot *p,void *mon,struct Unit *slot,int x,int y,int a,u16 b,int c);
void POKETRADE_SAVE_OpenMessageWindow(TradeWork *p,int flag,int x,int y,int w,int h);
void POKETRADE_SAVE_OpenMessageWindowAtPos(TradeWork *p, int a, int flag);
void POKETRADE_SAVE_OpenMessageWindowTop(TradeWork *p);
void POKETRADE_SAVE_ShowTimeIcon(TradeWork *p);
void POKETRADE_SAVE_CloseMessageWindow(TradeWork *p);
void POKETRADE_SAVE_CloseMessageWindowClear(TradeWork *p);
void POKETRADE_SAVE_CreateMessageResources(TradeWork *p);
void POKETRADE_SAVE_DeleteMessageResources(TradeWork *p);
int POKETRADE_SAVE_IsMessagePrintDone(TradeWork *p);
void POKETRADE_SAVE_CloseTaskMenu(TradeWork *p);
void POKETRADE_SAVE_OpenTaskMenuAt(TradeWork *p,int *ids,int count,int x,int y);
void POKETRADE_SAVE_OpenTaskMenu(TradeWork *p, int *ids, int count);
void POKETRADE_SAVE_PrintNickname(void *a,void *b,int x,int y,int flag,int mode,TradeWork *p);
void POKETRADE_SAVE_PrintDexNumber(void *a,void *b,int x,int y,int flag,TradeWork *p);
void POKETRADE_SAVE_PrintSpeciesName(void *a,void *b,int x,int y,int flag,TradeWork *p);
void POKETRADE_SAVE_PrintLevel(void *a,void *b,int x,int y,TradeWork *p);
void POKETRADE_SAVE_PrintGender(void *a,void *b,int x,int y,TradeWork *p,int mode,int guard);
void POKETRADE_SAVE_PrintStatLabels(void *a,struct BmpWin *b,int x,int y,TradeWork *p);
void POKETRADE_SAVE_PrintHeldItem(void *a,struct BmpWin *b,int x,int y,TradeWork *p);
void POKETRADE_SAVE_PrintHpValues(void *a,struct BmpWin *b,int x,int y,TradeWork *p);
void POKETRADE_SAVE_PrintStatValues(void *a, struct BmpWin *b, int c, int d, TradeWork *p);
void POKETRADE_SAVE_PrintAbilityLabel(void *a,struct BmpWin *b,int x,int y,TradeWork *p);
void POKETRADE_SAVE_PrintMoveNames(void *a,struct BmpWin *b,int x,int y,TradeWork *p);
void POKETRADE_SAVE_PrintNatureName(void *a,struct BmpWin *b,int x,int y,TradeWork *p);
void POKETRADE_SAVE_PrintExperience(void *a,struct BmpWin *b,int x,int y,TradeWork *p);
void POKETRADE_SAVE_DrawOfferCardWindow(TradeWork *work,int i,void *mon);
void POKETRADE_SAVE_DeleteOfferStatusIcons(TradeWork *p);
void POKETRADE_SAVE_DeleteTypeIcons(TradeWork *p);
void POKETRADE_SAVE_CloseSummaryPage(TradeWork *p, int disableSubWindows);
void POKETRADE_SAVE_OpenSummaryScreen(TradeWork *p,void *a);
void POKETRADE_SAVE_DrawSummaryPage(TradeWork *p,int mode,void *mon);
void POKETRADE_SAVE_PrepareSummaryWindow(TradeWork *p, void *unusedData, int b, int unusedFlag);
void POKETRADE_SAVE_ToggleTypeIconSet(TradeWork *p,void *a);
void POKETRADE_SAVE_ShowSummaryMon(TradeWork *p,void *mon,int side,int flag);
void POKETRADE_SAVE_DeleteOfferCardWindow(TradeWork *p,int i);
void POKETRADE_SAVE_CloseSummaryWindow(TradeWork *p,int a);
void POKETRADE_SAVE_DrawOfferListWindows(TradeWork *work, int unused);
void POKETRADE_SAVE_DeleteOfferListWindows(TradeWork *p);
void POKETRADE_SAVE_SetupWindowRegsSummary(void *unused);
void POKETRADE_SAVE_DrawPartnerOfferCard(TradeWork *work,int i,void *mon);
void POKETRADE_SAVE_DeletePartnerOfferCard(TradeWork *p,int i);
void *POKETRADE_SAVE_OpenTaskMenuWindow(TradeWork *p,int a);
void POKETRADE_SAVE_CloseTaskMenuWindow(TradeWork *p,int a,int b);
int POKETRADE_SAVE_IsTouchOutsideArea(void *unused);
void POKETRADE_SAVE_VBlankSetupWindowRegs(struct TcbTask *a, void *pArg);
void POKETRADE_SAVE_Init3DProjection(u16 a);
void POKETRADE_SAVE_Free3DLightSet(void);
void POKETRADE_SAVE_SetCameraSummary(TradeWork *p);
void POKETRADE_SAVE_SetCameraTrade(TradeWork *p);
void POKETRADE_SAVE_Update3DParticles(TradeWork *p);
/* END mkheaders: generated region */

#endif
