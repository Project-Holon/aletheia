/*
 * function: MAP_ATTR_IsAnySand
 * address:  0x021AB390
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Terrain-id predicate: MAP_ATTR_IsSandD (0x19) or MAP_ATTR_IsSandVariant (0x0b, 0x0c, 0x23).
 *
 * symbols:
 *   MAP_ATTR_IsSandD  0x021AB370  thumb
 *   MAP_ATTR_IsSandVariant  0x021AB37C  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern BOOL MAP_ATTR_IsSandD(u16 id);
extern int MAP_ATTR_IsSandVariant(u32 id);


BOOL MAP_ATTR_IsAnySand(u16 id)
{
    if (MAP_ATTR_IsSandD(id) || MAP_ATTR_IsSandVariant(id)) {
        return 1;
    }

    return 0;
}
