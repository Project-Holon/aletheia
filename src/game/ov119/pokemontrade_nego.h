#ifndef GAME_OV119_POKEMONTRADE_NEGO_H
#define GAME_OV119_POKEMONTRADE_NEGO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_nego.c, prototypes copied from their definitions. */

#include "../ov119/pokemontrade_types.h"
#include "../types.h"

void POKETRADE_NEGO_FreeOfferMons(TradeWork *p);
void POKETRADE_NEGO_ClearOfferSlots(TradeWork *p);
int POKETRADE_NEGO_CountOwnOffers(TradeWork *p);
int POKETRADE_NEGO_CheckCancelTouch(TradeWork *p);
void POKETRADE_NEGO_CloseCancelMenu(TradeWork *p, int a, int b);
int POKETRADE_NEGO_CanConfirmOffers(TradeWork *p);
int POKETRADE_NEGO_HasOffer(TradeWork *p);
int POKETRADE_NEGO_FindOfferIndex(TradeWork *p, int a, int b);
void POKETRADE_NEGO_StoreRemoteOffer(TradeWork *p,int i,void *src);
int POKETRADE_NEGO_FindFreeOfferIndex(TradeWork *p, int n, int a, int b);
int POKETRADE_NEGO_AddOffer(TradeWork *p,int side,int a,int b,void *value);
void POKETRADE_NEGO_RemoveOffer(TradeWork *p, int i, int j);
void POKETRADE_NEGO_RegisterIconResources(TradeWork *p,int n);
void POKETRADE_NEGO_ReleaseIconResources(TradeWork *p);
int POKETRADE_NEGO_AddSelectedAsOffer(TradeWork *p,int a,int b);
void POKETRADE_NEGO_DrawPlayerNames(TradeWork *p);
void POKETRADE_NEGO_DrawOfferStatusLabel(TradeWork *p,int i,int msg,int force);
void POKETRADE_NEGO_DeleteHeaderWindows(TradeWork *p);
void POKETRADE_NEGO_StepQuitMenuChoice(TradeWork *p);
void POKETRADE_NEGO_StepOpenQuitMenu(TradeWork *p);
void POKETRADE_NEGO_StepWaitSync25(TradeWork *p);
void POKETRADE_NEGO_StepSendSync25(TradeWork *p);
void POKETRADE_NEGO_StepWaitReplyKey(TradeWork *p);
void POKETRADE_NEGO_StepResolveReplies(TradeWork *p);
void POKETRADE_NEGO_StepSendReply(TradeWork *p);
void POKETRADE_NEGO_StepWaitReplySync(TradeWork *p);
void POKETRADE_NEGO_StepSendCancelReply(TradeWork *p);
void POKETRADE_NEGO_StepWaitCancelSync(TradeWork *p);
void POKETRADE_NEGO_StepShowWaitMessageA(TradeWork *p);
void POKETRADE_NEGO_StepShowWaitMessageB(TradeWork *p);
void POKETRADE_NEGO_StepConfirmMenuChoice(TradeWork *p);
void POKETRADE_NEGO_StepOpenConfirmMenu(TradeWork *p);
void POKETRADE_NEGO_StepResolveConfirm(TradeWork *p);
void POKETRADE_NEGO_StepSendConfirm(TradeWork *p);
void POKETRADE_NEGO_StepBeginConfirm(TradeWork *p);
void POKETRADE_NEGO_ShowOfferSummary(TradeWork *p,int index);
int POKETRADE_NEGO_PollOfferCursorKeys(TradeWork *p);
void POKETRADE_NEGO_StepReturnFromSummary(TradeWork *p);
void POKETRADE_NEGO_StepWaitSelectionDelay(TradeWork *p);
void POKETRADE_NEGO_StepBrowseOffers(TradeWork *p);
void POKETRADE_NEGO_StepOpenSummaryFromBrowse(TradeWork *p);
void POKETRADE_NEGO_StepOfferActionChoice(TradeWork *p);
void POKETRADE_NEGO_StepOpenOfferActionMenu(TradeWork *p);
void POKETRADE_NEGO_StepSendOfferMon(TradeWork *p);
void POKETRADE_NEGO_StepSendOfferIndex(TradeWork *p);
int POKETRADE_NEGO_TrySelectOffer(TradeWork *p,int idx);
void POKETRADE_NEGO_StepRebuildSceneAfterWipe(TradeWork *p);
void POKETRADE_NEGO_StepWaitMessageThenWipe(TradeWork *p);
void POKETRADE_NEGO_StepSendDeclineConfirm(TradeWork *p);
void POKETRADE_NEGO_StepBeginDeclineConfirm(TradeWork *p);
void POKETRADE_NEGO_StepDeclineMenuChoice(TradeWork *p);
void POKETRADE_NEGO_StepOpenDeclineMenu(TradeWork *p);
void POKETRADE_NEGO_StepBrowseOffersMain(TradeWork *p);
void POKETRADE_NEGO_StepWaitInputAfterMessage(TradeWork *p);
void POKETRADE_NEGO_StepShowNoOfferMessage(TradeWork *p);
void POKETRADE_NEGO_SetupWindowRegsOffers(TradeWork *p);
void POKETRADE_NEGO_StepWaitWipeBrowse(TradeWork *p);
void POKETRADE_NEGO_StepBuildBrowseScene(TradeWork *p);
void POKETRADE_NEGO_StepWaitWipeToBrowse(TradeWork *p);
void POKETRADE_NEGO_StepWipeToBrowse(TradeWork *p);
void POKETRADE_NEGO_StepSendReady(TradeWork *p);
void POKETRADE_NEGO_StepWaitReadySync(TradeWork *p);
void POKETRADE_NEGO_StepSendCheckResult(TradeWork *p);
void POKETRADE_NEGO_AbortHttpRequest(void *arg, u32 errorCode, u32 errorType, int dwcError);
void POKETRADE_NEGO_StepPollMonCheck(TradeWork *p);
void POKETRADE_NEGO_StepStartMonCheck(TradeWork *p);
void POKETRADE_NEGO_StepRetryMonCheck(TradeWork *p);
void POKETRADE_NEGO_StepBeginMonCheckWipe(TradeWork *p);
void POKETRADE_NEGO_StepResolveFinalAgree(TradeWork *p);
void POKETRADE_NEGO_StepSendFinalAgree(TradeWork *p);
void POKETRADE_NEGO_StepSendFinalReady(TradeWork *p);
void POKETRADE_NEGO_StepWaitMessageThenContinue(TradeWork *p);
void POKETRADE_NEGO_StepBeginFinalReady(TradeWork *p);
void POKETRADE_NEGO_StepFinalAgreeMenuChoice(TradeWork *p);
void POKETRADE_NEGO_StepOpenFinalAgreeMenu(TradeWork *p);
void POKETRADE_NEGO_StepWaitFinalMessage(TradeWork *p);
void POKETRADE_NEGO_StepBeginFinalWait(TradeWork *p);
void POKETRADE_NEGO_StepCancelMenuChoice(TradeWork *p);
void POKETRADE_NEGO_StepOpenCancelMenu(TradeWork *p);
void POKETRADE_NEGO_StepShowCancelMessage(TradeWork *p);
int POKETRADE_NEGO_IsMonOwnOffer(TradeWork *p,int a,int b);
int POKETRADE_NEGO_IsMonPeerSelected(TradeWork *p, int a, int b);
void POKETRADE_NEGO_StepWaitTouchRelease(TradeWork *p);
void POKETRADE_NEGO_StepSendOfferRemoval(TradeWork *p);
void POKETRADE_NEGO_InitOfferMarkers(TradeWork *p);
void POKETRADE_NEGO_SetOfferMarkersState(TradeWork *p, int a);
void POKETRADE_NEGO_UpdateOfferMarkers(TradeWork *p);
void POKETRADE_NEGO_PollMarkerTouch(TradeWork *p);
void POKETRADE_NEGO_TickMarkerTimers(TradeWork *p);
void POKETRADE_NEGO_FlashMarker(TradeWork *p, int a, int b);
void POKETRADE_NEGO_ResetMarkers(TradeWork *p);
void POKETRADE_NEGO_ExitMarkers(TradeWork *p);
void POKETRADE_NEGO_ShowOfferSlotMon(TradeWork *p,int i,void *v);
void POKETRADE_NEGO_TickOfferSlotTimers(TradeWork *p);
int POKETRADE_NEGO_SendOfferMon(TradeWork *p,void *src,int kind);
void POKETRADE_NEGO_PlaySeByKeyA(u32 key);
void POKETRADE_NEGO_PlaySeByKeyB(int key);
void POKETRADE_NEGO_PlaySeByEvent(int eventId, TradeWork *work);
/* END mkheaders: generated region */

#endif
