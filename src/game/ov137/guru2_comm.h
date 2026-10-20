#ifndef GAME_OV137_GURU2_COMM_H
#define GAME_OV137_GURU2_COMM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of guru2_comm.c, prototypes copied from their definitions. */

struct Guru2Comm;
struct Guru2Session;

#include "../types.h"

struct Guru2Comm *GURU2_COMM_Create(struct Guru2Session *session,int heap);
void GURU2_COMM_Destroy(struct Guru2Comm *p);
void GURU2_COMM_RegisterCommands(void *work);
void GURU2_COMM_Exit(struct Guru2Comm *p);
int GURU2_COMM_SendWithHeader(struct Guru2Comm *p,u32 id,const void *data,u32 size);
int GURU2_COMM_Send(struct Guru2Comm *p,u32 id,const void *data,u32 size);
void GURU2_COMM_RecvPartyData(int netId,int unused,void *data,struct Guru2Comm *p);
void GURU2_COMM_RecvSessionClosed(int netId,int size,int data,struct Guru2Comm *p);
void GURU2_COMM_RecvJoinRequest(int netId,int size,u8 *data,struct Guru2Comm *p);
void GURU2_COMM_RecvParentNotice(int netId,int size,int data,struct Guru2Comm *p);
int GURU2_COMM_GetOwnPlayerId(void);
void GURU2_COMM_RecvMemberCount(int netId,int size,u8 *data,struct Guru2Comm *p);
void GURU2_COMM_RecvStatusFlags(int netId,int size,u16 *data,struct Guru2Comm *p);
void GURU2_COMM_RecvPlayerReady(int netId,int size,void *data,struct Guru2Comm *p);
void GURU2_COMM_RecvSlotAssignment(int netId,int size,void *data,struct Guru2Comm *p);
void GURU2_COMM_RecvPlayerCount(int netId,int size,int *data,struct Guru2Comm *p);
void GURU2_COMM_RecvPlayerInput(int netId,int size,u8 *data,struct Guru2Comm *p);
void GURU2_COMM_RecvRoundResult(int netId,int size,void *data,struct Guru2Comm *p);
void GURU2_COMM_RecvSelectedSlot(int netId,int size,int *data,struct Guru2Comm *p);
void GURU2_COMM_RecvAngles(int netId,int size,void *data,struct Guru2Comm *p);
void GURU2_COMM_RecvAbortVote(int netId,int size,void *data,struct Guru2Comm *p);
void GURU2_COMM_RecvContinueVote(int netId,int size,void *data,struct Guru2Comm *p);
void *GURU2_COMM_GetRecvBuffer(int index,struct Guru2Comm *p);
void *GURU2_COMM_GetPartyCopy(struct Guru2Comm *p, int i);
/* END mkheaders: generated region */

#endif
