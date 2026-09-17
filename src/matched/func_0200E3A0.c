/*
 * function: func_0200E3A0
 * address:  0x0200E3A0
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the argument plus 0xd2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E3A0.c \
 *       --func func_0200E3A0 --addr 0x0200E3A0 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

u32 func_0200E3A0(u32 a)
{
    return a + 0xd2;
}
