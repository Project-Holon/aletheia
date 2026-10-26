#ifndef GAME_ARM9_NET_LOWER_DATA_H
#define GAME_ARM9_NET_LOWER_DATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_lower_data.c, prototypes copied from their definitions. */

struct NetLdataCommand;

#include "../types.h"

void GFL_NET_LOWER_DATA_Init(int heapId, int ackMode);
void GFL_NET_LOWER_DATA_Exit(void);
void GFL_NET_LOWER_DATA_SetSendData(void *sendData, int sendSize, int sendTarget, int isParent);
void GFL_NET_LOWER_DATA_CreatePostWork(u32 bufSize, int netId, u32 heapId, void *buf);
void GFL_NET_LOWER_DATA_DeletePostWork(int netId);
void *GFL_NET_LOWER_DATA_GetPostBuffer(unsigned int netId);
int GFL_NET_LOWER_DATA_GetPostRecvSize(unsigned int netId);
int GFL_NET_LOWER_DATA_IsSendFinished(void);
int GFL_NET_LOWER_DATA_IsPostComplete(unsigned int netId);
void GFL_NET_LOWER_DATA_MainSend(void);
u32 GFL_NET_LOWER_DATA_SendChunk(int size);
void *GFL_NET_LOWER_DATA_GetPostEndAddress(u32 netId);
void GFL_NET_LOWER_DATA_RecvChunk(u32 netId, u32 size, void *pData, void *pWork, struct GFLNetHandle *pNetHandle);
int GFL_NET_LOWER_DATA_SendControl(int kind);
void GFL_NET_LOWER_DATA_RecvControl(u32 netId, u32 size, struct NetLdataCommand *pData, void *pWork, struct GFLNetHandle *pNetHandle);
/* END mkheaders: generated region */

#endif
