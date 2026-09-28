/*
 * function: func_0202DC48
 * address:  0x0202DC48
 * packet:   pkt_0202DC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0202DC60  0x0202DC60  thumb
 */

typedef unsigned int u32;

extern void func_0202DC60(u32 a, u32 b, u32 c, u32 d, u32 *e);

void func_0202DC48(u32 a, u32 b, u32 c, u32 d)
{
    u32 buf[2] = { 0, 0 };

    func_0202DC60(a, b, c, d, buf);
}
