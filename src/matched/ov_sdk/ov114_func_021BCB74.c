/*
 * function: NHTTPi_SendProcPostDataBinary
 * address:  0x021BCB74
 * packet:   pkt_ov114_021BCB74
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SendProcPostDataBinary (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP            0x021bef08 arm
 *   NHTTPi_GetMutexInfoP             0x021bef58 arm
 *   NHTTPi_GetReqInfoP               0x021bef48 arm
 *   NHTTPi_GetThreadInfoP            0x021bef50 arm
 *   NHTTPi_GetBgnEndInfoP            0x021bef3c arm
 *   NHTTPi_strlen                    0x021ba118 arm
 *   NHTTPi_GetPostContentlength      0x021bc098 arm
 *   NHTTPi_intToStr                  0x021ba4e4 arm
 *   NHTTPi_SendData                  0x021bc384 arm
 *   NHTTPi_SendPostData              0x021bc160 arm
 *   STR_POST_TYPE_MULTIPART          0x021ce007 data
 *   g_021CE440                       0x021ce440 data
 *   g_021CE4B4                       0x021ce4b4 data
 *   STR_POST_DISPOS                  0x021cdfe0 data
 *   g_021CE4C8                       0x021ce4c8 data
 *   STR_POST_TYPE_BIN                0x021ce068 data
 *   g_021CE4CC                       0x021ce4cc data
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
    char f38[2];
    char f3a[0x12];
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

extern char STR_POST_TYPE_MULTIPART[];
extern char g_021CE440[];
extern char g_021CE4B4[];
extern char STR_POST_DISPOS[];
extern char g_021CE4C8[];
extern char STR_POST_TYPE_BIN[];
extern char g_021CE4CC[];

extern void *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(void *sysInfo_p);
extern ReqInfo *NHTTPi_GetReqInfoP(void *sysInfo_p);
extern ThreadInfo *NHTTPi_GetThreadInfoP(void *sysInfo_p);
extern BgnEnd *NHTTPi_GetBgnEndInfoP(void *sysInfo_p);
extern int NHTTPi_strlen(char *p);
extern int NHTTPi_intToStr(char *p, u32 n);
extern int NHTTPi_GetPostContentlength(void *mutexInfo_p, Req *req_p, char *label_p, u32 *contentLength, int sendtype);
extern int NHTTPi_SendData(ThreadData *threadData_p, char *src_p, int srclen);
extern int NHTTPi_SendPostData(void *mutexInfo_p, Req *req_p, char *commBuf_p, char *label_p, int socket, int *bufwp_p, int sendtype);

static int NHTTPi_SendProcPostDataBinary(ThreadData *threadData_p)
{
    void *sysInfo_p;
    void *mutexInfo_p;
    ReqInfo *reqInfo_p;
    Req *req_p;
    ThreadInfo *threadInfo_p;
    BgnEnd *bgnEndInfo_p;
    NHTTPi_DATALIST *datalist_p;
    char contentLengthBuf[12];
    unsigned long contentLength;
    int contentLengthBufLen;
    int result;
    int sendStatus;

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
            contentLength += 0x16;
            contentLength += NHTTPi_strlen(datalist_p->name) + 0x29;
            if (datalist_p->field14 != 0) {
                contentLength += 0x4b;
            }
            contentLength += 2;
            if (datalist_p->data == 0) {
                if (NHTTPi_GetPostContentlength(mutexInfo_p, req_p, datalist_p->name, &contentLength, 1) == 0) {
                    return 3;
                }
            } else {
                contentLength += datalist_p->len;
            }
            contentLength += 2;
            if (datalist_p == req_p->datalist_p->head) {
                break;
            }
            datalist_p = datalist_p->next;
        } while (datalist_p != 0);
    }
    contentLength += 0x18;
    contentLengthBufLen = NHTTPi_intToStr(contentLengthBuf, contentLength);
    result = NHTTPi_SendData(threadData_p, STR_POST_TYPE_MULTIPART, 0x2c);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, req_p->f3a, 0x12);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, g_021CE440, 2);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, g_021CE4B4, 0x10);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, contentLengthBuf, contentLengthBufLen);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, g_021CE440, 2);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, g_021CE440, 2);
    if (result != 0) {
        return result;
    }
    datalist_p = req_p->datalist_p;
    if (datalist_p != 0) {
        do {
            result = NHTTPi_SendData(threadData_p, req_p->f38, 0x14);
            if (result != 0) {
                return result;
            }
            result = NHTTPi_SendData(threadData_p, g_021CE440, 2);
            if (result != 0) {
                return result;
            }
            result = NHTTPi_SendData(threadData_p, STR_POST_DISPOS, 0x26);
            if (result != 0) {
                return result;
            }
            result = NHTTPi_SendData(threadData_p, datalist_p->name, NHTTPi_strlen(datalist_p->name));
            if (result != 0) {
                return result;
            }
            result = NHTTPi_SendData(threadData_p, g_021CE4C8, 3);
            if (result != 0) {
                return result;
            }
            if (datalist_p->field14 != 0) {
                result = NHTTPi_SendData(threadData_p, STR_POST_TYPE_BIN, 0x4b);
                if (result != 0) {
                    return result;
                }
            }
            result = NHTTPi_SendData(threadData_p, g_021CE440, 2);
            if (result != 0) {
                return result;
            }
            if (datalist_p->data == 0) {
                sendStatus = NHTTPi_SendPostData(mutexInfo_p, req_p, threadInfo_p->commBuf, datalist_p->name, bgnEndInfo_p->socket, &threadData_p->sendBufwp, 1);
                if (sendStatus != 0) {
                    return sendStatus;
                }
            } else {
                result = NHTTPi_SendData(threadData_p, datalist_p->data, datalist_p->len);
                if (result != 0) {
                    return result;
                }
            }
            result = NHTTPi_SendData(threadData_p, g_021CE440, 2);
            if (result != 0) {
                return result;
            }
            if (datalist_p == req_p->datalist_p->head) {
                break;
            }
            datalist_p = datalist_p->next;
        } while (datalist_p != 0);
    }
    result = NHTTPi_SendData(threadData_p, req_p->f38, 0x14);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, g_021CE4CC, 4);
    if (result != 0) {
        return result;
    }
    return 0;
}
