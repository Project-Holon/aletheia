/*
 * function: func_021BD548
 * address:  0x021BD548
 * packet:   pkt_ov114_021BD548
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ThreadConnectProc (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF3C  0x021BEF3C  arm  ov114
 *   func_021BEF48  0x021BEF48  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   func_021B9CA4  0x021B9CA4  arm  ov114
 *   func_021B9CFC  0x021B9CFC  arm  ov114
 *   func_021B9CE4  0x021B9CE4  arm  ov114
 *   func_021BEFCC  0x021BEFCC  arm  ov114
 *   func_021BEFD8  0x021BEFD8  arm  ov114
 *   func_021B9D8C  0x021B9D8C  arm  ov114
 *   func_021BA884  0x021BA884  arm  ov114
 *
 * The DWARF declares NHTTPi_SocClose(req_p, socket) and NHTTPi_SocOpen(void),
 * but the object passes (mutexInfo_p, req_p, socket) and req_p in r0.
 */

typedef unsigned long u32;

typedef struct _NHTTPThreadData {
    int id;
    char pad4[0x314 - 4];
    u32 hostaddr;
    char pad318[4];
    int port;
    char pad320[0x330 - 0x320];
    int result;
    char pad334[4];
    int isKeepAlive;
} NHTTPThreadData;

typedef struct _NHTTPReq {
    int doCancel;
    char pad4[8];
    int isProxy;
} NHTTPReq;

typedef struct _NHTTPi_REQLIST {
    char pad0[0xc];
    NHTTPReq *req_p;
    int socket;
} NHTTPi_REQLIST;

typedef struct _NHTTPReqInfo {
    NHTTPi_REQLIST *reqCurrent;
} NHTTPReqInfo;

typedef struct _NHTTPBgnEndInfo {
    char pad0[0xc];
    int socket;
} NHTTPBgnEndInfo;

typedef struct _NHTTPMutexInfo NHTTPMutexInfo;
typedef struct _NHTTPSysInfo NHTTPSysInfo;

typedef unsigned char  u8;
extern u8 *func_021BEF08(void);
extern NHTTPBgnEndInfo *func_021BEF3C(void);
extern void *func_021BEF48(int p);
extern void *func_021BEF58(int p);
extern int func_021B9CA4(int socket);
extern int func_021B9CFC(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
extern int func_021B9CE4(NHTTPReq *req_p);
extern void func_021BEFCC(NHTTPMutexInfo *mutexInfo_p);
extern void func_021BEFD8(NHTTPMutexInfo *mutexInfo_p);
extern int func_021B9D8C(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPMutexInfo *mutexInfo_p,
                         NHTTPReq *req_p, int socket, u32 hostaddr, int port);
extern u32 func_021BA884(u8 *p);

int func_021BD548(NHTTPThreadData *threadData_p)
{
    NHTTPSysInfo *sysInfo_p = (NHTTPSysInfo *)func_021BEF08();
    NHTTPBgnEndInfo *bgnEndInfo_p = func_021BEF3C();
    NHTTPReqInfo *reqInfo_p = func_021BEF48((int)sysInfo_p);
    NHTTPReq *req_p = reqInfo_p->reqCurrent->req_p;
    NHTTPMutexInfo *mutexInfo_p = func_021BEF58((int)sysInfo_p);

    if (threadData_p->isKeepAlive == 1) {
        if (func_021B9CA4(bgnEndInfo_p->socket) == -1)
            threadData_p->isKeepAlive = 0;
    }
    if (threadData_p->isKeepAlive == 0) {
        if (bgnEndInfo_p->socket >= 0) {
            if (func_021B9CFC(mutexInfo_p, req_p, bgnEndInfo_p->socket) < 0) {
                bgnEndInfo_p->socket = -1;
                threadData_p->result = 10;
                return 0;
            }
        }
        bgnEndInfo_p->socket = func_021B9CE4(req_p);
        if (bgnEndInfo_p->socket < 0) {
            threadData_p->result = 3;
            return 0;
        }
        func_021BEFCC(mutexInfo_p);
        reqInfo_p->reqCurrent->socket = bgnEndInfo_p->socket;
        func_021BEFD8(mutexInfo_p);
        if (req_p->doCancel)
            return 0;
        if (func_021B9D8C(bgnEndInfo_p, mutexInfo_p, req_p, bgnEndInfo_p->socket,
                          threadData_p->hostaddr, threadData_p->port) < 0) {
            if (req_p->isProxy) {
                threadData_p->result = 13;
                return 0;
            }
            if (func_021BA884((u8 *)bgnEndInfo_p)) {
                threadData_p->result = 14;
                return 0;
            } else {
                threadData_p->result = 5;
                return 0;
            }
        }
    } else {
        func_021BEFCC(mutexInfo_p);
        reqInfo_p->reqCurrent->socket = bgnEndInfo_p->socket;
        func_021BEFD8(mutexInfo_p);
    }
    return 1;
}
