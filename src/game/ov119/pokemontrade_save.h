#ifndef GAME_OV119_POKEMONTRADE_SAVE_H
#define GAME_OV119_POKEMONTRADE_SAVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_save.c, prototypes copied from their definitions. */

#include "../types.h"

void POKETRADE_SAVE_FreeIfSet(u32 *p);
void POKETRADE_SAVE_SetWaitCounter(u8 *p, u32 v);
void POKETRADE_SAVE_PopBgmFadeIn60(void *p);
void POKETRADE_SAVE_PopBgm(void *p);
void POKETRADE_SAVE_PopBgmFadeIn24(void *p);
void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p);
void POKETRADE_SAVE_StepEventMessage1(char *p);
void POKETRADE_SAVE_StepEventMessage2(char *p);
void POKETRADE_SAVE_StepWaitFade1(char *p);
void POKETRADE_SAVE_StepWaitFade2(char *p);
void POKETRADE_SAVE_StepWaitSyncRange(void *p);
void POKETRADE_SAVE_SendTradeSummary(char *p);
void *POKETRADE_SAVE_BackupSaveControl(void *sys, u16 heapId);
void POKETRADE_SAVE_RestoreSaveControl(void *sys, void *buf);
void *POKETRADE_SAVE_BackupZukan(void *src, u16 heapId);
void POKETRADE_SAVE_RestoreZukan(void *h, void *buf);
void *POKETRADE_SAVE_BackupBlock1F(void *sys, u16 heapId);
void POKETRADE_SAVE_RestoreBlock1F(void **h, void *dst);
void POKETRADE_SAVE_FreeBackups(char *p);
void POKETRADE_SAVE_RestoreBackups(char *p);
int POKETRADE_SAVE_ConsumePerapVoice(char *p, void *party, int idx);
void POKETRADE_SAVE_ApplyTradeResult(char *p);
void POKETRADE_SAVE_StepAfterTrade(char *p);
void POKETRADE_SAVE_StepWaitEvolutionMessage(char *p);
void POKETRADE_SAVE_StepRegisterReceived(char *p);
void POKETRADE_SAVE_StepCheckEvolution(char *p);
void POKETRADE_SAVE_StepSaveCancelNotice(char *p);
void POKETRADE_SAVE_StepBeginSyncRange24(void *p);
void POKETRADE_SAVE_StepWaitSyncRange24(void *p);
void POKETRADE_SAVE_StepStartSave(char *p);
void POKETRADE_SAVE_StepWaitSaveDone(char *p);
void POKETRADE_SAVE_StepBeginWipeOut(char *p);
void POKETRADE_SAVE_StepRebuildSceneAfterWipe(char *p);
void POKETRADE_SAVE_DeleteTypeIconActor(char *p);
void POKETRADE_SAVE_CreateTypeIconActor(char *p,void *mon,int index,int slot,int x,int y,int a,u16 b);
void POKETRADE_SAVE_DeleteStatusIconActor(char *p);
void POKETRADE_SAVE_CreateStatusIconActor(char *p,void *mon,int slot,int x,int y,int a,u16 b,int c);
void POKETRADE_SAVE_OpenMessageWindow(char *p,int flag,int x,int y,int w,int h);
void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int flag);
void POKETRADE_SAVE_OpenMessageWindowTop(void *p);
void POKETRADE_SAVE_ShowTimeIcon(char *p);
void POKETRADE_SAVE_CloseMessageWindow(char *p);
void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
void POKETRADE_SAVE_CreateMessageResources(char *p);
void POKETRADE_SAVE_DeleteMessageResources(char *p);
int POKETRADE_SAVE_IsMessagePrintDone(char *p);
void POKETRADE_SAVE_CloseTaskMenu(char *p);
void POKETRADE_SAVE_OpenTaskMenuAt(char *p,int *ids,int count,int x,int y);
void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count);
void POKETRADE_SAVE_PrintNickname(void *a,void *b,int x,int y,int flag,int mode,char *p);
void POKETRADE_SAVE_PrintDexNumber(void *a,void *b,int x,int y,int flag,char *p);
void POKETRADE_SAVE_PrintSpeciesName(void *a,void *b,int x,int y,int flag,char *p);
void POKETRADE_SAVE_PrintLevel(void *a,void *b,int x,int y,char *p);
void POKETRADE_SAVE_PrintGender(void *a,void *b,int x,int y,char *p,int mode,int guard);
void POKETRADE_SAVE_PrintStatLabels(int a,int b,int x,int y,char *p);
void POKETRADE_SAVE_PrintHeldItem(int a,int b,int x,int y,char *p);
void POKETRADE_SAVE_PrintHpValues(int a,int b,int x,int y,char *p);
void POKETRADE_SAVE_PrintStatValues(int a, int b, int c, int d, char *p);
void POKETRADE_SAVE_PrintAbilityLabel(int a,int b,int x,int y,char *p);
void POKETRADE_SAVE_PrintMoveNames(int a,int b,int x,int y,char *p);
void POKETRADE_SAVE_PrintNatureName(int a,int b,int x,int y,char *p);
void POKETRADE_SAVE_PrintExperience(int a,int b,int x,int y,char *p);
void POKETRADE_SAVE_DrawOfferCardWindow(char *p,int i,void *mon);
void POKETRADE_SAVE_DeleteOfferStatusIcons(char *p);
void POKETRADE_SAVE_DeleteTypeIcons(char *p);
void POKETRADE_SAVE_CloseSummaryPage(void *p, int disableSubWindows);
void POKETRADE_SAVE_OpenSummaryScreen(char *p,void *a);
void POKETRADE_SAVE_DrawSummaryPage(char *p,int mode,void *mon);
void POKETRADE_SAVE_PrepareSummaryWindow(char *p, void *unusedData, int b, int unusedFlag);
void POKETRADE_SAVE_ToggleTypeIconSet(char *p,int a);
void POKETRADE_SAVE_ShowSummaryMon(char *p,void *mon,int side,int flag);
void POKETRADE_SAVE_DeleteOfferCardWindow(char *p,int i);
void POKETRADE_SAVE_CloseSummaryWindow(char *p,int a);
void POKETRADE_SAVE_DrawOfferListWindows(char *p, int unused);
void POKETRADE_SAVE_DeleteOfferListWindows(char *p);
void POKETRADE_SAVE_SetupWindowRegsSummary(void *unused);
void POKETRADE_SAVE_DrawPartnerOfferCard(char *p,int i,void *mon);
void POKETRADE_SAVE_DeletePartnerOfferCard(char *p,int i);
void *POKETRADE_SAVE_OpenTaskMenuWindow(char *p,int a);
void POKETRADE_SAVE_CloseTaskMenuWindow(char *p,int a,int b);
int POKETRADE_SAVE_IsTouchOutsideArea(void *unused);
void POKETRADE_SAVE_VBlankSetupWindowRegs(void *a,char *p);
void POKETRADE_SAVE_Init3DProjection(u16 a);
void POKETRADE_SAVE_Free3DLightSet(void);
void POKETRADE_SAVE_SetCameraSummary(char *p);
void POKETRADE_SAVE_SetCameraTrade(char *p);
void POKETRADE_SAVE_Update3DParticles(char *p);
/* END mkheaders: generated region */

#endif
