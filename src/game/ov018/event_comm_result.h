#ifndef GAME_OV018_EVENT_COMM_RESULT_H
#define GAME_OV018_EVENT_COMM_RESULT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_comm_result.c, prototypes copied from their definitions. */

struct GameSystem;
struct ScriptWork;
struct GameEvent;
struct FieldMap;
struct FldMmdl;

#include "../ov018/event_comm_common_types.h"
#include "../types.h"
#include "../ov011/intrude_comm_types.h"
#include "../arm9/script_vm_types.h"

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
/* END mkheaders: generated region */

#endif
