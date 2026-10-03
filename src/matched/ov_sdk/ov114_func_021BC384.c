/*
 * function: func_021BC384
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
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF50 0x021BEF50 arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BBF44 0x021BBF44 arm ov114
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
extern u8 *func_021BEF08(void);
extern BgnEnd *func_021BEF3C();
extern ThreadInfo *func_021BEF50(void *sysInfo_p);
extern ReqInfo *func_021BEF48(void *sysInfo_p);
extern int func_021BBF44(void *req_p, char *commBuf_p, int socket, int *bufwp_p, char *src_p, int srclen);

int func_021BC384(ThreadData *threadData_p, char *src_p, int srclen)
{
    void *sysInfo_p;
    BgnEnd *bgnEndInfo_p;
    ThreadInfo *threadInfo_p;
    ReqInfo *reqInfo_p;
    void *req_p;
    char *commBuf_p;
    int stat;

    sysInfo_p = func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    threadInfo_p = func_021BEF50(sysInfo_p);
    reqInfo_p = func_021BEF48(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    commBuf_p = threadInfo_p->commBuf;
    if (srclen == 0) {
        return 0;
    }
    stat = func_021BBF44(req_p, commBuf_p, bgnEndInfo_p->socket, &threadData_p->bufwp, src_p, srclen);
    if (stat < 0) {
        return 1;
    }
    if (stat == 0) {
        return 2;
    }
    return 0;
}
