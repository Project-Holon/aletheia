#ifndef GAME_OV012_UNION_SCENE_H
#define GAME_OV012_UNION_SCENE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_subproc.c, prototypes copied from their definitions. */

struct GameSystem;
struct UnionSubEventWork;
struct FieldMap;
struct GameEvent;
struct PartyListParam;
struct BattleSelectParam;
typedef struct UnionSubEventWork UnionSubEventWork;
typedef struct PartyListParam PartyListParam;
typedef struct BattleSelectParam BattleSelectParam;

#include "../ov012/union_comm_types.h"
#include "../types.h"
#include "../ov006/event_wificlub_types.h"

struct GameEvent *UNION_SCENE_CreateSubEvent(struct GameSystem *gameSystem, void *fieldMap, UnionRoomWork *work);
int UNION_SCENE_SubEventMain(struct GameEvent *event, int *seq, void *work);
void UNION_SCENE_RequestScene(UnionRoomWork *unionRoom, int sceneId, void *sceneParam);
int UNION_SCENE_IsScenePending(UnionRoomWork *unionRoom);
int UNION_SCENE_StepStartOv111Proc(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, void *procWork, void *event, struct GameEvent **outEvent, u8 *step);
int UNION_SCENE_StepPokemonTrade(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, ClubTradeParam *tradeParam, void *event, struct GameEvent **outEvent, u8 *step);
int UNION_SCENE_StepGroupActivity(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, void *param, struct GameEvent *event, struct GameEvent **outEvent, u8 *step);
int UNION_SCENE_StepWarpToZone96AtSeat(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, void *param, void *event, struct GameEvent **outEvent, u8 *step);
int UNION_SCENE_StepWarpToZone97AtSeat(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, void *param, void *event, struct GameEvent **outEvent, u8 *step);
int UNION_SCENE_StepWarpToZone1A6(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, void *param, void *event, struct GameEvent **outEvent, u8 *step);
int UNION_SCENE_StepColosseumPartyEntry(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, PartyListParam *listParam, struct GameEvent *event, struct GameEvent **outEvent, u8 *step);
u32 UNION_SCENE_StepStartBattleSelect(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, BattleSelectParam *selectParam, void *event, struct GameEvent **outEvent, u8 *step);
int UNION_SCENE_StepStartPmsInput(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, void *procWork, void *event, struct GameEvent **outEvent, u8 *step);
/* END mkheaders: generated region */

#endif
