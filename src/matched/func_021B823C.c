/*
 * function: func_021B823C
 * address:  0x021B823C
 * packet:   pkt_021B8224
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk on the object 0x20 bytes in.
 *
 * symbols:
 *   func_021B8848  0x021B8848  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021B8848();

void func_021B823C(u8 *p)
{
    func_021B8848(p + 0x20);
}
