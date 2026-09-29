/*
 * function: func_0219C8D4
 * address:  0x0219C8D4
 * packet:   pkt_ov021_0219C8D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219D184  0x0219D184  thumb  ov021
 *   func_0219D3B4  0x0219D3B4  thumb  ov021
 *   func_0219C880  0x0219C880  thumb  ov021
 *   func_02050468  0x02050468  arm

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0216D598(u32);
extern u32 func_0216D67C(u32);
extern u8 *func_0216D520(u32);
extern void func_0219D184(u8 *, u32);
extern int func_0219D3B4(u8 *, u32, u16);
extern void func_0219C880(u8 *, u32, u16, u32);
extern void func_02050468(u32, u16, u32);

void func_0219C8D4(u32 o, u32 a)
{
    u32 t = func_0216D598(o);
    u8 *c = func_0216D520(func_0216D67C(o));
    if (a == 0xFFFF) {
        func_0219D184(c, o);
        return;
    }
    if (func_0219D3B4(c, o, a) != 1) {
        func_0219C880(c, o, a, t);
        func_02050468(*(u32 *)(c + 4), a, 1);
    }
}
