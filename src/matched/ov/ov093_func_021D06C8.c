/*
 * function: func_021D06C8
 * address:  0x021D06C8
 * packet:   pkt_ov093_021D06C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   _ull_mul       0x0209C054  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef unsigned long long u64;

struct G {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
    u8 pad1[0xc];
    void *list;
};

extern int func_021B9AB0(int k);
struct S2;
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *m);

u8 func_021D06C8(struct G *g)
{
    u8 buf[2];
    u32 cnt;
    u32 v;

    cnt = 1;
    buf[0] = 1;
    if (func_021D5B68(func_021B9C00(g->list, (u8)func_021B9AB0(2))) == 0) {
        buf[cnt++] = 2;
    }
    if (func_021D5B68(func_021B9C00(g->list, (u8)func_021B9AB0(3))) == 0) {
        buf[cnt++] = 3;
    }
    if (cnt > 1) {
        g->seed = g->mul * g->seed + g->add;
        if (cnt == 0) {
            v = (u32)(g->seed >> 32);
        } else {
            v = (u32)(((g->seed >> 32) * (u32)cnt) >> 32);
        }
        return buf[v];
    }
    return 1;
}
