/*
 * function: func_021A2F8C
 * address:  0x021A2F8C
 * packet:   pkt_ov021_021A2F8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x4, second argument forwarded.
 * Unlabelled leaf; its only blocker-caller is func_021C10B4.
 *
 * symbols:
 *   func_021A3AD0  0x021A3AD0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A3AD0(u8 *p, u32 v);

void func_021A2F8C(u8 *p, u32 b)
{
    func_021A3AD0((u8 *)(*(u32 *)(p + 0x4)), b);
}
