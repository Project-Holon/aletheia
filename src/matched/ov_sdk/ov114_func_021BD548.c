/*
 * function: NHTTPi_ThreadConnectProc
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
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetBgnEndInfoP  0x021BEF3C  arm  ov114
 *   NHTTPi_GetReqInfoP  0x021BEF48  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *   NHTTPi_checkKeepAlive  0x021B9CA4  arm  ov114
 *   NHTTPi_SocClose  0x021B9CFC  arm  ov114
 *   NHTTPi_SocOpen  0x021B9CE4  arm  ov114
 *   NHTTPi_lockReqList  0x021BEFCC  arm  ov114
 *   NHTTPi_unlockReqList  0x021BEFD8  arm  ov114
 *   NHTTPi_SocConnect  0x021B9D8C  arm  ov114
 *   NHTTPi_GetSSLError  0x021BA884  arm  ov114
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
extern u8 *NHTTPi_GetSystemInfoP(void);
extern NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(void);
extern void *NHTTPi_GetReqInfoP(int p);
extern void *NHTTPi_GetMutexInfoP(int p);
extern int NHTTPi_checkKeepAlive(int socket);
extern int NHTTPi_SocClose(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
extern int NHTTPi_SocOpen(NHTTPReq *req_p);
extern void NHTTPi_lockReqList(NHTTPMutexInfo *mutexInfo_p);
extern void NHTTPi_unlockReqList(NHTTPMutexInfo *mutexInfo_p);
extern int NHTTPi_SocConnect(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPMutexInfo *mutexInfo_p,
                         NHTTPReq *req_p, int socket, u32 hostaddr, int port);
extern u32 NHTTPi_GetSSLError(u8 *p);

int NHTTPi_ThreadConnectProc(NHTTPThreadData *threadData_p)
{
    NHTTPSysInfo *sysInfo_p = (NHTTPSysInfo *)NHTTPi_GetSystemInfoP();
    NHTTPBgnEndInfo *bgnEndInfo_p = NHTTPi_GetBgnEndInfoP();
    NHTTPReqInfo *reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    NHTTPReq *req_p = reqInfo_p->reqCurrent->req_p;
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP((int)sysInfo_p);

    if (threadData_p->isKeepAlive == 1) {
        if (NHTTPi_checkKeepAlive(bgnEndInfo_p->socket) == -1)
            threadData_p->isKeepAlive = 0;
    }
    if (threadData_p->isKeepAlive == 0) {
        if (bgnEndInfo_p->socket >= 0) {
            if (NHTTPi_SocClose(mutexInfo_p, req_p, bgnEndInfo_p->socket) < 0) {
                bgnEndInfo_p->socket = -1;
                threadData_p->result = 10;
                return 0;
            }
        }
        bgnEndInfo_p->socket = NHTTPi_SocOpen(req_p);
        if (bgnEndInfo_p->socket < 0) {
            threadData_p->result = 3;
            return 0;
        }
        NHTTPi_lockReqList(mutexInfo_p);
        reqInfo_p->reqCurrent->socket = bgnEndInfo_p->socket;
        NHTTPi_unlockReqList(mutexInfo_p);
        if (req_p->doCancel)
            return 0;
        if (NHTTPi_SocConnect(bgnEndInfo_p, mutexInfo_p, req_p, bgnEndInfo_p->socket,
                          threadData_p->hostaddr, threadData_p->port) < 0) {
            if (req_p->isProxy) {
                threadData_p->result = 13;
                return 0;
            }
            if (NHTTPi_GetSSLError((u8 *)bgnEndInfo_p)) {
                threadData_p->result = 14;
                return 0;
            } else {
                threadData_p->result = 5;
                return 0;
            }
        }
    } else {
        NHTTPi_lockReqList(mutexInfo_p);
        reqInfo_p->reqCurrent->socket = bgnEndInfo_p->socket;
        NHTTPi_unlockReqList(mutexInfo_p);
    }
    return 1;
}
