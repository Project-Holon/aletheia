/*
 * function: func_021A575C
 * address:  0x021A575C
 * packet:   pkt_021A572C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021A550C with no argument change.
 *
 * symbols:
 *   func_021A550C  0x021A550C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A550C(u32 *p);

void func_021A575C(u32 *p)
{
    func_021A550C(p);
}
