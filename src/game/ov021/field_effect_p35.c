/*
 * file:     field_effect_p35.c
 * unit:     yes
 * function: func_021AB4F8, func_021AB504, func_021AB580, func_021AB5AC
 * address:  0x021AB4F8
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
 *   data_021D8EA0  0x021D8EA0  data
 *   data_021D8EA1  0x021D8EA1  data
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB0F8  0x021AB0F8  thumb
 *   func_021AB11C  0x021AB11C  thumb
 *   func_021AB2E8  0x021AB2E8  thumb
 */
typedef unsigned short u16;

typedef int BOOL;

typedef unsigned long u32_021AB504;

typedef unsigned char  u8;

typedef unsigned int   u32_021AB580;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern unsigned short func_021AB0F0(unsigned long attr);
extern unsigned short func_021AB0F8(unsigned long attr);
extern int func_021AB11C(unsigned long attr);
extern int func_021AB2E8(int id);
BOOL sub_021AB4F8(u16 id);
int func_021AB504(u32_021AB504 attr);
u8 func_021AB580(u16 x);
int func_021AB5AC(unsigned long a, unsigned long b);
extern const u8 data_021D8EA0[];
extern const u8 data_021D8EA1[];


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x22.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB4F8(u16 id)
{
    if (id == 0x22) {
        return 1;
    }

    return 0;
}


/*
 * Terrain class of a tile attribute word, for the encounter-effect lane.
 * Its one caller, func_021AACD4 in effect_encount.c, drops the tile when
 * the answer is 8 and otherwise stores the class byte in its per-tile
 * candidate list, so 8 is "no effect".  Note the flag-half gate: unless
 * bit 2 of the high half is set, every id falls through to 8, which is why
 * the overwhelmingly common 0x0081 flag half never produces a class.
 *
 * The two half accessors are func_021AB0F0/func_021AB0F8 inlined.
 */
int func_021AB504(u32_021AB504 attr)
{
    u16 id = (u16)attr;
    u16 flags = (u16)(attr >> 16);

    if (id == 0x20) {
        return 7;
    }

    if (!(flags & 4)) {
        return 8;
    }

    switch (id) {
    case 4:
        return 0;
    case 5:
        return 1;
    case 0x21:
        return 2;
    case 8:
        return 3;
    case 10:
        return 4;
    case 0x3d:
        return 5;
    case 0x3f:
    case 0x43:
        return 6;
    }

    return 8;
}


/*
 * Addresses are Black-image addresses.
 */
u8 func_021AB580(u16 x)
{
    u32_021AB580 i;

    for (i = 0; i < 0x25; i++) {
        if (x == data_021D8EA0[i * 2])
            return data_021D8EA1[i * 2];
    }
    return 0;
}


int func_021AB5AC(unsigned long a, unsigned long b)
{
    unsigned short lo = func_021AB0F8(b);
    unsigned short hi = func_021AB0F0(b);

    if (func_021AB11C(a))
        return 0;
    if (((lo & 2) && !func_021AB11C(b)) || func_021AB2E8(hi))
        return 1;
    return 0;
}
