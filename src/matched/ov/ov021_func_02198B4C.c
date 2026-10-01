/*
 * function: func_02198B4C
 * address:  0x02198B4C
 * packet:   pkt_ov021_02198B4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 *func_0216D6BC(u32, u32);
extern u32 func_0216D67C(u32);
extern u32 func_0216D534(u32);
extern u32 func_02188CD0(u32);
extern u32 func_021BB528(u32, u32, u32, u32);
extern void func_0216D7CC(u32);

void func_02198B4C(u32 a, u32 b)
{
    u32 *p;

    p = func_0216D6BC(a, 8);
    p[0] = b;
    p[1] = func_021BB528(func_02188CD0(func_0216D534(func_0216D67C(a))), a, b, 1);
    func_0216D7CC(a);
}
