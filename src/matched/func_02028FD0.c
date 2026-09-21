/*
 * function: func_02028FD0
 * address:  0x02028FD0
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Blocked: g_flagTable_0209FE1C is named by this function's one pool word
 * (0x02028FDC), which lies inside the compared range, so the `literal`
 * class discards it; the object is not a string and not a pointer table
 * (no outside witness for the `string` or `data_table` class either).
 * Every concrete byte reproduces.
 * symbols:
 *   g_flagTable_0209FE1C  0x0209FE1C  data
 *
 * 2026-09-21, FAMILY wave.  Re-verified in a fresh process: still MATCH,
 * every concrete byte identical.  Evidence worked to exhaustion:
 *   - `--suggest-split` reports "witnesses image wide: 1, of them inside
 *     this range: 1"; a single-function file has nothing to cut against.
 *   - No sibling in field_sound_system.c (0x02028844..0x02029EB4) references
 *     the object: the only other listing hits are the rodata DEFINITION in
 *     asm/arm9/src/030_*.s, which is a referent, not a referrer.
 *   - sole-ref/data was probed directly.  in_data_section = True and the
 *     layout/data_objects.txt row IS an object start when the range is
 *     ignored, but `_map_attests(addr, lo, hi)` = False once the range is
 *     applied, because that row's sole referrer is this function's own pool
 *     word.  This is the documented "a lone reference never contributes its
 *     own start" rule firing correctly, not a tooling gap.
 * Declarations cross-checked against docs/families/field_sound_system.h.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct SoundParam {
    u8 pad00[4];
    u32 group;    /* +0x04 */
};

extern const u8 g_flagTable_0209FE1C[];

u32 func_02028FD0(struct SoundParam *obj, u32 kind)
{
    const u8 *p = g_flagTable_0209FE1C + obj->group * 8;
    return p[kind];
}
