/*
 * file:     unit_021BBEC0_p03.c
 * unit:     yes
 * function: func_021BC384, func_021BC40C, func_021BC488
 * address:  0x021BC384
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF50 0x021BEF50 arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BBF44 0x021BBF44 arm ov114
 *   g_021CE424 0x021CE424 data
 *   g_021CE440 0x021CE440 data
 *   g_021CE444 0x021CE444 data
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
} ReqList_021BC384;

typedef struct {
    ReqList_021BC384 *reqCurrent;
} ReqInfo;

typedef unsigned char  u8;

typedef struct {
    char pad0[0x1e8];
    char auth[0x5c];
    int authLen;
} Req_021BC40C;

typedef struct {
    char pad[0xc];
    Req_021BC40C *req_p;
} ReqList_021BC40C;

typedef struct {
    char pad0[0x4c];
    char auth[0x5c];
    int authLen;
} Req_021BC488;

typedef struct {
    char pad[0xc];
    Req_021BC488 *req_p;
} ReqList_021BC488;

extern u8 *func_021BEF08(void);
extern BgnEnd *func_021BEF3C();
extern void *func_021BEF50(int p);
extern void *func_021BEF48(int p);
extern int func_021BBF44(void *req_p, char *commBuf_p, int socket, int *bufwp_p, char *src_p, int srclen);
int func_021BC384(ThreadData *threadData_p, char *src_p, int srclen);
int func_021BC40C(void *threadData_p);
int func_021BC488(void *threadData_p);
extern char g_021CE424[];
extern char g_021CE440[];
extern char g_021CE444[];


/*
 * sdk:      NHTTPi_SendData (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
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
    threadInfo_p = func_021BEF50((int)sysInfo_p);
    reqInfo_p = func_021BEF48((int)sysInfo_p);
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


int func_021BC40C(void *threadData_p)
{
    int sendStatus;
    Req_021BC40C *req_p;
    ReqInfo *reqInfo_p;
    void *sysInfo_p;

    sysInfo_p = func_021BEF08();
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    if (req_p->authLen == 0) {
        return 0;
    }
    sendStatus = func_021BC384(threadData_p, g_021CE424, 0x1b);
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


/*
 * sdk:      NHTTPi_SendBasicAuthorization (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
int func_021BC488(void *threadData_p)
{
    int sendStatus;
    Req_021BC488 *req_p;
    ReqInfo *reqInfo_p;
    void *sysInfo_p;

    sysInfo_p = func_021BEF08();
    reqInfo_p = func_021BEF48((int)sysInfo_p);
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
