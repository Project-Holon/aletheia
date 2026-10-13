/*
 * function: PLACE_NAME_LETTER_GetBmp
 * address:  0x021BD1DC
 * packet:   pkt_021BD1CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to PLACE_NAME_LETTER_GetBmpRaw with no argument change.
 *
 * symbols:
 *   PLACE_NAME_LETTER_GetBmpRaw  0x021BD308  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int PLACE_NAME_LETTER_GetBmpRaw(u8 *p);

int PLACE_NAME_LETTER_GetBmp(u8 *a0)
{
    return PLACE_NAME_LETTER_GetBmpRaw(a0);
}
