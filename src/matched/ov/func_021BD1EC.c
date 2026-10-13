/*
 * function: PLACE_NAME_LETTER_GetWidth
 * address:  0x021BD1EC
 * packet:   pkt_021BD1EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to PLACE_NAME_LETTER_GetWidthRaw with no argument change.
 *
 * symbols:
 *   PLACE_NAME_LETTER_GetWidthRaw  0x021BD2F4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 PLACE_NAME_LETTER_GetWidthRaw(u8 *p);

int PLACE_NAME_LETTER_GetWidth(u8 *a0)
{
    return PLACE_NAME_LETTER_GetWidthRaw(a0);
}
