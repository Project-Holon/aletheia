/*
 * file:     unit_021BBEC0.c
 * unit:     yes
 * function: func_021BBEC0, func_021BBF44, func_021BC00C, func_021BC098, func_021BC160, func_021BC2FC, func_021BC384, func_021BC40C, func_021BC488, func_021BC504, func_021BC740, func_021BC924, func_021BC9F0, NHTTPi_SendProcPostDataBinary, func_021BCF24, func_021BD220, func_021BD270, func_021BD3B8, func_021BD430, func_021BD548, func_021BD6DC, NHTTPi_ThreadSendProc, func_021BDB68, NHTTPi_ThreadParseHeaderProc, NHTTPi_ThreadRecvBodyProc, func_021BE4D4
 * address:  0x021BBEC0
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
 *   DWCi_Ndi_memcpy  0x021BA100  arm  ov114
 *   func_021BA020    0x021BA020  arm  ov114
 *   func_021B9F94 0x021B9F94 arm ov114
 *   func_021BEBE0 0x021BEBE0 arm ov114
 *   func_021BEC74 0x021BEC74 arm ov114
 *   func_021BA25C 0x021BA25C arm ov114
 *   func_021BA13C  0x021BA13C  arm  ov114
 *   func_021BA2D0  0x021BA2D0  arm  ov114
 *   func_021BB2FC  0x021BB2FC  arm  ov114
 *   func_021BEBF0  0x021BEBF0  arm  ov114
 *   func_021BED04  0x021BED04  arm  ov114
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF50 0x021BEF50 arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   g_021CE424 0x021CE424 data
 *   g_021CE440 0x021CE440 data
 *   g_021CE444 0x021CE444 data
 *   NHTTPi_GetSystemInfoP            0x021bef08 arm
 *   NHTTPi_GetReqInfoP               0x021bef48 arm
 *   NHTTPi_GetThreadInfoP            0x021bef50 arm
 *   NHTTPi_GetBgnEndInfoP            0x021bef3c arm
 *   NHTTPi_intToStr                  0x021ba4e4 arm
 *   NHTTPi_SendData                  0x021bc384 arm
 *   NHTTPi_SendProxyAuthorization    0x021bc40c arm
 *   NHTTPi_SocSend                   0x021ba020 arm
 *   NHTTPi_memclr                    0x021ba13c arm
 *   g_021CE45C                       0x021ce45c data
 *   g_021CE468                       0x021ce468 data
 *   g_021CE46C                       0x021ce46c data
 *   g_021CE478                       0x021ce478 data
 *   g_021CE480                       0x021ce480 data
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   func_021BA448  0x021BA448  arm  ov114
 *   func_021BA150  0x021BA150  arm  ov114
 *   g_021CE4A8  0x021CE4A8  data
 *   func_021BABF4  0x021BABF4  arm  ov114
 *   func_021BA118  0x021BA118  arm  ov114
 *   func_021BA850  0x021BA850  arm  ov114
 *   g_021CE4B0     0x021CE4B0  data
 *   func_021BA4E4 0x021BA4E4 arm ov114
 *   g_021CE4B4 0x021CE4B4 data
 *   NHTTPi_GetMutexInfoP             0x021bef58 arm
 *   NHTTPi_strlen                    0x021ba118 arm
 *   NHTTPi_GetPostContentlength      0x021bc098 arm
 *   NHTTPi_SendPostData              0x021bc160 arm
 *   STR_POST_TYPE_MULTIPART          0x021ce007 data
 *   STR_POST_DISPOS                  0x021cdfe0 data
 *   g_021CE4C8                       0x021ce4c8 data
 *   STR_POST_TYPE_BIN                0x021ce068 data
 *   g_021CE4CC                       0x021ce4cc data
 *   NHTTPi_getUrlEncodedSize         0x021ba1f4 arm
 *   NHTTPi_encodeUrlChar             0x021ba2d0 arm
 *   STR_POST_TYPE_URLENCODE          0x021ce034 data
 *   g_021CE4D4                       0x021ce4d4 data
 *   g_021CE4D8                       0x021ce4d8 data
 *   func_021B9CFC  0x021B9CFC  arm  ov114
 *   func_021BA874  0x021BA874  arm  ov114
 *   func_021BEFCC  0x021BEFCC  arm  ov114
 *   func_021BEFD8  0x021BEFD8  arm  ov114
 *   func_021BB934  0x021BB934  arm  ov114
 *   func_021BEE1C  0x021BEE1C  arm  ov114
 *   func_021BEA98  0x021BEA98  arm  ov114
 *   func_021BF1B0  0x021BF1B0  arm  ov114
 *   func_021BEF40 0x021BEF40 arm ov114
 *   func_021BAEC8 0x021BAEC8 arm ov114
 *   func_021B9BF4 0x021B9BF4 arm ov114
 *   func_021BA130 0x021BA130 arm ov114
 *   func_021BA098 0x021BA098 arm ov114
 *   func_021BA124 0x021BA124 arm ov114
 *   func_021BA100 0x021BA100 arm ov114
 *   func_021B9CA4  0x021B9CA4  arm  ov114
 *   func_021B9CE4  0x021B9CE4  arm  ov114
 *   func_021B9D8C  0x021B9D8C  arm  ov114
 *   func_021BA884  0x021BA884  arm  ov114
 *   func_021B9E3C 0x021B9E3C arm ov114
 *   NHTTPi_Request2Connection        0x021bebe0 arm
 *   NHTTPi_SendBasicAuthorization    0x021bc488 arm
 *   NHTTPi_SendHeaderList            0x021bc924 arm
 *   NHTTPi_SendProcPostDataRaw       0x021bc9f0 arm
 *   g_021CE4DC                       0x021ce4dc data
 *   g_021CE4E4                       0x021ce4e4 data
 *   g_021CE4EC                       0x021ce4ec data
 *   g_021CE4F4                       0x021ce4f4 data
 *   func_021BA820  0x021BA820  arm  ov114
 *   memset         0x020923B0  arm
 *   NHTTPi_loadFromHdrRecvBuf        0x021bb210 arm
 *   NHTTPi_strnicmp                  0x021ba150 arm
 *   NHTTPi_strToInt                  0x021ba448 arm
 *   NHTTPi_findNextLineHdrRecvBuf    0x021bafa0 arm
 *   NHTTPi_getHeaderValue            0x021bbbc8 arm
 *   NHTTPi_compareTokenN_HdrRecvBuf  0x021bb12c arm
 *   g_021CE4F8                       0x021ce4f8 data
 *   g_021CE508                       0x021ce508 data
 *   g_021CE514                       0x021ce514 data
 *   g_021CE520                       0x021ce520 data
 *   g_021CE534                       0x021ce534 data
 *   NHTTPi_SetVirtualContentLength   0x021bef60 arm
 *   NHTTPi_BufFull                   0x021bc2fc arm
 *   NHTTPi_RecvBufN                  0x021bb344 arm
 *   NHTTPi_isRecvBufFull             0x021bb2fc arm
 *   NHTTPi_SocRecv                   0x021b9f94 arm
 *   NHTTPi_SkipLineBuf               0x021bc00c arm
 *   NHTTPi_strToHex                  0x021ba35c arm
 *   NHTTPi_RecvBuf                   0x021bb310 arm
 *   NHTTPi_Response2Connection       0x021bebf0 arm
 *   NHTTPi_ReceivedCallback          0x021bed90 arm
 *   func_021BD7E8 0x021BD7E8 arm ov114
 *   func_021BDD34 0x021BDD34 arm ov114
 *   func_021BDFF8 0x021BDFF8 arm ov114
 */
#include "nhttp_types.h"
#include "../../matched/arm9_sdk/libc/string.h"

#define BUF2(td) ((char *)(td) + 0x104)
struct Conn;
struct Node;
struct _NHTTPThreadData;
typedef unsigned long u32_021BC160;

typedef unsigned int   u32_021BC2FC;

extern void DWCi_Ndi_memcpy(void *dst_p, void *src_p, int size);
extern int func_021BA020(NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
extern int func_021B9F94(void *mutexInfo_p, NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
extern void *func_021BEBE0(void *, void *);
extern int func_021BEC74(void *mutexInfo_p, struct Conn *connection_p, char *label_p, int offset);
extern int func_021BA25C(char *p_p, int len);
extern void func_021BA13C(void *p_p, int size);
extern int func_021BA2D0(char *dst, int c);
extern int func_021BB2FC(u8 *p, u32_021BC2FC v);
extern struct Conn *func_021BEBF0(int a, int b);
extern void func_021BED04(void *mutexInfo_p, struct Conn *connection_p);
extern void *func_021BEF08();
extern void *func_021BEF3C();
extern void *func_021BEF50(void *sysInfo_p);
extern void *func_021BEF48(int p);
extern void *NHTTPi_GetSystemInfoP(void);
extern NHTTPReqInfo *NHTTPi_GetReqInfoP(void *sysInfo_p);
extern NHTTPThreadInfo *NHTTPi_GetThreadInfoP(void *sysInfo_p);
extern NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP(void *sysInfo_p);
extern int NHTTPi_intToStr(char *p_p, unsigned long n);
extern int NHTTPi_SendData(NHTTPThreadData *threadData_p, char *src_p, int srclen);
extern int NHTTPi_SendProxyAuthorization(NHTTPThreadData *threadData_p);
extern int NHTTPi_SocSend(NHTTPReq *req_p, int socket, char *buf_p, int len,
                          int flags);
extern void NHTTPi_memclr(void *p_p, int size);
extern void *func_021BEF58();
extern int func_021BA448(signed char *s, int len);
extern int func_021BA150(const char *p1_p, const char *p2_p, int size);
extern NHTTPi_DATALIST *func_021BABF4(void *list);
extern int func_021BA118(const char *s);
extern void func_021BA850(int a);
extern int func_021BA4E4(char *buf, u32 v);
extern void *NHTTPi_GetMutexInfoP(void *sysInfo_p);
extern int NHTTPi_strlen(char *p);
extern int NHTTPi_GetPostContentlength(void *mutexInfo_p, NHTTPReq *req_p, char *label_p, unsigned long *contentLength, int sendtype);
extern int NHTTPi_SendPostData(void *mutexInfo_p, NHTTPReq *req_p, char *commBuf_p, char *label_p, int socket, int *bufwp_p, int sendtype);
extern int NHTTPi_getUrlEncodedSize(char *p_p);
extern int NHTTPi_encodeUrlChar(char *p_p, char c);
extern int func_021B9CFC(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
extern void func_021BA874(u8 *p, int v);
extern void func_021BEFCC();
extern void func_021BEFD8();
extern int func_021BB934(int a, u8 *b);
extern void func_021BEE1C(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p);
extern void func_021BEA98(u8 *p);
extern int func_021BF1B0(NHTTPConnection *connection_p);
extern void *func_021BEF40(int p);
extern struct Node *func_021BAEC8(struct Node **a0);
extern void func_021B9BF4(int a);
extern int func_021BA130(char *a, char *b);
extern unsigned long func_021BA098(int unused, char *hostname_p);
extern int func_021BA124(char *s, int max);
extern void func_021BA100(void *dst, void *src, int n);
extern int func_021B9CA4(int socket);
extern int func_021B9CE4(NHTTPReq *req_p);
extern int func_021B9D8C(NHTTPBgnEndInfo *bgnEndInfo_p, NHTTPMutexInfo *mutexInfo_p,
                         NHTTPReq *req_p, int socket, u32 hostaddr, int port);
extern u32 func_021BA884(u8 *p);
extern int func_021B9E3C(NHTTPBgnEndInfo *bgn, void *mutex, NHTTPReq *req, int socket);
extern NHTTPConnection *NHTTPi_Request2Connection(void *mutexInfo_p, NHTTPReq *req_p);
extern int NHTTPi_SendBasicAuthorization(NHTTPThreadData *threadData_p);
extern int NHTTPi_SendHeaderList(NHTTPThreadData *threadData_p);
extern int NHTTPi_SendProcPostDataRaw(NHTTPThreadData *threadData_p);
extern void *func_021BA820(unsigned long size, int align);
extern int NHTTPi_loadFromHdrRecvBuf(NHTTPRes *res_p, char *dst_p, int pos,
                                     int len);
extern int NHTTPi_strnicmp(char *p1_p, char *p2_p, int size);
extern int NHTTPi_strToInt(char *p_p, int len);
extern int NHTTPi_findNextLineHdrRecvBuf(NHTTPRes *res_p, int pos, int limit,
                                         int *colon_pos_p,
                                         int *return_code_size_p);
extern int NHTTPi_getHeaderValue(NHTTPRes *res_p, char *label_p, int *pos_p);
extern int NHTTPi_compareTokenN_HdrRecvBuf(NHTTPRes *res_p, int pos, int limit,
                                           char *str_p, char extdeli);
extern void NHTTPi_SetVirtualContentLength(void *connection_p, u32 contentLength);
extern int NHTTPi_BufFull(void *mutexInfo_p, NHTTPRes *res_p);
extern int NHTTPi_RecvBufN(void *mutexInfo_p, NHTTPReq *req_p, int socket, int pos, int len, int flags);
extern int NHTTPi_isRecvBufFull(NHTTPRes *res_p, int pos);
extern int NHTTPi_SocRecv(void *mutexInfo_p, NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
extern int NHTTPi_SkipLineBuf(void *mutexInfo_p, NHTTPReq *req_p, int socket);
extern int NHTTPi_strToHex(char *p_p, int len);
extern int NHTTPi_RecvBuf(void *mutexInfo_p, NHTTPReq *req_p, int socket, int pos, int len);
extern void *NHTTPi_Response2Connection(void *mutexInfo_p, NHTTPRes *res_p);
extern void NHTTPi_ReceivedCallback(void *mutexInfo_p, void *connection_p);
extern int func_021BD7E8(NHTTPThreadData *td);
extern int func_021BDD34(NHTTPThreadData *td);
extern int func_021BDFF8(NHTTPThreadData *td);
int func_021BBEC0(char *buf_p, int bufwp);
int func_021BC00C(void *mutexInfo_p, void *req_p, int socket);
int func_021BC098(void *mutexInfo_p, NHTTPReq *req_p, char *label_p, unsigned long *contentLength, int sendtype);
int func_021BC2FC(void *mutexInfo_p, NHTTPRes *res_p);
int func_021BC384(NHTTPThreadData *threadData_p, char *src_p, int srclen);
int func_021BC40C(void *threadData_p);
int func_021BC488(void *threadData_p);
int NHTTPi_SendProxyConnectMethod(NHTTPThreadData *threadData_p);
int func_021BC924(void *threadData_p);
void func_021BD220(NHTTPThreadData *threadData_p);
int func_021BD3B8(NHTTPThreadData *threadData_p);
int func_021BD548(NHTTPThreadData *threadData_p);
int NHTTPi_ThreadParseHeaderProc(NHTTPThreadData *threadData_p);
void func_021BE4D4(void);
extern char g_021CE424[];
extern char g_021CE440[];
extern char g_021CE444[];
extern char g_021CE45C[];
extern char g_021CE468[];
extern char g_021CE46C[];
extern char g_021CE478[];
extern char g_021CE480[];
extern char g_021CE4A8[];
extern char g_021CE4B0[];
extern char g_021CE4B4[];
extern char STR_POST_TYPE_MULTIPART[];
extern char STR_POST_DISPOS[];
extern char g_021CE4C8[];
extern char STR_POST_TYPE_BIN[];
extern char g_021CE4CC[];
extern char STR_POST_TYPE_URLENCODE[];
extern char g_021CE4D4[];
extern char g_021CE4D8[];
extern char g_021CE4DC[];
extern char g_021CE4E4[];
extern char g_021CE4EC[];
extern char g_021CE4F4[];
extern char g_021CE4F8[];
extern char g_021CE508[];
extern char g_021CE514[];
extern char g_021CE520[];
extern char g_021CE534[];












/*
 * sdk:      NHTTPi_CheckHeaderEnd (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
int func_021BBEC0(char *buf_p, int bufwp)
{
    char c = buf_p[(bufwp - 2) & 3];

    if (c == '\r' && buf_p[(bufwp - 1) & 3] == '\r') {
        return 1;
    }
    if (c == '\n' && buf_p[(bufwp - 1) & 3] == '\n') {
        return 1;
    }
    if (buf_p[(bufwp - 4) & 3] == '\r' && buf_p[(bufwp - 3) & 3] == '\n' && c == '\r' && buf_p[(bufwp - 1) & 3] == '\n') {
        return 1;
    }
    return 0;
}













/*
 * sdk:      NHTTPi_SaveBuf (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * Two spellings carry the whole 194 concrete bytes.
 *
 * `const` on srclen is the frame. The parameter is live across both calls and
 * the epilogue returns it, so it needs a home; spelled plain, 1.1p1 keeps the
 * incoming argument slot as the home and the function has no frame at all (176
 * B): the outgoing 5th argument of NHTTPi_SocSend lands at sp+0, on top of src_p's
 * incoming slot. Spelled const, the parameter gets a fresh frame slot at sp+4,
 * which is the `sub sp, sp, #8`, and the outgoing argument then sits at sp+0 of
 * the new frame where the object has it. DWARF records a plain int because a
 * top-level qualifier on a parameter is not part of its type, so this is
 * invisible from the object and behaviourally inert here: nothing writes it.
 *
 * The loop carries no `srclen > 0` guard either. `len` is assigned from srclen
 * and then decremented, so the two are equal at the first test and the object
 * tests the counter once (cmp r4,#0 / bgt at +0x0B4); the redundant guard emits
 * a second compare. Declaration order is sendbyte, len, n: that is the DWARF
 * order and it is what puts len in r4 and n in r5, the opposite of the order
 * the locals were first written in.
 */
static int func_021BBF44(NHTTPReq *req_p, char *commBuf_p, int socket, int *bufwp_p, char *src_p, const int srclen)
{
    int sendbyte;
    int len;
    int n;

    len = srclen;
    while (len > 0) {
        if (req_p->doCancel != 0)
            return -1;
        n = 0x4000 - *bufwp_p;
        if (len <= n)
            n = len;
        DWCi_Ndi_memcpy(commBuf_p + *bufwp_p, src_p, n);
        src_p += n;
        *bufwp_p += n;
        len -= n;
        if (*bufwp_p == 0x4000) {
            sendbyte = func_021BA020(req_p, socket, commBuf_p, 0x4000, 0);
            if (sendbyte <= 0)
                return sendbyte;
            *bufwp_p -= sendbyte;
        }
    }
    return srclen;
}













/*
 * sdk:      NHTTPi_SkipLineBuf (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
int func_021BC00C(void *mutexInfo_p, void *req_p, int socket)
{
    char buf[2];
    int p;
    int recvbyte;
    int rc;

    rc = 0;
    p = 0;
    buf[0] = 0;
    buf[1] = 0;
    while (!(buf[p & 1] == '\r' && buf[(p - 1) & 1] == '\n')) {
        recvbyte = func_021B9F94(mutexInfo_p, req_p, socket, &buf[p & 1], 1, 0);
        if (recvbyte <= 0) {
            return recvbyte;
        }
        rc += recvbyte;
        p++;
    }
    return rc;
}












/*
 * sdk:      NHTTPi_GetPostContentlength (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
int func_021BC098(void *mutexInfo_p, NHTTPReq *req_p, char *label_p, unsigned long *contentLength, int sendtype)
{
    int offset;
    unsigned long length;
    char *value_p;
    NHTTPConnection *connection_p;

    offset = 0;
    connection_p = func_021BEBE0(mutexInfo_p, req_p);
    if (connection_p == 0) {
        return 0;
    }
    connection_p->postDataBuf = 0;
    while (1) {
        if (req_p->doCancel != 0) {
            return 0;
        }
        connection_p->postDataLen = 0;
        if (func_021BEC74(mutexInfo_p, (struct Conn *)connection_p, label_p, offset) < 0) {
            return 0;
        }
        length = connection_p->postDataLen;
        value_p = connection_p->postDataBuf;
        if (length != 0) {
            if (value_p == 0) {
                return 0;
            }
            offset += length;
            switch (sendtype) {
            case 0:
            case 1:
                *contentLength += length;
                break;
            case 2:
                *contentLength += func_021BA25C(value_p, length);
                break;
            }
        } else {
            return 1;
        }
    }
}












static int func_021BC160(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, char *commBuf_p,
                         char *label_p, int socket, int *bufwp_p, int sendtype)
{
    u32_021BC160 offset = 0;
    u32_021BC160 length;
    char *value_p;
    int stat;
    char urlencode[3];
    int p;
    int n;
    NHTTPConnection *connection_p;

    connection_p = (NHTTPConnection *)func_021BEBE0(mutexInfo_p, (NHTTPReq *)req_p);
    if (connection_p == 0)
        return 3;
    connection_p->postDataBuf = 0;

    while (1) {
        if (req_p->doCancel)
            return 3;
        connection_p->postDataLen = 0;
        if (func_021BEC74(mutexInfo_p, (struct Conn *)connection_p, label_p, offset) < 0)
            return 3;
        length = connection_p->postDataLen;
        value_p = connection_p->postDataBuf;
        if (length == 0)
            break;
        if (value_p == 0)
            return 3;
        offset += length;
        switch (sendtype) {
        case 0:
        case 1:
            stat = func_021BBF44((NHTTPReq *)req_p, commBuf_p, socket, bufwp_p, value_p, length);
            if (stat < 0)
                return 1;
            if (stat == 0)
                return 2;
            break;
        case 2:
            for (p = 0; p < length; p++) {
                func_021BA13C(urlencode, 3);
                n = func_021BA2D0(urlencode, value_p[p]);
                stat = func_021BBF44((NHTTPReq *)req_p, commBuf_p, socket, bufwp_p, urlencode, n);
                if (stat < 0)
                    return 1;
                if (stat == 0)
                    return 2;
            }
            break;
        }
    }
    return 0;
}












int func_021BC2FC(void *mutexInfo_p, NHTTPRes *res_p)
{
    void *connection_p;
    int full;
    int ret;

    ret = 0;
    full = func_021BB2FC((u8 *)res_p, res_p->bodyLen);
    if (res_p->recvBufLen == 0 || res_p->recvBuf_p == 0 || full != 0) {
        connection_p = func_021BEBF0((int)mutexInfo_p, (int)res_p);
        if (connection_p != 0) {
            func_021BED04(mutexInfo_p, connection_p);
            if (res_p->recvBuf_p != 0 && res_p->recvBufLen != 0) {
                full = func_021BB2FC((u8 *)res_p, res_p->bodyLen);
                if (full == 0)
                    ret = 1;
            }
        }
    } else if (full == 0) {
        ret = 1;
    }
    return ret;
}











/*
 * sdk:      NHTTPi_SendData (libnhttp.TWL.HYB.recvBufLen(nhttp_thread.o))
 */
/*
 * sdk:      NHTTPi_SendData (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
int func_021BC384(NHTTPThreadData *threadData_p, char *src_p, int srclen)
{
    void *sysInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPThreadInfo *threadInfo_p;
    NHTTPReqInfo *reqInfo_p;
    void *req_p;
    char *commBuf_p;
    int stat;

    sysInfo_p = func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    threadInfo_p = func_021BEF50((void *)((int)sysInfo_p));
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    commBuf_p = threadInfo_p->commBuf;
    if (srclen == 0) {
        return 0;
    }
    stat = func_021BBF44(req_p, commBuf_p, bgnEndInfo_p->socket, &threadData_p->sendBufwp, src_p, srclen);
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
    NHTTPReq *req_p;
    NHTTPReqInfo *reqInfo_p;
    void *sysInfo_p;

    sysInfo_p = func_021BEF08();
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    if (req_p->proxyAuthLen == 0) {
        return 0;
    }
    sendStatus = func_021BC384(threadData_p, g_021CE424, 0x1b);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = func_021BC384(threadData_p, req_p->proxyAuth, req_p->proxyAuthLen);
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
    NHTTPReq *req_p;
    NHTTPReqInfo *reqInfo_p;
    void *sysInfo_p;

    sysInfo_p = func_021BEF08();
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    if (req_p->basicAuthLen == 0) {
        return 0;
    }
    sendStatus = func_021BC384(threadData_p, g_021CE444, 0x15);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = func_021BC384(threadData_p, req_p->basicAuth, req_p->basicAuthLen);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = func_021BC384(threadData_p, g_021CE440, 2);
    if (sendStatus == 0) {
        return 0;
    }
    return sendStatus;
}










int NHTTPi_SendProxyConnectMethod(NHTTPThreadData *threadData_p)
{
    int stat;
    int portlen;
    char portstr[5];
    void *sysInfo_p;
    NHTTPThreadInfo *threadInfo_p;
    NHTTPReq *req_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    req_p = (NHTTPReq *)NHTTPi_GetReqInfoP(sysInfo_p)->reqCurrent->req_p;
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);

    portlen = NHTTPi_intToStr(portstr, req_p->port);

    stat = NHTTPi_SendData(threadData_p, g_021CE45C, 8);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, req_p->URL_p + 8, req_p->hostLen - 8);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE468, 1);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, portstr, portlen);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE46C, 0xb);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE478, 6);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, req_p->URL_p + 8, req_p->hostLen - 8);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE468, 1);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, portstr, portlen);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE440, 2);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE480, 0x25);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendProxyAuthorization(threadData_p);
    if (stat != 0)
        return stat;

    NHTTPi_SendData(threadData_p, g_021CE440, 2);

    if (threadData_p->sendBufwp > 0)
    {
        stat = NHTTPi_SocSend(req_p, bgnEndInfo_p->socket, threadInfo_p->commBuf,
                              threadData_p->sendBufwp, 0);
        if (stat < 0)
            return 1;
        if (stat == 0)
            return 2;
    }

    threadData_p->sendBufwp = 0;
    NHTTPi_memclr(threadInfo_p->commBuf, 0x4000);
    return 0;
}










static int func_021BC740(NHTTPThreadData *threadData_p)
{
    void *sysInfo_p = func_021BEF08();
    NHTTPReqInfo *reqInfo_p = func_021BEF48((int)sysInfo_p);
    NHTTPThreadInfo *threadInfo_p = func_021BEF50((void *)((int)sysInfo_p));
    NHTTPBgnEndInfo *bgnEndInfo_p = func_021BEF3C(sysInfo_p);
    void *mutexInfo_p = func_021BEF58((int)sysInfo_p);
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
        recvbyte = func_021B9F94(mutexInfo_p, req_p, bgnEndInfo_p->socket, &tmpbuf[totalRecvbyte],
                                 512 - totalRecvbyte, 0);
        totalRecvbyte += recvbyte;
        res_p->httpStatus = func_021BA448((signed char *)(&tmpbuf[9]), 3);
        if (func_021BA150(tmpbuf, g_021CE4A8, 5) == 0 && tmpbuf[8] == ' ' && res_p->httpStatus == 200)
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
            recvbyte = func_021B9F94(mutexInfo_p, req_p, bgnEndInfo_p->socket, commBuf_p, 1, 0);
            if (recvbyte < 0)
                return 0;
            if (recvbyte != 0)
                return 0;
        }
    }
}








int func_021BC924(void *threadData_p)
{
	int sendStatus;
	NHTTPi_DATALIST *datalist_p;
	NHTTPReq *req_p;
	NHTTPi_REQLIST *reqInfo_p;
	void *sysInfo_p;

	sysInfo_p = func_021BEF08();
	reqInfo_p = ((NHTTPReqInfo *)func_021BEF48((int)sysInfo_p))->reqCurrent;
	req_p = reqInfo_p->req_p;
	while ((datalist_p = func_021BABF4(&req_p->hdrlist_p)) != 0) {
		sendStatus = func_021BC384(threadData_p, datalist_p->name, func_021BA118(datalist_p->name));
		if (sendStatus) {
			return sendStatus;
		}
		sendStatus = func_021BC384(threadData_p, g_021CE4B0, 2);
		if (sendStatus) {
			return sendStatus;
		}
		sendStatus = func_021BC384(threadData_p, datalist_p->data, func_021BA118(datalist_p->data));
		if (sendStatus) {
			return sendStatus;
		}
		sendStatus = func_021BC384(threadData_p, g_021CE440, 2);
		if (sendStatus) {
			return sendStatus;
		}
		func_021BA850((int)datalist_p);
	}
	return 0;
}







/*
 * sdk:      NHTTPi_SendProcPostDataRaw (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
static int func_021BC9F0(NHTTPThreadData *threadData_p)
{
    void *sysInfo_p;
    NHTTPThreadInfo *threadInfo_p;
    void *mutexInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPReq *req_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    char *commBuf_p;
    unsigned long contentLength;
    int contentLengthBufLen;
    char contentLengthBuf[12];
    int sendStatus;
    int result;

    sysInfo_p = func_021BEF08();
    mutexInfo_p = func_021BEF58((int)sysInfo_p);
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    threadInfo_p = func_021BEF50((void *)((int)sysInfo_p));
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






static int NHTTPi_SendProcPostDataBinary(NHTTPThreadData *threadData_p)
{
    void *sysInfo_p;
    void *mutexInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPReq *req_p;
    NHTTPThreadInfo *threadInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
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
            if (datalist_p->isBinary != 0) {
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
    result = NHTTPi_SendData(threadData_p, (req_p->multipartBound + 2), 0x12);
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
            result = NHTTPi_SendData(threadData_p, req_p->multipartBound, 0x14);
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
            if (datalist_p->isBinary != 0) {
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
    result = NHTTPi_SendData(threadData_p, req_p->multipartBound, 0x14);
    if (result != 0) {
        return result;
    }
    result = NHTTPi_SendData(threadData_p, g_021CE4CC, 4);
    if (result != 0) {
        return result;
    }
    return 0;
}






static int NHTTPi_SendProcPostDataAscii(NHTTPThreadData *threadData_p)
{
    void *sysInfo_p;
    void *mutexInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPReq *req_p;
    NHTTPThreadInfo *threadInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
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
void func_021BD220(NHTTPThreadData *threadData_p)
{
    threadData_p->id = -1;
    func_021BA13C((void *)((int)threadData_p->preHostname), 0x100);
    func_021BA13C((void *)((int)threadData_p->tmpBodyBuf), 0x200);
    threadData_p->hostaddr = -1;
    threadData_p->preHostaddr = -1;
    threadData_p->sendBufwp = 0;
    threadData_p->isKeepAlive = 0;
    threadData_p->isChunked = 0;
    threadData_p->restartConnect = 0;
    threadData_p->contentLength = 0;
    threadData_p->result = 0;
}






/*
 * sdk:      NHTTPi_ThreadReqEnd (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
static void func_021BD270(NHTTPThreadData *threadData_p)
{
    NHTTPSysInfo *sysInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPReq *req_p;
    NHTTPRes *res_p;
    NHTTPConnection *connection_p;

    sysInfo_p = (NHTTPSysInfo *)func_021BEF08();
    bgnEndInfo_p = func_021BEF3C(sysInfo_p);
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    mutexInfo_p = func_021BEF58((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    connection_p = func_021BEBE0(mutexInfo_p, req_p);

    if (req_p->doCancel) {
        threadData_p->result = 8;
        threadData_p->isKeepAlive = 0;
    }
    if (threadData_p->isKeepAlive == 0 && bgnEndInfo_p->socket >= 0) {
        if (func_021B9CFC(mutexInfo_p, req_p, bgnEndInfo_p->socket) < 0)
            threadData_p->result = 10;
        bgnEndInfo_p->socket = -1;
    }
    if (threadData_p->result == 0) {
        res_p->isSuccess = 1;
    } else {
        res_p->isSuccess = 0;
        func_021BA874((u8 *)bgnEndInfo_p, threadData_p->result);
        if (res_p->recvBuf_p == threadData_p->tmpBodyBuf) {
            res_p->recvBuf_p = 0;
            res_p->recvBufLen = 0;
        }
    }
    if (connection_p != 0)
        connection_p->nhttpError = threadData_p->result;

    func_021BEFCC(mutexInfo_p);
    func_021BA850((int)reqInfo_p->reqCurrent);
    reqInfo_p->reqCurrent = 0;
    func_021BEFD8(mutexInfo_p);
    func_021BB934((int)mutexInfo_p, (u8 *)req_p);
    if (connection_p != 0 && res_p->isSuccess != 0)
        connection_p->status = 5;
    func_021BEE1C(mutexInfo_p, connection_p);
    if (connection_p != 0)
        func_021BEA98((u8 *)connection_p);
    func_021BF1B0(connection_p);
}




int func_021BD3B8(NHTTPThreadData *threadData_p)
{
    void *sysInfo_p;
    void *mutexInfo_p;
    void *listInfo_p;
    NHTTPi_REQLIST *list_p;
    NHTTPReqInfo *reqInfo_p;
    void *threadInfo_p;

    sysInfo_p = func_021BEF08();
    mutexInfo_p = func_021BEF58();
    func_021BEFCC();
    listInfo_p = func_021BEF40((int)sysInfo_p);
    list_p = (NHTTPi_REQLIST *)func_021BAEC8(listInfo_p);
    if (list_p == 0) {
        threadData_p->id = -1;
    } else {
        reqInfo_p = func_021BEF48((int)sysInfo_p);
        threadData_p->id = list_p->id;
        reqInfo_p->reqCurrent = list_p;
    }
    func_021BEFD8(mutexInfo_p);
    if (threadData_p->id >= 0) {
        return 1;
    }
    threadInfo_p = func_021BEF50(sysInfo_p);
    func_021B9BF4((int)threadInfo_p);
    return 0;
}




static int func_021BD430(NHTTPThreadData *threadData_p)
{
    void *sysInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPReq *req_p;
    char *hostname_p;

    sysInfo_p = func_021BEF08();
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    hostname_p = req_p->hostname_p;
    if (req_p->isProxy) {
        hostname_p = req_p->proxyAddr;
    }
    if (func_021BA118(hostname_p) == 0 || func_021BA130(hostname_p, threadData_p->preHostname) != 0) {
        threadData_p->hostaddr = func_021BA098((int)req_p, hostname_p);
        if (threadData_p->hostaddr == 0) {
            if (req_p->isProxy) {
                threadData_p->result = 12;
                return 0;
            } else {
                threadData_p->result = 4;
                return 0;
            }
        }
    } else {
        threadData_p->hostaddr = threadData_p->preHostaddr;
    }
    func_021BA13C((void *)((int)threadData_p->preHostname), 256);
    func_021BA100(threadData_p->preHostname, hostname_p, func_021BA124(hostname_p, 255));
    threadData_p->port = req_p->port;
    if (req_p->isProxy) {
        threadData_p->port = req_p->proxyPort;
    }
    if (threadData_p->hostaddr != threadData_p->preHostaddr
        || threadData_p->port != threadData_p->prePort
        || req_p->isSSL == 1) {
        threadData_p->isKeepAlive = 0;
    }
    threadData_p->preHostaddr = threadData_p->hostaddr;
    threadData_p->prePort = threadData_p->port;
    return 1;
}




/*
 * sdk:      NHTTPi_ThreadConnectProc (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * The DWARF declares NHTTPi_SocClose(req_p, socket) and NHTTPi_SocOpen(void),
 * but the object passes (mutexInfo_p, req_p, socket) and req_p in r0.
 */
int func_021BD548(NHTTPThreadData *threadData_p)
{
    NHTTPSysInfo *sysInfo_p = (NHTTPSysInfo *)func_021BEF08();
    NHTTPBgnEndInfo *bgnEndInfo_p = func_021BEF3C();
    NHTTPReqInfo *reqInfo_p = func_021BEF48((int)sysInfo_p);
    NHTTPReq *req_p = reqInfo_p->reqCurrent->req_p;
    NHTTPMutexInfo *mutexInfo_p = func_021BEF58((int)sysInfo_p);

    if (threadData_p->isKeepAlive == 1) {
        if (func_021B9CA4(bgnEndInfo_p->socket) == -1)
            threadData_p->isKeepAlive = 0;
    }
    if (threadData_p->isKeepAlive == 0) {
        if (bgnEndInfo_p->socket >= 0) {
            if (func_021B9CFC(mutexInfo_p, req_p, bgnEndInfo_p->socket) < 0) {
                bgnEndInfo_p->socket = -1;
                threadData_p->result = 10;
                return 0;
            }
        }
        bgnEndInfo_p->socket = func_021B9CE4(req_p);
        if (bgnEndInfo_p->socket < 0) {
            threadData_p->result = 3;
            return 0;
        }
        func_021BEFCC(mutexInfo_p);
        reqInfo_p->reqCurrent->socket = bgnEndInfo_p->socket;
        func_021BEFD8(mutexInfo_p);
        if (req_p->doCancel)
            return 0;
        if (func_021B9D8C(bgnEndInfo_p, mutexInfo_p, req_p, bgnEndInfo_p->socket,
                          threadData_p->hostaddr, threadData_p->port) < 0) {
            if (req_p->isProxy) {
                threadData_p->result = 13;
                return 0;
            }
            if (func_021BA884((u8 *)bgnEndInfo_p)) {
                threadData_p->result = 14;
                return 0;
            } else {
                threadData_p->result = 5;
                return 0;
            }
        }
    } else {
        func_021BEFCC(mutexInfo_p);
        reqInfo_p->reqCurrent->socket = bgnEndInfo_p->socket;
        func_021BEFD8(mutexInfo_p);
    }
    return 1;
}






/*
 * sdk:      NHTTPi_ThreadProxyProc (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
static int func_021BD6DC(NHTTPThreadData *threadData_p)
{
    void *sysInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPReqInfo *reqInfo_p;
    void *mutexInfo_p;
    NHTTPReq *req_p;
    int sendStatus;
    int SSLConnectResult;

    sysInfo_p = func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    mutexInfo_p = func_021BEF58((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    threadData_p->result = 10;
    threadData_p->sendBufwp = 0;
    if (req_p->isSSL && req_p->isProxy) {
        sendStatus = NHTTPi_SendProxyConnectMethod(threadData_p);
        if (sendStatus != 0) {
            return sendStatus;
        }
        if (func_021BC740(threadData_p) == 0) {
            return 1;
        }
        SSLConnectResult = func_021B9E3C(bgnEndInfo_p, mutexInfo_p, req_p, bgnEndInfo_p->socket);
        if (SSLConnectResult != 0) {
            if (SSLConnectResult == -1004) {
                if (func_021BA884((u8 *)bgnEndInfo_p) != 0) {
                    threadData_p->result = 16;
                }
                return 1;
            } else if (SSLConnectResult == -1005) {
                if (func_021BA884((u8 *)bgnEndInfo_p) != 0) {
                    threadData_p->result = 17;
                }
                return 1;
            } else {
                if (func_021BA884((u8 *)bgnEndInfo_p) != 0) {
                    threadData_p->result = 14;
                }
                return 1;
            }
        }
    }
    return 0;
}







static int NHTTPi_ThreadSendProc(NHTTPThreadData *threadData_p)
{
    void *sysInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPReq *req_p;
    void *mutexInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPConnection *connection_p;
    NHTTPThreadInfo *threadInfo_p;
    char *commBuf_p;
    int urlLength;
    int sendStatus;
    int isMultipartForm;
    NHTTPi_DATALIST *datalist_p;
    int postResult;
    int a_encodingType;
    int stat;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    commBuf_p = threadInfo_p->commBuf;
    urlLength = NHTTPi_strlen(req_p->URL_p);
    sendStatus = 0;
    threadData_p->result = 0xa;
    if (connection_p != 0) {
        connection_p->status = 2;
    }
    threadData_p->sendBufwp = 0;
    switch (req_p->method) {
    case 0:
        sendStatus = NHTTPi_SendData(threadData_p, g_021CE4DC, 4);
        break;
    case 1:
        sendStatus = NHTTPi_SendData(threadData_p, g_021CE4E4, 5);
        break;
    case 2:
        sendStatus = NHTTPi_SendData(threadData_p, g_021CE4EC, 5);
        break;
    }
    if (sendStatus != 0) {
        return sendStatus;
    }
    if (req_p->isProxy != 0 && req_p->isSSL == 0) {
        sendStatus = NHTTPi_SendData(threadData_p, req_p->URL_p, urlLength);
        if (sendStatus != 0) {
            return sendStatus;
        }
    } else {
        if (urlLength > req_p->hostDescLen) {
            sendStatus = NHTTPi_SendData(threadData_p, req_p->URL_p + req_p->hostDescLen, urlLength - req_p->hostDescLen);
            if (sendStatus != 0) {
                return sendStatus;
            }
        } else {
            sendStatus = NHTTPi_SendData(threadData_p, g_021CE4F4, 1);
            if (sendStatus != 0) {
                return sendStatus;
            }
        }
    }
    sendStatus = NHTTPi_SendData(threadData_p, g_021CE46C, 0xb);
    if (sendStatus != 0) {
        return sendStatus;
    }
    stat = 8;
    if (req_p->isSSL == 0) {
        stat = 7;
    }
    sendStatus = NHTTPi_SendData(threadData_p, g_021CE478, 6);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = NHTTPi_SendData(threadData_p, req_p->URL_p + stat, req_p->hostLen - stat);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = NHTTPi_SendData(threadData_p, g_021CE440, 2);
    if (sendStatus != 0) {
        return sendStatus;
    }
    if (req_p->isProxy != 0 && req_p->isSSL == 0) {
        sendStatus = NHTTPi_SendProxyAuthorization(threadData_p);
        if (sendStatus != 0) {
            return sendStatus;
        }
    }
    sendStatus = NHTTPi_SendBasicAuthorization(threadData_p);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = NHTTPi_SendHeaderList(threadData_p);
    if (sendStatus != 0) {
        return sendStatus;
    }
    if (req_p->method == 1) {
        if (req_p->isRawData != 0) {
            postResult = NHTTPi_SendProcPostDataRaw(threadData_p);
        } else {
            a_encodingType = req_p->postEncoding;
            if (a_encodingType == 0) {
                isMultipartForm = 0;
                datalist_p = req_p->datalist_p;
                if (datalist_p != 0) {
                    while (1) {
                        if (datalist_p->isBinary != 0) {
                            isMultipartForm = 1;
                            break;
                        }
                        if (datalist_p == req_p->datalist_p->head) {
                            break;
                        }
                        datalist_p = datalist_p->next;
                        if (datalist_p != 0) {
                            continue;
                        }
                        break;
                    }
                }
            } else {
                isMultipartForm = 1;
                if (a_encodingType != 2) {
                    isMultipartForm = 0;
                }
            }
            if (isMultipartForm) {
                postResult = NHTTPi_SendProcPostDataBinary(threadData_p);
            } else {
                postResult = NHTTPi_SendProcPostDataAscii(threadData_p);
            }
        }
        if (postResult != 0) {
            if (postResult == 3) {
                threadData_p->result = 3;
            }
            return postResult;
        }
    } else {
        sendStatus = NHTTPi_SendData(threadData_p, g_021CE440, 2);
        if (sendStatus != 0) {
            return sendStatus;
        }
    }
    stat = threadData_p->sendBufwp;
    postResult = 0;
    if (stat > 0) {
        stat = NHTTPi_SocSend(req_p, bgnEndInfo_p->socket, commBuf_p, threadData_p->sendBufwp, 0);
        threadData_p->sendBufwp = 0;
        NHTTPi_memclr(commBuf_p, 0x4000);
        if (stat < 0) {
            postResult = 1;
        }
        if (stat == 0) {
            postResult = 2;
        }
    }
    threadData_p->sendBufwp = 0;
    NHTTPi_memclr(commBuf_p, 0x4000);
    return postResult;
}







/*
 * sdk:      NHTTPi_ThreadRecvHeaderProc (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * note: NHTTPRes.headerLen is declared volatile. The object stores headerLen and
 * reloads it from the same slot before the zero test; every non-volatile
 * spelling tried (12 variants) forwards the stored register and drops the ldr.
 * The DWARF has a plain int.
 */
static int func_021BDB68(NHTTPThreadData *threadData_p)
{
    NHTTPSysInfo *sysInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPReq *req_p;
    NHTTPRes *res_p;
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPConnection *connection_p;
    int recvbyte;
    char tmpBuf[4];
    NHTTPi_HDRBUFLIST *headerBuf_p;
    int wp;

    sysInfo_p = func_021BEF08();
    reqInfo_p = (NHTTPReqInfo *)func_021BEF48((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    mutexInfo_p = func_021BEF58(sysInfo_p);
    connection_p = func_021BEBE0(mutexInfo_p, req_p);
    bgnEndInfo_p = func_021BEF3C(sysInfo_p);
    memset(tmpBuf, 0, 4);
    if (connection_p)
        connection_p->status = 3;
    res_p->headerLen = 0;
    func_021BA13C(threadData_p->tmpHeaderBuf, 14);
    headerBuf_p = res_p->hdrBufBlock_p;
    threadData_p->recvBufwp = 0;

    while (1) {
        if (req_p->doCancel)
            return 0;
        if (threadData_p->recvBufwp < 0x400) {
            recvbyte = func_021B9F94(mutexInfo_p, req_p, bgnEndInfo_p->socket,
                                     res_p->hdrBufFirst + threadData_p->recvBufwp, 1, 0);
            tmpBuf[threadData_p->recvBufwp & 3] = res_p->hdrBufFirst[threadData_p->recvBufwp];
        } else {
            wp = threadData_p->recvBufwp & 0x1ff;
            if (wp == 0) {
                if (headerBuf_p) {
                    headerBuf_p = headerBuf_p->next_p = func_021BA820(0x204, 4);
                } else {
                    headerBuf_p = func_021BA820(0x204, 4);
                    res_p->hdrBufBlock_p = headerBuf_p;
                }
                if (headerBuf_p == 0) {
                    threadData_p->result = 1;
                    return 0;
                }
                headerBuf_p->next_p = 0;
            }
            recvbyte = func_021B9F94(mutexInfo_p, req_p, bgnEndInfo_p->socket,
                                     headerBuf_p->block + wp, 1, 0);
            tmpBuf[threadData_p->recvBufwp & 3] = headerBuf_p->block[wp];
        }
        if (recvbyte <= 0) {
            threadData_p->result = 10;
            return 0;
        }
        threadData_p->recvBufwp += recvbyte;
        if (func_021BBEC0(tmpBuf, threadData_p->recvBufwp))
            break;
    }
    res_p->headerLen = threadData_p->recvBufwp;
    if (res_p->headerLen == 0) {
        threadData_p->result = 7;
        return 0;
    }
    return 1;
}





int NHTTPi_ThreadParseHeaderProc(NHTTPThreadData *threadData_p)
{
    int connectionHeaderStrLen;
    int labelend;
    int n;
    char *commBuf_p;
    NHTTPThreadInfo *threadInfo_p;
    NHTTPReq *req_p;
    NHTTPRes *res_p;
    NHTTPReqInfo *reqInfo_p;
    void *sysInfo_p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    commBuf_p = threadInfo_p->commBuf;

    if (NHTTPi_loadFromHdrRecvBuf(res_p, threadData_p->tmpHeaderBuf, 0, 0xe) == 0)
    {
        threadData_p->result = 7;
        return 0;
    }
    if (NHTTPi_strnicmp(threadData_p->tmpHeaderBuf, g_021CE4A8, 5) != 0)
    {
        threadData_p->result = 7;
        return 0;
    }
    if (threadData_p->tmpHeaderBuf[8] != 0x20)
    {
        threadData_p->result = 7;
        return 0;
    }

    res_p->httpStatus = NHTTPi_strToInt(threadData_p->tmpHeaderBuf + 9, 3);
    if (res_p->httpStatus < 0)
    {
        threadData_p->result = 7;
        return 0;
    }

    if (NHTTPi_findNextLineHdrRecvBuf(res_p, 0xc, res_p->headerLen, &labelend, 0) < 0)
    {
        threadData_p->result = 7;
        return 0;
    }

    threadData_p->contentLength = NHTTPi_getHeaderValue(res_p, g_021CE4F8, &n);
    if (threadData_p->contentLength == 0)
    {
        threadData_p->result = 0;
        return 0;
    }
    if (threadData_p->contentLength > 0x4000)
    {
        threadData_p->result = 7;
        return 0;
    }
    if (threadData_p->contentLength > 0)
    {
        if (NHTTPi_loadFromHdrRecvBuf(res_p, commBuf_p, n,
                                      threadData_p->contentLength) == 0)
        {
            threadData_p->result = 7;
            return 0;
        }
        threadData_p->contentLength =
            NHTTPi_strToInt(commBuf_p, threadData_p->contentLength);
        if (threadData_p->contentLength < 0)
        {
            threadData_p->result = 7;
            return 0;
        }
        res_p->contentLength = threadData_p->contentLength;
    }
    else
    {
        res_p->contentLength = -1;
    }

    if (req_p->isSSL != 0)
    {
        threadData_p->isKeepAlive = 0;
    }
    else
    {
        connectionHeaderStrLen = NHTTPi_getHeaderValue(res_p, g_021CE508, &n);
        if (connectionHeaderStrLen == 0)
        {
            threadData_p->result = 7;
            threadData_p->isKeepAlive = 0;
            return 0;
        }
        if (connectionHeaderStrLen > 0x4000)
        {
            threadData_p->isKeepAlive = 0;
        }
        else
        {
            if (connectionHeaderStrLen > 0)
            {
                if (NHTTPi_compareTokenN_HdrRecvBuf(res_p, n,
                                                   n + connectionHeaderStrLen,
                                                   g_021CE514, 0) == 0)
                    threadData_p->isKeepAlive = 1;
                else
                    threadData_p->isKeepAlive = 0;
            }
            else
            {
                threadData_p->isKeepAlive = 0;
            }
        }
    }

    threadData_p->isChunked = NHTTPi_getHeaderValue(res_p, g_021CE520, &n);
    if (threadData_p->isChunked == 0)
    {
        threadData_p->result = 7;
        return 0;
    }
    if (threadData_p->isChunked > 0x4000)
    {
        threadData_p->isChunked = 0;
    }
    else
    {
        threadData_p->isChunked =
            (threadData_p->isChunked > 0)
                ? (NHTTPi_compareTokenN_HdrRecvBuf(res_p, n,
                                                   n + threadData_p->isChunked,
                                                   g_021CE534, 0x3b) == 0)
                : 0;
    }

    threadData_p->result = 0;
    res_p->isHeaderParse = 1;
    return 1;
}




static int NHTTPi_ThreadRecvBodyProc(NHTTPThreadData *threadData_p)
{
    void *sysInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPReq *req_p;
    NHTTPRes *res_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    void *mutexInfo_p;
    void *connection_p;
    NHTTPThreadInfo *threadInfo_p;
    char *commBuf_p;
    char tmpBuf[2];
    int chunkSize = 0;
    int n;
    int recvbyte;
    int idx;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    commBuf_p = threadInfo_p->commBuf;
    if (req_p->method == 2 || res_p->httpStatus == 0xcc || res_p->httpStatus == 0x130 ||
        (res_p->httpStatus >= 100 && res_p->httpStatus < 200)) {
        return 1;
    }
    NHTTPi_SetVirtualContentLength(connection_p, 0);
    if (connection_p != 0) {
        *(int *)connection_p = 4;
    }
    if (threadData_p->contentLength < 0) {
        goto chunked;
    }
    NHTTPi_SetVirtualContentLength(connection_p, threadData_p->contentLength);
    if (threadData_p->contentLength > 0) {
        do {
            if (threadData_p->result != 6) {
                if (!NHTTPi_BufFull(mutexInfo_p, res_p)) {
                    threadData_p->result = 6;
                    res_p->recvBuf_p = BUF2(threadData_p);
                    res_p->recvBufLen = 0x200;
                }
            }
            if (threadData_p->result == 6)
                n = NHTTPi_RecvBufN(mutexInfo_p, req_p, bgnEndInfo_p->socket, chunkSize,
                                    threadData_p->contentLength, chunkSize);
            else
                n = NHTTPi_RecvBufN(mutexInfo_p, req_p, bgnEndInfo_p->socket, res_p->bodyLen,
                                    threadData_p->contentLength, chunkSize);
            if (n < 0) {
                return 0;
            }
            if (n == 0) {
                break;
            }
            if (threadData_p->result != 6) {
                res_p->bodyLen += n;
                res_p->totalBodyLen += n;
            }
            threadData_p->contentLength -= n;
        } while (threadData_p->contentLength > 0);
    }
    if (threadData_p->result != 6) {
        if (threadData_p->contentLength != 0) {
            threadData_p->result = NHTTPi_isRecvBufFull(res_p, res_p->bodyLen) ? 6 : 0xa;
        } else {
            threadData_p->result = chunkSize;
        }
    }
    goto tail;
chunked:
    threadData_p->result = 0xa;
    if (threadData_p->isChunked == 0) {
        goto plain;
    }
    chunkSize = 0xa - 0xb;
reset:
    tmpBuf[0] = 0;
    tmpBuf[1] = 0;
    threadData_p->recvBufwp = 0;
    while (threadData_p->recvBufwp < 0x4000) {
        if (NHTTPi_SocRecv(mutexInfo_p, req_p, bgnEndInfo_p->socket, commBuf_p + threadData_p->recvBufwp, 1, 0) < 0) {
            return 0;
        }
        idx = threadData_p->recvBufwp;
        recvbyte = commBuf_p[idx];
        tmpBuf[idx & 1] = (char)recvbyte;
        if (recvbyte == ';' || (recvbyte == 0xa && tmpBuf[(idx - 1) & 1] == 0xd)) {
            if (recvbyte == 0xa) {
                idx--;
            } else {
                if (NHTTPi_SkipLineBuf(mutexInfo_p, req_p, bgnEndInfo_p->socket) <= 0) {
                    return 0;
                }
            }
            if (idx == 0) {
                return 0;
            }
            chunkSize = NHTTPi_strToHex(commBuf_p, idx);
            if (chunkSize < 0) {
                return 0;
            }
            break;
        }
        threadData_p->recvBufwp++;
    }
    if (threadData_p->recvBufwp == 0x4000) {
        threadData_p->result = 7;
        return 0;
    }
    if (chunkSize > 0) {
        NHTTPi_SetVirtualContentLength(connection_p, chunkSize);
        if (chunkSize > 0) {
            do {
                if (threadData_p->result != 6) {
                    if (!NHTTPi_BufFull(mutexInfo_p, res_p)) {
                        threadData_p->result = 6;
                        res_p->recvBuf_p = BUF2(threadData_p);
                        res_p->recvBufLen = 0x200;
                    }
                }
                if (threadData_p->result == 6)
                    n = NHTTPi_RecvBufN(mutexInfo_p, req_p, bgnEndInfo_p->socket, 0, chunkSize, 0);
                else
                    n = NHTTPi_RecvBufN(mutexInfo_p, req_p, bgnEndInfo_p->socket, res_p->bodyLen, chunkSize, 0);
                if (n <= 0) {
                    return 0;
                }
                res_p->bodyLen += n;
                res_p->totalBodyLen += n;
                chunkSize -= n;
                if (chunkSize == 0) {
                    if (NHTTPi_SocRecv(mutexInfo_p, req_p, bgnEndInfo_p->socket, commBuf_p, 2, 0) <= 0) {
                        return 0;
                    }
                }
            } while (chunkSize > 0);
        }
        goto reset;
    }
    NHTTPi_SkipLineBuf(mutexInfo_p, req_p, bgnEndInfo_p->socket);
    threadData_p->result = 0;
    goto tail;
plain:
    for (;;) {
        if (!NHTTPi_BufFull(mutexInfo_p, res_p)) {
            threadData_p->result = 6;
            res_p->recvBuf_p = BUF2(threadData_p);
            res_p->recvBufLen = 0x200;
        }
        if (threadData_p->result == 6) {
            n = NHTTPi_RecvBuf(mutexInfo_p, req_p, bgnEndInfo_p->socket, chunkSize, chunkSize);
        } else {
            n = NHTTPi_RecvBuf(mutexInfo_p, req_p, bgnEndInfo_p->socket, res_p->bodyLen, 0);
        }
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            if (threadData_p->result != 6) {
                threadData_p->result = 0;
            }
            break;
        }
        res_p->bodyLen += n;
        res_p->totalBodyLen += n;
    }
tail:
    {
        void *conn2 = NHTTPi_Response2Connection(mutexInfo_p, res_p);

        if (threadData_p->result == 0 && conn2 != 0) {
            NHTTPi_ReceivedCallback(mutexInfo_p, conn2);
        }
    }
    return 1;
}



/*
 * sdk:      NHTTPi_CommThreadProcMain (libnhttp.TWL.HYB.a(nhttp_thread.o))
 */
void func_021BE4D4(void)
{
    void *sysInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPThreadData threadData;

    sysInfo_p = func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    func_021BD220((NHTTPThreadData *)&threadData);
    while (bgnEndInfo_p->isThreadEnd == 0) {
        if (threadData.restartConnect == 0) {
            if (func_021BD3B8(&threadData) == 0) {
                continue;
            }
            if (reqInfo_p->reqCurrent->req_p->doCancel != 0) {
                func_021BD270((struct _NHTTPThreadData *)(&threadData));
                continue;
            }
            if (func_021BD430(&threadData) == 0) {
                func_021BD270((struct _NHTTPThreadData *)(&threadData));
                continue;
            }
        }
        if (threadData.restartConnect == 1) {
            threadData.restartConnect = 0;
        }
        if (func_021BD548((struct _NHTTPThreadData *)(&threadData)) == 0) {
            func_021BD270((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        switch (func_021BD6DC(&threadData)) {
        case 0:
            break;
        case 2:
            threadData.restartConnect = 1;
            continue;
        case 1:
            func_021BD270((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        switch (func_021BD7E8(&threadData)) {
        case 0:
            break;
        case 2:
            threadData.restartConnect = 1;
            continue;
        case 1:
        case 3:
            func_021BD270((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        if (reqInfo_p->reqCurrent->req_p->doCancel != 0) {
            func_021BD270((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        if (func_021BDB68((struct _NHTTPThreadData *)(&threadData)) == 0) {
            func_021BD270((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        if (func_021BDD34(&threadData) == 0) {
            func_021BD270((struct _NHTTPThreadData *)(&threadData));
            continue;
        }
        func_021BDFF8(&threadData);
        func_021BD270((struct _NHTTPThreadData *)(&threadData));
    }
}
