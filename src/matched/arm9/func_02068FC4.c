/*
 * function: func_02068FC4
 * address:  0x02068FC4
 * packet:   pkt_02068808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02068FC4.c \
 *       --func func_02068FC4 --addr 0x02068FC4 --cc 1.1p1 --arm
 */

struct Pen;
extern void func_02068E78(struct Pen *p, int a1, int a2, int a3, int a5, int a6, int a7);

void func_02068FC4(int a, int b, int c, int d, int e)
{
    func_02068E78((struct Pen *)a, b, c, d, e, 0x020A18DC, c);
}
