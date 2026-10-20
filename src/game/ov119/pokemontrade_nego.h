#ifndef GAME_OV119_POKEMONTRADE_NEGO_H
#define GAME_OV119_POKEMONTRADE_NEGO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_nego.c, prototypes copied from their definitions. */

#include "../ov119/pokemontrade_types.h"
#include "../types.h"

void POKETRADE_NEGO_FreeOfferMons(char *p);
void POKETRADE_NEGO_ClearOfferSlots(char *p);
int POKETRADE_NEGO_CountOwnOffers(char *p);
int POKETRADE_NEGO_CheckCancelTouch(char *p);
void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);
int POKETRADE_NEGO_CanConfirmOffers(char *p);
int POKETRADE_NEGO_HasOffer(char *p);
int POKETRADE_NEGO_FindOfferIndex(char *p, int a, int b);
void POKETRADE_NEGO_StoreRemoteOffer(char *p,int i,void *src);
int POKETRADE_NEGO_FindFreeOfferIndex(const char *p, int n, int a, int b);
int POKETRADE_NEGO_AddOffer(TradeWork *p,int side,int a,int b,void *value);
void POKETRADE_NEGO_RemoveOffer(TradeWork *p, int i, int j);
void POKETRADE_NEGO_RegisterIconResources(char *p,int n);
void POKETRADE_NEGO_ReleaseIconResources(char *p);
int POKETRADE_NEGO_AddSelectedAsOffer(char *p,int a,int b);
void POKETRADE_NEGO_DrawPlayerNames(char *p);
void POKETRADE_NEGO_DrawOfferStatusLabel(u8 *p,int i,int msg,int force);
void POKETRADE_NEGO_DeleteHeaderWindows(unsigned char *p);
void POKETRADE_NEGO_StepQuitMenuChoice(void *p);
void POKETRADE_NEGO_StepOpenQuitMenu(char *p);
void POKETRADE_NEGO_StepWaitSync25(unsigned char *p);
void POKETRADE_NEGO_StepSendSync25(unsigned char *p);
void POKETRADE_NEGO_StepWaitReplyKey(unsigned char *p);
void POKETRADE_NEGO_StepResolveReplies(char *p);
void POKETRADE_NEGO_StepSendReply(unsigned char *p);
void POKETRADE_NEGO_StepWaitReplySync(unsigned char *p);
void POKETRADE_NEGO_StepSendCancelReply(unsigned char *p);
void POKETRADE_NEGO_StepWaitCancelSync(unsigned char *p);
void POKETRADE_NEGO_StepShowWaitMessageA(unsigned char *p);
void POKETRADE_NEGO_StepShowWaitMessageB(unsigned char *p);
void POKETRADE_NEGO_StepConfirmMenuChoice(unsigned char *p);
void POKETRADE_NEGO_StepOpenConfirmMenu(char *p);
void POKETRADE_NEGO_StepResolveConfirm(char *p);
void POKETRADE_NEGO_StepSendConfirm(void *p);
void POKETRADE_NEGO_StepBeginConfirm(char *p);
void POKETRADE_NEGO_ShowOfferSummary(TradeWork *p,int index);
int POKETRADE_NEGO_PollOfferCursorKeys(char *p);
void POKETRADE_NEGO_StepReturnFromSummary(char *p);
void POKETRADE_NEGO_StepWaitSelectionDelay(char *p);
void POKETRADE_NEGO_StepBrowseOffers(char *p);
void POKETRADE_NEGO_StepOpenSummaryFromBrowse(TradeWork *p);
void POKETRADE_NEGO_StepOfferActionChoice(char *p);
void POKETRADE_NEGO_StepOpenOfferActionMenu(char *p);
void POKETRADE_NEGO_StepSendOfferMon(char *p);
void POKETRADE_NEGO_StepSendOfferIndex(void *p);
int POKETRADE_NEGO_TrySelectOffer(char *p,int idx);
void POKETRADE_NEGO_StepRebuildSceneAfterWipe(char *p);
void POKETRADE_NEGO_StepWaitMessageThenWipe(char *p);
void POKETRADE_NEGO_StepSendDeclineConfirm(void *p);
void POKETRADE_NEGO_StepBeginDeclineConfirm(char *p);
void POKETRADE_NEGO_StepDeclineMenuChoice(char *p);
void POKETRADE_NEGO_StepOpenDeclineMenu(void *p);
void POKETRADE_NEGO_StepBrowseOffersMain(char *p);
void POKETRADE_NEGO_StepWaitInputAfterMessage(void *p);
void POKETRADE_NEGO_StepShowNoOfferMessage(char *p);
void POKETRADE_NEGO_SetupWindowRegsOffers(void *p);
void POKETRADE_NEGO_StepWaitWipeBrowse(void *p);
void POKETRADE_NEGO_StepBuildBrowseScene(char *p);
void POKETRADE_NEGO_StepWaitWipeToBrowse(void *p);
void POKETRADE_NEGO_StepWipeToBrowse(void *p);
void POKETRADE_NEGO_StepSendReady(void *p);
void POKETRADE_NEGO_StepWaitReadySync(unsigned char *p);
void POKETRADE_NEGO_StepSendCheckResult(void *p);
void POKETRADE_NEGO_AbortHttpRequest(void **p);
void POKETRADE_NEGO_StepPollMonCheck(u8 *p);
void POKETRADE_NEGO_StepStartMonCheck(char *p);
void POKETRADE_NEGO_StepRetryMonCheck(void *p);
void POKETRADE_NEGO_StepBeginMonCheckWipe(void *p);
void POKETRADE_NEGO_StepResolveFinalAgree(char *p);
void POKETRADE_NEGO_StepSendFinalAgree(void *p);
void POKETRADE_NEGO_StepSendFinalReady(u8 *p);
void POKETRADE_NEGO_StepWaitMessageThenContinue(void *p);
void POKETRADE_NEGO_StepBeginFinalReady(char *p);
void POKETRADE_NEGO_StepFinalAgreeMenuChoice(void *p);
void POKETRADE_NEGO_StepOpenFinalAgreeMenu(void *p);
void POKETRADE_NEGO_StepWaitFinalMessage(char *p);
void POKETRADE_NEGO_StepBeginFinalWait(char *p);
void POKETRADE_NEGO_StepCancelMenuChoice(void *p);
void POKETRADE_NEGO_StepOpenCancelMenu(void *p);
void POKETRADE_NEGO_StepShowCancelMessage(char *p);
int POKETRADE_NEGO_IsMonOwnOffer(char *p,int a,int b);
int POKETRADE_NEGO_IsMonPeerSelected(char *p, int a, int b);
void POKETRADE_NEGO_StepWaitTouchRelease(void *p);
void POKETRADE_NEGO_StepSendOfferRemoval(void *p);
void POKETRADE_NEGO_InitOfferMarkers(void *p);
void POKETRADE_NEGO_SetOfferMarkersState(void *p, int a);
void POKETRADE_NEGO_UpdateOfferMarkers(void *p);
void POKETRADE_NEGO_PollMarkerTouch(void *p);
void POKETRADE_NEGO_TickMarkerTimers(void *p);
void POKETRADE_NEGO_FlashMarker(void *p, int a, int b);
void POKETRADE_NEGO_ResetMarkers(void *p);
void POKETRADE_NEGO_ExitMarkers(void *p);
void POKETRADE_NEGO_ShowOfferSlotMon(void *p,int i,void *v);
void POKETRADE_NEGO_TickOfferSlotTimers(void *p);
int POKETRADE_NEGO_SendOfferMon(char *p,void *src,int kind);
void POKETRADE_NEGO_PlaySeByKeyA(u32 key);
void POKETRADE_NEGO_PlaySeByKeyB(int key);
void POKETRADE_NEGO_PlaySeByEvent(int eventId, u8 *work);
/* END mkheaders: generated region */

#endif
