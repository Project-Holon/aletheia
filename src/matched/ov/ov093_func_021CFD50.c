/*
 * function: func_021CFD50
 * address:  0x021CFD50
 * packet:   pkt_ov093_021CFD50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D38  0x021B8D38  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   _ull_mul       0x0209C054  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef unsigned long long u64;

struct G {
    void *p0;
    void *p1;
    u8 pad0[0xec];
    u64 seed;
    u64 mul;
    u64 add;
};

extern u8 func_021B8D38(void *p, void *a, u16 k, u8 *out);
extern int func_021B9934(void *p, int i);

int func_021CFD50(struct G *g, int k)
{
    u8 buf[4];
    u8 n;
    u32 v;

    n = func_021B8D38(g->p0, g->p1, k | 0x100, buf);
    if (n) {
        g->seed = g->mul * g->seed + g->add;
        if (n == 0) {
            v = (u32)(g->seed >> 32);
        } else {
            v = (u32)(((g->seed >> 32) * (u32)n) >> 32);
        }
        return func_021B9934(g->p1, buf[(u8)v]);
    }
    return 0;
}
