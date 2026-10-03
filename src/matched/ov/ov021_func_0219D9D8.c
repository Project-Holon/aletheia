/*
 * function: func_0219D9D8
 * address:  0x0219D9D8
 * packet:   pkt_ov021_0219D9D8
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
 *   func_0219DBC8  0x0219DBC8  thumb  ov021
 *   func_0219DB44  0x0219DB44  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_0219D85C(u32);
extern int func_0216DB24(int a0);
extern u32 func_0216D7DC(u32);
extern u32 func_0216D7E4(u32);
extern u32 func_0216E3C4(u32);
extern void func_0219DBC8(u32, u32, u32, u32);
extern void func_0219DB44(u32, u32, u32, u32);

void func_0219D9D8(u32 a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C(a) != 0 && func_0216DB24(a) == 1) {
        b = func_0216D7DC(a);
        c = func_0216D7E4(a);
        d = func_0216E3C4(a);
        func_0219DBC8(a, b, c, d);
        func_0219DB44(a, b, c, d);
    }
}
