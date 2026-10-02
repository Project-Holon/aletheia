/*
 * function: func_021A5A00
 * address:  0x021A5A00
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E2C0.
 *
 * symbols:
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0219E2C0(void *a, void *r);

void func_021A5A00(u8 *p, void *r)
{
    func_0219E2C0(*(void **)(p + 0x1c), r);
}
