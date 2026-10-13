/*
 * function: PLACE_NAME_LETTER_SetVisible
 * address:  0x021BD1E4
 * packet:   pkt_021BD1CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to PLACE_NAME_LETTER_SetVisibleRaw with no argument change.
 *
 * symbols:
 *   PLACE_NAME_LETTER_SetVisibleRaw  0x021BD5F8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void PLACE_NAME_LETTER_SetVisibleRaw(void *p, unsigned int a);

void PLACE_NAME_LETTER_SetVisible(void *p, unsigned int a)
{
PLACE_NAME_LETTER_SetVisibleRaw(p, a);
}
