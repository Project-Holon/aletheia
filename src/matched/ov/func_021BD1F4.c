/*
 * function: PLACE_NAME_LETTER_GetHeight
 * address:  0x021BD1F4
 * packet:   pkt_021BD1EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to PLACE_NAME_LETTER_GetHeightRaw with no argument change.
 *
 * symbols:
 *   PLACE_NAME_LETTER_GetHeightRaw  0x021BD2FC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 PLACE_NAME_LETTER_GetHeightRaw(u8 *p);

int PLACE_NAME_LETTER_GetHeight(u8 *a0)
{
    return PLACE_NAME_LETTER_GetHeightRaw(a0);
}
