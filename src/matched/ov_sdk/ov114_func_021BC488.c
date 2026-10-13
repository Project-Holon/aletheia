/*
 * function: NHTTPi_SendBasicAuthorization
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
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_SendData 0x021BC384 arm ov114
 *   sNHTTPAuthorizationBasic 0x021CE444 data
 *   sNHTTPCrLf 0x021CE440 data
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

extern char sNHTTPAuthorizationBasic[];
extern char sNHTTPCrLf[];

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetReqInfoP(int p);
extern int NHTTPi_SendData(void *threadData_p, char *src_p, int srclen);

int NHTTPi_SendBasicAuthorization(void *threadData_p)
{
    int sendStatus;
    Req *req_p;
    ReqInfo *reqInfo_p;
    void *sysInfo_p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    if (req_p->authLen == 0) {
        return 0;
    }
    sendStatus = NHTTPi_SendData(threadData_p, sNHTTPAuthorizationBasic, 0x15);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = NHTTPi_SendData(threadData_p, req_p->auth, req_p->authLen);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = NHTTPi_SendData(threadData_p, sNHTTPCrLf, 2);
    if (sendStatus == 0) {
        return 0;
    }
    return sendStatus;
}
