/*
 * function: ZONEDATA_GetLightTableMember
 * address:  0x02014A10
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +000C ABS32 sub_0209E054_Map       : 0209E054 (data, from header) has no witness outside 02014A10..02014A20
 * symbols:
 *   sub_0209E054_Map  0x0209E054  data
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 sub_0209E054_Map[];

u16 ZONEDATA_GetLightTableMember(u32 i)
{
    return sub_0209E054_Map[i];
}
