/*
 * function: PLACE_NAME_LETTER_GetIntY
 * address:  0x021BD2E8
 * packet:   pkt_021BD2E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call thunk on the word at +0x14; callee of PLACE_NAME_LETTER_GetY.
 *
 * symbols:
 *   func_0209C494  0x0209C494  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_0209C494(u32 v);

void PLACE_NAME_LETTER_GetIntY(u32 *p)
{
    func_0209C494(p[5]);
}
