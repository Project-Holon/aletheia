/*
 * function: func_021A572C
 * address:  0x021A572C
 * packet:   pkt_021A572C
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
 *   func_021A3960  0x021A3960  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(unsigned char *p);

void func_021A572C(u8 *p)
{
    func_021A3960(*(void **)(p + 0xc));
}
