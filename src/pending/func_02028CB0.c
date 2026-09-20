/*
 * function: func_02028CB0
 * address:  0x02028CB0
 * packet:   pkt_02028BDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * blocker:  02028C30 label
 * blocker:  02028C50 label
 */

typedef unsigned int u32;

extern int func_02028C30(u32 v);
extern int func_02028C50(u32 v);

int func_02028CB0(u32 v)
{
    if (func_02028C30(v) == 0) {
        return 0;
    }
    if (func_02028C50(v) != 0) {
        return 1;
    }
    return 0;
}
