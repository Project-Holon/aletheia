#ifndef GAME_OV012_COLOSSEUM_COMM_COMMAND_H
#define GAME_OV012_COLOSSEUM_COMM_COMMAND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of colosseum_comm_command.c, prototypes copied from their definitions. */

struct GameData;
struct MyStatus;
struct GameSystem;
struct ColosseumBattleInfo;
struct ColosseumBattleMember;
typedef struct ColosseumBattleInfo ColosseumBattleInfo;
typedef struct ColosseumBattleMember ColosseumBattleMember;

#include "../ov012/union_comm_types.h"
#include "../types.h"
#include "../ov010/comm_player_types.h"

void COLOSSEUM_AddCommandTable(UnionRoomWork *unionRoom);
u8 *COLOSSEUM_GetRecvBuffer(int netId, u8 *buffer, int size);
void COLOSSEUM_NoOp(void);
void COLOSSEUM_RecvPlayerEntry(u32 netId, u32 size, void *data, UnionRoomWork *unionWork);
u32 COLOSSEUM_SendPlayerEntry(const void *data, u32 toParent);
void COLOSSEUM_RecvTrainerCard(u32 netId, u32 size, void *data, UnionRoomWork *unionWork);
int COLOSSEUM_SendTrainerCard(const void *data);
void COLOSSEUM_RecvPackage(u32 netId, u32 size, void *data, UnionRoomWork *unionWork);
u32 COLOSSEUM_SendPackage(const void *package);
void COLOSSEUM_RecvChoiceRequest(u32 netId, u32 size, u8 *data, UnionRoomWork *unionWork);
u32 COLOSSEUM_SendChoiceRequest(ColosseumWork *work);
void COLOSSEUM_RecvChoiceReply(u32 netId, u32 size, u32 *data, UnionRoomWork *unionWork);
int COLOSSEUM_SendChoiceReply(ColosseumWork *work, u32 netId, u32 result);
void COLOSSEUM_RecvParty(u32 netId, u32 size, void *data, UnionRoomWork *unionWork);
u32 COLOSSEUM_SendParty(const void *party);
void COLOSSEUM_RecvBattlePositions(int netId, u32 size, void *data, UnionRoomWork *unionWork);
int COLOSSEUM_SendBattlePositions(const void *positions);
void COLOSSEUM_RecvReady(int netId,int size,int data,UnionRoomWork *unionWork);
u32 COLOSSEUM_SendReady(void);
void COLOSSEUM_RecvReadyCancel(int netId, int size, int data, UnionRoomWork *unionWork);
u32 COLOSSEUM_SendReadyCancel(void);
void COLOSSEUM_RecvCancelAck(int netId,int size,int data,UnionRoomWork *unionWork);
u32 COLOSSEUM_SendCancelAck(int netId);
void COLOSSEUM_RecvAllReady(int netId,int size,int data,UnionRoomWork *unionWork);
u32 COLOSSEUM_SendAllReady(void);
void COLOSSEUM_RecvConfirm(int netId, int size, int data, UnionRoomWork *unionWork);
void COLOSSEUM_RecvFinish(int netId, int size, int data, UnionRoomWork *unionWork);
int COLOSSEUM_SendFinish(void);
/* END mkheaders: generated region */

#endif
