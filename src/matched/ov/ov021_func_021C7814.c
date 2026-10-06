/*
 * function: func_021C7814
 * address:  0x021C7814
 * packet:   pkt_ov021_021C7814
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021C7844  0x021C7844  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u32 x, y, z; } V;
extern u16 func_02188C84(u8 *p);
extern Q *func_021C6C70(u32 heap, u32 size, void *fn);
extern u32 func_021C6CCC(u8 *p);
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; } X;
extern int func_021C7844(u32 a, u32 b, u32 c);
Q *func_021C7814(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 0x14, func_021C7844);
    X *x = (X *)func_021C6CCC((u8 *)q);
    x->f0 = a;
    x->f4 = b;
    x->f8 = c;
    x->fC = d;
    x->f10 = e;
    return q;
}
