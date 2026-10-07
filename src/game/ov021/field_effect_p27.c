/*
 * file:     field_effect_p27.c
 * unit:     yes
 * function: func_021AB2E8, func_021AB2F8
 * address:  0x021AB2E8
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

typedef unsigned long u32;

typedef int BOOL;

BOOL func_021AB2E8(int id);
int func_021AB2F8(int x);
int func_021AB304(int x);


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x41, 0x44.
 */
BOOL func_021AB2E8(int id)
{
    if (id == 0x41 || id == 0x44) {
        return 1;
    }

    return 0;
}

/*
 * Two equality predicates.
 */
int func_021AB2F8(int x)
{
    return x == 0x14;
}


int func_021AB304(int x)
{
    return x == 0x17;
}
