/*
 * function: func_021BD1E4
 * address:  0x021BD1E4
 * packet:   pkt_021BD1CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021BD5F8 with no argument change.
 *
 * symbols:
 *   func_021BD5F8  0x021BD5F8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BD5F8(void *p, unsigned int a);

void func_021BD1E4(void *p, unsigned int a)
{
func_021BD5F8(p, a);
}
