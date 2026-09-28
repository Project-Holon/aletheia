/*
 * function: func_0202D4A8
 * address:  0x0202D4A8
 * packet:   pkt_0202D4A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02019C90  0x02019C90  thumb
 *   func_020490A8  0x020490A8  arm
 *
 * pokegra.c: resolve a species/form/egg to its graphics archive index, the
 * shiny palette flag (0 or 9), the draw mode and base, checking the
 * narc for the gendered palette variant when mode 1 asks.
 *
 * The 4-byte residue that held through five lanes and 2320 permuter
 * compiles (docs/notes/func_0202D4A8.c.txt: the two spilled values got
 * sp+4/sp+8 the wrong way round) is a declaration: the 2-way shiny value
 * written to *out_pal is an enum, which changes where the frame allocator
 * puts its spill slot (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md;
 * the permuter's `type` mutation only cycles integer types).  `case 1`
 * is written before `case 2`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202D4A8.c  *       --func func_0202D4A8 --addr 0x0202D4A8 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_02019C90(u16 species, u32 form, u32 attr);
extern int func_020490A8(void *narc, u32 index);

typedef enum { PAL_0 } Pal;

void func_0202D4A8(void *narc, u32 species, s32 form, s32 mode,
                   u32 base, u32 shiny, u32 egg,
                   u32 *out_index, u32 *out_pal, u32 *out_mode, u32 *out_base,
                   u32 **out_ptr, u32 female)
{
    s32 idx;
    s32 count;
    s32 first;
    s32 hidden;
    Pal mode2;
    s32 pal;

    idx = species * 0x14;

    if (shiny == 0) {
        mode2 = 0;
    } else {
        mode2 = 9;
    }

    if (female != 0) {
        if (shiny == 0) {
            pal = 0;
        } else {
            pal = 9;
        }
    } else {
        if (shiny == 0) {
            pal = 2;
        } else {
            pal = 0xb;
        }
    }

    if (egg != 0) {
        s32 t;

        if (species == 0x1ea) {
            t = 1;
        } else {
            t = 0;
        }
        idx = (t + 0x28a) * 0x14;
    } else if (form != 0) {
        first = (s32)func_02019C90((u16)species, 0, 0x1f);
        hidden = (s32)func_02019C90((u16)species, 0, 0x23);
        count = (s32)func_02019C90((u16)species, 0, 0x20);
        if (form >= count) {
            form = 0;
        }
        if (hidden != 0) {
            if (out_ptr != 0 && form != 0) {
                *out_ptr = (u32 *)(base + (u32)((first + form - 1) * 2 + 0x37ad));
            }
        } else if (form != 0) {
            idx = (first + form - 1) * 0x14 + 0x32f0;
        }
    }

    switch (mode) {
    case 0:
        break;
    case 1:
        count = func_020490A8(narc, (u32)(idx + pal + 1));
        mode = 1;
        if (count == 0) {
            mode = 0;
        }
        break;
    case 2:
        mode = 0;
        break;
    default:
        break;
    }

    if (out_index != 0) {
        *out_index = (u32)idx;
    }
    if (out_pal != 0) {
        *out_pal = (u32)mode2;
    }
    if (out_mode != 0) {
        *out_mode = (u32)mode;
    }
    if (out_base != 0) {
        *out_base = base;
    }
}
