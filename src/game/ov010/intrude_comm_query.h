#ifndef GAME_OV010_INTRUDE_COMM_QUERY_H
#define GAME_OV010_INTRUDE_COMM_QUERY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intrude_comm_query.c, prototypes copied from their definitions. */

struct GameSystem;
struct GameComm;
struct BattleRecSlot;
struct GameData;
struct MyStatus;
typedef struct GameComm GameComm;

#include "../ov011/intrude_comm_types.h"
#include "../types.h"

int INTRUDE_COMM_CheckEntryAllowed(struct GameSystem *gameSystem);
IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(GameComm *comm);
int INTRUDE_COMM_GetPlayerNetId(GameComm *comm);
int INTRUDE_COMM_TogglePeerFlags(IntrudeCommSys *work, int mask, int unused);
struct BattleRecSlot *GAME_DATA_GetBattleRecSlotByNetId(struct GameData *gameData, u32 netId);
struct MyStatus *GAME_DATA_GetMyStatusByNetId(struct GameData *gameData, u32 netId);
IntrudeMemberEntry *INTRUDE_COMM_GetMemberEntry(IntrudeCommSys *work, int index);
u8 GAME_DATA_GetIntrudeIdByte(struct GameData *gameData);
u8 INTRUDE_COMM_GetUnionInfoReceived(IntrudeCommSys *work);
void *INTRUDE_COMM_GetReturnSlots(IntrudeCommSys *work);
int INTRUDE_COMM_GetAreaOwnerVersion(GameComm *comm);
int INTRUDE_COMM_GetAreaSlotFlag(GameComm *comm);
int INTRUDE_COMM_IsStepToOwnArea(GameComm *comm, struct GameData *gameData, int stepKind);
int INTRUDE_COMM_NormalizeVersion(int version, u32 trainerId);
int INTRUDE_COMM_GetAreaOwnerVersionClass(GameComm *comm, struct GameData *gameData);
int INTRUDE_COMM_IsListedId(u16 value);
int INTRUDE_COMM_HasUnlockFlags(struct GameData *gameData);
int INTRUDE_COMM_IsWarnedWithoutRequest(IntrudeCommSys *work);
int INTRUDE_COMM_GetVisitProgress(GameComm *comm);
void INTRUDE_COMM_SetCompleted(GameComm *comm);
int INTRUDE_COMM_GetRequestState(GameComm *comm);
int INTRUDE_COMM_CountEventPeers(GameComm *comm);
int INTRUDE_COMM_GetRequesterStatus(GameComm *comm, struct MyStatus *out);
int INTRUDE_COMM_IsSessionEndPending(GameComm *comm, int unused);
void INTRUDE_COMM_ClearHoldMode(GameComm *comm);
/* END mkheaders: generated region */

#endif
