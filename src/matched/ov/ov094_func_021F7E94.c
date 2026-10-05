/*
 * function: func_021F7E94
 * address:  0x021F7E94
 * packet:   pkt_ov094_021F7E94
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail call through r3 with a constant second argument. Labelled in wave D8.
 *
 * symbols:
 *   func_021F7A28  0x021F7A28  thumb ov094
 */

typedef unsigned int u32;
extern void func_021F7A28(int a, u32 b);

void func_021F7E94(int a)
{
    func_021F7A28(a, 0x26E);
}
