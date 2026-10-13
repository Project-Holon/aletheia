/*
 * function: MAP_ATTR_IsAnySingleGrass
 * address:  0x021AB27C
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
 *   MAP_ATTR_IsGrassSingle  0x021AB23C  thumb
 *   MAP_ATTR_IsTallGrassSingle  0x021AB264  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern BOOL MAP_ATTR_IsGrassSingle(u16 id);
extern BOOL MAP_ATTR_IsTallGrassSingle(u16 id);


BOOL MAP_ATTR_IsAnySingleGrass(u16 id)
{
    if (MAP_ATTR_IsGrassSingle(id) == 1 || MAP_ATTR_IsTallGrassSingle(id) == 1) {
        return 1;
    }

    return 0;
}
