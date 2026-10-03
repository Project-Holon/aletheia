/*
 * function: func_021BC488
 * address:  0x021BC488
 * packet:   pkt_ov114_021BC488
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SendBasicAuthorization (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BC384 0x021BC384 arm ov114
 *   g_021CE444 0x021CE444 data
 *   g_021CE440 0x021CE440 data
 */

typedef struct {
    char pad0[0x4c];
    char auth[0x5c];
    int authLen;
} Req;

typedef struct {
    char pad[0xc];
    Req *req_p;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

extern char g_021CE444[];
extern char g_021CE440[];

typedef unsigned char  u8;
extern u8 *func_021BEF08(void);
extern ReqInfo *func_021BEF48();
extern int func_021BC384(void *threadData_p, char *src_p, int srclen);

int func_021BC488(void *threadData_p)
{
    int sendStatus;
    Req *req_p;
    ReqInfo *reqInfo_p;
    void *sysInfo_p;

    sysInfo_p = func_021BEF08();
    reqInfo_p = func_021BEF48(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    if (req_p->authLen == 0) {
        return 0;
    }
    sendStatus = func_021BC384(threadData_p, g_021CE444, 0x15);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = func_021BC384(threadData_p, req_p->auth, req_p->authLen);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = func_021BC384(threadData_p, g_021CE440, 2);
    if (sendStatus == 0) {
        return 0;
    }
    return sendStatus;
}
