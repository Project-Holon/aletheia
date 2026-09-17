/*
 * function: func_020275E4
 * address:  0x020275E4
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the constant 0x53.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020275E4.c \
 *       --func func_020275E4 --addr 0x020275E4 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

u32 func_020275E4(void)
{
    return 0x53;
}