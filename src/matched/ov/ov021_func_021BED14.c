/*
 * function: func_021BED14
 * address:  0x021BED14
 * packet:   pkt_ov021_021BED14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BEA6C  0x021BEA6C  thumb  ov021
 *   func_021BF274  0x021BF274  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; } X;
extern u32 func_020122C0(u32 a, u32 b, void *c, u32 d);
extern X *func_020124E8(u32 h);
extern u32 func_021BEA6C(u32 k);
extern void func_021BF274(void);
u32 func_021BED14(u32 a, u32 b)
{
    u32 h = func_020122C0(a, 0, func_021BF274, 0x2c);
    X *x = func_020124E8(h);
    x->f0 = a;
    x->f4 = b;
    x->f8 = 7;
    x->fC = func_021BEA6C(7);
    return h;
}
