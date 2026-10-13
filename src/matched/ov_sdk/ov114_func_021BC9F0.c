/*
 * function: NHTTPi_SendProcPostDataRaw
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
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_GetThreadInfoP 0x021BEF50 arm ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_GetPostContentlength 0x021BC098 arm ov114
 *   NHTTPi_intToStr 0x021BA4E4 arm ov114
 *   NHTTPi_SendData 0x021BC384 arm ov114
 *   NHTTPi_SendPostData 0x021BC160 arm ov114
 *   sNHTTPContentLengthHeader 0x021CE4B4 data
 *   sNHTTPCrLf 0x021CE440 data
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

extern char sNHTTPContentLengthHeader[];
extern char sNHTTPCrLf[];

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(int p);
extern void *NHTTPi_GetReqInfoP(int p);
extern void *NHTTPi_GetThreadInfoP(int p);
extern BgnEnd *NHTTPi_GetBgnEndInfoP(void *sysInfo);
extern int NHTTPi_GetPostContentlength(void *mutex, Req *req, int a, u32 *len_p, int b);
extern int NHTTPi_intToStr(char *buf, u32 v);
extern int NHTTPi_SendData(ThreadData *td, char *buf, int len);
extern int NHTTPi_SendPostData(void *mutex, Req *req, char *commBuf, int a, int socket, int *bufwp, int b);

static int NHTTPi_SendProcPostDataRaw(ThreadData *threadData_p)
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

    sysInfo_p = NHTTPi_GetSystemInfoP();
    mutexInfo_p = NHTTPi_GetMutexInfoP((int)sysInfo_p);
    reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    threadInfo_p = NHTTPi_GetThreadInfoP((int)sysInfo_p);
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    contentLength = 0;
    if (req_p->rawPostData_p == 0) {
        if (NHTTPi_GetPostContentlength(mutexInfo_p, req_p, 0, &contentLength, 0) == 0) {
            return 3;
        }
    } else {
        contentLength = req_p->rawPostDataLen;
    }
    contentLengthBufLen = NHTTPi_intToStr(contentLengthBuf, contentLength);
    result = NHTTPi_SendData(threadData_p, sNHTTPContentLengthHeader, 16);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, contentLengthBuf, contentLengthBufLen);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, sNHTTPCrLf, 2);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, sNHTTPCrLf, 2);
    if (result != 0) {
        return result;
    }
    if (req_p->rawPostData_p == 0) {
        commBuf_p = threadInfo_p->commBuf;
        sendStatus = NHTTPi_SendPostData(mutexInfo_p, req_p, commBuf_p, 0, bgnEndInfo_p->socket, &threadData_p->sendBufwp, 0);
        if (sendStatus != 0) {
            return sendStatus;
        }
    } else {
        result = NHTTPi_SendData(threadData_p, req_p->rawPostData_p, req_p->rawPostDataLen);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}
