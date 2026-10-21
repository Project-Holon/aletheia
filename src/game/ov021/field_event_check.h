#ifndef GAME_OV021_FIELD_EVENT_CHECK_H
#define GAME_OV021_FIELD_EVENT_CHECK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_event_check.c, prototypes copied from their definitions. */

struct FieldEventInput;
struct GameEvent;
struct Mmdl;
typedef struct FieldEventInput FieldEventInput;

#include "../ov020/event_mapchange_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../arm9/zonedata_types.h"

int FIELDMAP_GetHeapSizeForMapType(int zoneId);
int FIELD_EVENT_CHECK_CheckGridEvents(void *gameSystem, FieldMap *fieldMap, int *outResetEncount, int *outMenuRequest);
int FIELD_EVENT_CHECK_RunGrid(void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckCommEvents(void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_RunRail(void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckRailEvents(void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_Run(void *gameSystem, FieldMap *fieldMap, u32 unusedC, u32 unusedD);
void FIELD_EVENT_CHECK_InitInput(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
void FIELD_EVENT_CHECK_StopSoundAfterEvent(void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_AddStepRecord(void *gameData);
int FIELD_EVENT_CHECK_StartPendingScript(FieldEventInput *input);
int FIELD_EVENT_CHECK_CheckPosEventAtPlayer(FieldEventInput *input);
int FIELD_EVENT_CHECK_CheckPosEventForDir(FieldEventInput *input, int dir);
int FIELD_EVENT_CHECK_CheckPosEventFacing(FieldEventInput *input);
int FIELD_EVENT_CHECK_CheckPosEventHeldDir(FieldEventInput *input);
void *FIELD_EVENT_CHECK_CheckIntrudeEdge(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckPosEventCenterTile(FieldEventInput *input);
int FIELD_EVENT_CHECK_CheckStepEvents(FieldEventInput *input, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_GetEggCycleDecrement(void *party);
void FIELD_EVENT_CHECK_DecrementEggCycles(void *party);
void FIELD_EVENT_CHECK_UpdateEggStepCounter(void *gameData, void *party);
int FIELD_EVENT_CHECK_IsEggReadyToHatch(void *party);
int FIELD_EVENT_CHECK_CheckEggHatch(FieldEventInput *input, FieldMap *fieldMap, void *gameSystem, void *gameData);
void FIELD_EVENT_CHECK_UpdateWalkFriendship(void *gameData, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckZoneStepMessage(void *gameSystem, FieldMap *fieldMap, u16 zoneId);
int FIELD_EVENT_CHECK_CheckMovePokemonCooldown(FieldMap *fieldMap, void *gameSystem, void *gameData);
int FIELD_EVENT_CHECK_CheckStepEncount(FieldMap *fieldMap, void *gameSystem, void *gameData);
struct GameEvent *FIELD_EVENT_CHECK_CreateGPowerExpireEvent(void *gameSystem);
int FIELD_EVENT_CHECK_CheckGridConnect(FieldEventInput *input, FieldMap *fieldMap, VecFx32 *pos);
void *FIELD_EVENT_CHECK_CheckTileMoveTask(FieldEventInput *input, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_StartConnectEvent(FieldEventInput *input, FieldMap *fieldMap, int connectId, VecFx32 *pos);
void FIELD_EVENT_CHECK_SetEntranceFromGridConnect(FieldEventInput *input, int connectId, VecFx32 *pos);
u32 FIELD_EVENT_CHECK_FindGridConnectId(FieldEventInput *input, VecFx32 *pos);
void FIELD_EVENT_CHECK_GetFrontPos(FieldEventInput *input, VecFx32 *out);
int FIELD_EVENT_CHECK_IsConnectOnFootType(void *connect);
int FIELD_EVENT_CHECK_IsConnectExitDir(void *connect, int dir);
int FIELD_EVENT_CHECK_CheckGridConnectFront(FieldEventInput *input, int unused, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckFrontTileEvents(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckRailConnect(FieldEventInput *input, void *unused, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckRailConnectFront(FieldEventInput *input, void *unused, FieldMap *fieldMap, RailLocation *frontLocation);
int FIELD_EVENT_CHECK_CheckWildEncount(FieldEventInput *input, void *unused, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckRailSignBoard(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
void FIELD_EVENT_CHECK_SetEntranceFromRailConnect(FieldEventInput *input, int connectId, RailLocation *location);
int FIELD_EVENT_CHECK_StartRailConnectEvent(FieldEventInput *input, FieldMap *fieldMap, int connectId, RailLocation *location);
int FIELD_EVENT_CHECK_IsRailFrontFree(void *player, FieldEventInput *input);
int FIELD_EVENT_CHECK_LedgeJumpTaskMain(struct GameEvent *task, u32 *seq, void *arg);
struct GameEvent *FIELD_EVENT_CHECK_CreateLedgeJumpTask(int unused, void *gameSystem, FieldMap *fieldMap, int dir, int jumpTwoTiles);
int FIELD_EVENT_CHECK_CheckLedgeJump(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
struct Mmdl *FIELD_EVENT_CHECK_SearchGridFrontMmdl(FieldEventInput *input, FieldMap *fieldMap);
struct Mmdl *FIELD_EVENT_CHECK_SearchRailFrontMmdl(FieldEventInput *input, FieldMap *fieldMap);
u16 FIELD_EVENT_CHECK_GetFrontTileMessage(FieldEventInput *input, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_FindPartyMemberWithMove(void *gameData, u32 move);
int FIELD_EVENT_CHECK_CountAlivePartyMembers(void *gameSystem);
int FIELD_EVENT_CHECK_IsLedgePathClear(FieldEventInput *input, FieldMap *fieldMap);
/* END mkheaders: generated region */

#endif
