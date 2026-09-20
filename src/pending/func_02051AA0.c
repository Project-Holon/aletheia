/*
 * function: func_02051AA0
 * address:  0x02051AA0
 * packet:   pkt_02051A54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  PC24 func_020616CC at +0x08: 0x020616CC lies outside both claimed windows and is branched to only from here
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051AA0.c \
 *       --func func_02051AA0 --addr 0x02051AA0 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

extern int func_020616CC(int a, int b, int c);

int func_02051AA0(int a, int b)
{
    return (u16)func_020616CC(a, b, 1) << 3;
}
