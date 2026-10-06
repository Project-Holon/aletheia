/*
 * function: func_021AB328
 * address:  0x021AB328
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xf.
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

BOOL func_021AB328(int id)
{
    if (id == 0xf) {
        return 1;
    }

    return 0;
}
