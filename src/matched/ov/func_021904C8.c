/*
 * function: func_021904C8
 * address:  0x021904C8
 * packet:   pkt_02190490
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_02045C04 with no argument change.
 *
 * symbols:
 *   func_02045C04  0x02045C04  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec;
extern u32 func_02045C04(struct Rec *rec);

u32 func_021904C8(struct Rec *a0)
{
    return func_02045C04(a0);
}
