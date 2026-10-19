/*
 * file:     d_nhttp_common.c
 * unit:     yes
 * function: NHTTPi_GetStaticResource, NHTTPi_WaitForCompletion, NHTTPi_NotifyCompletion, NHTTPi_ControlConnectionList, NHTTPi_CommitConnectionList, NHTTPi_OmitConnectionList, NHTTPi_Connection2Response, NHTTPi_Request2Connection, NHTTPi_Response2Connection, NHTTPi_GetConnection, NHTTPi_GetRequest, NHTTPi_GetResponse, NHTTPi_GetConnectionListLength, NHTTPi_PostSendCallback, NHTTPi_BufferFullCallback, NHTTPi_ReceivedCallback, NHTTPi_CompleteCallback, NHTTPi_SetPostDataBuffer, NHTTPi_SetBodyBuffer, NHTTPi_InitSystemInfo, NHTTPi_GetSystemInfoP, NHTTPi_GetBgnEndInfoP, NHTTPi_GetListInfoP, NHTTPi_GetReqInfoP, NHTTPi_GetThreadInfoP, NHTTPi_GetMutexInfoP, NHTTPi_SetVirtualContentLength, NHTTPi_InitConnectionList, NHTTPi_InitMutexInfo, NHTTPi_initLockReqList, NHTTPi_exitLockReqList, NHTTPi_lockReqList, NHTTPi_unlockReqList, NHTTPi_addRef, NHTTPi_decRef
 * address:  0x021BEA20
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
 *   NHTTPi_InitMutex 0x021B9B4C arm ov114
 *   NHTTPi_InitBgnEndInfo  0x021BA7DC  arm  ov114
 *   NHTTPi_InitListInfo  0x021BACEC  arm  ov114
 *   NHTTPi_InitRequestInfo  0x021BB3C0  arm  ov114
 *   NHTTPi_InitThreadInfo  0x021BBE94  arm  ov114
 *   gNHTTPModuleGlobals 0x021CF984 data
 *   g_021CF984_hdr 0x021CF984 data
 *   gNHTTPStaticResource 0x021CF98C data
 *   gNHTTPSystemInfo  0x021CF9C0  data
 *   gNHTTPSslSeed  0x021CF964  data
 *   NHTTPi_LockMutexThunk  0x021B9B58  arm  ov114
 *   OS_SleepThread  0x020857B0  arm  arm9
 *   OS_WakeupThread  0x02085800  arm  arm9
 *   OS_UnlockMutex  0x02086078  arm  arm9
 */
typedef unsigned int u32;
#include "nhttp_types.h"

/* Static resource block (size 0x24): init flag, a mutex and a thread queue. */
typedef struct {
    int unique;
    int mutex[6];
    int queueHead;
    int queueTail;
} NHTTPStaticResource;

typedef struct {
    u8 pad_0[0xc];
    u32 waitQueue;
} NHTTPWaiter;

extern void NHTTPi_InitMutex(int *mutex_p);
extern void OS_SleepThread(void *);
extern void OS_WakeupThread(void *, int);
extern void NHTTPi_InitBgnEndInfo(NHTTPBgnEndInfo *);
extern void NHTTPi_InitListInfo(NHTTPListInfo *);
extern void NHTTPi_InitRequestInfo(NHTTPReqInfo *);
extern void NHTTPi_InitThreadInfo(NHTTPThreadInfo *);
extern void NHTTPi_LockMutexThunk(int *mutex_p);
struct OSMutex;
extern void OS_UnlockMutex(struct OSMutex *mutex);
NHTTPStaticResource *NHTTPi_GetStaticResource(void);
void NHTTPi_WaitForCompletion(NHTTPWaiter *waiter_p);
void NHTTPi_NotifyCompletion(NHTTPWaiter *waiter_p);
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
extern NHTTPModuleGlobals gNHTTPModuleGlobals;
extern NHTTPModuleGlobals g_021CF984_hdr;
extern NHTTPStaticResource gNHTTPStaticResource;
extern u8 gNHTTPSystemInfo[];



/*
 * sdk:      NHTTPi_GetStaticResource (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 */
NHTTPStaticResource *NHTTPi_GetStaticResource(void)
{
    NHTTPStaticResource *resource_p = &gNHTTPStaticResource;
    if (gNHTTPModuleGlobals.isInitialized == 0) {
        NHTTPi_InitMutex(&resource_p->mutex[0]);
        resource_p->queueTail = 0;
        resource_p->queueHead = 0;
        resource_p->unique = 1;
    }
    return resource_p;
}



/*
 * Waits on the static resource queue until the waiter's queue word is clear.
 */
void NHTTPi_WaitForCompletion(NHTTPWaiter *waiter_p)
{
    NHTTPStaticResource *resource_p = NHTTPi_GetStaticResource();
    while (waiter_p->waitQueue != 0)
        OS_SleepThread(&resource_p->queueHead);
}



/*
 * Clears the waiter's queue word and wakes the static resource queue.
 */
void NHTTPi_NotifyCompletion(NHTTPWaiter *waiter_p)
{
    NHTTPStaticResource *resource_p = NHTTPi_GetStaticResource();
    waiter_p->waitQueue = 0;
    OS_WakeupThread(&resource_p->queueHead, 0);
}



NHTTPConnection *NHTTPi_ControlConnectionList(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *handle_p, unsigned long order)
{
    NHTTPConnection *ret_p = 0;
    NHTTPConnection **connection_pp;
    NHTTPConnection *connection_p;

    NHTTPi_lockReqList(mutexInfo_p);
    if (order == 3) {
        ret_p = handle_p;
        handle_p->next_p = gNHTTPModuleGlobals.connListHead;
        gNHTTPModuleGlobals.connListHead = handle_p;
    } else {
        connection_pp = &g_021CF984_hdr.connListHead;
        connection_p = gNHTTPModuleGlobals.connListHead;
        while (connection_p != 0) {
            switch (order) {
            case 0:
                if (connection_p == handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 1:
                if (connection_p->req_p == (void *)handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 2:
                if (connection_p->res_p == (void *)handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 4:
                if (connection_p == handle_p) {
                    ret_p = *connection_pp;
                    *connection_pp = ret_p->next_p;
                }
                break;
            }
            if (ret_p != 0) {
                break;
            }
            connection_pp = &(*connection_pp)->next_p;
            connection_p = *connection_pp;
        }
    }
    NHTTPi_unlockReqList(mutexInfo_p);
    return ret_p;
}



int NHTTPi_CommitConnectionList(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *handle_p)
{
    return -(NHTTPi_ControlConnectionList(mutexInfo_p, handle_p, 3) == 0);
}



int NHTTPi_OmitConnectionList(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *handle_p)
{
    return -(NHTTPi_ControlConnectionList(mutexInfo_p, handle_p, 4) == 0);
}



NHTTPRes *NHTTPi_Connection2Response(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *handle_p)
{
    NHTTPConnection *connection_p = NHTTPi_GetConnection(mutexInfo_p, handle_p);

    return connection_p ? connection_p->res_p : 0;
}



/*
 * ov114 tail-call thunk: NHTTPi_ControlConnectionList(mutexInfo, req, 1) via `ldr ip,pool; bx ip`.
 */
NHTTPConnection *NHTTPi_Request2Connection(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p)
{
    return NHTTPi_ControlConnectionList(mutexInfo_p, (NHTTPConnection *)req_p, 1);
}



/*
 * ov114 tail-call thunk: NHTTPi_ControlConnectionList(mutexInfo, res, 2) via `ldr ip,pool; bx ip`.
 */
NHTTPConnection *NHTTPi_Response2Connection(NHTTPMutexInfo *mutexInfo_p, NHTTPRes *res_p)
{
    return NHTTPi_ControlConnectionList(mutexInfo_p, (NHTTPConnection *)res_p, 2);
}



NHTTPConnection *NHTTPi_GetConnection(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *handle_p)
{
    return NHTTPi_ControlConnectionList(mutexInfo_p, handle_p, 0);
}



/*
 * Looks the connection up and returns its request, or the handle when absent.
 */
void *NHTTPi_GetRequest(NHTTPMutexInfo *mutexInfo_p, void *handle_p)
{
    NHTTPConnection *connection_p = NHTTPi_GetConnection(mutexInfo_p, handle_p);
    if (connection_p != 0)
        handle_p = connection_p->req_p;
    return handle_p;
}



/*
 * Looks the connection up and returns its response, or the handle when absent.
 */
void *NHTTPi_GetResponse(NHTTPMutexInfo *mutexInfo_p, void *handle_p)
{
    NHTTPConnection *connection_p = NHTTPi_GetConnection(mutexInfo_p, handle_p);
    if (connection_p != 0)
        handle_p = connection_p->res_p;
    return handle_p;
}



/*
 * Counts the entries on the connection list.
 */
u32 NHTTPi_GetConnectionListLength(void)
{
    u32 count = 0;
    NHTTPConnection *connection_p = gNHTTPModuleGlobals.connListHead;
    while (connection_p != 0) {
        connection_p = connection_p->next_p;
        count++;
    }
    return count;
}



/*
 * sdk:      NHTTPi_PostSendCallback (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 */
int NHTTPi_PostSendCallback(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p, char *label_p, int offset)
{
    NHTTPPostSendArg arg;
    NHTTPRes *res_p;
    int ret = -1;

    if (NHTTPi_GetConnection(mutexInfo_p, connection_p) != 0) {
        res_p = NHTTPi_Connection2Response(mutexInfo_p, connection_p);
        if (res_p != 0 && connection_p->connectionCallback != 0) {
            arg.label = label_p;
            arg.value = connection_p->postDataBuf;
            arg.length = connection_p->postDataLen;
            arg.offset = offset;
            ret = connection_p->connectionCallback(connection_p, 1, &arg);
            NHTTPi_SetPostDataBuffer(mutexInfo_p, connection_p, arg.value, arg.length);
        }
    }
    return ret;
}



void NHTTPi_BufferFullCallback(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p)
{
    NHTTPBodyBufArg arg;
    NHTTPRes *res_p;

    if (NHTTPi_GetConnection(mutexInfo_p, connection_p) != 0) {
        res_p = NHTTPi_Connection2Response(mutexInfo_p, connection_p);
        if (res_p != 0 && connection_p->connectionCallback != 0) {
            arg.buf = res_p->recvBuf_p;
            arg.length = res_p->recvBufLen;
            arg.offset = res_p->bodyLen;
            connection_p->connectionCallback(connection_p, 2, &arg);
            NHTTPi_SetBodyBuffer(mutexInfo_p, connection_p, arg.buf, arg.length, arg.offset);
        }
    }
}



/*
 * sdk:      NHTTPi_ReceivedCallback (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 */
void NHTTPi_ReceivedCallback(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p)
{
    NHTTPBodyBufArg arg;
    NHTTPRes *res_p;

    if (NHTTPi_GetConnection(mutexInfo_p, connection_p) != 0) {
        res_p = NHTTPi_Connection2Response(mutexInfo_p, connection_p);
        if (res_p != 0 && connection_p->connectionCallback != 0) {
            arg.buf = res_p->recvBuf_p;
            arg.length = res_p->recvBufLen;
            arg.offset = res_p->bodyLen;
            connection_p->connectionCallback(connection_p, 3, &arg);
            NHTTPi_SetBodyBuffer(mutexInfo_p, connection_p, arg.buf, arg.length, arg.offset);
        }
    }
}



void NHTTPi_CompleteCallback(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p)
{
    int (*callback)(NHTTPConnection *, int, void *);
    if (NHTTPi_GetConnection(mutexInfo_p, connection_p) == 0)
        return;
    callback = connection_p->connectionCallback;
    if (callback == 0)
        return;
    callback(connection_p, 4, 0);
}



/*
 * Stores the post data buffer and length on the connection; -1 when the connection is absent.
 */
int NHTTPi_SetPostDataBuffer(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p, void *buf_p, unsigned long length)
{
    NHTTPConnection *found_p = NHTTPi_GetConnection(mutexInfo_p, connection_p);
    if (found_p == 0)
        return -1;
    found_p->postDataBuf = buf_p;
    found_p->postDataLen = length;
    return 0;
}



int NHTTPi_SetBodyBuffer(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p, void *buf_p, unsigned long length, unsigned long offset)
{
    NHTTPConnection *found_p = NHTTPi_GetConnection(mutexInfo_p, connection_p);
    if (found_p) {
        NHTTPRes *res_p = NHTTPi_Connection2Response(mutexInfo_p, found_p);
        if (res_p == 0) {
            return -1;
        }
        res_p->recvBuf_p = buf_p;
        res_p->recvBufLen = length;
        res_p->bodyLen = offset;
        return 0;
    }
    return -1;
}



void NHTTPi_InitSystemInfo(NHTTPSysInfo *sysInfo_p)
{
    NHTTPi_InitBgnEndInfo(NHTTPi_GetBgnEndInfoP(sysInfo_p));
    NHTTPi_InitListInfo(NHTTPi_GetListInfoP(sysInfo_p));
    NHTTPi_InitRequestInfo(NHTTPi_GetReqInfoP(sysInfo_p));
    NHTTPi_InitMutexInfo(NHTTPi_GetMutexInfoP(sysInfo_p));
    NHTTPi_InitThreadInfo(NHTTPi_GetThreadInfoP(sysInfo_p));
}



NHTTPSysInfo *NHTTPi_GetSystemInfoP(void)
{
    NHTTPSysInfo *sysInfo_p = gNHTTPModuleGlobals.sysInfo_p;
    if (sysInfo_p == 0) {
        sysInfo_p = (NHTTPSysInfo *)gNHTTPSystemInfo;
        gNHTTPModuleGlobals.sysInfo_p = sysInfo_p;
        NHTTPi_InitSystemInfo(sysInfo_p);
    }
    return sysInfo_p;
}


/*
 * Returns the first member, so the body is a `bx lr`.
 */
NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(NHTTPSysInfo *sysInfo_p)
{
    return &sysInfo_p->bgnEndInfo;
}


NHTTPListInfo *NHTTPi_GetListInfoP(NHTTPSysInfo *sysInfo_p)
{
    return &sysInfo_p->listInfo;
}


NHTTPReqInfo *NHTTPi_GetReqInfoP(NHTTPSysInfo *sysInfo_p)
{
    return &sysInfo_p->reqInfo;
}


NHTTPThreadInfo *NHTTPi_GetThreadInfoP(NHTTPSysInfo *sysInfo_p)
{
    return &sysInfo_p->threadInfo;
}


NHTTPMutexInfo *NHTTPi_GetMutexInfoP(NHTTPSysInfo *sysInfo_p)
{
    return &sysInfo_p->mutexInfo;
}


/*
 * Null-guarded setter of the virtual content length.
 */
void NHTTPi_SetVirtualContentLength(NHTTPConnection *connection_p, u32 virtualContentLength)
{
    if (connection_p != 0)
        connection_p->virtualContentLength = virtualContentLength;
}



/*
 * Drains the module list, then empties the module head pointer.
 */
void NHTTPi_InitConnectionList(void)
{
    if (gNHTTPModuleGlobals.connListHead != 0)
        NHTTPi_GetConnectionListLength();
    gNHTTPModuleGlobals.connListHead = 0;
}


void NHTTPi_InitMutexInfo(NHTTPMutexInfo *mutexInfo_p)
{
    mutexInfo_p->isInitialized = 0;
}



/*
 * One-shot bring-up: initialises the mutex once and latches the flag.
 */
void NHTTPi_initLockReqList(NHTTPMutexInfo *mutexInfo_p)
{
    if (mutexInfo_p->isInitialized != 0)
        return;
    NHTTPi_InitMutex(mutexInfo_p->mutex);
    mutexInfo_p->isInitialized = 1;
}


/*
 * Empty ARM stub: `bx lr`.
 */
void NHTTPi_exitLockReqList(void)
{
}



/*
 * unblocked: NHTTPi_LockMutexThunk (the ARM veneer `ldr ip,[pc]; bx ip; .word
 *   0x02086028`, printed as a .word run in ov114) was matched as the same
 *   far-tail-call shape and filed as pkt_ov114_021B9B58; the ABS32 site then
 *   attests as `matched, overlay`.
 *
 * Tail-call thunk to the ARM stub at 0x021B9B58.
 */
void NHTTPi_lockReqList(NHTTPMutexInfo *mutexInfo_p)
{
    NHTTPi_LockMutexThunk((int *)mutexInfo_p);
}



/*
 * ov114 tail-call thunk (ldr ip,pool; bx ip).
 */
void NHTTPi_unlockReqList(NHTTPMutexInfo *mutexInfo_p)
{
    OS_UnlockMutex((struct OSMutex *)mutexInfo_p);
}



int NHTTPi_addRef(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p)
{
    NHTTPi_lockReqList(mutexInfo_p);
    ++connection_p->ref;
    NHTTPi_unlockReqList(mutexInfo_p);
    return connection_p->ref;
}



int NHTTPi_decRef(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p)
{
    NHTTPi_lockReqList(mutexInfo_p);
    --connection_p->ref;
    NHTTPi_unlockReqList(mutexInfo_p);
    return connection_p->ref;
}
