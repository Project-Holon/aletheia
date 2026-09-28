/*
 * function: func_021AB23C
 * address:  0x021AB23C
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x4, 0x21, 0x5.
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

BOOL func_021AB23C(u16 id)
{
    if (id == 0x4 || id == 0x21 || id == 0x5) {
        return 1;
    }

    return 0;
}
