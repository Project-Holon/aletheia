/*
 * function: NHTTPi_BufFull
 * address:  0x021BC2FC
 * packet:   pkt_ov114_021BC2FC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm  ov114
 * status:   EXACT
 *
 * sdk:      NHTTPi_BufFull (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_isRecvBufFull  0x021BB2FC  arm  ov114
 *   NHTTPi_Response2Connection  0x021BEBF0  arm  ov114
 *   NHTTPi_BufferFullCallback  0x021BED04  arm  ov114
 */

typedef struct {
    int pad0;
    int pos;
    char pad8[0x14];
    int a;
    char pad20[0x8];
    int b;
} Res;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int NHTTPi_isRecvBufFull(u8 *p, u32 v);
struct Conn;
extern struct Conn *NHTTPi_Response2Connection(int a, int b);
struct Conn;
extern void NHTTPi_BufferFullCallback(void *mutexInfo_p, struct Conn *connection_p);

int NHTTPi_BufFull(void *mutexInfo_p, Res *res_p)
{
    void *connection_p;
    int full;
    int ret;

    ret = 0;
    full = NHTTPi_isRecvBufFull((u8 *)res_p, res_p->pos);
    if (res_p->a == 0 || res_p->b == 0 || full != 0) {
        connection_p = NHTTPi_Response2Connection((int)mutexInfo_p, (int)res_p);
        if (connection_p != 0) {
            NHTTPi_BufferFullCallback(mutexInfo_p, connection_p);
            if (res_p->b != 0 && res_p->a != 0) {
                full = NHTTPi_isRecvBufFull((u8 *)res_p, res_p->pos);
                if (full == 0)
                    ret = 1;
            }
        }
    } else if (full == 0) {
        ret = 1;
    }
    return ret;
}
