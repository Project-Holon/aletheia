/*
 * function: NHTTPi_cancelAllRequests
 * address:  0x021BBAAC
 * packet:   pkt_ov114_021BBAAC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_cancelAllRequests (libnhttp.TWL.HYB.a(nhttp_request.o))
 *
 * symbols:
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_GetListInfoP 0x021BEF40 arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_lockReqList 0x021BEFCC arm ov114
 *   NHTTPi_SocCancel 0x021BA068 arm ov114
 *   NHTTPi_allFreeReqQueue 0x021BAE90 arm ov114
 *   NHTTPi_unlockReqList 0x021BEFD8 arm ov114
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

typedef struct {
    int doCancel;
} Req;

typedef struct {
    char pad[0xc];
    Req *volatile req_p;
    int arg;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

extern void *NHTTPi_GetReqInfoP(int p);
typedef unsigned int   u32;
extern void *NHTTPi_GetListInfoP(int p);
extern void *NHTTPi_GetMutexInfoP(int p);
extern void NHTTPi_lockReqList(void);
extern void NHTTPi_SocCancel(int a, int b, int c);
extern void NHTTPi_allFreeReqQueue(u32 **p, int v);
extern void NHTTPi_unlockReqList(void *mutexInfo_p);

void NHTTPi_cancelAllRequests(void *sysInfo_p)
{
    ReqInfo *reqInfo_p;
    void *listInfo_p;
    void *mutexInfo_p;
    ReqList *reqCurrent_p;

    reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    listInfo_p = NHTTPi_GetListInfoP((int)sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP((int)sysInfo_p);
    reqCurrent_p = reqInfo_p->reqCurrent;
    NHTTPi_lockReqList();
    if (reqCurrent_p) {
        if (reqCurrent_p->req_p->doCancel == 0) {
            reqCurrent_p->req_p->doCancel = 1;
            NHTTPi_SocCancel((int)mutexInfo_p, (int)reqCurrent_p->req_p, reqCurrent_p->arg);
        }
    }
    NHTTPi_allFreeReqQueue(listInfo_p, (int)mutexInfo_p);
    NHTTPi_unlockReqList(mutexInfo_p);
}
