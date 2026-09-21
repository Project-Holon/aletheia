/*
 * function: func_02022E20
 * address:  0x02022E20
 * packet:   pkt_02022E20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02023B74  0x02023B74  thumb
 *   func_02023BFC  0x02023BFC  thumb
 *   func_02023C3C  0x02023C3C  thumb
 *   func_02023D18  0x02023D18  thumb
 *   func_02023D40  0x02023D40  thumb
 *   func_02023D60  0x02023D60  thumb
 *
 * The family's ten-argument setup dispatcher, called from func_0202350C
 * with a wipe's configuration block already unpacked into registers and
 * stack.  The last argument selects the shape: zero takes the window
 * path (func_02023B74 / func_02023BFC / func_02023C3C) and anything else
 * takes the blend path (func_02023D18 / func_02023D40 / func_02023D60).
 *
 * The two arms are written out in full rather than factored, which is
 * what keeps them as two separate three-call sequences with their own
 * epilogues rather than one tail-merged tail
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022E20.c \
 *       --func func_02022E20 --addr 0x02022E20 --cc 1.1p1 --thumb
 */

typedef unsigned int  u32;

extern void func_02023B74(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02023BFC(u32 a0, u32 a1, u32 a2);
extern void func_02023C3C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void func_02023D18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_02023D40(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02023D60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5,
                          u32 a6);

void func_02022E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7, u32 a8, u32 a9)
{
    if (a9 == 0) {
        func_02023B74(a1, 0, a3, a4);
        func_02023BFC(a2, 0, a4);
        func_02023C3C(a5, a6, a7, a8, a3, a4);
    } else {
        func_02023D18(a0, a1, 0, a3, a4);
        func_02023D40(a0, a2, 0, a4);
        func_02023D60(a0, a5, a6, a7, a8, a3, a4);
    }
}
