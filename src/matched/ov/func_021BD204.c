/*
 * function: PLACE_NAME_LETTER_GetY
 * address:  0x021BD204
 * packet:   pkt_021BD204
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to PLACE_NAME_LETTER_GetIntY with no argument change.
 *
 * symbols:
 *   PLACE_NAME_LETTER_GetIntY  0x021BD2E8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void PLACE_NAME_LETTER_GetIntY(u32 *p);

void PLACE_NAME_LETTER_GetY(u32 *a0)
{
    PLACE_NAME_LETTER_GetIntY(a0);
}
