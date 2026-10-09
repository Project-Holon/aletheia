/*
 * file:     unit_021BA88C.c
 * unit:     yes
 * function: func_021BA88C, func_021BA988
 * address:  0x021BA88C
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
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF40 0x021BEF40 arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BEF50 0x021BEF50 arm ov114
 *   func_021BACEC 0x021BACEC arm ov114
 *   func_021BB3C0 0x021BB3C0 arm ov114
 *   func_021BEFA4 0x021BEFA4 arm ov114
 *   func_021BEF6C 0x021BEF6C arm ov114
 *   func_021BA820 0x021BA820 arm ov114
 *   func_021BA874 0x021BA874 arm ov114
 *   func_021BEFC8 0x021BEFC8 arm ov114
 *   func_021B9B64 0x021B9B64 arm ov114
 *   func_021BA850 0x021BA850 arm ov114
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

extern NHTTPBgnEndInfo *func_021BEF3C(void);
extern void *func_021BEF40(int p);
extern void *func_021BEF48(int p);
extern void *func_021BEF58(int p);
extern void *func_021BEF50(int p);
extern void func_021BACEC(u8 *p);
extern void func_021BB3C0(u8 *p);
extern void func_021BEFA4(u8 *p);
extern void func_021BEF6C(void);
extern int func_021BA820(int a, int b);
extern void func_021BA874(u8 *p, int v);
extern void func_021BEFC8();
extern int func_021B9B64(void *threadInfo_p, unsigned long priority, unsigned long *stack_p);
extern void func_021BA850(int a);
extern NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(NHTTPSysInfo *sysInfo_p);
extern NHTTPThreadInfo *NHTTPi_GetThreadInfoP(NHTTPSysInfo *sysInfo_p);
extern void NHTTPi_CheckCurrentThread(NHTTPThreadInfo *threadInfo_p, BOOLE is);
extern void NHTTPi_cancelAllRequests(NHTTPSysInfo *sysInfo_p);
extern void NHTTPi_destroyCommThread(NHTTPThreadInfo *threadInfo_p, NHTTPBgnEndInfo *bgnEndInfo_p);
extern void NHTTPi_free(void *ptr_p);
extern void NHTTPi_exitLockReqList(void);
extern unsigned long NHTTPi_GetConnectionListLength(void);
extern int NHTTPi_SocClose(void *mutexInfo_p, NHTTPReq *req_p, int socket);
int func_021BA88C(void *sysInfo_p, void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio);
void NHTTPi_CleanupAsync(NHTTPSysInfo *sysInfo_p, void (*callback)(void));


/*
 * sdk:      NHTTPi_Startup (libnhttp.TWL.HYB.a(nhttp_bgnend.o))
 */
int func_021BA88C(void *sysInfo_p, void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio)
{
    void *threadInfo_p;
    void *mutexInfo_p;
    void *reqInfo_p;
    void *listInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    unsigned long *stack_p;

    bgnEndInfo_p = func_021BEF3C();
    listInfo_p = func_021BEF40((int)sysInfo_p);
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    mutexInfo_p = func_021BEF58((int)sysInfo_p);
    threadInfo_p = func_021BEF50((int)sysInfo_p);
    bgnEndInfo_p->alloc = alloc;
    bgnEndInfo_p->free = free;
    bgnEndInfo_p->error = 0;
    bgnEndInfo_p->sslError = 0;
    bgnEndInfo_p->isThreadEnd = 0;
    bgnEndInfo_p->defaultRootCAId = 0;
    func_021BACEC(listInfo_p);
    func_021BB3C0(reqInfo_p);
    func_021BEFA4(mutexInfo_p);
    func_021BEF6C();
    bgnEndInfo_p->socket = -1;
    bgnEndInfo_p->commThreadStack = (void *)func_021BA820(0x2000, 8);
    stack_p = bgnEndInfo_p->commThreadStack;
    if (stack_p == 0) {
        func_021BA874((u8 *)bgnEndInfo_p, 1);
        func_021BEFC8();
        return 0;
    }
    if (func_021B9B64(threadInfo_p, threadprio, stack_p) != 0) {
        bgnEndInfo_p->isOpened = 1;
        return 1;
    }
    func_021BA874((u8 *)bgnEndInfo_p, 9);
    func_021BA850((int)bgnEndInfo_p->commThreadStack);
    bgnEndInfo_p->commThreadStack = 0;
    func_021BEFC8();
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
