/*
 * function: func_020275E8
 * address:  0x020275E8
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020275E8.c \\
 *       --func func_020275E8 --addr 0x020275E8 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

u32 func_020275E8(void)
{
    return 0x21;
}
