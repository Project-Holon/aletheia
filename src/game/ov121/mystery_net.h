#ifndef GAME_OV121_MYSTERY_NET_H
#define GAME_OV121_MYSTERY_NET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mystery_net.c, prototypes copied from their definitions. */

struct MysteryNetRec;

#include "../types.h"
#include "../ov121/mystery_net_types.h"

void *MYSTERY_NET_Create(void *arg,int heap);
void MYSTERY_NET_Delete(u8 *p);
void MYSTERY_NET_Step(char *p);
void MYSTERY_NET_SetAction(char *p, unsigned action);
int MYSTERY_NET_GetAction(void *p);
unsigned int MYSTERY_NET_GetResult(char *p);
int MYSTERY_NET_GetReceivedData(u8 *p, void *a, u32 b);
int MYSTERY_NET_UpdateWifiError(void *p);
void MYSTERY_NET_Exit(char *p);
int MYSTERY_NET_HandleWifiError(char *p);
int MYSTERY_NET_ShowWifiError(void *work);
int MYSTERY_NET_ShowWifiErrorDw(void *work);
void MYSTERY_NET_NoopHandler(void *a, int *state, char *p);
void MYSTERY_NET_StartSession(void *a, int *state, char *p);
void MYSTERY_NET_StopSession(void *a, int *state, char *p);
void MYSTERY_NET_PollWihStatus(void *a, int *b, char *c);
void MYSTERY_NET_StartBeacon(void *a,int *state,char *p);
void MYSTERY_NET_DeleteBeacon(void *a, int *state, char *p);
void MYSTERY_NET_RunBeacon(void *a,int *b,char *p);
void MYSTERY_NET_StartIrc(void *a, int *state, char *p);
void MYSTERY_NET_DeleteIrc(void *a, int *state, char *p);
void MYSTERY_NET_RunIrc(void *a, int *state, char *p);
void MYSTERY_NET_RunNdDownload(void *task,int *state,char *p);
void MYSTERY_NET_EndDownload(void *a, int *state, char *p);
void MYSTERY_NET_SetNdState(MysteryNetNdContext *p, int *state, int value);
void MYSTERY_NET_AbortNd(MysteryNetNdContext *p,int a,int *state,int b,int c);
void MYSTERY_NET_InitTask(MysteryNetWork *p, void *a, void *b);
void MYSTERY_NET_ClearTask(void *p);
void MYSTERY_NET_Dispatch(char *p);
void MYSTERY_NET_SetHandler(MysteryNetWork *p,void (*f)(void *, int *, char *));
int MYSTERY_NET_IsHandler(MysteryNetWork *p, void (*value)(void *, int *, char *));
void *MYSTERY_NET_GetBuffer(char *p);
int MYSTERY_NET_GetBufferSize(void);
int MYSTERY_NET_IsEqual(int a, int b);
void MYSTERY_NET_FlagExit(void *userArg);
void MYSTERY_NET_OnNdAsyncDone(int reason, int b, int serverError);
void MYSTERY_NET_MarkNdDone(void);
int MYSTERY_NET_ParseHexValue(const signed char *p);
int MYSTERY_NET_IsZeroBlock(const unsigned *p, unsigned size);
int MYSTERY_NET_GetErrorHookState(void *arg, u32 errorCode, u32 type, int dwcError);
int MYSTERY_NET_ImportRecords(char *p, void *a, unsigned short b);
int MYSTERY_NET_BuildPokemonFromRecord(struct MysteryNetRec *r, void *gs, u16 heap);
/* END mkheaders: generated region */

#endif
