/*
 * function: func_021AB0F8
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
 * the flag half.  bit 0 is the passable flag (func_021AB11C), bit 1 selects
 * the alternate encounter-effect set (enceff.c at 0x021CF6CE), bit 2 gates
 * the terrain-class switch in func_021AB504.
 *
 * symbols:
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;



u16 func_021AB0F8(u32 attr)
{
    return (u16)(attr >> 16);
}
