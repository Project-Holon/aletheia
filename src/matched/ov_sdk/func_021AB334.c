/*
 * function: MAP_ATTR_IsSnowTile
 * address:  0x021AB334
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Terrain-id predicate forwarding to MAP_ATTR_IsSnow (id 0x0e).
 *
 * symbols:
 *   MAP_ATTR_IsSnow  0x021AB31C  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern BOOL MAP_ATTR_IsSnow(u16 id);


BOOL MAP_ATTR_IsSnowTile(u16 id)
{
    if (MAP_ATTR_IsSnow(id)) {
        return 1;
    }

    return 0;
}
