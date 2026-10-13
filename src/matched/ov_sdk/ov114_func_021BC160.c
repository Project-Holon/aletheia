/*
 * function: NHTTPi_SendPostData
 * address:  0x021BC160
 * packet:   pkt_ov114_021BC160
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SendPostData (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_Request2Connection  0x021BEBE0  arm  ov114
 *   NHTTPi_PostSendCallback  0x021BEC74  arm  ov114
 *   NHTTPi_SaveBuf  0x021BBF44  arm  ov114
 *   NHTTPi_memclr  0x021BA13C  arm  ov114
 *   NHTTPi_encodeUrlChar  0x021BA2D0  arm  ov114
 *
 * The DWARF types offset as int. With an int offset, length takes r7 instead of
 * r5 and the two SaveBuf stack stores merge into one stm; declared u32, every
 * byte matches.
 */

typedef unsigned long u32;

typedef struct _NHTTPMutexInfo NHTTPMutexInfo;

typedef struct _NHTTPReq {
    int doCancel;
} NHTTPReq;

typedef struct _NHTTPConnection {
    char pad0[0x24];
    char *postDataBuf;      /* +0x24 */
    u32 postDataLen;        /* +0x28 */
} NHTTPConnection;

extern NHTTPConnection *NHTTPi_Request2Connection(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
struct Conn;
extern int NHTTPi_PostSendCallback(void *mutexInfo_p, struct Conn *connection_p, char *label_p, int offset);
extern int NHTTPi_SaveBuf(NHTTPReq *req_p, char *commBuf_p, int socket, int *bufwp_p,
                         char *src_p, int srclen);
extern void NHTTPi_memclr(void *p_p, int size);
extern int NHTTPi_encodeUrlChar(char *dst, int c);

static int NHTTPi_SendPostData(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, char *commBuf_p,
                         char *label_p, int socket, int *bufwp_p, int sendtype)
{
    u32 offset = 0;
    u32 length;
    char *value_p;
    int stat;
    char urlencode[3];
    int p;
    int n;
    NHTTPConnection *connection_p;

    connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);
    if (connection_p == 0)
        return 3;
    connection_p->postDataBuf = 0;

    while (1) {
        if (req_p->doCancel)
            return 3;
        connection_p->postDataLen = 0;
        if (NHTTPi_PostSendCallback(mutexInfo_p, (struct Conn *)connection_p, label_p, offset) < 0)
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
            stat = NHTTPi_SaveBuf(req_p, commBuf_p, socket, bufwp_p, value_p, length);
            if (stat < 0)
                return 1;
            if (stat == 0)
                return 2;
            break;
        case 2:
            for (p = 0; p < length; p++) {
                NHTTPi_memclr(urlencode, 3);
                n = NHTTPi_encodeUrlChar(urlencode, value_p[p]);
                stat = NHTTPi_SaveBuf(req_p, commBuf_p, socket, bufwp_p, urlencode, n);
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
