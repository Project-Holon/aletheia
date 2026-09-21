/*
 * function: func_02028C30
 * address:  0x02028C30
 * packet:   pkt_02028C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
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
