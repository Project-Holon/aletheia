/*
 * function: NHTTPi_CommThreadProcMain
 * address:  0x021BE4D4
 * packet:   pkt_ov114_021BE4D4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_CommThreadProcMain (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_ThreadInit 0x021BD220 arm ov114
 *   NHTTPi_ThreadExecReqQueue 0x021BD3B8 arm ov114
 *   NHTTPi_ThreadHostAddrProc 0x021BD430 arm ov114
 *   NHTTPi_ThreadConnectProc 0x021BD548 arm ov114
 *   NHTTPi_ThreadProxyProc 0x021BD6DC arm ov114
 *   NHTTPi_ThreadSendProc 0x021BD7E8 arm ov114
 *   NHTTPi_ThreadRecvHeaderProc 0x021BDB68 arm ov114
 *   NHTTPi_ThreadParseHeaderProc 0x021BDD34 arm ov114
 *   NHTTPi_ThreadRecvBodyProc 0x021BDFF8 arm ov114
 *   NHTTPi_ThreadReqEnd 0x021BD270 arm ov114
 */

typedef struct {
    char pad[0x334];
    int restartConnect;
    int isKeepAlive;
    int isChunked;
} ThreadData;

typedef struct {
    int doCancel;
} Req;

typedef struct {
    char pad[0xc];
    Req *req_p;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef struct {
    char pad[0x18];
    int isThreadEnd;
} BgnEnd;

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern BgnEnd *NHTTPi_GetBgnEndInfoP(void);
struct _NHTTPThreadData;
extern void *NHTTPi_GetReqInfoP(int p);
extern void NHTTPi_ThreadInit(ThreadData *td);
extern int NHTTPi_ThreadExecReqQueue(ThreadData *td);
extern int NHTTPi_ThreadHostAddrProc(ThreadData *td);
extern int NHTTPi_ThreadConnectProc(struct _NHTTPThreadData *threadData_p);
extern int NHTTPi_ThreadProxyProc(ThreadData *td);
extern int NHTTPi_ThreadSendProc(ThreadData *td);
extern int NHTTPi_ThreadRecvHeaderProc(struct _NHTTPThreadData *threadData_p);
extern int NHTTPi_ThreadParseHeaderProc(ThreadData *td);
extern int NHTTPi_ThreadRecvBodyProc(ThreadData *td);
extern void NHTTPi_ThreadReqEnd(struct _NHTTPThreadData *threadData_p);

void NHTTPi_CommThreadProcMain(void)
{
    void *sysInfo_p;
    BgnEnd *bgnEndInfo_p;
    ReqInfo *reqInfo_p;
    ThreadData threadData;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    NHTTPi_ThreadInit(&threadData);
    while (bgnEndInfo_p->isThreadEnd == 0) {
        if (threadData.restartConnect == 0) {
            if (NHTTPi_ThreadExecReqQueue(&threadData) == 0) {
                continue;
            }
            if (reqInfo_p->reqCurrent->req_p->doCancel != 0) {
                NHTTPi_ThreadReqEnd((struct _NHTTPThreadData *)(&threadData));
                continue;
            }
            if (NHTTPi_ThreadHostAddrProc(&threadData) == 0) {
                NHTTPi_ThreadReqEnd((struct _NHTTPThreadData *)(&threadData));
                continue;
            }
        }
        if (threadData.restartConnect == 1) {
            threadData.restartConnect = 0;
        }
        if (NHTTPi_ThreadConnectProc((struct _NHTTPThreadData *)(&threadData)) == 0) {
            NHTTPi_ThreadReqEnd((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        switch (NHTTPi_ThreadProxyProc(&threadData)) {
        case 0:
            break;
        case 2:
            threadData.restartConnect = 1;
            continue;
        case 1:
            NHTTPi_ThreadReqEnd((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        switch (NHTTPi_ThreadSendProc(&threadData)) {
        case 0:
            break;
        case 2:
            threadData.restartConnect = 1;
            continue;
        case 1:
        case 3:
            NHTTPi_ThreadReqEnd((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        if (reqInfo_p->reqCurrent->req_p->doCancel != 0) {
            NHTTPi_ThreadReqEnd((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        if (NHTTPi_ThreadRecvHeaderProc((struct _NHTTPThreadData *)(&threadData)) == 0) {
            NHTTPi_ThreadReqEnd((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        if (NHTTPi_ThreadParseHeaderProc(&threadData) == 0) {
            NHTTPi_ThreadReqEnd((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        NHTTPi_ThreadRecvBodyProc(&threadData);
        NHTTPi_ThreadReqEnd((struct _NHTTPThreadData *)(&threadData));
    }
}
