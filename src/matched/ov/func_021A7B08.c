/*
 * function: func_021A7B08
 * address:  0x021A7B08
 * packet:   pkt_021A7B08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021A811C with no argument change.
 *
 * symbols:
 *   func_021A811C  0x021A811C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A811C(u32 a, u32 b);

struct V3;

void func_021A7B08(int a, struct V3 *b)
{
    func_021A811C(a, (u32)b);
}
