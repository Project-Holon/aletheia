/*
 * file:     field_effect_p30.c
 * unit:     yes
 * function: func_021AB390, func_021AB3B0, func_021AB3D4, func_021AB3E0
 * address:  0x021AB390
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
 *   func_021AB370  0x021AB370  thumb
 *   func_021AB37C  0x021AB37C  thumb
 */
typedef unsigned short u16;

typedef unsigned long u32;

typedef int BOOL;

extern BOOL func_021AB370(u16 id);
extern int func_021AB37C(u32 id);
BOOL func_021AB390(u16 id);
BOOL func_021AB3B0(u16 id);
int func_021AB3D4(int x);
BOOL sub_021AB3E0(u16 id);



/*
 * Terrain-id predicate: func_021AB370 (0x19) or func_021AB37C (0x0b, 0x0c, 0x23).
 */
BOOL func_021AB390(u16 id)
{
    if (func_021AB370(id) || func_021AB37C(id)) {
        return 1;
    }

    return 0;
}




/*
 * Terrain-id predicate: true for id 0x3d, 0x3e, 0x3f, 0x42 and 0x43.  The
 * compiler folds the last two arms into one (u16)(id - 0x42) <= 1 range test.
 */
BOOL func_021AB3B0(u16 id)
{
    if (id == 0x3d || id == 0x3e || id == 0x3f || id == 0x42 || id == 0x43) {
        return 1;
    }

    return 0;
}

int func_021AB3D4(int x)
{
    return x == 0x2;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x1e.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB3E0(u16 id)
{
    if (id == 0x1e) {
        return 1;
    }

    return 0;
}
