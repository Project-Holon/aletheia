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
/* END mkheaders: generated region */

#endif
