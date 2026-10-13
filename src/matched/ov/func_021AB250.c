/*
 * function: MAP_ATTR_IsGrassDouble
 * address:  0x021AB250
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x6, 0x22, 0x7.
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

BOOL MAP_ATTR_IsGrassDouble(u16 id)
{
    if (id == 0x6 || id == 0x22 || id == 0x7) {
        return 1;
    }

    return 0;
}
