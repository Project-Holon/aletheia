/*
 * function: MAP_ATTR_IsBlocked
 * address:  0x021AB11C
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The walk/collision test: a tile blocks movement when its attribute word
 * is absent (MAP_ATTR_IsPresent) or when bit 0 of the flag half is set.
 *
 * symbols:
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb
 *   MAP_ATTR_IsPresent  0x021AB100  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern u16 MAP_ATTR_GetFlags(u32 attr);
extern BOOL MAP_ATTR_IsPresent(u32 attr);


BOOL MAP_ATTR_IsBlocked(u32 attr)
{
    u16 flags;

    flags = MAP_ATTR_GetFlags(attr);

    if (!MAP_ATTR_IsPresent(attr) || (flags & 1)) {
        return 1;
    }

    return 0;
}
