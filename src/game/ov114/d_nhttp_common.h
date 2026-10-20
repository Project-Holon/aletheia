#ifndef GAME_OV114_D_NHTTP_COMMON_H
#define GAME_OV114_D_NHTTP_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of d_nhttp_common.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"
#include "../types.h"

void NHTTPi_WaitForCompletion(NHTTPConnection *connection_p);
void NHTTPi_NotifyCompletion(NHTTPConnection *connection_p);
NHTTPConnection *NHTTPi_ControlConnectionList(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *handle_p, unsigned long order);
int NHTTPi_CommitConnectionList(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *handle_p);
int NHTTPi_OmitConnectionList(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *handle_p);
NHTTPRes *NHTTPi_Connection2Response(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *handle_p);
NHTTPConnection *NHTTPi_Request2Connection(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
NHTTPConnection *NHTTPi_Response2Connection(NHTTPMutexInfo *mutexInfo_p, NHTTPRes *res_p);
NHTTPConnection *NHTTPi_GetConnection(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *handle_p);
void *NHTTPi_GetRequest(NHTTPMutexInfo *mutexInfo_p, void *handle_p);
void *NHTTPi_GetResponse(NHTTPMutexInfo *mutexInfo_p, void *handle_p);
u32 NHTTPi_GetConnectionListLength(void);
int NHTTPi_PostSendCallback(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p, char *label_p, int offset);
void NHTTPi_BufferFullCallback(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p);
void NHTTPi_ReceivedCallback(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p);
void NHTTPi_CompleteCallback(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p);
int NHTTPi_SetPostDataBuffer(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p, void *buf_p, unsigned long length);
int NHTTPi_SetBodyBuffer(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p, void *buf_p, unsigned long length, unsigned long offset);
void NHTTPi_InitSystemInfo(NHTTPSysInfo *sysInfo_p);
NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(NHTTPSysInfo *sysInfo_p);
NHTTPListInfo *NHTTPi_GetListInfoP(NHTTPSysInfo *sysInfo_p);
NHTTPReqInfo *NHTTPi_GetReqInfoP(NHTTPSysInfo *sysInfo_p);
NHTTPThreadInfo *NHTTPi_GetThreadInfoP(NHTTPSysInfo *sysInfo_p);
NHTTPMutexInfo *NHTTPi_GetMutexInfoP(NHTTPSysInfo *sysInfo_p);
void NHTTPi_SetVirtualContentLength(NHTTPConnection *connection_p, u32 virtualContentLength);
void NHTTPi_InitConnectionList(void);
void NHTTPi_InitMutexInfo(NHTTPMutexInfo *mutexInfo_p);
void NHTTPi_initLockReqList(NHTTPMutexInfo *mutexInfo_p);
void NHTTPi_exitLockReqList(void);
void NHTTPi_lockReqList(NHTTPMutexInfo *mutexInfo_p);
void NHTTPi_unlockReqList(NHTTPMutexInfo *mutexInfo_p);
int NHTTPi_addRef(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p);
int NHTTPi_decRef(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p);
/* END mkheaders: generated region */

#endif
