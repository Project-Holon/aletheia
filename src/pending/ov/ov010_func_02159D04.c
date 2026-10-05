/*
 * function: func_02159D04
 * address:  0x02159D04
 * packet:   pkt_ov010_02159D04
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_02082A48  0x02082A48  arm
 *   func_02082A90  0x02082A90  arm
 *
 * The map-matrix decoder: unpack one a/0/0/9 sub-file into the runtime matrix
 * object. File = { u16 mode; u16 pad; u16 width; u16 height; u32 cells[] },
 * plus a second block of the same length when mode == 1. Block one is copied
 * into the u32 grid at +0x71C. Block two is narrowed into the u16 grid at
 * +0x14; without it the u16 grid is filled with the caller's zone id.
 *
 * recoup 2026-10-05 (lane P18L7, 21 compiles, no EXACT): DIFF 11/100 bytes,
 * only registers. Original: zone_id r7, src+8 r6, pooled 0x71C r4. Compiled:
 * zone_id r4, src+8 r7, pool r6. Twin search: grep of func_02082A90 and
 * func_02082A48 across src/matched/ov finds no function with both calls.
 * Callee types: both are void copy/fill helpers, no caller uses a result.
 * Tried, all 11 B unless noted: the six per-function pragmas (opt_propagation
 * 14 B, others 11); u32 and unsigned long zone_id; unsigned long n; matrix_id
 * as unsigned long; named per-element pointers in the loop; early map_grid
 * pointer local; (char *)dst + 0x71C in the call; i = 0 split from the for;
 * non-const src (96 B); zone_grid bound only in the loop arm (50 B); count
 * cached in a local (40 B); second = cells + n (88 B); cells[count + i] with
 * no second local (47 B). Idioms checked: a-colour-swap-no-source-form-fixes-
 * can-be-opt-lifetimes-off (11), a-long-index-colours-apart-from-an-int (11),
 * two-long-lived-values-in-each-others-registers (no missing arg, no join
 * local), a-named-per-element-pointer-settles-thumb-loop-register-colours
 * (11), a-global-base-pointer-colours-above-a-plain-loop-index (n/a). Older
 * note: docs/notes/pkt_ov010_02159D04.c.txt (120 declaration orders, permuter).
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct MatrixFile {
    u16 mode;
    u16 pad02;
    u16 width;
    u16 height;
    u32 cells[];
};

struct MapMatrix {
    u16 field00;
    u16 zone_id;
    u32 matrix_id;
    u16 width;
    u16 height;
    u16 mode;
    u16 pad0e;
    u32 count;
    u16 zone_grid[900];
    u32 map_grid[900];
};

extern void func_02082A48(u32 value, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);

void func_02159D04(struct MapMatrix *dst, const struct MatrixFile *src,
                   u32 matrix_id, u16 zone_id)
{
    u32 n;
    const u32 *cells;
    const u32 *second;
    u32 i;
    u16 *zone_grid;

    dst->matrix_id = matrix_id;
    n = src->width * src->height;
    dst->height = src->height;
    dst->count = n;
    dst->mode = src->mode;
    dst->zone_id = zone_id;
    dst->width = src->width;
    cells = src->cells;
    func_02082A90(cells, dst->map_grid, n * 4);

    zone_grid = dst->zone_grid;
    if (dst->mode == 1) {
        second = cells + dst->count;
        for (i = 0; i < dst->count; i++)
            zone_grid[i] = (u16)second[i];
    } else {
        func_02082A48(zone_id, zone_grid, 0x708);
    }
}
