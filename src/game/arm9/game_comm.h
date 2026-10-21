#ifndef GAME_ARM9_GAME_COMM_H
#define GAME_ARM9_GAME_COMM_H

#include "../types.h"

typedef struct GameComm GameComm;
typedef struct GameCommSeq GameCommSeq;
typedef struct GameCommInfoMessage GameCommInfoMessage;

/* Exit callback of GAME_COMM_RequestExit: called with the two words the exit request carries. */
typedef void (*GameCommExitFunc)(u32 arg0, u32 arg1);
void GAME_COMM_RequestExit(GameComm *comm, GameCommExitFunc exitFunc, u32 exitArg);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of game_comm.c, prototypes copied from their definitions. */

struct VecSet;
struct GameComm;
struct GameData;
struct GameCommSeq;
struct GameCommInfoMessage;
typedef struct GameComm GameComm;
typedef struct GameCommSeq GameCommSeq;
typedef struct GameCommInfoMessage GameCommInfoMessage;

#include "../types.h"

struct VecSet *GAME_COMM_Create(u32 heapId, void *gameData);
void GAME_COMM_Delete(struct VecSet *obj);
void GAME_COMM_Update(GameComm *p);
void GAME_COMM_CallHandler(GameComm *comm, u32 arg);
void GAME_COMM_CallKindNotify(GameComm *comm, u32 arg);
void GAME_COMM_Start(GameComm *comm, u32 kind, u32 param);
void GAME_COMM_RequestExitNoCallback(GameComm *comm);
void GAME_COMM_RequestExit(GameComm *comm, GameCommExitFunc exitFunc, u32 exitArg);
u32 GAME_COMM_GetKind(const GameComm *comm);
u32 GAME_COMM_IsTransition(const GameComm *comm);
void *GAME_COMM_GetWork(const GameComm *comm);
struct GameData *GAME_COMM_GetGameData(const GameComm *comm);
u32 GAME_COMM_GetLastKind(const GameComm *comm);
void GAME_COMM_SetCounter(GameComm *comm, u32 value);
void GAME_COMM_ClearCounter(GameComm *comm);
u32 GAME_COMM_GetCounter(const GameComm *comm);
void GAME_COMM_SetSeqState(GameCommSeq *seq, u32 state);
void GAME_COMM_SetNotifyFlag(GameComm *comm, u32 flag);
u32 GAME_COMM_GetNotifyFlag(const GameComm *comm);
void GAME_COMM_UpdatePlayerStatus(GameComm *comm, int netId, u16 zoneId, u8 palaceNetId, u32 fieldStatus, int quiet);
void GAME_COMM_ClearPlayerStatus(GameComm *comm);
void GAME_COMM_PushInfoMessage(GameComm *comm, u32 netId0, u32 netId1, u32 messageId);
int GAME_COMM_PopInfoMessage(GameComm *comm, GameCommInfoMessage *message);
void GAME_COMM_ClearInfoMessages(GameComm *comm);
void GAME_COMM_PushPairMessage(GameComm *comm, u32 netId0, u32 netId1);
void GAME_COMM_PushPalaceMessage(GameComm *comm, u32 netId, u32 palaceNetId);
void GAME_COMM_PushPlayerMessage(GameComm *comm, u32 netId);
/* END mkheaders: generated region */

#endif
