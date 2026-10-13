/*
 * function: PLACE_NAME_LETTER_GetMotion
 * address:  0x021BD304
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the object pointer advanced by 0x10 bytes.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *PLACE_NAME_LETTER_GetMotion(u8 *p)
{
    return p + 0x10;
}

