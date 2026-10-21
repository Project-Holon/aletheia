/*
 * file:     d_nhttp_private.c
 * unit:     yes
 * function: NHTTP_CreateConnection, NHTTP_DeleteConnection, NHTTPi_DeleteConnection, NHTTP_WaitForConnection, NHTTP_StartConnection, NHTTP_CancelConnection, NHTTP_GetConnectionStatus, NHTTP_GetBodyBuffer, NHTTP_GetUserParam, NHTTP_GetConnectionError, NHTTP_GetConnectionProgress
 * address:  0x021BF04C
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
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_alloc 0x021BA820 arm ov114
 *   NHTTPi_SetError 0x021BA874 arm ov114
 *   NHTTPi_memclr 0x021BA13C arm ov114
 *   NHTTPi_CreateRequest 0x021BB3CC arm ov114
 *   NHTTPi_free 0x021BA850 arm ov114
 *   NHTTPi_CommitConnectionList 0x021BEB88 arm ov114
 *   NHTTPi_SetVirtualContentLength 0x021BEF60 arm ov114
 *   NHTTPi_GetConnection  0x021BEC00  arm  ov114
 *   NHTTPi_DeleteConnection  0x021BF1B0  arm  ov114
 *   NHTTPi_GetSystemInfoP      0x021bef08 arm
 *   NHTTPi_GetMutexInfoP       0x021bef58 arm
 *   NHTTPi_GetThreadInfoP      0x021bef50 arm
 *   NHTTPi_CancelRequestAsync  0x021bba14 arm
 *   NHTTPi_decRef              0x021bf018 arm
 *   NHTTPi_DestroyRequest      0x021bb8b4 arm
 *   NHTTP_WaitForConnection    0x021bf288 arm
 *   NHTTPi_DestroyResponse     0x021bbb28 arm
 *   NHTTPi_OmitConnectionList  0x021beba8 arm
 *   NHTTPi_free                0x021ba850 arm
 *   NHTTPi_GetThreadInfoP 0x021BEF50  arm
 *   NHTTPi_CheckCurrentThread 0x021B9C1C  arm
 *   NHTTPi_WaitForCompletion 0x021BEA64  arm
 *   NHTTPi_GetConnection       0x021bec00 arm
 *   NHTTPi_SendRequestAsync    0x021bb97c arm
 *   NHTTPi_addRef              0x021befe4 arm
 *   NHTTPi_Connection2Response  0x021bebc8 arm
 */
#include "../types.h"
#include "nhttp_types.h"

#include "d_nhttp_common.h"
#include "nhttp_bgnend.h"
#include "nhttp_stdlib_ntr.h"
#include "nhttp_request.h"
#include "nhttp_os_ntr.h"
int NHTTP_WaitForConnection(NHTTPConnection *handle_p);
#include "nhttp_response.h"
NHTTPConnection *NHTTP_CreateConnection(char *url_p, int method, char *buf_p, u32 len, int (*callback)(NHTTPConnection *, int, void *), void *userParam_p);
int NHTTP_DeleteConnection(NHTTPConnection *handle_p);
int NHTTPi_DeleteConnection(NHTTPConnection *connection_p);
int NHTTP_StartConnection(void *handle);
int NHTTP_CancelConnection(void *handle);
int NHTTP_GetConnectionStatus(NHTTPConnection *handle_p);
int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);
void *NHTTP_GetUserParam(void *handle);
int NHTTP_GetConnectionError(NHTTPConnection *handle_p);
int NHTTP_GetConnectionProgress(void *handle, unsigned long *received_p, unsigned long *contentlen_p);

NHTTPConnection *NHTTP_CreateConnection(char *url_p, int method, char *buf_p, u32 len,
                               int (*callback)(NHTTPConnection *, int, void *), void *userParam_p)
{
    NHTTPConnection *connection_p;
    NHTTPSysInfo *sysInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPMutexInfo *mutexInfo_p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    connection_p = NHTTPi_alloc(0x804c, 0x20);
    if (connection_p == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        return 0;
    }
    NHTTPi_memclr(connection_p, 0x804c);
    connection_p->req_p = NHTTPi_CreateRequest(bgnEndInfo_p, url_p, method, buf_p, (long unsigned int)len, userParam_p, 0, 0);
    if (connection_p->req_p == 0) {
        NHTTPi_free(connection_p);
        return 0;
    }
    connection_p->res_p = connection_p->req_p->res_p;
    connection_p->status = 0;
    connection_p->connectionCallback = callback;
    connection_p->postDataBuf = 0;
    connection_p->postDataLen = 0;
    connection_p->reqId = -1;
    NHTTPi_CommitConnectionList(mutexInfo_p, connection_p);
    connection_p->nhttpError = 0xf;
    connection_p->sslError = 0;
    connection_p->running = 1;
    NHTTPi_SetVirtualContentLength(connection_p, 0);
    connection_p->reqCallback = 0;
    connection_p->tmpBufOffset = 0;
    connection_p->tmpBufRest = 0;
    NHTTPi_memclr(connection_p->tmpBuf, 0x8000);
    connection_p->ref = 1;
    return connection_p;
}

/*
 * Looks the connection up and deletes it; -1 when the handle is unknown.
 */
int NHTTP_DeleteConnection(NHTTPConnection *handle_p)
{
    NHTTPConnection *connection_p = NHTTPi_GetConnection(NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP()), handle_p);
    if (connection_p == 0)
        return -1;
    return NHTTPi_DeleteConnection(connection_p);
}

int NHTTPi_DeleteConnection(NHTTPConnection *connection_p)
{
    NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);

    NHTTPi_GetThreadInfoP(sysInfo_p);
    if (connection_p == 0)
        return -1;
    if (connection_p->ref > 0 && connection_p->reqId >= 0) {
        NHTTPi_CancelRequestAsync(sysInfo_p, connection_p->reqId);
        connection_p->reqId = -1;
    }
    if (NHTTPi_decRef(mutexInfo_p, connection_p) > 0)
        return 0;
    if (connection_p->req_p != 0 && connection_p->req_p->isStarted == 0)
        NHTTPi_DestroyRequest(sysInfo_p, connection_p->req_p);
    if (connection_p->res_p != 0) {
        if (connection_p->req_p != 0)
            NHTTP_WaitForConnection(connection_p);
        NHTTPi_DestroyResponse(mutexInfo_p, connection_p->res_p);
    }
    NHTTPi_OmitConnectionList(mutexInfo_p, connection_p);
    NHTTPi_free(connection_p);
    return 0;
}

int NHTTP_WaitForConnection(NHTTPConnection *handle_p)
{
    NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    NHTTPThreadInfo *threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    NHTTPConnection *connection_p;
    int status;

    connection_p = NHTTPi_GetConnection(NHTTPi_GetMutexInfoP(sysInfo_p), handle_p);
    if (connection_p == 0)
        return -1;
    status = NHTTP_GetConnectionStatus(handle_p);
    NHTTPi_CheckCurrentThread(threadInfo_p, 1);
    if (status != -1 && status != 0) {
        if (NHTTP_GetConnectionError(handle_p) == 0xf)
            NHTTPi_WaitForCompletion(connection_p);
    }
    return 0;
}

int NHTTP_StartConnection(void *handle)
{
    NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    NHTTPConnection *connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);

    if (connection_p == 0)
        return -1;
    if (connection_p->req_p == 0)
        return -1;
    connection_p->reqId = NHTTPi_SendRequestAsync(sysInfo_p, connection_p->req_p);
    if (connection_p->reqId >= 0) {
        connection_p->status = 1;
        NHTTPi_addRef(mutexInfo_p, connection_p);
    }
    return 0;
}

int NHTTP_CancelConnection(void *handle)
{
    NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    NHTTPConnection *connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);

    if (connection_p == 0)
        return -1;
    if (connection_p->reqId < 0)
        return -1;
    NHTTPi_CancelRequestAsync(sysInfo_p, connection_p->reqId);
    return 0;
}

/*
 * Connection status of the handle; -1 when the handle is unknown.
 */
int NHTTP_GetConnectionStatus(NHTTPConnection *handle_p)
{
    NHTTPConnection *connection_p = NHTTPi_GetConnection(NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP()), handle_p);
    if (connection_p == 0)
        return -1;
    return connection_p->status;
}

int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p)
{
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPConnection *connection_p;
    NHTTPRes *res_p;

    mutexInfo_p = NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP());
    connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);
    if (connection_p == 0)
        goto fail;
    res_p = NHTTPi_Connection2Response(mutexInfo_p, connection_p);
    if (res_p == 0)
        return -1;
    *value_pp = res_p->recvBuf_p;
    *size_p = res_p->recvBufLen;
    return res_p->bodyLen;
fail:
    return -1;
}

void *NHTTP_GetUserParam(void *handle)
{
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPConnection *connection_p;
    NHTTPRes *res_p;

    mutexInfo_p = NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP());
    connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);
    if (connection_p == 0)
        goto fail;
    res_p = NHTTPi_Connection2Response(mutexInfo_p, connection_p);
    return res_p ? res_p->param_p : 0;
fail:
    return 0;
}

/*
 * NHTTP error of the handle's connection; -1 when the handle is unknown.
 */
int NHTTP_GetConnectionError(NHTTPConnection *handle_p)
{
    NHTTPConnection *connection_p = NHTTPi_GetConnection(NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP()), handle_p);
    if (connection_p != 0)
        return connection_p->nhttpError;
    return -1;
}

int NHTTP_GetConnectionProgress(void *handle, unsigned long *received_p, unsigned long *contentlen_p)
{
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPConnection *connection_p;
    NHTTPRes *res_p;

    mutexInfo_p = NHTTPi_GetMutexInfoP(NHTTPi_GetSystemInfoP());
    connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);
    if (connection_p == 0)
        goto fail;
    res_p = NHTTPi_Connection2Response(mutexInfo_p, connection_p);
    if (res_p == 0)
        goto fail2;
    *received_p = res_p->totalBodyLen;
    *contentlen_p = (res_p->contentLength == 0xffffffff) ? 0 : res_p->contentLength;
    return 0;
fail2:
    return -1;
fail:
    return -1;
}
