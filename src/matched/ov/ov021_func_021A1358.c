/*
 * function: FIELD_SUBSCREEN_GetCGear
 * address:  0x021A1358
 * packet:   pkt_ov021_021A1358
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

u32 FIELD_SUBSCREEN_GetCGear(u32 *p)
{
    if (p[0] == 0 || p[0] == 8)
        return p[8];
    return 0;
}
