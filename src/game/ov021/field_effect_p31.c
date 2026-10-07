/*
 * file:     field_effect_p31.c
 * unit:     yes
 * function: func_021AB3EC, func_021AB3F8
 * address:  0x021AB3EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned short u16;

typedef int BOOL;

BOOL sub_021AB3EC(u16 id);
BOOL sub_021AB3F8(u16 id);


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x30.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB3EC(u16 id)
{
    if (id == 0x30) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x32.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB3F8(u16 id)
{
    if (id == 0x32) {
        return 1;
    }

    return 0;
}
