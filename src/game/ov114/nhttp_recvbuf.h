#ifndef GAME_OV114_NHTTP_RECVBUF_H
#define GAME_OV114_NHTTP_RECVBUF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_recvbuf.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"
#include "../types.h"

int NHTTPi_findNextLineHdrRecvBuf(const NHTTPRes *res_p, int pos, int limit, int *colon_pos_p, int *return_code_size_p);
int NHTTPi_skipSpaceHdrRecvBuf(const NHTTPRes *res_p, int pos, int limit);
int NHTTPi_compareTokenN_HdrRecvBuf(const NHTTPRes *res_p, int pos, int limit, char *str_p, char extdeli);
int NHTTPi_loadFromHdrRecvBuf(NHTTPRes *res_p, char *dst_p, int pos, int len);
int NHTTPi_isRecvBufFull(NHTTPRes *res_p, u32 pos);
int NHTTPi_RecvBuf(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket, int pos, int flags);
int NHTTPi_RecvBufN(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket, int pos, int len, int flags);
/* END mkheaders: generated region */

#endif
