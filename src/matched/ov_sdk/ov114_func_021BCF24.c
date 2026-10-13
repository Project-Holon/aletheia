/*
 * function: NHTTPi_SendProcPostDataAscii
 * address:  0x021BCF24
 * packet:   pkt_ov114_021BCF24
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SendProcPostDataAscii (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP            0x021bef08 arm
 *   NHTTPi_GetMutexInfoP             0x021bef58 arm
 *   NHTTPi_GetReqInfoP               0x021bef48 arm
 *   NHTTPi_GetThreadInfoP            0x021bef50 arm
 *   NHTTPi_GetBgnEndInfoP            0x021bef3c arm
 *   NHTTPi_getUrlEncodedSize         0x021ba1f4 arm
 *   NHTTPi_GetPostContentlength      0x021bc098 arm
 *   NHTTPi_intToStr                  0x021ba4e4 arm
 *   NHTTPi_SendData                  0x021bc384 arm
 *   NHTTPi_encodeUrlChar             0x021ba2d0 arm
 *   NHTTPi_SendPostData              0x021bc160 arm
 *   STR_POST_TYPE_URLENCODE          0x021ce034 data
 *   sNHTTPContentLengthHeader                       0x021ce4b4 data
 *   sNHTTPCrLf                       0x021ce440 data
 *   sNHTTPEquals                       0x021ce4d4 data
 *   sNHTTPAmpersand                       0x021ce4d8 data
 */

typedef unsigned long u32;

typedef struct _NHTTPi_DATALIST {
    struct _NHTTPi_DATALIST *head;
    struct _NHTTPi_DATALIST *next;
    char *name;
    char *data;
    u32 len;
    void *field14;
} NHTTPi_DATALIST;

typedef struct {
    char pad[0x34];
    NHTTPi_DATALIST *datalist_p;
} Req;

typedef struct {
    char pad[0xc];
    Req *req_p;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef struct {
    char pad[0x324];
    int sendBufwp;
} ThreadData;

typedef struct {
    char pad[0x100];
    char commBuf[1];
} ThreadInfo;

typedef struct {
    char pad[0xc];
    int socket;
} BgnEnd;

extern char STR_POST_TYPE_URLENCODE[];
extern char sNHTTPContentLengthHeader[];
extern char sNHTTPCrLf[];
extern char sNHTTPEquals[];
extern char sNHTTPAmpersand[];

extern void *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(void *sysInfo_p);
extern ReqInfo *NHTTPi_GetReqInfoP(void *sysInfo_p);
extern ThreadInfo *NHTTPi_GetThreadInfoP(void *sysInfo_p);
extern BgnEnd *NHTTPi_GetBgnEndInfoP(void *sysInfo_p);
extern int NHTTPi_getUrlEncodedSize(char *p_p);
extern int NHTTPi_intToStr(char *p, u32 n);
extern int NHTTPi_GetPostContentlength(void *mutexInfo_p, Req *req_p, char *label_p, u32 *contentLength, int sendtype);
extern int NHTTPi_SendData(ThreadData *threadData_p, char *src_p, int srclen);
extern int NHTTPi_encodeUrlChar(char *p_p, char c);
extern int NHTTPi_SendPostData(void *mutexInfo_p, Req *req_p, char *commBuf_p, char *label_p, int socket, int *bufwp_p, int sendtype);

static int NHTTPi_SendProcPostDataAscii(ThreadData *threadData_p)
{
    void *sysInfo_p;
    void *mutexInfo_p;
    ReqInfo *reqInfo_p;
    Req *req_p;
    ThreadInfo *threadInfo_p;
    BgnEnd *bgnEndInfo_p;
    NHTTPi_DATALIST *datalist_p;
    char tmpBuf[12];
    unsigned long contentLength;
    int tmpBufLen;
    int result;
    int sendStatus;
    int p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    contentLength = 0;
    datalist_p = req_p->datalist_p;
    if (datalist_p != 0) {
        do {
            contentLength += NHTTPi_getUrlEncodedSize(datalist_p->name);
            contentLength += 1;
            if (datalist_p->data == 0) {
                if (NHTTPi_GetPostContentlength(mutexInfo_p, req_p, datalist_p->name, &contentLength, 2) == 0) {
                    return 3;
                }
            } else {
                contentLength += NHTTPi_getUrlEncodedSize(datalist_p->data);
            }
            if (datalist_p == req_p->datalist_p->head) {
                break;
            }
            contentLength += 1;
            datalist_p = datalist_p->next;
        } while (datalist_p != 0);
    }
    tmpBufLen = NHTTPi_intToStr(tmpBuf, contentLength);
    result = NHTTPi_SendData(threadData_p, STR_POST_TYPE_URLENCODE, 0x31);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, sNHTTPContentLengthHeader, 0x10);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, tmpBuf, tmpBufLen);
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
    datalist_p = req_p->datalist_p;
    if (datalist_p != 0) {
        do {
            for (p = 0; datalist_p->name[p] != 0; p++) {
                tmpBufLen = NHTTPi_encodeUrlChar(tmpBuf, datalist_p->name[p]);
                result = NHTTPi_SendData(threadData_p, tmpBuf, tmpBufLen);
                if (result != 0) {
                    return result;
                }
            }
            result = NHTTPi_SendData(threadData_p, sNHTTPEquals, 1);
            if (result != 0) {
                return result;
            }
            if (datalist_p->data == 0) {
                sendStatus = NHTTPi_SendPostData(mutexInfo_p, req_p, threadInfo_p->commBuf, datalist_p->name, bgnEndInfo_p->socket, &threadData_p->sendBufwp, 2);
                if (sendStatus != 0) {
                    return sendStatus;
                }
            } else {
                for (p = 0; datalist_p->data[p] != 0; p++) {
                    tmpBufLen = NHTTPi_encodeUrlChar(tmpBuf, datalist_p->data[p]);
                    result = NHTTPi_SendData(threadData_p, tmpBuf, tmpBufLen);
                    if (result != 0) {
                        return result;
                    }
                }
            }
            if (datalist_p == req_p->datalist_p->head) {
                break;
            }
            result = NHTTPi_SendData(threadData_p, sNHTTPAmpersand, 1);
            if (result != 0) {
                return result;
            }
            datalist_p = datalist_p->next;
        } while (datalist_p != 0);
    }
    return 0;
}
