/*
 * function: MAP_ATTR_IsGimmickD7
 * address:  0x021AB1AC
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xd7.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */

typedef unsigned short u16;
typedef int BOOL;

BOOL MAP_ATTR_IsGimmickD7(u16 id)
{
    if (id == 0xd7) {
        return 1;
    }

    return 0;
}
