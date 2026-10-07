/*
 * function: func_02156E24
 * address:  0x02156E24
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_02156E30 with a zero third argument.
 *
 * symbols:
 *   func_02156E30  0x02156E30  thumb  ov009
 */

typedef unsigned int   u32;
extern void func_02156E30(u32 a, u32 b, u32 c, u32 d);

void func_02156E24(int a, int b, int c)
{
    func_02156E30(a, b, 0, c);
}

