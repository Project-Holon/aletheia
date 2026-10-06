/*
 * function: func_021C7058
 * address:  0x021C7058
 * packet:   pkt_ov021_021C7058
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
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *p);
extern Q *func_021C6C70(u32 heap, u32 size, void *fn);
extern u32 func_021C6CCC(u8 *p);
extern int func_021C71A4(W *w);
Q *func_021C7058(u32 a, u16 b, u32 c)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 0x1c, func_021C71A4);
    W *w = (W *)func_021C6CCC((u8 *)q);
    w->f0 = a;
    w->f4 = (u32)func_02188C58((void *)a);
    w->fC = 0;
    w->f8 = 1;
    w->fE = 0;
    w->f10 = b;
    w->f18 = c;
    return q;
}
