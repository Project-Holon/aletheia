/*
 * function: func_02193060
 * address:  0x02193060
 * packet:   pkt_02193060
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_02193044 with no argument change.
 *
 * symbols:
 *   func_02193044  0x02193044  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02193044(u32 v);

void func_02193060(u32 a)
{
    func_02193044(a);
}
