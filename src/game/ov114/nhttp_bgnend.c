/*
 * file:     nhttp_bgnend.c
 * unit:     yes
 * function: NHTTPi_InitBgnEndInfo, NHTTPi_alloc, NHTTPi_free, NHTTPi_SetError, NHTTPi_SetSSLError, NHTTPi_GetSSLError, NHTTPi_Startup, NHTTPi_CleanupAsync, NHTTPi_GetError
 * address:  0x021BA7DC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * libnhttp start up, clean up and the error words of the socket state.
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_GetListInfoP 0x021BEF40 arm ov114
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_GetThreadInfoP 0x021BEF50 arm ov114
 *   NHTTPi_InitListInfo 0x021BACEC arm ov114
 *   NHTTPi_InitRequestInfo 0x021BB3C0 arm ov114
 *   NHTTPi_initLockReqList 0x021BEFA4 arm ov114
 *   NHTTPi_InitConnectionList 0x021BEF6C arm ov114
 *   NHTTPi_exitLockReqList 0x021BEFC8 arm ov114
 *   NHTTPi_createCommThread 0x021B9B64 arm ov114
 *   NHTTPi_GetBgnEndInfoP          0x021BEF3C  arm ov114
 *   NHTTPi_GetThreadInfoP          0x021BEF50  arm ov114
 *   NHTTPi_CheckCurrentThread      0x021B9C1C  arm ov114
 *   NHTTPi_cancelAllRequests       0x021BBAAC  arm ov114
 *   NHTTPi_destroyCommThread       0x021B9BD4  arm ov114
 *   NHTTPi_free                    0x021BA850  arm ov114
 *   NHTTPi_exitLockReqList         0x021BEFC8  arm ov114
 *   NHTTPi_GetConnectionListLength 0x021BEC48  arm ov114
 *   NHTTPi_SocClose                0x021B9CFC  arm ov114
 */
#include "nhttp_types.h"


typedef enum { FALSE_, TRUE_ } BOOLE;

extern NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
extern NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(NHTTPSysInfo *sysInfo_p);
extern NHTTPListInfo *NHTTPi_GetListInfoP(NHTTPSysInfo *sysInfo_p);
extern NHTTPReqInfo *NHTTPi_GetReqInfoP(NHTTPSysInfo *sysInfo_p);
extern NHTTPMutexInfo *NHTTPi_GetMutexInfoP(NHTTPSysInfo *sysInfo_p);
extern NHTTPThreadInfo *NHTTPi_GetThreadInfoP(NHTTPSysInfo *sysInfo_p);
extern void NHTTPi_InitListInfo(NHTTPListInfo *listInfo_p);
extern void NHTTPi_InitRequestInfo(NHTTPReqInfo *reqInfo_p);
extern void NHTTPi_initLockReqList(NHTTPMutexInfo *mutexInfo_p);
extern void NHTTPi_InitConnectionList(void);
extern void NHTTPi_exitLockReqList();
extern int NHTTPi_createCommThread(NHTTPThreadInfo *threadInfo_p, unsigned long priority, unsigned long *stack_p);
extern NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(NHTTPSysInfo *sysInfo_p);
extern NHTTPThreadInfo *NHTTPi_GetThreadInfoP(NHTTPSysInfo *sysInfo_p);
extern void NHTTPi_CheckCurrentThread(NHTTPThreadInfo *threadInfo_p, BOOLE is);
extern void NHTTPi_cancelAllRequests(NHTTPSysInfo *sysInfo_p);
extern void NHTTPi_destroyCommThread(NHTTPThreadInfo *threadInfo_p, NHTTPBgnEndInfo *bgnEndInfo_p);
extern void NHTTPi_free(void *ptr_p);
extern void NHTTPi_exitLockReqList(void);
extern unsigned long NHTTPi_GetConnectionListLength(void);
extern int NHTTPi_SocClose(void *mutexInfo_p, NHTTPReq *req_p, int socket);
void NHTTPi_InitBgnEndInfo(NHTTPBgnEndInfo *info_p);
void *NHTTPi_alloc(unsigned long size, int align);
void NHTTPi_free(void *ptr_p);
void NHTTPi_SetError(NHTTPBgnEndInfo *bgnEndInfo_p, int error);
void NHTTPi_SetSSLError(NHTTPBgnEndInfo *bgnEndInfo_p, int sslError);
u32 NHTTPi_GetSSLError(NHTTPBgnEndInfo *bgnEndInfo_p);
int NHTTPi_Startup(NHTTPSysInfo *sysInfo_p, void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio);
void NHTTPi_CleanupAsync(NHTTPSysInfo *sysInfo_p, void (*callback)(void));
u32 NHTTPi_GetError(NHTTPBgnEndInfo *bgnEndInfo_p);



/*
 * sdk:      NHTTPi_InitBgnEndInfo (libnhttp.TWL.HYB.a(nhttp_bgnend.o))
 */
void NHTTPi_InitBgnEndInfo(NHTTPBgnEndInfo *info_p)
{
    info_p->alloc = 0;
    info_p->free = 0;
    info_p->isOpened = 0;
    info_p->socket = -1;
    NHTTPi_SetSSLError(info_p, 0);
    NHTTPi_SetError(info_p, 0);
    info_p->isThreadEnd = 0;
    info_p->commThreadStack = 0;
    info_p->forDebugCallback = 0;
}



void *NHTTPi_alloc(unsigned long size, int align)
{
    void *(*alloc)(unsigned long, int) = NHTTPi_GetSystemInfoP()->bgnEndInfo.alloc;
    if (alloc == 0)
        return 0;
    return alloc(size, align);
}



/*
 * Calls the free hook of the system info on the block, if the hook is set.
 */
void NHTTPi_free(void *ptr_p)
{
    void (*free)(void *) = NHTTPi_GetSystemInfoP()->bgnEndInfo.free;
    if (free != 0)
        free(ptr_p);
}


void NHTTPi_SetError(NHTTPBgnEndInfo *bgnEndInfo_p, int error)
{
    bgnEndInfo_p->error = error;
}


void NHTTPi_SetSSLError(NHTTPBgnEndInfo *bgnEndInfo_p, int sslError)
{
    bgnEndInfo_p->sslError = sslError;
}


u32 NHTTPi_GetSSLError(NHTTPBgnEndInfo *bgnEndInfo_p)
{
    return bgnEndInfo_p->sslError;
}



/*
 * sdk:      NHTTPi_Startup (libnhttp.TWL.HYB.a(nhttp_bgnend.o))
 */
int NHTTPi_Startup(NHTTPSysInfo *sysInfo_p, void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio)
{
    NHTTPThreadInfo *threadInfo_p;
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPListInfo *listInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    unsigned long *stack_p;

    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    listInfo_p = NHTTPi_GetListInfoP(sysInfo_p);
    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    bgnEndInfo_p->alloc = alloc;
    bgnEndInfo_p->free = free;
    bgnEndInfo_p->error = 0;
    bgnEndInfo_p->sslError = 0;
    bgnEndInfo_p->isThreadEnd = 0;
    bgnEndInfo_p->defaultRootCAId = 0;
    NHTTPi_InitListInfo(listInfo_p);
    NHTTPi_InitRequestInfo(reqInfo_p);
    NHTTPi_initLockReqList(mutexInfo_p);
    NHTTPi_InitConnectionList();
    bgnEndInfo_p->socket = -1;
    bgnEndInfo_p->commThreadStack = (void *)NHTTPi_alloc(0x2000, 8);
    stack_p = bgnEndInfo_p->commThreadStack;
    if (stack_p == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        NHTTPi_exitLockReqList();
        return 0;
    }
    if (NHTTPi_createCommThread(threadInfo_p, threadprio, stack_p) != 0) {
        bgnEndInfo_p->isOpened = 1;
        return 1;
    }
    NHTTPi_SetError(bgnEndInfo_p, 9);
    NHTTPi_free(bgnEndInfo_p->commThreadStack);
    bgnEndInfo_p->commThreadStack = 0;
    NHTTPi_exitLockReqList();
    return 0;
}



void NHTTPi_CleanupAsync(NHTTPSysInfo *sysInfo_p, void (*callback)(void))
{
    NHTTPBgnEndInfo *bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    NHTTPThreadInfo *threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);

    NHTTPi_CheckCurrentThread(threadInfo_p, TRUE_);
    NHTTPi_cancelAllRequests(sysInfo_p);
    NHTTPi_destroyCommThread(threadInfo_p, bgnEndInfo_p);
    NHTTPi_free(bgnEndInfo_p->commThreadStack);
    bgnEndInfo_p->commThreadStack = 0;
    NHTTPi_exitLockReqList();
    bgnEndInfo_p->isOpened = 0;
    if (callback)
        callback();
    NHTTPi_GetConnectionListLength();
    if (bgnEndInfo_p->socket >= 0) {
        NHTTPi_SocClose(0, 0, bgnEndInfo_p->socket);
        bgnEndInfo_p->socket = -1;
    }
}

u32 NHTTPi_GetError(NHTTPBgnEndInfo *bgnEndInfo_p)
{
    return bgnEndInfo_p->error;
}
