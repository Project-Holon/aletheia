#ifndef GAME_OV114_NHTTP_REQUEST_H
#define GAME_OV114_NHTTP_REQUEST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_request.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"

void NHTTPi_InitRequestInfo(NHTTPReqInfo *reqInfo_p);
NHTTPReq *NHTTPi_CreateRequest(NHTTPBgnEndInfo *bgnEndInfo_p, char *url_p, int method, char *buf_p, unsigned long len, void *param_p, NHTTPBufFullFn bufFull, NHTTPFreeBufFn freeBuf);
void NHTTPi_DestroyRequest(NHTTPSysInfo *sysInfo_p, NHTTPReq *req_p);
void deleteStrList(NHTTPi_DATALIST *list_p);
int NHTTPi_destroyRequestObject(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
int NHTTPi_SendRequestAsync(NHTTPSysInfo *sysInfo_p, NHTTPReq *req_p);
int NHTTPi_CancelRequestAsync(NHTTPSysInfo *sysInfo_p, int id);
void NHTTPi_cancelAllRequests(NHTTPSysInfo *sysInfo_p);
/* END mkheaders: generated region */

#endif
