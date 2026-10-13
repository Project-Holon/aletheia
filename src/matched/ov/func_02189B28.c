/*
 * function: FIELDMAP_GetMapType
 * address:  0x02189B28
 * packet:   pkt_02189B28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to ZONEDATA_GetMapType with no argument change.
 *
 * symbols:
 *   ZONEDATA_GetMapType  0x02013B50  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 ZONEDATA_GetMapType(u32 id);

u32 FIELDMAP_GetMapType(u32 id)
{
    return ZONEDATA_GetMapType(id);
}
