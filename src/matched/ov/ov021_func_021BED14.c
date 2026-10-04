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
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern X *func_020124E8(u32 h);
typedef unsigned char  u8;
extern int func_021BEA6C(int x);
extern int func_021BF274(u32 p0, int *st, u8 *q);
u32 func_021BED14(u32 a, u32 b)
{
    u32 h = (u32)func_020122C0((void *)a, 0, func_021BF274, 0x2c);
    X *x = func_020124E8(h);
    x->f0 = a;
    x->f4 = b;
    x->f8 = 7;
    x->fC = func_021BEA6C(7);
    return h;
}
