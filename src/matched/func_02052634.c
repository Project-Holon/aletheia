/*
 * function: func_02052634
 * address:  0x02052634
 * packet:   pkt_0205250C
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02058380   0x02058380  arm
 *   func_02053A60   0x02053A60  arm
 *   func_020583CC   0x020583CC  arm
 *
 * Promote-first callee of src/pending/func_020515B4.c (parks lane 2).
 * Pops one node off the list at p+0x10, runs the loader for the node and
 * (p->f28 + (arg1 << 5), arg2), then hands the node to func_020583CC; the
 * node is discarded when bit 14 of the word at *(node->f20) is set.
 *
 * Built by the 1.2 front end, not dsi/1.1p1: the epilogue is the ARMv4T
 * style `pop {r4-r7, lr}; bx lr` *and* the frame pads with `sub sp, sp, #4`
 * instead of spending a dead `push {r3}` on the alignment word, which is
 * the small-frame signature in
 * docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md.
 * On dsi/1.1p1 this same C is 4 bytes short (112) at every -proc value.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02052634.c \
 *       --func func_02052634 --addr 0x02052634 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */

typedef unsigned int u32;

extern void *func_02058380(void *p);
extern void func_02053A60(void *a, void *b, int c);
extern void func_020583CC(void *a, void *b);

int func_02052634(char *p, int b, int c)
{
    void *r = 0;

    if (*(u32 *)(p + 0x10) != 0) {
        r = func_02058380(p + 0x10);
        func_02053A60(r, (void *)(*(u32 *)(p + 0x28) + (b << 5)), c);
        func_020583CC(p + 4, r);
        if ((*(u32 *)(*(u32 *)(*(u32 *)((char *)r + 0x20))) << 0x11 >> 0x1f) != 0)
            r = 0;
    }
    return (int)r;
}
