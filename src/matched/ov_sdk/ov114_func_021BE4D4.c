/*
 * function: func_021BE4D4
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
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BD220 0x021BD220 arm ov114
 *   func_021BD3B8 0x021BD3B8 arm ov114
 *   func_021BD430 0x021BD430 arm ov114
 *   func_021BD548 0x021BD548 arm ov114
 *   func_021BD6DC 0x021BD6DC arm ov114
 *   func_021BD7E8 0x021BD7E8 arm ov114
 *   func_021BDB68 0x021BDB68 arm ov114
 *   func_021BDD34 0x021BDD34 arm ov114
 *   func_021BDFF8 0x021BDFF8 arm ov114
 *   func_021BD270 0x021BD270 arm ov114
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

extern void *func_021BEF08(void);
extern BgnEnd *func_021BEF3C(void);
extern ReqInfo *func_021BEF48(void *sysInfo);
extern void func_021BD220(ThreadData *td);
extern int func_021BD3B8(ThreadData *td);
extern int func_021BD430(ThreadData *td);
extern int func_021BD548(ThreadData *td);
extern int func_021BD6DC(ThreadData *td);
extern int func_021BD7E8(ThreadData *td);
extern int func_021BDB68(ThreadData *td);
extern int func_021BDD34(ThreadData *td);
extern int func_021BDFF8(ThreadData *td);
extern void func_021BD270(ThreadData *td);

void func_021BE4D4(void)
{
    void *sysInfo_p;
    BgnEnd *bgnEndInfo_p;
    ReqInfo *reqInfo_p;
    ThreadData threadData;

    sysInfo_p = func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    reqInfo_p = func_021BEF48(sysInfo_p);
    func_021BD220(&threadData);
    while (bgnEndInfo_p->isThreadEnd == 0) {
        if (threadData.restartConnect == 0) {
            if (func_021BD3B8(&threadData) == 0) {
                continue;
            }
            if (reqInfo_p->reqCurrent->req_p->doCancel != 0) {
                func_021BD270(&threadData);
                continue;
            }
            if (func_021BD430(&threadData) == 0) {
                func_021BD270(&threadData);
                continue;
            }
        }
        if (threadData.restartConnect == 1) {
            threadData.restartConnect = 0;
        }
        if (func_021BD548(&threadData) == 0) {
            func_021BD270(&threadData);
            continue;
        }
        switch (func_021BD6DC(&threadData)) {
        case 0:
            break;
        case 2:
            threadData.restartConnect = 1;
            continue;
        case 1:
            func_021BD270(&threadData);
            continue;
        }
        switch (func_021BD7E8(&threadData)) {
        case 0:
            break;
        case 2:
            threadData.restartConnect = 1;
            continue;
        case 1:
        case 3:
            func_021BD270(&threadData);
            continue;
        }
        if (reqInfo_p->reqCurrent->req_p->doCancel != 0) {
            func_021BD270(&threadData);
            continue;
        }
        if (func_021BDB68(&threadData) == 0) {
            func_021BD270(&threadData);
            continue;
        }
        if (func_021BDD34(&threadData) == 0) {
            func_021BD270(&threadData);
            continue;
        }
        func_021BDFF8(&threadData);
        func_021BD270(&threadData);
    }
}
