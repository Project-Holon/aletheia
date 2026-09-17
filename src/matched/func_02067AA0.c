/*
 * function: func_02067AA0
 * address:  0x02067AA0
 * packet:   pkt_02067AA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067AA0.c \
 *       --func func_02067AA0 --addr 0x02067AA0 --arm --cc 1.1p1
 */

void func_02067AA0(int *p, int a, int b)
{
    p[2] = a;
    p[3] = b;
}
