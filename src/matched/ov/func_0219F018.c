/*
 * function: FIELD_RAIL_LOADER_GetSetting
 * address:  0x0219F018
 * packet:   pkt_0219F018
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the object pointer advanced by 0x8 bytes.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *FIELD_RAIL_LOADER_GetSetting(u8 *p)
{
    return p + 0x8;
}

