/*
 * function: func_021BC2FC
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
 *   func_021BB2FC  0x021BB2FC  arm  ov114
 *   func_021BEBF0  0x021BEBF0  arm  ov114
 *   func_021BED04  0x021BED04  arm  ov114
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
extern int func_021BB2FC(u8 *p, u32 v);
extern void *func_021BEBF0(void *mutexInfo_p, Res *res_p);
struct Conn;
extern void func_021BED04(void *mutexInfo_p, struct Conn *connection_p);

int func_021BC2FC(void *mutexInfo_p, Res *res_p)
{
    void *connection_p;
    int full;
    int ret;

    ret = 0;
    full = func_021BB2FC((u8 *)res_p, res_p->pos);
    if (res_p->a == 0 || res_p->b == 0 || full != 0) {
        connection_p = func_021BEBF0(mutexInfo_p, res_p);
        if (connection_p != 0) {
            func_021BED04(mutexInfo_p, connection_p);
            if (res_p->b != 0 && res_p->a != 0) {
                full = func_021BB2FC((u8 *)res_p, res_p->pos);
                if (full == 0)
                    ret = 1;
            }
        }
    } else if (full == 0) {
        ret = 1;
    }
    return ret;
}
