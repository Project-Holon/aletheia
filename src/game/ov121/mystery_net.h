#ifndef GAME_OV121_MYSTERY_NET_H
#define GAME_OV121_MYSTERY_NET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mystery_net.c, prototypes copied from their definitions. */

struct MysteryNetRec;

#include "../types.h"

void *MYSTERY_NET_Create(void *arg,int heap);
void MYSTERY_NET_Delete(u8 *p);
void MYSTERY_NET_Step(char *p);
void MYSTERY_NET_SetAction(char *p, unsigned action);
int MYSTERY_NET_GetAction(void *p);
void *MYSTERY_NET_GetResult(char *p);
int MYSTERY_NET_GetReceivedData(u8 *p, void *a, u32 b);
int MYSTERY_NET_UpdateWifiError(void *p);
void MYSTERY_NET_Exit(char *p);
int MYSTERY_NET_HandleWifiError(char *p);
int MYSTERY_NET_ShowWifiError(void *work);
int MYSTERY_NET_ShowWifiErrorDw(void *work);
void MYSTERY_NET_NoopHandler(void);
void MYSTERY_NET_StartSession(void *a, int *state, char *p);
void MYSTERY_NET_StopSession(void *a, int *state, char *p);
void MYSTERY_NET_PollWihStatus(int a, int b, char *c);
void MYSTERY_NET_StartBeacon(void *a,int *state,char *p);
void MYSTERY_NET_DeleteBeacon(void *a, int *state, char *p);
void MYSTERY_NET_RunBeacon(void *a,int b,char *p);
void MYSTERY_NET_StartIrc(void *a, int *state, char *p);
void MYSTERY_NET_DeleteIrc(void *a, int *state, char *p);
void MYSTERY_NET_RunIrc(void *a, int *state, char *p);
void MYSTERY_NET_RunNdDownload(void *task,int *state,char *p);
void MYSTERY_NET_EndDownload(void *a, int *state, char *p);
void MYSTERY_NET_SetNdState(char *p, int *state, int value);
void MYSTERY_NET_AbortNd(u32 p,int a,int *state,int b,int c);
void MYSTERY_NET_InitTask(void *p, int a, void *b);
void MYSTERY_NET_ClearTask(void *p);
void MYSTERY_NET_Dispatch(char *p);
void MYSTERY_NET_SetHandler(u32 *p,void *f);
int MYSTERY_NET_IsHandler(int *p, int value);
void *MYSTERY_NET_GetBuffer(char *p);
int MYSTERY_NET_GetBufferSize(void);
int MYSTERY_NET_IsEqual(int a, int b);
void MYSTERY_NET_FlagExit(char *p);
void MYSTERY_NET_OnNdAsyncDone(int a, int b);
void MYSTERY_NET_MarkNdDone(void);
int MYSTERY_NET_ParseHexValue(const signed char *p);
int MYSTERY_NET_IsZeroBlock(const unsigned *p, unsigned size);
int MYSTERY_NET_GetErrorHookState(char *p, int unused, int type);
int MYSTERY_NET_ImportRecords(char *p, void *a, unsigned short b);
int MYSTERY_NET_BuildPokemonFromRecord(struct MysteryNetRec *r, void *gs, u16 heap);
/* END mkheaders: generated region */

#endif
