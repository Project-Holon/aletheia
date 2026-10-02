/*
 * function: func_021C097C
 * address:  0x021C097C
 * packet:   pkt_ov217_021C097C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C0A38  0x021C0A38  thumb  ov217
 *   func_021C0A04  0x021C0A04  thumb  ov217
 *   func_021C0A5C  0x021C0A5C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_021C0A38(u32 a0);
extern void func_021C0A04(int a);
extern void func_021C0A5C(int a, int b, int c);

int func_021C097C(int a0, int a1)
{
    int r;
    r = func_021C0A38(a0);
    func_021C0A04(r);
    func_021C0A5C(r, a1, a0);
    return r;
}
