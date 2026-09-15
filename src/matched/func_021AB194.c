/*
 * function: func_021AB194
 * address:  0x021AB194
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xd4.
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

BOOL func_021AB194(u16 id)
{
    if (id == 0xd4) {
        return 1;
    }

    return 0;
}
