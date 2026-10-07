/*
 * file:     field_effect_p26.c
 * unit:     yes
 * function: func_021AB29C, func_021AB2BC, func_021AB2DC
 * address:  0x021AB29C
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
 *   func_021AB250  0x021AB250  thumb
 *   func_021AB270  0x021AB270  thumb
 *   func_021AB27C  0x021AB27C  thumb
 */
typedef unsigned short u16;

typedef unsigned long u32;

typedef int BOOL;

extern BOOL func_021AB250(u16 id);
extern BOOL func_021AB270(u16 id);
extern BOOL func_021AB27C(u16 id);
BOOL func_021AB29C(u16 id);
BOOL func_021AB2BC(u16 id);
BOOL func_021AB2DC(u16 id);



/*
 * Terrain-id predicate: the union of the two families below.
 */
BOOL func_021AB29C(u16 id)
{
    if (func_021AB250(id) == 1 || func_021AB270(id) == 1) {
        return 1;
    }

    return 0;
}



BOOL func_021AB2BC(u16 id)
{
    if (func_021AB27C(id) == 1 || func_021AB29C(id) == 1) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x1d.
 */
BOOL func_021AB2DC(u16 id)
{
    if (id == 0x1d) {
        return 1;
    }

    return 0;
}
