/*
 * function: func_021A5A18
 * address:  0x021A5A18
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E664.
 *
 * symbols:
 *   func_0219E664  0x0219E664  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0219E664(void *o, u32 k, void *buf);

int func_021A5A18(u8 *p, u32 k, void *buf)
{
    return func_0219E664(*(void **)(p + 0x1c), k, buf);
}
