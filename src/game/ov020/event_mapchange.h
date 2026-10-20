#ifndef GAME_OV020_EVENT_MAPCHANGE_H
#define GAME_OV020_EVENT_MAPCHANGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_mapchange.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct GameInitWork;
struct FirstStartWork;
struct NewGameStartWork;
struct ContinueWork;
struct ChangeFieldWork;
struct EventDataSystem;
typedef struct GameInitWork GameInitWork;
typedef struct FirstStartWork FirstStartWork;
typedef struct NewGameStartWork NewGameStartWork;
typedef struct ContinueWork ContinueWork;
typedef struct ChangeFieldWork ChangeFieldWork;

#include "../ov020/event_mapchange_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../arm9/zonedata_types.h"
#include "../ov010/fld_btl_inst_tool_shared_types.h"

int EVENT_MAPCHANGE_CallHookAndInvert(void (*hook)(void));
struct GameEvent *EVENT_MAPCHANGE_CreateByMode(struct GameSystem *gameSystem, GameInitWork *initWork);
int EVENT_MAPCHANGE_FirstStartEvent(struct GameEvent *event, int *seq, FirstStartWork *work);
struct GameEvent *EVENT_MAPCHANGE_CreateFirstStartEvent(struct GameSystem *gameSystem, GameInitWork *initWork);
void EVENT_MAPCHANGE_InitUnionInfo(struct GameSystem *gameSystem);
int EVENT_MAPCHANGE_NewGameStartEvent(struct GameEvent *event, int *seq, NewGameStartWork *work);
struct GameEvent *EVENT_MAPCHANGE_CreateNewGameStartEvent(struct GameSystem *gameSystem);
void EVENT_MAPCHANGE_RefreshUnionInfo(struct GameSystem *gameSystem);
int EVENT_MAPCHANGE_ContinueEvent(struct GameEvent *event, int *seq, ContinueWork *work);
struct GameEvent *EVENT_MAPCHANGE_CreateContinueEvent(struct GameSystem *gameSystem, GameInitWork *initWork);
void EVENT_MAPCHANGE_CheckSeasonChange(MapChangeWork *work);
void EVENT_MAPCHANGE_SetupExitEntranceParam(MapChangeWork *work, struct GameEvent *event);
void EVENT_MAPCHANGE_SetupEnterEntranceParam(MapChangeWork *work, struct GameEvent *event);
int EVENT_MAPCHANGE_ChangeFieldEvent(struct GameEvent *event, int *seq, ChangeFieldWork *changeField);
struct GameEvent *EVENT_MAPCHANGE_CreateChangeFieldEvent(MapChangeWork *work, int changeKind);
int EVENT_MAPCHANGE_EntranceEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_EntranceCommEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_DetachedTailEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_FadeEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_FadeDelayedEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_TargetPositionEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_SeasonEffectAEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_SeasonEffectBEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_ResetPlayerFormEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_FadeWaitEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_FadeDetachEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_EffectCEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_SwapCommOverlayEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_RunFixedZoneEvent(GameEvent *event, int *state, MapChangeWork *work);
void EVENT_MAPCHANGE_InitWork(MapChangeWork *work, GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateWarpEvent(GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId, const VecFx32 *pos, u16 dir, int seasonFadeAllowed);
GameEvent *EVENT_MAPCHANGE_CreateRailWarpEvent(GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);
GameEvent *EVENT_MAPCHANGE_CreateRailWarpEventWithTransition(GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventWithTargetPos(GameSystem *gameSystem, FieldMap *fieldMap, const VecFx32 *targetPos, u16 zoneId, const VecFx32 *pos);
GameEvent *EVENT_MAPCHANGE_CreateDigEscapeEvent(int unused, GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateEscapeRopeEvent(GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateSituationWarpEvent(GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateSpecialLocationWarpEvent(GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateZoneStartWarpEvent(GameSystem *gameSystem, u16 zoneId);
GameEvent *EVENT_MAPCHANGE_CreateFixedExitTypeWarpEvent(GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId, const VecFx32 *pos, u16 dir);
GameEvent *EVENT_MAPCHANGE_CreateFixedZoneEvent(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_MAPCHANGE_CreateSpecialLocationEvent(GameSystem *gameSystem, u8 *unusedPos);
GameEvent *EVENT_MAPCHANGE_CreateIntrudeWarpEvent(GameSystem *gameSystem, u16 zoneId, VecFx32 *pos, int requestSession);
GameEvent *EVENT_MAPCHANGE_CreateIntrudeReturnEvent(GameSystem *gameSystem);
void EVENT_MAPCHANGE_GetCurrentLocation(Location *location, FieldMap *fieldMap);
GameEvent *EVENT_MAPCHANGE_CreateExitWarpEvent(GameSystem *gameSystem, FieldMap *fieldMap, void *connectData, int exitDir);
GameEvent *EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate(GameSystem *gameSystem, FieldMap *fieldMap, void *connectData, int exitDir);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventWithTransition(GameSystem *gameSystem, FieldMap *fieldMap, int transitionType, u16 zoneId, const VecFx32 *pos, u16 dir);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId, const VecFx32 *pos, u16 dir);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventToLocation(GameSystem *gameSystem, FieldMap *fieldMap, int unused2, const Location *location, u16 dir);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventPlain(GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId, const VecFx32 *pos, short dir);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(GameSystem *gameSystem, u16 zoneId, const VecFx32 *pos);
void EVENT_MAPCHANGE_InitFieldFromSituationWarp(GameSystem *gameSystem);
int EVENT_MAPCHANGE_RunSituationWarpArrivalEvent(GameEvent *event, int *state, WarpIdArrivalWork *work);
GameEvent *EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent(GameSystem *gameSystem);
int EVENT_MAPCHANGE_DirToAngle(int dir);
void EVENT_MAPCHANGE_ResolveLocation(struct EventDataSystem *eventData, Location *source, Location *dest);
void EVENT_MAPCHANGE_ApplyLocation(GameSystem *gameSystem, Location *warpLocation);
void EVENT_MAPCHANGE_AddEventDataMmdl(GameData *gameData, const Location *location);
void EVENT_MAPCHANGE_AddWfbcMmdl(GameData *gameData, const Location *location);
void EVENT_MAPCHANGE_DeleteAllMmdl(GameData *gameData);
void EVENT_MAPCHANGE_ReloadMmdl(GameData *gameData, const Location *location);
void EVENT_MAPCHANGE_SetMapEffectMask(GameData *gameData, u16 zoneId);
void EVENT_MAPCHANGE_UpdateFieldStateForZone(GameSystem *gameSystem, u16 zoneId);
void EVENT_MAPCHANGE_DeleteAllMmdlOfSystem(GameSystem *gameSystem);
void EVENT_MAPCHANGE_SetPlayerVanish(FieldMap *fieldMap, unsigned int vanish);
void EVENT_MAPCHANGE_ApplyZoneTableEntry(GameData *gameData, int zoneId);
GameEvent *EVENT_MAPCHANGE_CreateIntrudeSessionEvent(GameSystem *gameSystem, FieldMap *fieldMap, Location *location, int requestSession, int intrudeId);
GameEvent *EVENT_MAPCHANGE_CreateIntrudeArriveEvent(GameSystem *gameSystem, FieldMap *fieldMap, Location *location);
int EVENT_MAPCHANGE_RunIntrudeArriveEvent(GameEvent *event, int *state, MapChangeIntrudeWork *work);
int EVENT_MAPCHANGE_RunIntrudeSessionEvent(GameEvent *event, int *state, MapChangeIntrudeWork *work);
void EVENT_MAPCHANGE_UpdateEscapeLocation(GameData *gameData, const Location *destination);
void EVENT_MAPCHANGE_CopySpecialLocation(GameData *gameData, Location *out);
void EVENT_MAPCHANGE_ResetPlayerObjectCode(GameData *gameData);
void EVENT_MAPCHANGE_AddPresetMail(GameData *gameData);
void EVENT_MAPCHANGE_StartSeasonEffect(GameData *gameData);
void *EVENT_MAPCHANGE_TamperLeakA(void);
void *EVENT_MAPCHANGE_TamperLeakB(void);
void EVENT_MAPCHANGE_NopHook(void);
/* END mkheaders: generated region */

#endif
