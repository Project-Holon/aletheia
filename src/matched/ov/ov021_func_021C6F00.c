/*
 * function: func_021C6F00
 * address:  0x021C6F00
 * packet:   pkt_ov021_021C6F00
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
 *   func_021C6F30  0x021C6F30  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;
typedef struct { u32 f0; u8 f4; u8 f5; u16 f6; u16 f8; u16 fA; u32 fC; u32 f10; } W;
extern u32 func_02188C84(u32 a);
extern Q *func_021C6C70(u32 heap, u32 size, void *fn);
extern W *func_021C6CCC(Q *q);
extern void func_021C6F30(void);
Q *func_021C6F00(u32 a, u16 b, u32 c)
{
    Q *q = func_021C6C70(func_02188C84(a), 0x14, func_021C6F30);
    W *w = func_021C6CCC(q);
    w->f4 = 0;
    w->f0 = a;
    w->f6 = 0;
    w->f8 = b;
    w->f10 = c;
    return q;
}
