/*
 * function: func_02028C30
 * address:  0x02028C30
 * packet:   pkt_02028C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: every concrete byte is identical; the ABS32 at +0x1C
 * naming the 0x26-entry u16 table at 0x0209FDD0 has no witness outside
 * 02028C30..02028C50.  The only pool word in the image that names that
 * address is 0x02028C4C, which is inside this function's own extent, and
 * the table fails `string` (no printable run) and `data_table` (not a run
 * of in-region pointers).  This is the wall already recorded in
 * docs/notes/lane2_band_0_64_pass3.c.txt; it cannot close from C.
 * Consequence: src/pending/func_02028CB0.c stays MATCH* on the 02028C30
 * blocker -- only func_02028C50 of its two sites is closable.
 *
 * symbols:
 *   sTable_0209FDD0  0x0209FDD0  data
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

typedef unsigned short u16;
typedef unsigned int   u32;

extern const u16 sTable_0209FDD0[];

int func_02028C30(u32 v)
{
    u32 i;

    for (i = 0; i < 0x26; i++) {
        if (v == sTable_0209FDD0[i]) {
            return 1;
        }
    }
    return 0;
}
