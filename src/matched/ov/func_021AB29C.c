/*
 * function: MAP_ATTR_IsAnyDoubleGrass
 * address:  0x021AB29C
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Terrain-id predicate: the union of the two families below.
 *
 * symbols:
 *   MAP_ATTR_IsGrassDouble  0x021AB250  thumb
 *   MAP_ATTR_IsTallGrassDouble  0x021AB270  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern BOOL MAP_ATTR_IsGrassDouble(u16 id);
extern BOOL MAP_ATTR_IsTallGrassDouble(u16 id);


BOOL MAP_ATTR_IsAnyDoubleGrass(u16 id)
{
    if (MAP_ATTR_IsGrassDouble(id) == 1 || MAP_ATTR_IsTallGrassDouble(id) == 1) {
        return 1;
    }

    return 0;
}
