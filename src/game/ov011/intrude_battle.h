#ifndef GAME_OV011_INTRUDE_BATTLE_H
#define GAME_OV011_INTRUDE_BATTLE_H
struct FieldMap;
struct MyStatus;

struct GameComm;
struct GameData;
struct VecFx32;
void INTRUDE_COMM_GetMarkerPosForPartner(struct GameComm *comm, struct GameData *gameData, struct VecFx32 *outPos);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of intrude_battle.c, prototypes copied from their definitions. */

struct IntrudeCommParam;
struct GameData;
struct IntrudeCommSys;
struct IntrudeZonePairInfo;
struct IntrudeJoinReply;
struct WordSet;
struct Proc;
struct IntrudePartyParam;
struct IntrudePartyWork;
struct GameEvent;
struct GameSystem;
typedef struct IntrudeCommParam IntrudeCommParam;
typedef struct IntrudeZonePairInfo IntrudeZonePairInfo;
typedef struct IntrudeJoinReply IntrudeJoinReply;
typedef struct IntrudePartyParam IntrudePartyParam;
typedef struct IntrudePartyWork IntrudePartyWork;

#include "../ov011/intrude_comm_types.h"
#include "../types.h"

int INTRUDE_COMM_PartyProcInit(struct Proc *proc, int unused, IntrudePartyParam *param);
int INTRUDE_COMM_PartyProcMain(void *proc, int *state, IntrudePartyParam *param, IntrudePartyWork *work);
int INTRUDE_LINK_ProcExit(void *procWork, int unused1, int unused2, IntrudeLinkProc *linkProc);
struct GameEvent *INTRUDE_LINK_CreateEvent(struct GameSystem *gameSystem, void *procArg);
int INTRUDE_LINK_EventMain(struct GameEvent *event, int *state, void *work);
u8 INTRUDE_COMM_GetPartnerSlot(void *comm, void *gameData);
int INTRUDE_COMM_RequestPartnerSymbolPage(IntrudeCommSys *linkState, u8 value);
u32 INTRUDE_COMM_IsPartnerSymbolPageReceived(IntrudeCommSys *linkState);
u8 *INTRUDE_COMM_GetPartnerSymbolPage(IntrudeCommSys *linkState);
void INTRUDE_COMM_SetPendingAreaNotice(IntrudeCommSys *linkState, u8 value);
int INTRUDE_COMM_ConsumeAreaNoticeSeen(IntrudeCommSys *linkState, int zoneId);
/* END mkheaders: generated region */

#endif
