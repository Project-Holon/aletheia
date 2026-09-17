/*
 * function: func_02067AAC
 * address:  0x02067AAC
 * packet:   pkt_02067AAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067AAC.c \
 *       --func func_02067AAC --addr 0x02067AAC --arm --cc 1.1p1
 */

void func_02067AAC(int *p, int a, int b)
{
    p[7] = a;
    p[8] = b;
}
