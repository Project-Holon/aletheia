/*
 * function: func_0219049C
 * address:  0x0219049C
 * packet:   pkt_02190490
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0xc.
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0201C6B4();

void func_0219049C(u8 *p)
{
    func_0201C6B4(*(u32 *)(p + 0xc));
}
