/*
 * function: func_0219D6CC
 * address:  0x0219D6CC
 * packet:   pkt_ov021_0219D6CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DA20  0x0216DA20  thumb  ov010
 *   func_0219D7AC  0x0219D7AC  thumb  ov021
 *   func_0219D7D0  0x0219D7D0  thumb  ov021
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02197EB4  0x02197EB4  thumb  ov021
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0219D780  0x0219D780  thumb  ov021
 *   func_0216D708  0x0216D708  thumb  ov010
 *   func_0219D7F0  0x0219D7F0  thumb  ov021
 *   func_0219D824  0x0219D824  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_0216DA20(u32, u32);
extern void func_0219D7AC(u32);
extern void func_0219D7D0(u32);
extern u32 func_0216D57C(u32, u32);
extern void func_02197EB4(u32);
extern u32 func_0216DB10(u32);
extern u32 func_0219D780(u32);
extern void func_0216D708(u32);
extern void func_0219D7F0(u32);
extern void func_0219D824(u32);

void func_0219D6CC(u32 a)
{
    u32 k = 2;
    if (func_0216DA20(a, 2) == 0) {
        func_0219D7AC(a);
        func_0219D7D0(a);
        if (func_0216D57C(a, k << 8) != 0) {
            func_02197EB4(a);
        } else if (func_0216DB10(a) == 0 && func_0219D780(a) == 1) {
            func_0216D708(a);
        }
        func_0219D7F0(a);
        func_0219D824(a);
    }
}
