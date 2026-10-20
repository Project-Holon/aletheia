#ifndef GAME_ARM9_NET_QUEUE_H
#define GAME_ARM9_NET_QUEUE_H

/* Public functions of net_queue.c, prototypes copied from their definitions. */

#include "../arm9/net_types.h"
#include "../arm9/net_types.h"
#include "../types.h"

NetQueueNode *GFL_NET_QUEUE_GetFreeNode(NetQueue *queue);
int GFL_NET_QUEUE_IsEmpty(NetQueue *queue);
int GFL_NET_QUEUE_GetCount(NetQueue *queue);
u32 GFL_NET_QUEUE_PopList(NetQueueList *list);
void GFL_NET_QUEUE_PutByte(NetSendBuf *out, int byte);
int GFL_NET_QUEUE_WriteHeader(NetQueueNode *node, NetSendBuf *out);
int GFL_NET_QUEUE_WriteNode(NetQueueNode *node, NetSendBuf *out, NetRingBuff *ring, BOOL needHeader);
int GFL_NET_QUEUE_Put(NetQueue *queue, u32 command, const u8 *pDataArea, u32 size, u32 isFast, u32 copyToRing, u32 sendID);
NetQueueNode *GFL_NET_QUEUE_GetNext(NetQueue *queue);
void GFL_NET_QUEUE_RemoveNext(NetQueue *queue);
int GFL_NET_QUEUE_FillSendBuffer(NetQueue *queue, NetSendBuf *out);
void GFL_NET_QUEUE_Init(NetQueue *queue, u32 nodeMax, NetRingBuff *ring, u32 heapId);
void GFL_NET_QUEUE_Reset(NetQueue *queue);
void GFL_NET_QUEUE_Exit(NetQueue *queue);
int GFL_NET_QUEUE_IsCommandQueued(NetQueue *queue, int command);

#endif
