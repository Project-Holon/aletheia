/*
 * function: MAP_ATTR_IsSplashWaterB
 * address:  0x021AB364
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x1c.
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

BOOL MAP_ATTR_IsSplashWaterB(u16 id)
{
    if (id == 0x1c) {
        return 1;
    }

    return 0;
}
