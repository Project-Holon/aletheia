/*
 * function: func_021AB100
 * address:  0x021AB100
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The tile attribute word is present at all: neither the all-ones no-tile
 * sentinel nor the 0xFF no-terrain id in its low half.
 *
 * symbols:
 *   func_021AB0F0  0x021AB0F0  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern u16 func_021AB0F0(u32 attr);


BOOL func_021AB100(u32 attr)
{
    u16 id;

    id = func_021AB0F0(attr);

    if (attr == 0xFFFFFFFF || id == 0xFF) {
        return 0;
    }

    return 1;
}
