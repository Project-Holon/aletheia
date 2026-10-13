/*
 * function: PLACE_NAME_LETTER_IsActive
 * address:  0x021BD20C
 * packet:   pkt_ov021_021BD20C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PLACE_NAME_LETTER_GetActive  0x021BD2D8  thumb  ov021
 *
 * Unlabelled leaf: tail call to PLACE_NAME_LETTER_GetActive (loads +0x44).
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 PLACE_NAME_LETTER_GetActive(u8 *p);

unsigned int PLACE_NAME_LETTER_IsActive(char *p)
{
    return PLACE_NAME_LETTER_GetActive((u8 *)p);
}
