/*
 * function: func_021A5B6C
 * address:  0x021A5B6C
 * packet:   pkt_021A5B6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the last three arguments.
 *
 * symbols:
 *   func_0219E424  0x0219E424  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0219E424(u32 o, u32 k, u32 x);

void func_021A5B6C(u32 a, u32 b, u32 c, u32 d)
{
    func_0219E424(b, c, d);
}
