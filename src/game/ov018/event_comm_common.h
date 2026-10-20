#ifndef GAME_OV018_EVENT_COMM_COMMON_H
#define GAME_OV018_EVENT_COMM_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_comm_common.c, prototypes copied from their definitions. */

struct GameSystem;
struct ScriptWork;
struct GameEvent;
struct FieldMap;
struct FldMmdl;

#include "../ov018/event_comm_common_types.h"
#include "../types.h"
#include "../ov011/intrude_comm_types.h"
#include "../arm9/script_vm_types.h"

void EVENT_COMM_COMMON_InitMsgBox(EventCommMsgBox *msgBox, struct GameSystem *gameSystem);
void EVENT_COMM_COMMON_ExitMsgBox(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_SetupPrintWin(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_DeletePrintWin(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_PrintText(EventCommMsgBox *msgBox, void *text);
void EVENT_COMM_COMMON_PrintMsg(EventCommMsgBox *msgBox, u16 msgId);
void EVENT_COMM_COMMON_ClearPrintWin(EventCommMsgBox *msgBox);
int EVENT_COMM_COMMON_IsPrintFinished(EventCommMsgBox *msgBox);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_SetupListWindow(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_DeleteListWindow(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_PrintToWindow(EventCommMsgBox *msgBox, void *msgData, void *window, unsigned int msgId, int x, int y);
void EVENT_COMM_COMMON_PrintListWindow(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y);
void EVENT_COMM_COMMON_DeleteChoice(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_StartChoice(EventCommMsgBox *msgBox, struct GameSystem *gameSystem);
int EVENT_COMM_COMMON_PollChoice(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_SetupListWindowB(EventCommMsgBox *msgBox, struct GameSystem *gameSystem, int x, int y, int width, int height);
void EVENT_COMM_COMMON_PrintListWindowB(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y);
void EVENT_COMM_COMMON_DeleteListWindowB(EventCommMsgBox *msgBox);
int EVENT_COMM_COMMON_GetMissionState(IntrudeSession *session);
int EVENT_COMM_COMMON_GetPeerTalkStatus(IntrudeCommSys *sys, u8 netId);
int EVENT_COMM_COMMON_CmdCallExitSyncEvent(ScriptVm *vm, struct ScriptWork *scriptWork);
struct GameEvent *EVENT_COMM_COMMON_CreateExitSyncEvent(struct GameSystem *gameSystem, u16 *result);
int EVENT_COMM_COMMON_ExitSyncEventMain(struct GameEvent *event, int *seq, void *wk);
int EVENT_COMM_COMMON_CmdGetObjCode(ScriptVm *vm, struct ScriptWork *scriptWork);
int EVENT_COMM_COMMON_CmdCheckMissionInfoPending(ScriptVm *vm, struct ScriptWork *scriptWork);
int EVENT_COMM_COMMON_CmdCallMissionInfoEvent(ScriptVm *vm, struct ScriptWork *scriptWork);
struct GameEvent *EVENT_COMM_COMMON_CreateMissionInfoEvent(struct GameSystem *gameSystem);
int EVENT_COMM_COMMON_MissionInfoEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_FreeMissionInfoWork(EventCommMsgBox *msgBox);
struct GameEvent *EVENT_COMM_COMMON_CreateReturnPalaceEvent(struct GameSystem *gameSystem);
int EVENT_COMM_COMMON_ReturnPalaceEventMain(struct GameEvent *event, int *seq, void *wk);
int EVENT_COMM_COMMON_CmdGetIntrudeDistance(ScriptVm *vm, struct ScriptWork *scriptWork);
int EVENT_COMM_COMMON_CmdCheckBattleRecState(ScriptVm *vm, struct ScriptWork *scriptWork);
struct GameEvent *EVENT_COMM_COMMON_CreateTalkStartEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, void *unused, struct FldMmdl *playerMmdl, int netId, u16 heapId);
int EVENT_COMM_COMMON_TalkStartEventMain(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *EVENT_COMM_COMMON_CreateTalkEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId);
struct GameEvent *EVENT_COMM_COMMON_CreateTalkedStartEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId);
int EVENT_COMM_COMMON_TalkedStartEventMain(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *EVENT_COMM_COMMON_CreateTalkedEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId);
void EVENT_COMM_COMMON_InitCommonWork(struct GameSystem *gameSystem, IntrudeCommSys *sys, EventCommCommonWork *work, struct FieldMap *fieldMap, struct FldMmdl *playerMmdl, int netId, u16 heapId);
void EVENT_COMM_COMMON_ExitCommonWork(IntrudeCommSys *sys, EventCommCommonWork *work);
int EVENT_COMM_COMMON_TalkEventMain(struct GameEvent *event, int *seq, void *wk);
int EVENT_COMM_COMMON_TalkedEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkTypeEvent(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys);
void EVENT_COMM_COMMON_ChangeTalkedTypeEvent(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys);
int EVENT_COMM_COMMON_GetTalkType(EventCommCommonWork *work, IntrudeCommSys *sys);
struct GameEvent *EVENT_COMM_COMMON_CreateMissionResultEvent(struct GameSystem *gameSystem, int showResult);
int EVENT_COMM_COMMON_MissionResultEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkMsgEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkMsgEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedMsgEvent(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_ChangeTalkPowerGiftTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkPowerGiftTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkPowerGiftAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkPowerGiftAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedPowerGiftAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedPowerGiftAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedPowerGiftTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedPowerGiftTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkPowerShareTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkPowerShareTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkPowerShareAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkPowerShareAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedPowerShareAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedPowerShareAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedPowerShareTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedPowerShareTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkBattleTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_BattleRequestEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkBattleAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_BattleAnswerEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedBattleAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_ChangeTalkedBattleTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_ChangeTalkSearchTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkSearchTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkSearchAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkSearchAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedSearchAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedSearchAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedSearchTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedSearchTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeSearchFoundEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_SearchFoundEventMain(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *EVENT_COMM_COMMON_CreateSupportMsgEvent(struct GameSystem *gameSystem, u32 heapId);
int EVENT_COMM_COMMON_SupportMsgEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkGreetingTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkGreetingTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkGreetingAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkGreetingAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedGreetingAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedGreetingAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedGreetingTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedGreetingTargetEventMain(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *EVENT_COMM_COMMON_CreateOfferEvent(struct GameSystem *gameSystem, IntrudeCommSys *sys, IntrudeMemberRecord *offer);
int EVENT_COMM_COMMON_OfferEventMain(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *EVENT_COMM_COMMON_CreateOfferAnswerEvent(struct GameSystem *gameSystem, IntrudeMemberRecord *offer);
int EVENT_COMM_COMMON_OfferAnswerEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkItemSaleEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_ItemSaleEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkItemPurchaseEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_ItemPurchaseEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedItemSaleEvent(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_ChangeTalkedItemPurchaseEvent(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent(struct GameEvent *event, EventCommCommonWork *src, u16 *msgIds);
int EVENT_COMM_COMMON_MsgEventMain(struct GameEvent *event, int *seq, void *eventWork);
void EVENT_COMM_COMMON_StartMsgEvent95(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent105(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110ByKindA(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110ByKindB(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110Alt(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgScriptEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_MsgScriptEventMain(struct GameEvent *event, int *seq, void *eventWork);
/* END mkheaders: generated region */

#endif
