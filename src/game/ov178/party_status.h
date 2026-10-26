#ifndef GAME_OV178_PARTY_STATUS_H
#define GAME_OV178_PARTY_STATUS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of party_status.c, prototypes copied from their definitions. */

struct PartyStatusObj5;
struct PartyStatusObj6;
struct PartyStatusObj4;
struct PartyStatusObj2;
struct PartyStatusWork;
struct PartyStatusArgs;
struct PartyStatusNetArgs;
struct WifiBattleMatchNetCtx;
struct LiveBattleMatchIrcWork;
struct Proc;
typedef struct PartyStatusObj5 PartyStatusObj5;
typedef struct PartyStatusObj6 PartyStatusObj6;
typedef struct PartyStatusObj4 PartyStatusObj4;
typedef struct PartyStatusObj2 PartyStatusObj2;
typedef struct PartyStatusWork PartyStatusWork;
typedef struct PartyStatusArgs PartyStatusArgs;
typedef struct PartyStatusNetArgs PartyStatusNetArgs;

#include "../types.h"

int PARTY_STATUS_Create(void *handle,int unused,PartyStatusObj5 *q);
int PARTY_STATUS_Destroy(void *handle,int unused,PartyStatusObj6 *q,PartyStatusWork *p);
int PARTY_STATUS_Update(void *unused,int unused2,PartyStatusObj4 *q,PartyStatusWork *p);
void PARTY_STATUS_InitRecord(PartyStatusArgs *args, PartyStatusWork *work, PartyStatusObj2 *record);
int PARTY_STATUS_CreateSub(struct Proc *proc, int unused, PartyStatusNetArgs *param);
int PARTY_STATUS_DestroySub(void *proc, u32 unused, PartyStatusNetArgs *param, void *work);
int PARTY_STATUS_UpdateSub(u32 unused, u32 *state, PartyStatusNetArgs *param, void *work);
void PARTY_STATUS_Noop(void *work, PartyStatusNetArgs *param, int heapId);
int PARTY_STATUS_NetSync(struct WifiBattleMatchNetCtx **out,PartyStatusNetArgs *ctx,u32 *state);
void PARTY_STATUS_DestroySubWork(struct WifiBattleMatchNetCtx **work, PartyStatusNetArgs *param);
void PARTY_STATUS_CreateSubWork(struct LiveBattleMatchIrcWork **work, PartyStatusNetArgs *param, u16 heapId);
unsigned PARTY_STATUS_NetSync2(struct LiveBattleMatchIrcWork **netWork,PartyStatusNetArgs *ctx,unsigned *state);
void PARTY_STATUS_ExitSubWork(struct LiveBattleMatchIrcWork **work, PartyStatusNetArgs *param);
/* END mkheaders: generated region */

#endif
