#ifndef GAME_OV114_NHTTP_THREAD_H
#define GAME_OV114_NHTTP_THREAD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_thread.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"

void NHTTPi_IsCreateCommThreadMessageQueueOn(NHTTPThreadInfo *threadInfo_p);
void NHTTPi_IsCreateCommThreadMessageQueueOff(NHTTPThreadInfo *threadInfo_p);
int NHTTPi_IsCreateCommThreadMessageQueue(NHTTPThreadInfo *threadInfo_p);
int NHTTPi_CheckHeaderEnd(char *buf_p, int bufwp);
int NHTTPi_SkipLineBuf(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
int NHTTPi_GetPostContentlength(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, char *label_p, unsigned long *contentLength, int sendtype);
int NHTTPi_BufFull(NHTTPMutexInfo *mutexInfo_p, NHTTPRes *res_p);
int NHTTPi_SendData(NHTTPThreadData *threadData_p, char *src_p, int srclen);
int NHTTPi_SendProxyAuthorization(NHTTPThreadData *threadData_p);
int NHTTPi_SendBasicAuthorization(NHTTPThreadData *threadData_p);
int NHTTPi_SendProxyConnectMethod(NHTTPThreadData *threadData_p);
int NHTTPi_SendHeaderList(NHTTPThreadData *threadData_p);
void NHTTPi_ThreadInit(NHTTPThreadData *threadData_p);
int NHTTPi_ThreadExecReqQueue(NHTTPThreadData *threadData_p);
int NHTTPi_ThreadConnectProc(NHTTPThreadData *threadData_p);
int NHTTPi_ThreadParseHeaderProc(NHTTPThreadData *threadData_p);
void NHTTPi_CommThreadProcMain(void);
/* END mkheaders: generated region */

#endif
