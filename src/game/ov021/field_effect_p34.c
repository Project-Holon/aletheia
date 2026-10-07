/*
 * file:     field_effect_p34.c
 * unit:     yes
 * function: func_021AB4B8, func_021AB4EC
 * address:  0x021AB4B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021AB140  0x021AB140  thumb
 *   func_021AB404  0x021AB404  thumb
 *   func_021AB410  0x021AB410  thumb
 *   func_021AB328  0x021AB328  thumb
 */
typedef unsigned short u16;

typedef int BOOL;

extern int func_021AB140(int id);
extern int func_021AB404(int id);
extern int func_021AB410(int id);
extern int func_021AB328(int id);
int func_021AB4B8(int id);
BOOL sub_021AB4EC(u16 id);


int func_021AB4B8(int id)
{
    if (func_021AB140(id) || func_021AB404(id) || func_021AB410(id) || func_021AB328(id))
        return 1;
    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x21.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB4EC(u16 id)
{
    if (id == 0x21) {
        return 1;
    }

    return 0;
}
