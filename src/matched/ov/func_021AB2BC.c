/*
 * function: MAP_ATTR_IsAnyGrass
 * address:  0x021AB2BC
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
 *   MAP_ATTR_IsAnySingleGrass  0x021AB27C  thumb
 *   MAP_ATTR_IsAnyDoubleGrass  0x021AB29C  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern BOOL MAP_ATTR_IsAnySingleGrass(u16 id);
extern BOOL MAP_ATTR_IsAnyDoubleGrass(u16 id);


BOOL MAP_ATTR_IsAnyGrass(u16 id)
{
    if (MAP_ATTR_IsAnySingleGrass(id) == 1 || MAP_ATTR_IsAnyDoubleGrass(id) == 1) {
        return 1;
    }

    return 0;
}
