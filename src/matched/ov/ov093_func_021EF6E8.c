/*
 * function: func_021EF6E8
 * address:  0x021EF6E8
 * packet:   pkt_ov093_021EF6E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF6F0  0x021EF6F0  thumb  ov093
 *
 * Tail-call stub (ldr r3,[pc]; bx r3) to func_021EF6F0; callee of func_021EA55C case 6.
 */

typedef unsigned int u32;

extern void func_021EF6F0(u32 a, u32 b, u32 c);

void func_021EF6E8(u32 a, u32 b, u32 c)
{
    func_021EF6F0(a, b, c);
}
