#ifndef GAME_OV175_WIFIBATTLEMATCH_CORE_H
#define GAME_OV175_WIFIBATTLEMATCH_CORE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifibattlematch_core.c, prototypes copied from their definitions. */

struct Proc;
struct WifiBattleMatchParams;
struct WifiBattleMatchNetTask;
struct WifibattlematchCallback;
struct WifiBattleMatchCompWork;
struct WifiBattleMatchStatRecord;
struct Party;
struct WifibattlematchNetSub;
struct WifiBattleMatchNetCtx;
struct WifiBattleMatchReportBlock;
struct GameData;
struct WifiBattleMatchReportPlayer;
struct WifiBattleMatchTeam;
struct RegDataA;
struct RegDataB;
struct WifibattlematchNetRecord;
struct NetErrRecord;
typedef struct WifibattlematchCallback WifibattlematchCallback;

#include "../types.h"
#include "../ov177/wifibattlematch_menu_types.h"
#include "../ov177/wifibattlematch_view_types.h"
#include "../ov175/wifibattlematch_net_types.h"
#include "../ov175/sake_types.h"

int WIFIBATTLEMATCH_NET_Create(void *a,void *b,void *obj,void *d);
int WIFIBATTLEMATCH_NET_Close(void *a,void *b,void *obj,void *d);
int WIFIBATTLEMATCH_NET_Other(void *a,void *b,void *obj,void *d);
int WIFIBATTLEMATCH_NET_TaskCreate(void *sys, int *state, struct WifiBattleMatchParams *params);
int WIFIBATTLEMATCH_NET_TaskDestroy(struct Proc *sys,int unused,int unused2,struct WifiBattleMatchNetTask *task);
int WIFIBATTLEMATCH_NET_TaskMain(unsigned sys,int *state,int unused,struct WifiBattleMatchNetTask *task);
void WIFIBATTLEMATCH_NET_TaskStepRouteByEntryState(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepMainMenu(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepRatingCheckPartyOnServer(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepRatingFetchGdbRecord(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepRatingMatchmake(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepRatingConfirmQuit(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepRatingSaveAndUploadQuit(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepFreeFinishAndSave(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepFreeConfirmQuit(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskCleanupA(WifibattlematchCallback *obj, int *unused, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskCleanupB(WifibattlematchCallback *a, int *pp, void *taskArg);
void WIFIBATTLEMATCH_NET_TaskStepPostPartyData(WifibattlematchCallback *sys, int *state, void *taskArg);
void WIFIBATTLEMATCH_NET_SetupBoxRecord(struct WifiBattleMatchNetTask *task, u32 mode);
void WIFIBATTLEMATCH_NET_DeleteBoxRecord(struct WifiBattleMatchNetTask *obj);
u32 WIFIBATTLEMATCH_NET_IsBoxReady(struct WifiBattleMatchNetTask *obj);
u32 WIFIBATTLEMATCH_NET_IsBoxAnimDone(struct WifiBattleMatchNetTask *obj);
void WIFIBATTLEMATCH_NET_SetupBoxAndWait(struct WifiBattleMatchNetTask *obj, u32 arg);
void WIFIBATTLEMATCH_NET_DeleteBoxAndWait(struct WifiBattleMatchNetTask *obj);
void WIFIBATTLEMATCH_NET_CreateRegCardWindow(struct WifiBattleMatchNetTask *task,const void *arg);
void WIFIBATTLEMATCH_NET_DeleteRegCard(struct WifiBattleMatchNetTask *obj);
int WIFIBATTLEMATCH_NET_IsRegCardReady(struct WifiBattleMatchNetTask *task);
int WIFIBATTLEMATCH_NET_GetSetBsubwayStat(void *save, u32 kind, struct WifiBattleMatchNetTask *obj);
void WIFIBATTLEMATCH_NET_IncBsubwayStat(void *a, int b, u32 c);
void WIFIBATTLEMATCH_NET_SetupChoiceMenu(struct WifiBattleMatchNetTask *task,int mode);
void WIFIBATTLEMATCH_NET_DeleteChoiceMenu(struct WifiBattleMatchNetTask *obj);
int WIFIBATTLEMATCH_NET_PollChoiceMenu(struct WifiBattleMatchNetTask *obj);
void WIFIBATTLEMATCH_NET_CopyBoxRecord(void *recordArg, struct WifiBattleMatchNetTask *task);
void WIFIBATTLEMATCH_NET_CopyBoxSave(void *recordArg, struct WifiBattleMatchNetTask *task);
void WIFIBATTLEMATCH_NET_CopyBsubwayStat(void *recordArg, struct WifiBattleMatchNetTask *task);
void WIFIBATTLEMATCH_NET_SetWaitCallback(struct WifiBattleMatchNetTask *obj, WifibattlematchCallbackFn fn);
u32 WIFIBATTLEMATCH_NET_PollWaitResult(struct WifiBattleMatchNetTask *obj);
int WIFIBATTLEMATCH_NET_VerifyPartySignature(void *recordArg, u16 heapId);
int WIFIBATTLEMATCH_NET_HandleCancel(struct WifiBattleMatchNetTask *obj, int trigger, int go);
void WIFIBATTLEMATCH_NET_ClearError(struct WifiBattleMatchNetTask *obj);
int WIFIBATTLEMATCH_NET_CompCreate(void *sys,int unused,struct WifiBattleMatchParams *params);
int WIFIBATTLEMATCH_NET_CompDestroy(struct Proc *sys,u32 unused,u32 arg,struct WifiBattleMatchCompWork *comp);
int WIFIBATTLEMATCH_NET_CompMain(unsigned sys,int *state,int unused,struct WifiBattleMatchCompWork *comp);
void WIFIBATTLEMATCH_NET_CompStepRouteByEntryState(WifibattlematchCallback *sys, int *unused, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepFetchRapPair(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepReconcileEntryState(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepRegisterParty(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepMainMenu(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepMatchmake(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepReportAndUploadResult(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle(WifibattlematchCallback *a, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepAskRetry(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepConfirmQuit(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepCheckPeriodThenSaveQuit(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompExit(WifibattlematchCallback *sys, int *unusedState, void *unusedWork);
void WIFIBATTLEMATCH_NET_CompCleanup(WifibattlematchCallback *obj, int *unused, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepCheckPeriod(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepWithdrawEntry(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_CompStepPostPartyData(WifibattlematchCallback *sys, int *state, void *compArg);
void WIFIBATTLEMATCH_NET_SetupCompStatusWindow(struct WifiBattleMatchCompWork *obj);
void WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(struct WifiBattleMatchCompWork *obj);
u32 WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(struct WifiBattleMatchCompWork *obj);
int WIFIBATTLEMATCH_NET_IsCompStatusWindowIdle(struct WifiBattleMatchCompWork *obj);
void WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait(struct WifiBattleMatchCompWork *obj);
void WIFIBATTLEMATCH_NET_DrawCompStatusWindow(struct WifiBattleMatchCompWork *obj, u32 arg);
void WIFIBATTLEMATCH_NET_StartRegCardAnim(struct WifiBattleMatchCompWork *obj, const WifiBattleMatchViewRecord *arg);
void WIFIBATTLEMATCH_NET_DeleteCompRegCard(struct WifiBattleMatchCompWork *obj);
u32 WIFIBATTLEMATCH_NET_IsCompRegCardReady(struct WifiBattleMatchCompWork *obj);
void WIFIBATTLEMATCH_NET_SetupCompPartyWindow(struct WifiBattleMatchCompWork *ctx);
void WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(struct WifiBattleMatchCompWork *obj);
int WIFIBATTLEMATCH_NET_IsCompPartyWindowReady(struct WifiBattleMatchCompWork *comp);
int WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(struct WifiBattleMatchCompWork *comp);
void WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(struct WifiBattleMatchCompWork *comp, int mode);
void WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(struct WifiBattleMatchCompWork *obj);
int WIFIBATTLEMATCH_NET_PollCompChoiceMenu(struct WifiBattleMatchCompWork *obj);
void WIFIBATTLEMATCH_NET_SetCompWaitCallback(struct WifiBattleMatchCompWork *obj, WifibattlematchCallbackFn fn);
u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(struct WifiBattleMatchCompWork *obj);
void WIFIBATTLEMATCH_NET_CopyCompBox(struct WifiBattleMatchStatRecord *dest, struct WifiBattleMatchCompWork *ctx);
void WIFIBATTLEMATCH_NET_CopyCompSave(struct WifiBattleMatchStatRecord *dst, struct WifiBattleMatchCompWork *obj);
void WIFIBATTLEMATCH_NET_CopyCompResponse(void *saveArg, void *responseArg);
u32 WIFIBATTLEMATCH_NET_VerifyCompSignature(void *objArg, void *list, u32 heapId);
int WIFIBATTLEMATCH_NET_CompareParty(struct Party *a, struct Party *b);
int WIFIBATTLEMATCH_NET_CompHandleCancel(struct WifiBattleMatchCompWork *obj, int trigger, int go);
void WIFIBATTLEMATCH_NET_CompClearError(struct WifiBattleMatchCompWork *obj);
int WIFIBATTLEMATCH_NET_GetSetCompStat(struct WifiBattleMatchCompWork *obj, struct WifibattlematchNetSub *rec);
/* END mkheaders: generated region */

#endif
