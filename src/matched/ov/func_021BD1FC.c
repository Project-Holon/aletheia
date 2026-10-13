/*
 * function: PLACE_NAME_LETTER_GetX
 * address:  0x021BD1FC
 * packet:   pkt_021BD1FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to PLACE_NAME_LETTER_GetIntX with no argument change.
 *
 * symbols:
 *   PLACE_NAME_LETTER_GetIntX  0x021BD2DC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void PLACE_NAME_LETTER_GetIntX(u32 *p);

void PLACE_NAME_LETTER_GetX(u32 *a0)
{
    PLACE_NAME_LETTER_GetIntX(a0);
}
