/*
 * function: NHTTPi_Startup
 * address:  0x021BA88C
 * packet:   pkt_ov114_021BA88C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_Startup (libnhttp.TWL.HYB.a(nhttp_bgnend.o))
 *
 * symbols:
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_GetListInfoP 0x021BEF40 arm ov114
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_GetThreadInfoP 0x021BEF50 arm ov114
 *   NHTTPi_InitListInfo 0x021BACEC arm ov114
 *   NHTTPi_InitRequestInfo 0x021BB3C0 arm ov114
 *   NHTTPi_initLockReqList 0x021BEFA4 arm ov114
 *   NHTTPi_InitConnectionList 0x021BEF6C arm ov114
 *   NHTTPi_alloc 0x021BA820 arm ov114
 *   NHTTPi_SetError 0x021BA874 arm ov114
 *   NHTTPi_exitLockReqList 0x021BEFC8 arm ov114
 *   NHTTPi_createCommThread 0x021B9B64 arm ov114
 *   NHTTPi_free 0x021BA850 arm ov114
 */

typedef struct {
    void *(*alloc)(unsigned long, int);
    void (*free)(void *);
    int opened;
    int fc;
    int f10;
    int f14;
    int f18;
    void *buf;
    int f20;
    int f24;
} BgnEnd;

extern BgnEnd *NHTTPi_GetBgnEndInfoP(void);
extern void *NHTTPi_GetListInfoP(int p);
extern void *NHTTPi_GetReqInfoP(int p);
extern void *NHTTPi_GetMutexInfoP(int p);
extern void *NHTTPi_GetThreadInfoP(int p);
typedef unsigned char  u8;
extern void NHTTPi_InitListInfo(u8 *p);
extern void NHTTPi_InitRequestInfo(u8 *p);
extern void NHTTPi_initLockReqList(u8 *p);
extern void NHTTPi_InitConnectionList(void);
extern int NHTTPi_alloc(int a, int b);
extern void NHTTPi_SetError(u8 *p, int v);
extern void NHTTPi_exitLockReqList();
extern int NHTTPi_createCommThread(void *threadInfo_p, unsigned long priority, unsigned long *stack_p);
extern void NHTTPi_free(int a);

int NHTTPi_Startup(void *sysInfo_p, void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio)
{
    void *threadInfo_p;
    void *mutexInfo_p;
    void *reqInfo_p;
    void *listInfo_p;
    BgnEnd *bgnEndInfo_p;
    unsigned long *stack_p;

    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP();
    listInfo_p = NHTTPi_GetListInfoP((int)sysInfo_p);
    reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP((int)sysInfo_p);
    threadInfo_p = NHTTPi_GetThreadInfoP((int)sysInfo_p);
    bgnEndInfo_p->alloc = alloc;
    bgnEndInfo_p->free = free;
    bgnEndInfo_p->f14 = 0;
    bgnEndInfo_p->f10 = 0;
    bgnEndInfo_p->f18 = 0;
    bgnEndInfo_p->f24 = 0;
    NHTTPi_InitListInfo(listInfo_p);
    NHTTPi_InitRequestInfo(reqInfo_p);
    NHTTPi_initLockReqList(mutexInfo_p);
    NHTTPi_InitConnectionList();
    bgnEndInfo_p->fc = -1;
    bgnEndInfo_p->buf = (void *)NHTTPi_alloc(0x2000, 8);
    stack_p = bgnEndInfo_p->buf;
    if (stack_p == 0) {
        NHTTPi_SetError((u8 *)bgnEndInfo_p, 1);
        NHTTPi_exitLockReqList();
        return 0;
    }
    if (NHTTPi_createCommThread(threadInfo_p, threadprio, stack_p) != 0) {
        bgnEndInfo_p->opened = 1;
        return 1;
    }
    NHTTPi_SetError((u8 *)bgnEndInfo_p, 9);
    NHTTPi_free((int)bgnEndInfo_p->buf);
    bgnEndInfo_p->buf = 0;
    NHTTPi_exitLockReqList();
    return 0;
}
