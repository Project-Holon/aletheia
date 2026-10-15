/*
 * function: NNSi_G2dInitPenSimple
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
 *   python tools/match.py one --src src/matched/NNSi_G2dInitPenSimple.c \
 *       --func NNSi_G2dInitPenSimple --addr 0x02068FC4 --cc 1.1p1 --arm
 *
 * symbols:
 *   NNSi_G2dInitPen  0x02068E78  arm
 */

struct Pen;
extern void NNSi_G2dInitPen(struct Pen *p, int a1, int a2, int a3, int a5, int a6, int a7);

void NNSi_G2dInitPenSimple(int a, int b, int c, int d, int e)
{
    NNSi_G2dInitPen((struct Pen *)a, b, c, d, e, 0x020A18DC, c);
}
