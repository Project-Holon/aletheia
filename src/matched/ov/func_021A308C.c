/*
 * function: func_021A308C
 * address:  0x021A308C
 * packet:   pkt_021A3080
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x4.
 *
 * symbols:
 *   func_021A3970  0x021A3970  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A3970(u32 *p);

void func_021A308C(u8 *p)
{
    func_021A3970((u32 *)(*(u32 *)(p + 0x4)));
}
