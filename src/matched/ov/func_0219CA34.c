/*
 * function: func_0219CA34
 * address:  0x0219CA34
 * packet:   pkt_0219CA34
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
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020307B0();

void func_0219CA34(u8 *p)
{
    func_020307B0(*(u32 *)(p + 0x4));
}
