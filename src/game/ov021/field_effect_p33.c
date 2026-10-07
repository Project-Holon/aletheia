/*
 * file:     field_effect_p33.c
 * unit:     yes
 * function: func_021AB44C, func_021AB458
 * address:  0x021AB44C
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

BOOL sub_021AB44C(u16 id);
int func_021AB458(int id);


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x33.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB44C(u16 id)
{
    if (id == 0x33) {
        return 1;
    }

    return 0;
}

int func_021AB458(int id)
{
    if (id == 0x53 || (unsigned short)(id + 0xFFAB) <= 1)
        return 1;
    return 0;
}
