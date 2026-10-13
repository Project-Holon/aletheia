/*
 * function: FLDMMDL_RAIL_DirToRailKey
 * address:  0x0219E938
 * packet:   pkt_0219E938
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to ZONEDATA_DirToRailKey with no argument change.
 *
 * symbols:
 *   ZONEDATA_DirToRailKey  0x0201441C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 ZONEDATA_DirToRailKey(int i);

u32 FLDMMDL_RAIL_DirToRailKey(int a0)
{
    return ZONEDATA_DirToRailKey(a0);
}
