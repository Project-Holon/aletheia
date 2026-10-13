/*
 * function: NHTTPi_ThreadRecvHeaderProc
 * address:  0x021BDB68
 * packet:   pkt_ov114_021BDB68
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ThreadRecvHeaderProc (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetReqInfoP  0x021BEF48  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *   NHTTPi_Request2Connection  0x021BEBE0  arm  ov114
 *   NHTTPi_GetBgnEndInfoP  0x021BEF3C  arm  ov114
 *   NHTTPi_memclr  0x021BA13C  arm  ov114
 *   NHTTPi_SocRecv  0x021B9F94  arm  ov114
 *   NHTTPi_alloc  0x021BA820  arm  ov114
 *   NHTTPi_CheckHeaderEnd  0x021BBEC0  arm  ov114
 *   memset         0x020923B0  arm
 *
 * note: NHTTPRes.headerLen is declared volatile. The object stores headerLen and
 * reloads it from the same slot before the zero test; every non-volatile
 * spelling tried (12 variants) forwards the stored register and drops the ldr.
 * The DWARF has a plain int.
 */

#include "../arm9_sdk/libc/string.h"

typedef struct _NHTTPSysInfo NHTTPSysInfo;
typedef struct _NHTTPMutexInfo NHTTPMutexInfo;

typedef struct _NHTTPi_HDRBUFLIST {
    struct _NHTTPi_HDRBUFLIST *next_p;
    char block[512];
} NHTTPi_HDRBUFLIST;

typedef struct _NHTTPBgnEndInfo {
    char pad0[0xc];
    int socket;             /* +0xc */
} NHTTPBgnEndInfo;

typedef struct _NHTTPConnection {
    int status;
} NHTTPConnection;

typedef struct _NHTTPRes {
    volatile int headerLen;                      /* +0x0 */
    char pad4[0x34 - 4];
    NHTTPi_HDRBUFLIST *hdrBufBlock_p;   /* +0x34 */
    char hdrBufFirst[1024];             /* +0x38 */
} NHTTPRes;

typedef struct _NHTTPReq {
    int doCancel;
    char pad4[0x2c - 4];
    NHTTPRes *res_p;                    /* +0x2c */
} NHTTPReq;

typedef struct _NHTTPi_REQLIST {
    char pad0[0xc];
    NHTTPReq *req_p;                    /* +0xc */
} NHTTPi_REQLIST;

typedef struct _NHTTPReqInfo {
    NHTTPi_REQLIST *reqCurrent;
} NHTTPReqInfo;

typedef struct _NHTTPThreadData {
    char pad0[0x304];
    char tmpHeaderBuf[14];              /* +0x304 */
    char pad312[0x328 - 0x312];
    int recvBufwp;                      /* +0x328 */
    char pad32c[4];
    int result;                         /* +0x330 */
} NHTTPThreadData;

extern NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
extern NHTTPReqInfo *NHTTPi_GetReqInfoP();
extern NHTTPMutexInfo *NHTTPi_GetMutexInfoP();
extern NHTTPConnection *NHTTPi_Request2Connection(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
extern NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP();
extern void NHTTPi_memclr(void *p_p, int size);
extern int NHTTPi_SocRecv(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket,
                         char *buf_p, int len, int flags);
extern void *NHTTPi_alloc(unsigned long size, int align);
extern int NHTTPi_CheckHeaderEnd(char *buf_p, int bufwp);

static int NHTTPi_ThreadRecvHeaderProc(NHTTPThreadData *threadData_p)
{
    NHTTPSysInfo *sysInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPReq *req_p;
    NHTTPRes *res_p;
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPConnection *connection_p;
    int recvbyte;
    char tmpBuf[4];
    NHTTPi_HDRBUFLIST *headerBuf_p;
    int wp;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP();
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    memset(tmpBuf, 0, 4);
    if (connection_p)
        connection_p->status = 3;
    res_p->headerLen = 0;
    NHTTPi_memclr(threadData_p->tmpHeaderBuf, 14);
    headerBuf_p = res_p->hdrBufBlock_p;
    threadData_p->recvBufwp = 0;

    while (1) {
        if (req_p->doCancel)
            return 0;
        if (threadData_p->recvBufwp < 0x400) {
            recvbyte = NHTTPi_SocRecv(mutexInfo_p, req_p, bgnEndInfo_p->socket,
                                     res_p->hdrBufFirst + threadData_p->recvBufwp, 1, 0);
            tmpBuf[threadData_p->recvBufwp & 3] = res_p->hdrBufFirst[threadData_p->recvBufwp];
        } else {
            wp = threadData_p->recvBufwp & 0x1ff;
            if (wp == 0) {
                if (headerBuf_p) {
                    headerBuf_p = headerBuf_p->next_p = NHTTPi_alloc(0x204, 4);
                } else {
                    headerBuf_p = NHTTPi_alloc(0x204, 4);
                    res_p->hdrBufBlock_p = headerBuf_p;
                }
                if (headerBuf_p == 0) {
                    threadData_p->result = 1;
                    return 0;
                }
                headerBuf_p->next_p = 0;
            }
            recvbyte = NHTTPi_SocRecv(mutexInfo_p, req_p, bgnEndInfo_p->socket,
                                     headerBuf_p->block + wp, 1, 0);
            tmpBuf[threadData_p->recvBufwp & 3] = headerBuf_p->block[wp];
        }
        if (recvbyte <= 0) {
            threadData_p->result = 10;
            return 0;
        }
        threadData_p->recvBufwp += recvbyte;
        if (NHTTPi_CheckHeaderEnd(tmpBuf, threadData_p->recvBufwp))
            break;
    }
    res_p->headerLen = threadData_p->recvBufwp;
    if (res_p->headerLen == 0) {
        threadData_p->result = 7;
        return 0;
    }
    return 1;
}
