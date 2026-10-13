/*
 * function: WIPE_SUB_CalcCircleLines
 * address:  0x0202384C
 * packet:   pkt_0202384C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_02022D88   0x02022D88  thumb
 *   WIPE_SUB_CalcCircleSpan  0x020237B8  thumb
 *
 * Rebuilds the wipe's per-scanline window table, one row for each of the
 * screen's 0xC0 lines.  sub_02022D88 hands back the buffer whose two s16
 * arrays live at +0x300 (left edge) and +0x480 (right edge).  Inside the
 * band (f14, 2*f14] the pair is mirrored from row 2*f14 - y; everywhere
 * else it is computed through WIPE_SUB_CalcCircleSpan.
 *
 * Two facts closed it (the notes stood at 98 bytes against 104):
 *  - WIPE_SUB_CalcCircleSpan's THIRD argument is w->f14, the value still live in r2
 *    from the band test, not 0.  That was the "re-load" the notes chased.
 *  - The guard is an if / else-if / else chain with the call written out
 *    in BOTH outer arms; mwcc cross-jumps the two copies, leaving the
 *    `bgt` over a `b` at +0x16 and hoisting &l into r7
 *    (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * EXACT* only because the 102-byte body is followed by two bytes of
 * alignment padding before WIPE_SUB_ShutterStart.
 */
typedef signed short s16;
typedef signed int   s32;
typedef unsigned int u32;


struct Wipe {
    u32 f00;
    u32 f04;
    u32 f08;
    s32 f0c;      /* 0x0c */
    s32 f10;      /* 0x10 */
    s32 f14;      /* 0x14  half-height of the mirrored band */
};

struct Buf {
    s16 pad000[0x180];
    s16 left[0xC0];   /* 0x300 */
    s16 right[0xC0];  /* 0x480 */
};

struct Obj;
extern void *sub_02022D88(struct Obj *obj, u32 idx);
extern void WIPE_SUB_CalcCircleSpan(s32 a0, s32 a1, s32 a2, s32 a3, s32 *out0,
                          s32 *out1);

void WIPE_SUB_CalcCircleLines(struct Wipe *w)
{
    struct Buf *b;
    s32 y;
    s32 l;
    s32 r;

    y = 0;
    b = sub_02022D88((struct Obj *)w, 0);

    do {
        if (y <= w->f14) {
            WIPE_SUB_CalcCircleSpan(w->f0c, w->f10, w->f14, y, &l, &r);
        } else if (y <= w->f14 * 2) {
            l = b->left[w->f14 * 2 - y];
            r = b->right[w->f14 * 2 - y];
        } else {
            WIPE_SUB_CalcCircleSpan(w->f0c, w->f10, w->f14, y, &l, &r);
        }
        b->left[y] = (s16)l;
        b->right[y] = (s16)r;
        y = y + 1;
    } while (y < 0xC0);
}

