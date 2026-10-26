#ifndef GAME_OV132_STA_NET_H
#define GAME_OV132_STA_NET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_net.c, prototypes copied from their definitions. */

struct ActingHost;

#include "../types.h"

void *STA_NET_FindRecValueByKey(struct ActingHost *p, u8 key);
void STA_NET_BeginTransfer(struct ActingHost *work);
void STA_NET_UpdateTransferState(char *p);
int STA_NET_SendChunk(char *p,u32 chunk);
void STA_NET_AdvanceChunk(int unused,int unused1,int unused2,char *p);
void *STA_NET_GetChunkPtr(int unused,char *p);
int STA_NET_IsTransferDone(char *p);
int STA_NET_NotifyHostKind4(u8 *p);
int STA_NET_NotifyHostKind5(char *p);
int STA_NET_NotifyHostKind6(char *p);
int STA_NET_SendSlot1Command(u8 *p);
void STA_NET_SetSlot1Done(void *unused, void *unused1, void *unused2, u8 *p);
void *STA_NET_GetSlot1Value(void *unused, u8 *p);
int STA_NET_SendSlot2Command(u8 *p);
void STA_NET_SetSlot2Done(void *unused, void *unused1, void *unused2, u8 *p);
void *STA_NET_GetSlot2Value(void *unused, u8 *p);
int STA_NET_SendSlot3Command(u8 *p);
void STA_NET_SetSlot3Done(void *unused, void *unused1, void *unused2, u8 *p);
void *STA_NET_GetSlot3Value(void *unused, u8 *p);
u32 STA_NET_GetSlot1Done(char *p);
int STA_NET_GetSlot3Done(int *p);
int STA_NET_SendRandomOrder(u8 *p);
u32 STA_NET_SendKindA(char *p, int value);
u32 STA_NET_GetCurrentSlotValue(char *p);
u8 STA_NET_GetSlotValueByIndex(char *p, int index);
void *STA_NET_GetSlotWordByIndex(char *p,u32 index);
int STA_NET_GetRole(int *p);
u32 STA_NET_GetBoxesReceived(u8 *p);
int STA_NET_GetRecordsReceived(int *p);
void STA_NET_SetState6Pair(char *p, u32 pairA, int pairB);
void STA_NET_BeginKind5Phase(char *p);
void STA_NET_SetState18Value(char *p,u32 value);
u32 STA_NET_GetPairA(char *p);
u32 STA_NET_GetPairB(char *p);
/* END mkheaders: generated region */

#endif
