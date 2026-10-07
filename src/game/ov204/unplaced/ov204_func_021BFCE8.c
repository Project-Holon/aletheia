/*
 * function: func_021BFCE8
 * address:  0x021BFCE8
 * packet:   pkt_021BFCE8
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020515B4  0x020515B4  arm
 *
 * True extent is 0x021BFCE8..0x021BFD20 (56 bytes of code).  The word run
 * beginning at 0x021BFD20 is the head of the overlay's particle parameter
 * table, not a literal pool of this function, and the next func_ label is
 * absent, so the band-lane enumeration measures this as a ~3704-byte
 * function running to the overlay's span end.  That figure is a labelling
 * artefact, not a function.
 *
 * The 0x021BFCE8 head of the tree is closed: the sole (non-SDK) callee
 * func_020515B4 is already EXACT in src/matched/func_020515B4.c, so the
 * call relocations resolve through the `matched` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BFCE8.c \
 *       --func func_021BFCE8 --addr 0x021BFCE8 --region ov204 \
 *       --cc 1.1p1 --thumb --flags=-O4,p
 */

typedef unsigned int u32;

extern int func_020515B4(void *p, int b, int c);

void func_021BFCE8(u32 *a0, u32 a1, u32 a2, u32 a3)
{
    u32 *p = a0;
    u32 buf[3] = { 0 };

    buf[0] = a1;
    buf[1] = a2;
    buf[2] = a3;
    func_020515B4((void *)p[2], 0, (int)buf);
    func_020515B4((void *)p[2], 1, (int)buf);
    func_020515B4((void *)p[2], 2, (int)buf);
}
