/*
 * function: PLACE_NAME_LETTER_Update
 * address:  0x021BD1CC
 * packet:   pkt_021BD1CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to PLACE_NAME_LETTER_UpdateActive with no argument change.
 *
 * symbols:
 *   PLACE_NAME_LETTER_UpdateActive  0x021BD3BC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void PLACE_NAME_LETTER_UpdateActive(void *p);

void PLACE_NAME_LETTER_Update(void *a)
{
    PLACE_NAME_LETTER_UpdateActive(a);
}
