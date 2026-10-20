#ifndef GAME_OV009_DWC_TRANSPORT_H
#define GAME_OV009_DWC_TRANSPORT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_transport.c, prototypes copied from their definitions. */

struct TransInfo;
typedef struct TransInfo TransInfo;

int DWC_IsSendableReliable(unsigned char a);
int DWC_SendReliable(unsigned char aid, void *buffer, int size);
int DWCi_SendReliable(unsigned short type, unsigned char aid, void *buffer, int size);
unsigned long DWC_SendReliableBitmap(unsigned long bitmap, void *buffer, int size);
int DWC_SendUnreliable(unsigned char aid, void *buffer, int size);
int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size);
int DWC_SetUserSendCallback(void (*cb)(int, unsigned char, void *), void *param);
int DWC_SetUserRecvCallback(void (*cb)(unsigned char, unsigned char *, int, void *), void *param);
int DWC_SetUserRecvTimeoutCallback(void (*cb)(unsigned char, void *), void *param);
unsigned short DWCs_DecodeHeader(void *message);
long DWCs_GetRequiredHeaderSize(unsigned short type);
int DWC_SetRecvTimeoutTime(unsigned char aid, unsigned long time);
int DWC_SetConnectionKeepAliveTime(unsigned long v);
unsigned long DWC_GetConnectionKeepAliveTime(void);
void DWCi_InitTransport(TransInfo *info);
void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable);
void DWCi_PingCallback(void *connection, int latency);
void DWCi_TransportProcess(void);
void DWCi_ClearTransConnection(int i);
void DWCi_ShutdownTransport(void);
void DWCi_ResetLastSomeDataRecvTimeByAid(int aid);
unsigned char DWCs_GetSendState(int i);
unsigned char DWCs_GetRecvState(int i);
void DWCs_Send(unsigned char aid, unsigned char *buffer, int size, int reliable);
void DWCi_SendUnreliable(unsigned char aidFrom, unsigned char aidTo, unsigned char *buffer, int size, int fromDWC_SendUnreliable);
void DWCs_HandleReliableMessage(void *connection, unsigned char *message, int size);
void DWCs_HandleUnreliableMessage(void *connection, void *message, int size);
void DWCs_RecvDataHeader(unsigned char aid, void *message, int size);
void DWCs_RecvDataBody(unsigned char aid, void *message, int size);
void DWCs_RecvSystemDataBody(unsigned char aid, void *message, int size);
int DWCs_GetOutgoingBufferFreeSize(unsigned char aid);
void DWCs_UpdateConnectionKeepAliveTime(void *connection);
/* END mkheaders: generated region */

#endif
