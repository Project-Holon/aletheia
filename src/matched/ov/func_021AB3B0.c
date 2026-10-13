/*
 * function: MAP_ATTR_IsFishableWater
 * address:  0x021AB3B0
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-id predicate: true for id 0x3d, 0x3e, 0x3f, 0x42 and 0x43.  The
 * compiler folds the last two arms into one (u16)(id - 0x42) <= 1 range test.
 *
 * symbols:
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;



BOOL MAP_ATTR_IsFishableWater(u16 id)
{
    if (id == 0x3d || id == 0x3e || id == 0x3f || id == 0x42 || id == 0x43) {
        return 1;
    }

    return 0;
}
