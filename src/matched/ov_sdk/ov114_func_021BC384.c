/*
 * function: NHTTPi_SendData
 * address:  0x021BC384
 * packet:   pkt_ov114_021BC384
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SendData (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_GetThreadInfoP 0x021BEF50 arm ov114
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_SaveBuf 0x021BBF44 arm ov114
 */

typedef struct {
    char pad[0x324];
    int bufwp;
} ThreadData;

typedef struct {
    char pad0[0x100];
    char commBuf[1];
} ThreadInfo;

typedef struct {
    char pad[0xc];
    int socket;
} BgnEnd;

typedef struct {
    char pad[0xc];
    void *req_p;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern BgnEnd *NHTTPi_GetBgnEndInfoP();
extern void *NHTTPi_GetThreadInfoP(int p);
extern void *NHTTPi_GetReqInfoP(int p);
extern int NHTTPi_SaveBuf(void *req_p, char *commBuf_p, int socket, int *bufwp_p, char *src_p, int srclen);

int NHTTPi_SendData(ThreadData *threadData_p, char *src_p, int srclen)
{
    void *sysInfo_p;
    BgnEnd *bgnEndInfo_p;
    ThreadInfo *threadInfo_p;
    ReqInfo *reqInfo_p;
    void *req_p;
    char *commBuf_p;
    int stat;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP();
    threadInfo_p = NHTTPi_GetThreadInfoP((int)sysInfo_p);
    reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    commBuf_p = threadInfo_p->commBuf;
    if (srclen == 0) {
        return 0;
    }
    stat = NHTTPi_SaveBuf(req_p, commBuf_p, bgnEndInfo_p->socket, &threadData_p->bufwp, src_p, srclen);
    if (stat < 0) {
        return 1;
    }
    if (stat == 0) {
        return 2;
    }
    return 0;
}
