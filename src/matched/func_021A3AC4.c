/*
 * function: func_021A3AC4
 * address:  0x021A3AC4
 * packet:   pkt_021A3AC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Widens the second argument to 16 bits before the tail call.
 *
 * symbols:
 *   func_021A3C24  0x021A3C24  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A3C24(u32 a, u32 b);

void func_021A3AC4(u32 a, u32 v)
{
    func_021A3C24(a, (u16)v);
}
