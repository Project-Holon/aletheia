#ifndef GAME_OV018_INTRUDE_FIELD_H
#define GAME_OV018_INTRUDE_FIELD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intrude_field.c, prototypes copied from their definitions. */

struct FieldMap;
struct GameSystem;
struct FieldPlayer;
struct GameEvent;
struct EdgeBlockWork;
struct AreaChangeWork;
struct ExitConfirmWork;
struct NoticeEventWork;
struct GameComm;
struct IntrudeStartParam;
struct SymbolSpawnContext;
struct SymbolMonEntry;
struct GameData;
struct OfferEventWork;
typedef struct EdgeBlockWork EdgeBlockWork;
typedef struct AreaChangeWork AreaChangeWork;
typedef struct ExitConfirmWork ExitConfirmWork;
typedef struct NoticeEventWork NoticeEventWork;
typedef struct IntrudeStartParam IntrudeStartParam;
typedef struct SymbolSpawnContext SymbolSpawnContext;
typedef struct SymbolMonEntry SymbolMonEntry;
typedef struct OfferEventWork OfferEventWork;

#include "../ov011/intrude_comm_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../ov018/intrude_field_types.h"
#include "../ov010/fldmmdl_types.h"

void INTRUDE_FIELD_Update(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player);
int INTRUDE_FIELD_FindRemotePlayerAhead(IntrudeCommSys *work, struct FieldPlayer *player, int *outIndex);
struct GameEvent *INTRUDE_FIELD_CreateEdgeBlockTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, u16 moveDir, u16 edgeDir, int sessionBusy);
int INTRUDE_FIELD_TaskEdgeBlock(struct GameEvent *event, u32 *seq, EdgeBlockWork *work, u32 eventArg3);
struct GameEvent *INTRUDE_FIELD_CreateAreaChangeTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, u16 edgeDir);
int INTRUDE_FIELD_TaskAreaChange(struct GameEvent *event, u32 *seq, AreaChangeWork *work);
int INTRUDE_FIELD_CreateTileEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player);
struct GameEvent *INTRUDE_FIELD_CreateEdgeTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, int *posX, u16 moveDir, u16 facingDir);
struct GameEvent *INTRUDE_FIELD_CreateExitConfirmEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *work);
int INTRUDE_FIELD_EventExitConfirm(struct GameEvent *event, u32 *seq, ExitConfirmWork *work);
struct GameEvent *INTRUDE_FIELD_CreateNoticeEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
int INTRUDE_FIELD_EventNotice(struct GameEvent *event, u32 *seq, NoticeEventWork *work);
int INTRUDE_FIELD_IsAtAreaEdge(const VecFx32 *pos);
int INTRUDE_FIELD_IsInEdgeMargin(const VecFx32 *pos);
void INTRUDE_FIELD_UpdateCommState(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct GameComm *gameComm, struct FieldPlayer *player);
void INTRUDE_FIELD_StartCommAfterExit(struct GameSystem *gameSystem, int result);
void INTRUDE_FIELD_StartComm(struct GameSystem *gameSystem);
void INTRUDE_FIELD_UpdateAreaIndex(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player, IntrudeCommSys *work);
void INTRUDE_FIELD_ResetExtraAreaCount(int unusedArg0, int unusedArg1, IntrudeCommSys *work);
void INTRUDE_FIELD_AddAreaMaps(struct FieldMap *fieldMap, struct GameSystem *gameSystem, IntrudeCommSys *work);
void INTRUDE_FIELD_AddAreaMapCount(struct FieldMap *fieldMap, int count);
void INTRUDE_FIELD_ChangePlayerLook(IntrudeCommSys *work, struct GameSystem *gameSystem, int objCode, u8 kind, u8 flag);
int INTRUDE_FIELD_TryStartOfferEvent(struct GameSystem *gameSystem, IntrudeCommSys *work, struct FieldPlayer *player);
IntrudeZonePos *INTRUDE_FIELD_FindZonePos(u32 zoneId);
int INTRUDE_FIELD_GetZoneAnchor(int zoneId, VecFx32 *out);
void INTRUDE_FIELD_InitStartParam(IntrudeStartParam *param);
u8 INTRUDE_FIELD_GetStartKind(IntrudeStartParam *param);
void INTRUDE_FIELD_AddMmdl(struct FieldMap *fieldMap, u16 gridX, u16 gridZ, int height, u16 objCode, u16 eventId, u16 objId);
void INTRUDE_FIELD_AddAreaMmdls(struct FieldMap *fieldMap);
int INTRUDE_FIELD_IsDisconnectNeeded(struct GameSystem *gameSystem, int zoneId);
int INTRUDE_FIELD_IsStartRequested(IntrudeCommSys *work);
void INTRUDE_FIELD_SetSingleAreaMode(IntrudeCommSys *work);
u8 INTRUDE_FIELD_GetHostGender(struct GameComm *gameComm);
int INTRUDE_FIELD_IsListedZone(u32 zoneId);
void INTRUDE_FIELD_AddMarkerMmdl(struct FieldMap *fieldMap, u16 gridX, u16 gridZ, int height);
void INTRUDE_FIELD_AddMarkerMmdls(struct FieldMap *fieldMap);
void INTRUDE_FIELD_AddSymbolMonMmdl(const SymbolSpawnContext *spawn, const SymbolMonEntry *entry, u16 objId, u16 gridX, u16 gridZ, int height);
void INTRUDE_FIELD_GetMmdlParamPair(u32 *out, Mmdl *mmdl);
int INTRUDE_FIELD_GetMmdlParam0(Mmdl *mmdl);
void *INTRUDE_FIELD_CreateSymbolMon(int heapId, struct GameData *gameData, const SymbolMonEntry *entry);
void INTRUDE_FIELD_SpawnSymbolMons(struct FieldMap *fieldMap, int objIdBase, SymbolMonEntry *entries, int unused, int cellKind);
struct GameEvent *INTRUDE_FIELD_CreateOfferInfoEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *work, u16 senderNetId);
int INTRUDE_FIELD_EventOfferInfo(struct GameEvent *event, u32 *seq, OfferEventWork *work);
void INTRUDE_FIELD_InitPlayerSpin(PlayerSpinWork *spin, struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 objCode, u8 kind, u8 flag);
int INTRUDE_FIELD_StepPlayerSpin(PlayerSpinWork *spin, IntrudeCommSys *work);
/* END mkheaders: generated region */

#endif
