/*
 * function: func_0202F630
 * address:  0x0202F630
 * packet:   pkt_0202F498
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   func_020185F0  0x020185F0  thumb
 *   func_0202F640  0x0202F640  thumb
 */

typedef unsigned int u32;

extern u32  func_020185F0(u32 a);
extern void func_0202F640(u32 a, u32 b);

void func_0202F630(u32 a, u32 b)
{
    func_0202F640(func_020185F0(a), b);
}
