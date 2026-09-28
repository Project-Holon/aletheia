/*
 * function: func_02027610
 * address:  0x02027610
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027610.c \\
 *       --func func_02027610 --addr 0x02027610 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

u32 func_02027610(u32 a)
{
    return a + 0x38;
}
