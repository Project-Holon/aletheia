/*
 * function: func_021BC160
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
 *   func_021BEBE0  0x021BEBE0  arm  ov114
 *   func_021BEC74  0x021BEC74  arm  ov114
 *   func_021BBF44  0x021BBF44  arm  ov114
 *   func_021BA13C  0x021BA13C  arm  ov114
 *   func_021BA2D0  0x021BA2D0  arm  ov114
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

extern NHTTPConnection *func_021BEBE0(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
struct Conn;
extern int func_021BEC74(void *mutexInfo_p, struct Conn *connection_p, char *label_p, int offset);
extern int func_021BBF44(NHTTPReq *req_p, char *commBuf_p, int socket, int *bufwp_p,
                         char *src_p, int srclen);
extern void func_021BA13C(void *p_p, int size);
extern int func_021BA2D0(char *dst, int c);

static int func_021BC160(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, char *commBuf_p,
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

    connection_p = func_021BEBE0(mutexInfo_p, req_p);
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
            stat = func_021BBF44(req_p, commBuf_p, socket, bufwp_p, value_p, length);
            if (stat < 0)
                return 1;
            if (stat == 0)
                return 2;
            break;
        case 2:
            for (p = 0; p < length; p++) {
                func_021BA13C(urlencode, 3);
                n = func_021BA2D0(urlencode, value_p[p]);
                stat = func_021BBF44(req_p, commBuf_p, socket, bufwp_p, urlencode, n);
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
