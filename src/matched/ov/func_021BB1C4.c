/*
 * function: RAIL_ATTR_IsForceMoveLeft
 * address:  0x021BB1C4
 * packet:   pkt_021BB1C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int RAIL_ATTR_IsForceMoveLeft(int x)
{
    if (x == 167)
        return 1;
    return 0;
}
