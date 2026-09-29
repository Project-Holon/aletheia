/*
 * function: func_0219D634
 * address:  0x0219D634
 * packet:   pkt_ov021_0219D634
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D528  0x0216D528  thumb  ov010
 *   func_0219D558  0x0219D558  thumb  ov021
 *   func_0216E3CC  0x0216E3CC  thumb  ov010
 *   func_0219D584  0x0219D584  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;
extern u16 *func_0216E3C4(u32);
extern u32 func_0216D67C(u32);
extern u32 *func_0216D528(u32);
extern u32 func_0219D558(u32 *, u32);
extern u16 *func_0216E3CC(u16 *);
extern u32 func_0219D584(u32, u32 *, u32, u16 *);
extern u32 func_021C6590(u32, u32, u32, u32);

u32 func_0219D634(u32 a)
{
    u16 *p;
    u32 b;
    u32 *s;
    u32 r;
    p = func_0216E3C4(a);
    b = func_0216D67C(a);
    s = func_0216D528(b);
    r = func_0219D558(s, *p);
    if (r == 0xFFFF) {
        r = func_0219D584(b, s, *p, func_0216E3CC(p));
    }
    return func_021C6590(s[1], r, 0, 0);
}
