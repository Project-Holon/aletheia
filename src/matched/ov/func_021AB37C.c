/*
 * function: MAP_ATTR_IsSandVariant
 * address:  0x021AB37C
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xc, 0xb, 0x23.
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

BOOL MAP_ATTR_IsSandVariant(u32 id)
{
    if (id == 0xc || id == 0xb || id == 0x23) {
        return 1;
    }

    return 0;
}
