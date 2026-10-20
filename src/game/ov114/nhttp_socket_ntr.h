#ifndef GAME_OV114_NHTTP_SOCKET_NTR_H
#define GAME_OV114_NHTTP_SOCKET_NTR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_socket_ntr.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"

int NHTTPi_CpsAuthCallbackForDebug(void);
void NHTTPi_SetSSLseed(void);
int NHTTPi_checkKeepAlive(int socket);
int NHTTPi_SocOpen(NHTTPReq *req_p);
int NHTTPi_SocClose(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
int NHTTPi_SocConnect(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket, unsigned long hostaddr, int port);
int NHTTPi_SocSSLConnect(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
int NHTTPi_SocRecv_sub(NHTTPConnection *connection_p, int socket, char *buf_p, int len, int flags);
int NHTTPi_SocRecv(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
int NHTTPi_SocRecvRaw(int socket, char *buf_p, int len, int flags);
int NHTTPi_SocSend(NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
void NHTTPi_SocCancel(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
unsigned long NHTTPi_resolveHostname(NHTTPReq *req_p, char *hostname_p);
/* END mkheaders: generated region */

#endif
