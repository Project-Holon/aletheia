/*
 * function: NHTTPi_ThreadExecReqQueue
 * address:  0x021BD3B8
 * packet:   pkt_ov114_021BD3B8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ThreadExecReqQueue (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_lockReqList 0x021BEFCC arm ov114
 *   NHTTPi_GetListInfoP 0x021BEF40 arm ov114
 *   NHTTPi_popReqQueue 0x021BAEC8 arm ov114
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_unlockReqList 0x021BEFD8 arm ov114
 *   NHTTPi_GetThreadInfoP 0x021BEF50 arm ov114
 *   NHTTPi_idleCommThread 0x021B9BF4 arm ov114
 */

typedef struct {
    char pad[8];
    int a8;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef struct {
    int result;
} ThreadData;

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP();
extern void NHTTPi_lockReqList();
extern void *NHTTPi_GetListInfoP(int p);
struct Node;
extern struct Node *NHTTPi_popReqQueue(struct Node **a0);
extern void *NHTTPi_GetReqInfoP(int p);
extern void NHTTPi_unlockReqList(void *mutexInfo_p);
extern void *NHTTPi_GetThreadInfoP(void *sysInfo_p);
extern void NHTTPi_idleCommThread(int a);

int NHTTPi_ThreadExecReqQueue(ThreadData *threadData_p)
{
    void *sysInfo_p;
    void *mutexInfo_p;
    void *listInfo_p;
    ReqList *list_p;
    ReqInfo *reqInfo_p;
    void *threadInfo_p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    mutexInfo_p = NHTTPi_GetMutexInfoP();
    NHTTPi_lockReqList();
    listInfo_p = NHTTPi_GetListInfoP((int)sysInfo_p);
    list_p = (ReqList *)NHTTPi_popReqQueue(listInfo_p);
    if (list_p == 0) {
        threadData_p->result = -1;
    } else {
        reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
        threadData_p->result = list_p->a8;
        reqInfo_p->reqCurrent = list_p;
    }
    NHTTPi_unlockReqList(mutexInfo_p);
    if (threadData_p->result >= 0) {
        return 1;
    }
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    NHTTPi_idleCommThread((int)threadInfo_p);
    return 0;
}
