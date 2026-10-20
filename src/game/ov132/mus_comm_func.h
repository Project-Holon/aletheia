#ifndef GAME_OV132_MUS_COMM_FUNC_H
#define GAME_OV132_MUS_COMM_FUNC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mus_comm_func.c, prototypes copied from their definitions. */

struct ActingHost;
struct Context;

#include "../types.h"

void MUS_COMM_FUNC_Create(int unused, void *icaCtx, void *comm, int useExistingSession);
void MUS_COMM_FUNC_Delete(char *p);
void *MUS_COMM_FUNC_StartSession(int unused,char *p);
int MUS_COMM_FUNC_UpdateNetState(int *state,u8 *p);
int MUS_COMM_FUNC_WaitSessionNull(int unused,int unused1,void *p);
void MUS_COMM_FUNC_Task(int unused,int unused1,char *p);
void MUS_COMM_FUNC_SetHostFlag(char *p);
void MUS_COMM_FUNC_InitCommandTable(char *p);
void MUS_COMM_FUNC_InitWork(u8 *p, void *myStatusSrc, void *boxParamSrc, void *unused, void *hostEntry, u16 heap);
void MUS_COMM_FUNC_DeleteBuffers(char *p);
void MUS_COMM_FUNC_SetReady(char *p);
void MUS_COMM_FUNC_Update(char *p);
void MUS_COMM_FUNC_SetTimingSync(int unused, int timingId);
int MUS_COMM_FUNC_CheckTimingSync(char *p,int id);
int MUS_COMM_FUNC_GetSlotValueA(char *p,u32 index);
int MUS_COMM_FUNC_GetSlotValueB(char *p,u32 index);
char *MUS_COMM_FUNC_GetRecordPtr(char *p);
u32 MUS_COMM_FUNC_GetRecordSize(void);
int MUS_COMM_FUNC_Equals(int lhs,int rhs);
u32 MUS_COMM_FUNC_SendCommand(char *unused, int kind, u32 value, u32 id);
u32 MUS_COMM_FUNC_SendCommandWait(int unused,int kind,u32 value,u32 id);
u32 MUS_COMM_FUNC_SendMyStatus(struct ActingHost *p);
int MUS_COMM_FUNC_SendBoxData(char *p);
void MUS_COMM_FUNC_ReceiveBoxData(int unused,int unused1,int unused2,char *p);
void *MUS_COMM_FUNC_ResetBoxFlags(int unused,char *p);
int MUS_COMM_FUNC_SendStatusBlock(char *p, char *src);
void MUS_COMM_FUNC_SetRecordData(long index,int unused,int unused1,struct Context *p);
void *MUS_COMM_FUNC_ClearRecordData(long index,struct Context *p);
int MUS_COMM_FUNC_SendRecordBlock(const char *p);
void MUS_COMM_FUNC_ReceiveRecordBlock(int unused,int unused1,int unused2,const struct ActingHost *p);
char *MUS_COMM_FUNC_ClearRecords(int unused, struct ActingHost *p);
/* END mkheaders: generated region */

#endif
