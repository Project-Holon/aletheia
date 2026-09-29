/*
 * function: func_021A9ED8
 * address:  0x021A9ED8
 * packet:   pkt_ov021_021A9ED8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0216255C  0x0216255C  thumb  ov010
 *   func_021AA77C  0x021AA77C  thumb  ov021
 *   func_021AA7AC  0x021AA7AC  thumb  ov021
 *   d_021DDFA4     0x021DDFA4  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int d_021DDFA4;

extern u32 func_02188C84(u32 a);
extern u32 func_02188C80(u32 a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012844(u32 a);
extern u32 func_0216255C(u32 a);
extern u32 func_021AA77C(u32 heap);
extern void func_021AA7AC(u32 *p, u32 q);
extern void *func_02030734(u32 a, u32 b, u32 c, void *d, u32 e);

u32 *func_021A9ED8(u32 a)
{
    u32 heap = func_02188C84(a);
    u32 *p = (u32 *)func_02030734(heap, 0x14, 1, &d_021DDFA4, 0x62);
    u32 x;
    u32 t;
    u32 q;

    p[0] = a;
    x = func_02188C80(a);
    p[1] = x;
    t = func_020120F4(x);
    p[2] = t;
    p[3] = func_0216255C(func_02012844(t));
    q = func_021AA77C(heap);
    p[4] = q;
    func_021AA7AC(p, q);
    return p;
}
