/*
 * function: func_02050C04
 * address:  0x02050C04
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050C04.c \
 *       --func func_02050C04 --addr 0x02050C04 --cc 1.1p1 --arm
 */

extern int func_02050C30(int a, int b, int c, int d, int e, int f, int g);

int func_02050C04(int a, int b, int c, int d)
{
    return func_02050C30(a, b, c, 5, 6, 63, d);
}
