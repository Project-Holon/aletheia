/*
 * function: func_021C20B4
 * address:  0x021C20B4
 * packet:   pkt_021C20B4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forwarding wrapper: passes a fifth (stack) argument through.
 *
 * symbols:
 *   func_021C2288  0x021C2288  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void func_021C2288(u8 *p, int a, int b, int c, int d);

void func_021C20B4(int a0, int a1, int a2, int a3, int a4)
{
    func_021C2288((u8 *)a0, a1, a2, a3, a4);
}
