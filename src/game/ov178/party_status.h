#ifndef GAME_OV178_PARTY_STATUS_H
#define GAME_OV178_PARTY_STATUS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of party_status.c, prototypes copied from their definitions. */

struct PartyStatusObj5;
struct PartyStatusObj6;
struct PartyStatusObj1;
struct PartyStatusObj4;
struct PartyStatusObj2;
struct Proc;
typedef struct PartyStatusObj5 PartyStatusObj5;
typedef struct PartyStatusObj6 PartyStatusObj6;
typedef struct PartyStatusObj1 PartyStatusObj1;
typedef struct PartyStatusObj4 PartyStatusObj4;
typedef struct PartyStatusObj2 PartyStatusObj2;

#include "../types.h"

int PARTY_STATUS_Create(void *handle,int unused,PartyStatusObj5 *q);
int PARTY_STATUS_Destroy(void *handle,int unused,PartyStatusObj6 *q,PartyStatusObj1 *p);
int PARTY_STATUS_Update(void *unused,int unused2,PartyStatusObj4 *q,char *p);
void PARTY_STATUS_InitRecord(int *args, int *work, PartyStatusObj2 *record);
int PARTY_STATUS_CreateSub(struct Proc *proc, int unused, int *param);
int PARTY_STATUS_DestroySub(void *proc, u32 unused, u32 *param, void *work);
int PARTY_STATUS_UpdateSub(u32 unused, u32 state, u32 *param, void *work);
void PARTY_STATUS_Noop(int work, int *param, int heapId);
int PARTY_STATUS_NetSync(char **out,u32 *ctx,u32 *state);
void PARTY_STATUS_DestroySubWork(void **work, u32 *param);
void PARTY_STATUS_CreateSubWork(u32 *work, u32 **param, u16 heapId);
unsigned PARTY_STATUS_NetSync2(void **netWork,unsigned *ctx,unsigned *state);
void PARTY_STATUS_ExitSubWork(int *work, void *param);
/* END mkheaders: generated region */

#endif
