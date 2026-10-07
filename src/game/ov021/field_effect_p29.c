/*
 * file:     field_effect_p29.c
 * unit:     yes
 * function: func_021AB31C, func_021AB328, func_021AB334, func_021AB348, func_021AB358, func_021AB364, func_021AB370, func_021AB37C
 * address:  0x021AB31C
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

BOOL func_021AB31C(u16 id);
BOOL func_021AB328(int id);
BOOL func_021AB334(u16 id);
BOOL func_021AB348(u32 id);
int func_021AB358(int x);
BOOL func_021AB364(u16 id);
BOOL func_021AB370(u16 id);
BOOL func_021AB37C(u32 id);


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xe.
 */
BOOL func_021AB31C(u16 id)
{
    if (id == 0xe) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xf.
 */
BOOL func_021AB328(int id)
{
    if (id == 0xf) {
        return 1;
    }

    return 0;
}



/*
 * Terrain-id predicate forwarding to func_021AB31C (id 0x0e).
 */
BOOL func_021AB334(u16 id)
{
    if (func_021AB31C(id)) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x18, 0x10.
 */
BOOL func_021AB348(u32 id)
{
    if (id == 0x18 || id == 0x10) {
        return 1;
    }

    return 0;
}

int func_021AB358(int x)
{
    return x == 0x10;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x1c.
 */
BOOL func_021AB364(u16 id)
{
    if (id == 0x1c) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x19.
 */
BOOL func_021AB370(u16 id)
{
    if (id == 0x19) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xc, 0xb, 0x23.
 */
BOOL func_021AB37C(u32 id)
{
    if (id == 0xc || id == 0xb || id == 0x23) {
        return 1;
    }

    return 0;
}
