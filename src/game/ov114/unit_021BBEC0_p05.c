/*
 * file:     unit_021BBEC0_p05.c
 * unit:     yes
 * function: func_021BCF24, func_021BD220
 * address:  0x021BCF24
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
 *   g_021CE4B4                       0x021ce4b4 data
 *   g_021CE440                       0x021ce440 data
 *   g_021CE4D4                       0x021ce4d4 data
 *   g_021CE4D8                       0x021ce4d8 data
 *   func_021BA13C 0x021BA13C arm ov114
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
} ThreadData_021BCF24;

typedef struct {
    char pad[0x100];
    char commBuf[1];
} ThreadInfo;

typedef struct {
    char pad[0xc];
    int socket;
} BgnEnd;

typedef struct {
    int result;
    char sendBuf[0x100];
    char recvBuf[0x200];
    char pad0[0x314 - 0x304];
    int socket;
    int pipe;
    char pad1[0x324 - 0x31c];
    int a324;
    char pad2[0x32c - 0x328];
    int a32c;
    int a330;
    int a334;
    int a338;
    int a33c;
} ThreadData_021BD220;

extern void *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(void *sysInfo_p);
extern ReqInfo *NHTTPi_GetReqInfoP(void *sysInfo_p);
extern ThreadInfo *NHTTPi_GetThreadInfoP(void *sysInfo_p);
extern BgnEnd *NHTTPi_GetBgnEndInfoP(void *sysInfo_p);
extern int NHTTPi_getUrlEncodedSize(char *p_p);
extern int NHTTPi_intToStr(char *p, u32 n);
extern int NHTTPi_GetPostContentlength(void *mutexInfo_p, Req *req_p, char *label_p, u32 *contentLength, int sendtype);
extern int NHTTPi_SendData(ThreadData_021BCF24 *threadData_p, char *src_p, int srclen);
extern int NHTTPi_encodeUrlChar(char *p_p, char c);
extern int NHTTPi_SendPostData(void *mutexInfo_p, Req *req_p, char *commBuf_p, char *label_p, int socket, int *bufwp_p, int sendtype);
extern void func_021BA13C(int a, int b);
void func_021BD220(ThreadData_021BD220 *threadData_p);
extern char STR_POST_TYPE_URLENCODE[];
extern char g_021CE4B4[];
extern char g_021CE440[];
extern char g_021CE4D4[];
extern char g_021CE4D8[];


static int NHTTPi_SendProcPostDataAscii(ThreadData_021BCF24 *threadData_p)
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
    result = NHTTPi_SendData(threadData_p, g_021CE4B4, 0x10);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, tmpBuf, tmpBufLen);
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
            for (p = 0; datalist_p->name[p] != 0; p++) {
                tmpBufLen = NHTTPi_encodeUrlChar(tmpBuf, datalist_p->name[p]);
                result = NHTTPi_SendData(threadData_p, tmpBuf, tmpBufLen);
                if (result != 0) {
                    return result;
                }
            }
            result = NHTTPi_SendData(threadData_p, g_021CE4D4, 1);
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
            result = NHTTPi_SendData(threadData_p, g_021CE4D8, 1);
            if (result != 0) {
                return result;
            }
            datalist_p = datalist_p->next;
        } while (datalist_p != 0);
    }
    return 0;
}


/*
 * sdk:      NHTTPi_ThreadInit (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
void func_021BD220(ThreadData_021BD220 *threadData_p)
{
    threadData_p->result = -1;
    func_021BA13C((int)threadData_p->sendBuf, 0x100);
    func_021BA13C((int)threadData_p->recvBuf, 0x200);
    threadData_p->socket = -1;
    threadData_p->pipe = -1;
    threadData_p->a324 = 0;
    threadData_p->a338 = 0;
    threadData_p->a33c = 0;
    threadData_p->a334 = 0;
    threadData_p->a32c = 0;
    threadData_p->a330 = 0;
}
