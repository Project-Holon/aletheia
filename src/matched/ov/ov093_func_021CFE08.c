/*
 * function: func_021CFE08
 * address:  0x021CFE08
 * packet:   pkt_ov093_021CFE08
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D0644  0x021D0644  thumb  ov093
 *   func_021D055C  0x021D055C  thumb  ov093
 *   _ull_mul       0x0209C054  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef unsigned long long u64;

struct G {
    void *p0;
    u8 pad0[0xf0];
    u64 seed;
    u64 mul;
    u64 add;
};

extern u32 BTL_MAIN_GetRule(void **p);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D0644(void *g, void *m, void *a, int b);
extern int func_021D055C(u8 *g, void *a, int b);

int func_021CFE08(struct G *g, void *a, void *b)
{
    if (BTL_MAIN_GetRule(g->p0) != 0)
        return 0;
    if (func_021D59B4(b, 0x11) == 0x19) {
        if (func_021D0644(g, a, b, 4) == 0 && func_021D055C((u8 *)g, b, 4) != 0) {
            g->seed = g->mul * g->seed + g->add;
            if ((u32)(((g->seed >> 32) * 3) >> 32) < 2)
                return 1;
        }
    }
    return 0;
}
