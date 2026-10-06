/*
 * function: func_021BC9F0
 * address:  0x021BC9F0
 * packet:   pkt_ov114_021BC9F0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SendProcPostDataRaw (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BEF50 0x021BEF50 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BC098 0x021BC098 arm ov114
 *   func_021BA4E4 0x021BA4E4 arm ov114
 *   func_021BC384 0x021BC384 arm ov114
 *   func_021BC160 0x021BC160 arm ov114
 *   g_021CE4B4 0x021CE4B4 data
 *   g_021CE440 0x021CE440 data
 */

typedef unsigned long u32;

typedef struct {
    char pad[0x324];
    int sendBufwp;
} ThreadData;

typedef struct {
    char pad[0x24c];
    char *rawPostData_p;
    u32 rawPostDataLen;
} Req;

typedef struct {
    char pad[0xc];
    Req *req_p;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef struct {
    char pad[0x100];
    char commBuf[1];
} ThreadInfo;

typedef struct {
    char pad[0xc];
    int socket;
} BgnEnd;

extern char g_021CE4B4[];
extern char g_021CE440[];

typedef unsigned char  u8;
extern u8 *func_021BEF08(void);
extern void *func_021BEF58(int p);
extern void *func_021BEF48(int p);
extern void *func_021BEF50(int p);
extern BgnEnd *func_021BEF3C(void *sysInfo);
extern int func_021BC098(void *mutex, Req *req, int a, u32 *len_p, int b);
extern int func_021BA4E4(char *buf, u32 v);
extern int func_021BC384(ThreadData *td, char *buf, int len);
extern int func_021BC160(void *mutex, Req *req, char *commBuf, int a, int socket, int *bufwp, int b);

static int func_021BC9F0(ThreadData *threadData_p)
{
    void *sysInfo_p;
    ThreadInfo *threadInfo_p;
    void *mutexInfo_p;
    ReqInfo *reqInfo_p;
    Req *req_p;
    BgnEnd *bgnEndInfo_p;
    char *commBuf_p;
    u32 contentLength;
    int contentLengthBufLen;
    char contentLengthBuf[12];
    int sendStatus;
    int result;

    sysInfo_p = func_021BEF08();
    mutexInfo_p = func_021BEF58((int)sysInfo_p);
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    threadInfo_p = func_021BEF50((int)sysInfo_p);
    bgnEndInfo_p = func_021BEF3C(sysInfo_p);
    contentLength = 0;
    if (req_p->rawPostData_p == 0) {
        if (func_021BC098(mutexInfo_p, req_p, 0, &contentLength, 0) == 0) {
            return 3;
        }
    } else {
        contentLength = req_p->rawPostDataLen;
    }
    contentLengthBufLen = func_021BA4E4(contentLengthBuf, contentLength);
    result = func_021BC384(threadData_p, g_021CE4B4, 16);
    if (result != 0) {
        return result;
    }
    result = func_021BC384(threadData_p, contentLengthBuf, contentLengthBufLen);
    if (result != 0) {
        return result;
    }
    result = func_021BC384(threadData_p, g_021CE440, 2);
    if (result != 0) {
        return result;
    }
    result = func_021BC384(threadData_p, g_021CE440, 2);
    if (result != 0) {
        return result;
    }
    if (req_p->rawPostData_p == 0) {
        commBuf_p = threadInfo_p->commBuf;
        sendStatus = func_021BC160(mutexInfo_p, req_p, commBuf_p, 0, bgnEndInfo_p->socket, &threadData_p->sendBufwp, 0);
        if (sendStatus != 0) {
            return sendStatus;
        }
    } else {
        result = func_021BC384(threadData_p, req_p->rawPostData_p, req_p->rawPostDataLen);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}
