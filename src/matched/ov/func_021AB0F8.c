/*
 * function: MAP_ATTR_GetFlags
 * address:  0x021AB0F8
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-attribute accessor: the high half of the tile attribute word,
 * the flag half.  bit 0 is the passable flag (MAP_ATTR_IsBlocked), bit 1 selects
 * the alternate encounter-effect set (enceff.c at 0x021CF6CE), bit 2 gates
 * the terrain-class switch in MAP_ATTR_GetEncounterEffectKind.
 *
 * symbols:
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;



u16 MAP_ATTR_GetFlags(u32 attr)
{
    return (u16)(attr >> 16);
}
