/*
 * function: func_021BE89C
 * address:  0x021BE89C
 * packet:   pkt_ov021_021BE89C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02013FD8  0x02013FD8  thumb
 *   func_021BEA9C  0x021BEA9C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_02013FD8(u32 a);
extern void func_021BEA9C(u32 a, u32 b);
void func_021BE89C(u32 a, u32 b)
{
    func_021BEA9C(func_02013FD8(a), func_02013FD8(b));
}
