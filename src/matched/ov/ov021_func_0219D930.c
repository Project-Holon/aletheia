/*
 * function: func_0219D930
 * address:  0x0219D930
 * packet:   pkt_ov021_0219D930
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219D85C  0x0219D85C  thumb  ov021
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_0216D7E4  0x0216D7E4  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0219DAA4  0x0219DAA4  thumb  ov021
 *   func_0219DAD0  0x0219DAD0  thumb  ov021
 *   func_0219DB0C  0x0219DB0C  thumb  ov021
 *   func_0219DB5C  0x0219DB5C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_0219D85C(u32);
extern u32 func_0216DB24(u32);
extern u32 func_0216D7DC(u32);
extern u32 func_0216D7E4(u32);
extern u32 func_0216E3C4(u32);
extern void func_0219DAA4(u32, u32, u32, u32);
extern void func_0219DAD0(u32, u32, u32, u32);
extern void func_0219DB0C(u32, u32, u32, u32);
extern void func_0219DB5C(u32, u32, u32, u32);

void func_0219D930(u32 a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C(a) != 0 && func_0216DB24(a) == 1) {
        b = func_0216D7DC(a);
        c = func_0216D7E4(a);
        d = func_0216E3C4(a);
        func_0219DAA4(a, b, c, d);
        func_0219DAD0(a, b, c, d);
        func_0219DB0C(a, b, c, d);
        func_0219DB5C(a, b, c, d);
    }
}
