/*
 * function: NHTTPi_RecvProxyConnectHeader
 * address:  0x021BC740
 * packet:   pkt_ov114_021BC740
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * 2026-10-01 (wave2 lane11): closed by "for (endFlag = i = 0; ...)": the chained
 *   assignment gives i the literal and endFlag the copy (image mov ip,#0; mov lr,ip).
 * 2026-10-01 (lane02): 142 -> 3 B. Rebuilt from the DWARF locals (no tmp_p,
 *   no volatile, named commBuf_p, declaration order = reverse DWARF) and the
 *   image's control flow: the three CR/LF tests are an if / else-if chain
 *   that falls to i++ (no break), each pair tested tmpbuf[i-1] first. The
 *   residue is the shared zero of i and endFlag: image `mov ip,#0; mov lr,ip`
 *   (i owns the literal), ours `mov lr,#0; mov ip,lr`. Flat at 3 B: statement
 *   order (endFlag=0 at loop top / before strToInt / after i=0), comma and
 *   chained inits, `endFlag = i`, `i = endFlag`, decl swap, enum/long/unsigned
 *   endFlag, long i, flipped loop compare.
 *
 * sdk:      NHTTPi_RecvProxyConnectHeader (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetReqInfoP  0x021BEF48  arm  ov114
 *   NHTTPi_GetThreadInfoP  0x021BEF50  arm  ov114
 *   NHTTPi_GetBgnEndInfoP  0x021BEF3C  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *   NHTTPi_SocRecv  0x021B9F94  arm  ov114
 *   NHTTPi_strToInt  0x021BA448  arm  ov114
 *   NHTTPi_strnicmp  0x021BA150  arm  ov114
 *   sNHTTPHttpPrefix  0x021CE4A8  data
 */

typedef struct {
    char pad[0x18];
    int httpStatus;
    char pad1c[0x2c - 0x1c];
} NHTTPRes;

typedef struct {
    char pad[0x2c];
    NHTTPRes *res_p;
} NHTTPReq;

typedef struct {
    char pad[0xc];
    NHTTPReq *req_p;
} NHTTPReqList;

typedef struct {
    NHTTPReqList *reqCurrent;
} NHTTPReqInfo;

typedef struct {
    char pad[0xc];
    int socket;
} NHTTPBgnEndInfo;

typedef struct {
    char pad0[0x100];
    char commBuf[1];
} NHTTPThreadInfo;

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetReqInfoP(int p);
extern void *NHTTPi_GetThreadInfoP(int p);
extern NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(void *sysInfo_p);
extern void *NHTTPi_GetMutexInfoP(int p);
extern int NHTTPi_SocRecv(void *mutexInfo_p, NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
extern int NHTTPi_strToInt(signed char *s, int len);
extern int NHTTPi_strnicmp(const char *p1_p, const char *p2_p, int size);
extern char sNHTTPHttpPrefix[];

static int NHTTPi_RecvProxyConnectHeader(void)
{
    void *sysInfo_p = NHTTPi_GetSystemInfoP();
    NHTTPReqInfo *reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    NHTTPThreadInfo *threadInfo_p = NHTTPi_GetThreadInfoP((int)sysInfo_p);
    NHTTPBgnEndInfo *bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    void *mutexInfo_p = NHTTPi_GetMutexInfoP((int)sysInfo_p);
    char *commBuf_p;
    NHTTPReq *req_p;
    NHTTPRes *res_p;
    char tmpbuf[512];
    int i;
    int recvbyte;
    int endFlag;
    int connectFlag;
    int totalRecvbyte;

    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    connectFlag = 0;
    totalRecvbyte = 0;
    while (1) {
        recvbyte = NHTTPi_SocRecv(mutexInfo_p, req_p, bgnEndInfo_p->socket, &tmpbuf[totalRecvbyte],
                                 512 - totalRecvbyte, 0);
        totalRecvbyte += recvbyte;
        res_p->httpStatus = NHTTPi_strToInt((signed char *)(&tmpbuf[9]), 3);
        if (NHTTPi_strnicmp(tmpbuf, sNHTTPHttpPrefix, 5) == 0 && tmpbuf[8] == ' ' && res_p->httpStatus == 200)
            connectFlag = 1;
        for (endFlag = i = 0; i < totalRecvbyte; i++) {
            if (i > 1 && tmpbuf[i - 1] == 0x0d && tmpbuf[i] == 0x0d) {
                endFlag = 1;
            } else if (i > 1 && tmpbuf[i - 1] == 0x0a && tmpbuf[i] == 0x0a) {
                endFlag = 1;
            } else if (i > 3 && tmpbuf[i - 3] == 0x0d && tmpbuf[i - 2] == 0x0a && tmpbuf[i - 1] == 0x0d &&
                       tmpbuf[i] == 0x0a) {
                endFlag = 1;
            }
        }
        if (endFlag)
            return connectFlag ? 1 : 0;
        if (recvbyte < 0)
            return 0;
        if (totalRecvbyte >= 512) {
            commBuf_p = threadInfo_p->commBuf;
            recvbyte = NHTTPi_SocRecv(mutexInfo_p, req_p, bgnEndInfo_p->socket, commBuf_p, 1, 0);
            if (recvbyte < 0)
                return 0;
            if (recvbyte != 0)
                return 0;
        }
    }
}
