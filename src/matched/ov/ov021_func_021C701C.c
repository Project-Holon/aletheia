/*
 * function: func_021C701C
 * address:  0x021C701C
 * packet:   pkt_ov021_021C701C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021C71A4  0x021C71A4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; u32 f14; u32 f18; } W;
extern u32 func_02188C84(u32 a);
extern u32 func_02188C58(u32 a);
extern Q *func_021C6C70(u32 heap, u32 size, void *fn);
extern W *func_021C6CCC(Q *q);
extern int func_021C71A4(W *w);
Q *func_021C701C(u32 a, u16 b, u32 c)
{
    Q *q = func_021C6C70(func_02188C84(a), 0x1c, func_021C71A4);
    W *w = func_021C6CCC(q);
    w->f0 = a;
    w->f4 = func_02188C58(a);
    w->fC = 0;
    w->f8 = 0;
    w->fE = 0;
    w->f10 = b;
    w->f18 = c;
    return q;
}
