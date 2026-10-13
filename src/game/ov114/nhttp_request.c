/*
 * file:     nhttp_request.c
 * unit:     yes
 * function: NHTTPi_InitRequestInfo, NHTTPi_CreateRequest, NHTTPi_DestroyRequest, deleteStrList, NHTTPi_destroyRequestObject, NHTTPi_SendRequestAsync, NHTTPi_CancelRequestAsync, NHTTPi_cancelAllRequests
 * address:  0x021BB3C0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NHTTPi_alloc             0x021ba820 arm
 *   NHTTPi_SetError          0x021ba874 arm
 *   NHTTPi_memclr            0x021ba13c arm
 *   NHTTPi_strnlen           0x021ba124 arm
 *   NHTTPi_memcpy            0x021ba100 arm
 *   NHTTPi_strnicmp          0x021ba150 arm
 *   NHTTPi_strToHex          0x021ba35c arm
 *   NHTTPi_strtonum          0x021ba620 arm
 *   NHTTPi_free              0x021ba850 arm
 *   str_http_scheme          0x021ce400 data a1
 *   str_https_scheme         0x021ce408 data a1
 *   NHTTPi_strMultipartBound 0x021cdfc8 data a1
 *   NHTTPi_free  0x021BA850  arm  ov114
 *   NHTTPi_Request2Connection  0x021BEBE0  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *   NHTTPi_GetBgnEndInfoP     0x021bef3c arm
 *   NHTTPi_GetThreadInfoP     0x021bef50 arm
 *   NHTTPi_GetMutexInfoP      0x021bef58 arm
 *   NHTTPi_lockReqList        0x021befcc arm
 *   NHTTPi_GetListInfoP       0x021bef40 arm
 *   NHTTPi_setReqQueue        0x021bacfc arm
 *   NHTTPi_kickCommThread     0x021b9c08 arm
 *   NHTTPi_unlockReqList      0x021befd8 arm
 *   NHTTPi_GetReqInfoP      0x021bef48 arm
 *   NHTTPi_SocCancel        0x021ba068 arm
 *   NHTTPi_freeReqQueue     0x021bade0 arm
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_GetListInfoP 0x021BEF40 arm ov114
 *   NHTTPi_lockReqList 0x021BEFCC arm ov114
 *   NHTTPi_SocCancel 0x021BA068 arm ov114
 *   NHTTPi_allFreeReqQueue 0x021BAE90 arm ov114
 *   NHTTPi_unlockReqList 0x021BEFD8 arm ov114
 */
#include "nhttp_types.h"

extern void *NHTTPi_alloc(unsigned long size, int align);
extern void NHTTPi_SetError(NHTTPBgnEndInfo *bgnEndInfo_p, int error);
extern void NHTTPi_memclr(void *p_p, int size);
extern int NHTTPi_strnlen(char *p_p, int size);
extern void NHTTPi_memcpy(void *dst_p, void *src_p, int size);
extern int NHTTPi_strnicmp(char *p1_p, char *p2_p, int size);
extern int NHTTPi_strToHex(char *p_p, int len);
extern int NHTTPi_strtonum(char *p_p, int size);
extern void NHTTPi_free(void *ptr_p);
NHTTPMutexInfo *NHTTPi_GetMutexInfoP(NHTTPSysInfo *sysInfo_p);
NHTTPConnection *NHTTPi_Request2Connection(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
void NHTTPi_free(void *ptr_p);
extern NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(NHTTPSysInfo *sysInfo_p);
extern NHTTPThreadInfo *NHTTPi_GetThreadInfoP(NHTTPSysInfo *sysInfo_p);
extern NHTTPMutexInfo *NHTTPi_GetMutexInfoP(NHTTPSysInfo *sysInfo_p);
extern NHTTPListInfo *NHTTPi_GetListInfoP(NHTTPSysInfo *sysInfo_p);
extern void NHTTPi_lockReqList(NHTTPMutexInfo *mutexInfo_p);
extern int NHTTPi_setReqQueue(NHTTPListInfo *listInfo_p, NHTTPReq *req_p);
extern void NHTTPi_kickCommThread(NHTTPThreadInfo *threadInfo_p);
extern void NHTTPi_unlockReqList(NHTTPMutexInfo *mutexInfo_p);
extern NHTTPReqInfo *NHTTPi_GetReqInfoP(NHTTPSysInfo *sysInfo_p);
extern void NHTTPi_SocCancel(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
extern int NHTTPi_freeReqQueue(NHTTPListInfo *listInfo_p, NHTTPMutexInfo *mutexInfo_p, int id);
extern NHTTPReqInfo *NHTTPi_GetReqInfoP(NHTTPSysInfo *sysInfo_p);
extern NHTTPListInfo *NHTTPi_GetListInfoP(NHTTPSysInfo *sysInfo_p);
extern void NHTTPi_lockReqList(NHTTPMutexInfo *mutexInfo_p);
extern void NHTTPi_SocCancel(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
extern void NHTTPi_allFreeReqQueue(NHTTPListInfo *listInfo_p, NHTTPMutexInfo *mutexInfo_p);
extern void NHTTPi_unlockReqList(NHTTPMutexInfo *mutexInfo_p);
void NHTTPi_InitRequestInfo(NHTTPReqInfo *reqInfo_p);
NHTTPReq *NHTTPi_CreateRequest(NHTTPBgnEndInfo *bgnEndInfo_p, char *url_p, int method, char *buf_p, unsigned long len, void *param_p, NHTTPBufFullFn bufFull, NHTTPFreeBufFn freeBuf);
void NHTTPi_DestroyRequest(NHTTPSysInfo *sysInfo_p, NHTTPReq *req_p);
void deleteStrList(NHTTPi_DATALIST *list_p);
int NHTTPi_destroyRequestObject(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
int NHTTPi_SendRequestAsync(NHTTPSysInfo *sysInfo_p, NHTTPReq *req_p);
int NHTTPi_CancelRequestAsync(NHTTPSysInfo *sysInfo_p, int id);
void NHTTPi_cancelAllRequests(NHTTPSysInfo *sysInfo_p);
extern char str_http_scheme[8];
extern char str_https_scheme[9];
extern char NHTTPi_strMultipartBound[21];

/*
 * Clears the current request pointer.
 */
void NHTTPi_InitRequestInfo(NHTTPReqInfo *reqInfo_p)
{
    reqInfo_p->reqCurrent = 0;
}


NHTTPReq *NHTTPi_CreateRequest(
    NHTTPBgnEndInfo *bgnEndInfo_p, char *url_p, int method,
    char *buf_p, unsigned long len, void *param_p,
    NHTTPBufFullFn bufFull, NHTTPFreeBufFn freeBuf)
{
    int declen;
    int urllen;
    int i;
    int out;
    char *prefix_p;
    char *host_p;
    NHTTPReq *req_p;
    int prelen;
    int nhostenc;
    int deccount;
    int flag;
    int decode_urllen;
    int port;
    int suflen;
    char c;
    char a_url[512];

    req_p = 0;
    if (method != 0 && method != 1 && method != 2) {
        NHTTPi_SetError(bgnEndInfo_p, 0xb);
        goto cleanup;
    }

    req_p = NHTTPi_alloc(0x258, 4);
    if (req_p == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        goto cleanup;
    }
    NHTTPi_memclr(req_p, 0x258);

    req_p->res_p = NHTTPi_alloc(0x43c, 4);
    if (req_p->res_p == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        goto cleanup;
    }
    NHTTPi_memclr(req_p->res_p, 0x43c);

    req_p->res_p->recvBuf_p = buf_p;
    req_p->res_p->recvBufLen = len;
    req_p->res_p->bufFull = bufFull;
    req_p->res_p->freeBuf = freeBuf;

    urllen = NHTTPi_strnlen(url_p, 511);
    if (urllen <= 7) {
        NHTTPi_SetError(bgnEndInfo_p, 4);
        goto cleanup;
    }

    NHTTPi_memclr(a_url, 0x200);
    NHTTPi_memcpy(a_url, url_p, urllen);

    prelen = 7;
    req_p->port = 80;
    if (NHTTPi_strnicmp(a_url, str_http_scheme, prelen) != 0) {
        prelen = 8;
        if (NHTTPi_strnicmp(a_url, str_https_scheme, prelen) != 0) {
            NHTTPi_SetError(bgnEndInfo_p, 4);
            goto cleanup;
        }
        req_p->isSSL = 1;
        req_p->port = 443;
    }

    declen = urllen - prelen;
    prefix_p = a_url + prelen;
    if (declen <= 0) {
        NHTTPi_SetError(bgnEndInfo_p, 4);
        goto cleanup;
    }

    i = 0;
    nhostenc = 0;
    deccount = 0;
    flag = 2;
    while (i < declen && (c = prefix_p[i]) != '/') {
        if (deccount == 2) {
            deccount = deccount - 1;
        } else if (deccount == 1) {
            c = (char)NHTTPi_strToHex(prefix_p + (i - 1), flag);
            deccount = deccount - 1;
            if (c < 0) {
                NHTTPi_SetError(bgnEndInfo_p, 4);
                goto cleanup;
            }
            if (c == '/') {
                nhostenc = nhostenc - 1;
                break;
            }
        } else {
            if (c == '%') {
                deccount = 2;
                nhostenc = nhostenc + 1;
            }
        }
        i = i + 1;
    }
    if (deccount != 0) {
        NHTTPi_SetError(bgnEndInfo_p, 4);
        goto cleanup;
    }

    decode_urllen = prelen + declen - (nhostenc << 1);
    req_p->URL_p = NHTTPi_alloc(decode_urllen + 1, 4);
    if (req_p->URL_p == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        goto cleanup;
    }
    NHTTPi_memclr(req_p->URL_p, decode_urllen + 1);
    NHTTPi_memcpy(req_p->URL_p, a_url, prelen);

    i = 0;
    out = 0;
    deccount = 0;
    flag = 0;
    for (; i < declen; i++) {
        if (deccount == 2) {
            deccount = deccount - 1;
        } else if (deccount == 1) {
            c = (char)NHTTPi_strToHex(prefix_p + (i - 1), 2);
            deccount = deccount - 1;
            req_p->URL_p[prelen + out - 1] = c;
            if (c == '/')
                flag = 1;
        } else {
            c = prefix_p[i];
            if (c == '/')
                flag = 1;
            if (flag == 0 && c == '%') {
                deccount = 2;
            } else {
                req_p->URL_p[prelen + out] = c;
            }
            out = out + 1;
        }
    }
    req_p->URL_p[prelen + out] = 0;

    host_p = req_p->URL_p + prelen;
    for (i = 0; i < out; i++) {
        c = host_p[i];
        if (c == '/' || c == ':') {
            req_p->hostLen = i + prelen;
            break;
        }
    }
    if (i == out) {
        req_p->hostLen = i + prelen;
        req_p->hostDescLen = i + prelen;
    } else {
        c = host_p[i];
        if (c == '/') {
            req_p->hostDescLen = req_p->hostLen;
        } else if (c == ':') {
            for (; i < out; i++) {
                c = host_p[i];
                if (c == '/') {
                    req_p->hostDescLen = i + prelen;
                    break;
                }
            }
            if (i == out) {
                req_p->hostDescLen = i + prelen;
            } else {
                suflen = req_p->hostLen + 1;
                port = NHTTPi_strtonum(req_p->URL_p + suflen, req_p->hostDescLen - suflen);
                if (port < 0) {
                    port = req_p->port;
                } else if (port > 0xffff) {
                    NHTTPi_SetError(bgnEndInfo_p, 4);
                    goto cleanup;
                }
                req_p->port = (unsigned short)port;
            }
        }
    }

    urllen = req_p->hostLen - (req_p->isSSL ? 8 : 7);
    req_p->hostname_p = NHTTPi_alloc(urllen + 1, 4);
    if (req_p->hostname_p == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        goto cleanup;
    }
    NHTTPi_memclr(req_p->hostname_p, urllen + 1);
    NHTTPi_memcpy(req_p->hostname_p, req_p->URL_p + (req_p->isSSL ? 8 : 7), urllen);

    NHTTPi_memcpy(req_p->multipartBound, NHTTPi_strMultipartBound, 0x14);
    req_p->method = method;
    req_p->sslCon_p = 0;
    req_p->sslHandshakeState = 0;
    req_p->sslRecvLen = 0;
    req_p->sslSendLen = 0;
    req_p->sslLastError = 0;
    req_p->rootCA_p = 0;
    req_p->rootCALen = 0;
    req_p->clientCert_p = 0;
    req_p->verifyOption = 0;
    req_p->isIgnoreAuth = 0;
    req_p->res_p->param_p = param_p;
    req_p->isProxy = 0;
    req_p->postDataState = 0;
    return req_p;

cleanup:
    if (req_p != 0) {
        if (req_p->URL_p != 0)
            NHTTPi_free(req_p->URL_p);
        if (req_p->hostname_p != 0)
            NHTTPi_free(req_p->hostname_p);
        if (req_p->res_p != 0)
            NHTTPi_free(req_p->res_p);
        NHTTPi_free(req_p);
    }
    return 0;
}


/*
 * Unlinks the response from its connection, releases it and then tears the request down.
 */
void NHTTPi_DestroyRequest(NHTTPSysInfo *sysInfo_p, NHTTPReq *req_p)
{
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    NHTTPConnection *connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);

    if (connection_p != 0)
        connection_p->res_p = 0;
    NHTTPi_free(req_p->res_p);
    NHTTPi_destroyRequestObject(mutexInfo_p, req_p);
}


/*
 * sdk:      deleteStrList (libnhttp.TWL.HYB.a(nhttp_request.o))
 */
void deleteStrList(NHTTPi_DATALIST *list_p)
{
    NHTTPi_DATALIST *last_p;

    if (list_p) {
        do {
            last_p = list_p->prev;
            if (list_p != last_p) {
                NHTTPi_DATALIST *newLast_p = last_p->prev;
                NHTTPi_free(last_p);
                list_p->prev = newLast_p;
            } else {
                NHTTPi_free(list_p);
                list_p = 0;
            }
        } while (list_p);
    }
}


int NHTTPi_destroyRequestObject(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p)
{
    NHTTPConnection *connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);

    if (connection_p != 0)
        connection_p->req_p = 0;
    deleteStrList(req_p->hdrlist_p);
    deleteStrList(req_p->datalist_p);
    NHTTPi_free(req_p->URL_p);
    NHTTPi_free(req_p->hostname_p);
    NHTTPi_free(req_p);
    return 1;
}


int NHTTPi_SendRequestAsync(NHTTPSysInfo *sysInfo_p, NHTTPReq *req_p)
{
    NHTTPBgnEndInfo *bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    NHTTPThreadInfo *threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    int id;

    if (req_p->isStarted != 0) {
        NHTTPi_SetError(bgnEndInfo_p, 0xb);
        return -1;
    }
    NHTTPi_lockReqList(mutexInfo_p);
    id = NHTTPi_setReqQueue(NHTTPi_GetListInfoP(sysInfo_p), req_p);
    if (id >= 0) {
        req_p->isStarted = 1;
        NHTTPi_kickCommThread(threadInfo_p);
    } else {
        NHTTPi_SetError(bgnEndInfo_p, 1);
    }
    NHTTPi_unlockReqList(mutexInfo_p);
    return id;
}


int NHTTPi_CancelRequestAsync(NHTTPSysInfo *sysInfo_p, int id)
{
    int rc = 0;
    NHTTPReqInfo *reqInfo_p;
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPi_REQLIST *reqCurrent_p;

    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    reqCurrent_p = reqInfo_p->reqCurrent;
    NHTTPi_lockReqList(mutexInfo_p);
    if (reqCurrent_p != 0 && reqCurrent_p->id == id && *(int *)reqCurrent_p->req_p == 0) {
        *(int *)(*(int *volatile *)&reqCurrent_p->req_p) = 1;
        NHTTPi_SocCancel(mutexInfo_p, reqCurrent_p->req_p, reqCurrent_p->socket);
        rc = 1;
    }
    if (rc == 0)
        rc = NHTTPi_freeReqQueue(NHTTPi_GetListInfoP(sysInfo_p), mutexInfo_p, id);
    NHTTPi_unlockReqList(mutexInfo_p);
    return rc;
}


/*
 * sdk:      NHTTPi_cancelAllRequests (libnhttp.TWL.HYB.a(nhttp_request.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void NHTTPi_cancelAllRequests(NHTTPSysInfo *sysInfo_p)
{
    NHTTPReqInfo *reqInfo_p;
    NHTTPListInfo *listInfo_p;
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPi_REQLIST *reqCurrent_p;

    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    listInfo_p = NHTTPi_GetListInfoP(sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    reqCurrent_p = reqInfo_p->reqCurrent;
    NHTTPi_lockReqList(mutexInfo_p);
    if (reqCurrent_p) {
        NHTTPReq *volatile *req_pp = &reqCurrent_p->req_p;

        if ((*req_pp)->doCancel == 0) {
            (*req_pp)->doCancel = 1;
            NHTTPi_SocCancel(mutexInfo_p, *req_pp, reqCurrent_p->socket);
        }
    }
    NHTTPi_allFreeReqQueue(listInfo_p, mutexInfo_p);
    NHTTPi_unlockReqList(mutexInfo_p);
}
