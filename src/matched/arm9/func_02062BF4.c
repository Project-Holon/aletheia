/*
 * function: func_02062BF4
 * address:  0x02062BF4
 * packet:   pkt_02062B64
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dResetCellAnimation  0x02062F90  arm
 *
 * One step of the NNS G2D cell/animation player: advance the playback cursor,
 * fire the user callback if one is armed, hand off to NNS_G2dResetCellAnimation when the
 * playback mode says to, and finally clamp the cursor into the frame table's
 * bounds.
 *
 * The body is the one docs/notes/pkt_02062BF4.c.txt recorded as a codegen wall
 * (26 concrete bytes out under dsi/1.1p1, with 208 of the 276 bytes already
 * instruction-for-instruction).  It is filed here essentially unchanged.  TWO
 * things closed it, and neither was a new reading of the function:
 *
 *   1. THE `../2.0/sp2` PIN closes the note's second residue outright.  The
 *      note's item 2 was the scheduler moving the independent
 *      `ldr r1, [r4, #0x1c]` up into the load-delay slot of `ldr r0, [r4, #8]`,
 *      splitting the image's `ldr / eor / str / ldr` into `ldr / ldr / eor /
 *      str`.  That is a 1.1p1 scheduling habit; ../2.0/sp2 issues the four in
 *      the image's order with the SAME C.  Measured on the note's body
 *      unchanged: 1.1p1 nine mismatched instructions, ../1.2/sp2 forty-seven,
 *      ../2.0/sp2 three.  This is the same front end the cluster neighbour
 *      src/matched/func_02062BAC.c is pinned to.
 *
 *   2. THE RANGE FOLD, which is the note's item 1 and was the whole remaining
 *      residue (5 concrete bytes, three instructions).  mwccarm folds a
 *      disjunction over two CONSECUTIVE integers into a range test:
 *      `mode == 3 || mode == 4` becomes `sub r0, r0, #3 / cmp r0, #1 / bhi`,
 *      where the image has the unfolded `cmp r0, #3 / cmpne r0, #4 / bne`.
 *      The fold is not a spelling of the disjunction -- swapping the operand
 *      order, `(mode ^ 3) == 0 || (mode ^ 4) == 0`, and both nestings of the
 *      equivalent ternary all give either the same fold or a larger function.
 *      What blocks it is forcing the disjunction to be materialised as a VALUE
 *      before it is branched on:
 *
 *          if (mode == 3 || mode == 4 ? 1 : 0) { ... }
 *
 *      The `? 1 : 0` makes the condition an ordinary int expression, so the
 *      front end evaluates the two equality tests and if-converts them into
 *      `cmp` / `cmpne`, and only then branches -- which is exactly the image.
 *      This is the counterpart of
 *      docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md:
 *      there the disjunction has to be ONE expression to tail-merge, here it
 *      has to be one VALUE to escape the range fold.  Note that the function's
 *      other two disjunctions, `mode == 2 || mode == 4`, need no such
 *      treatment and are written plainly: 2 and 4 are not consecutive, so
 *      there is nothing to fold and the front end emits `cmp` / `cmpne` of its
 *      own accord.  The tell is precise -- consecutive constants fold, others
 *      do not.
 *
 * The permuter confirms the residue was never allocation: `--explain` on the
 * ../2.0/sp2 baseline reports NO register substitution at all.  It is worth
 * recording what it did do, because it is the shape of a near miss rather than
 * a close: `--mode hill --budget 800 --jobs 8 --types` walked the 5-byte
 * baseline down to 2 concrete bytes (instruction score 225 -> 10) and then
 * exhausted 275 single mutations with no further improvement.  It could reach
 * the right instruction COUNT and ordering but never the `cmp`/`cmpne` pair
 * itself, because no value-preserving mutation in its set can undo a fold the
 * front end performs on constants.  A residue the permuter cannot move is in
 * the declarations or in the reading of the image; here it was in neither --
 * it was in the shape of one condition, and `? 1 : 0` is the whole edit.
 *
 * WHY THE TWO ARMS DUPLICATE.  0x02062C44..0x02062C8C and
 * 0x02062C90..0x02062CD4 are byte-identical bodies reached from the two sides
 * of the mode test, and they are written out twice in the source for exactly
 * the reason docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md
 * gives: factoring them behind a label moves the branch target and reallocates
 * every register.  `getMode` is `static inline` and is called twice for the
 * same reason -- the image re-reads +0x18 and +0x1c after the callback,
 * because the callback may have written them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062BF4.c \
 *       --func func_02062BF4 --addr 0x02062BF4 --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 276 = original 276, 2 of 2 sites resolved
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Sub {
    u16 h0;       /* 0x00 */
    u16 h2;       /* 0x02 */
    u32 pad04;    /* 0x04 */
    u32 field_08; /* 0x08 */
    u32 ptr_0C;   /* 0x0C */
};

typedef void (*Callback)(u32, u32);

struct Slider {
    u32 pos;         /* 0x00 */
    u32 pad04;       /* 0x04 */
    u32 field_08;    /* 0x08 */
    u32 field_0C;    /* 0x0C */
    u32 field_10;    /* 0x10 */
    u32 pad14;       /* 0x14 */
    u32 field_18;    /* 0x18 */
    struct Sub *sub; /* 0x1C */
    u32 field_20;    /* 0x20 */
    u32 field_24;    /* 0x24 */
    Callback cb_28;  /* 0x28 */
};

struct NNSG2dAnimController;
extern void NNS_G2dResetCellAnimation(struct NNSG2dAnimController *pAnimCtrl);

static inline u32 getMode(struct Slider *s) {
    u32 m = s->field_18;
    if (m == 0) {
        m = s->sub->field_08;
    }
    return m;
}

void func_02062BF4(struct Slider *s)
{
    u32 mode = getMode(s);
    if (mode == 3 || mode == 4 ? 1 : 0) {
        struct Sub *sub;
        u32 pos;
        s->field_08 ^= 1;
        sub = s->sub;
        pos = s->pos;
        if (pos <= (sub->ptr_0C + (sub->h2 << 3) - 8)) {
            if (s->field_20 == 1) {
                s->cb_28(s->field_24, s->field_10);
            }
            mode = getMode(s);
            if (mode == 2 || mode == 4) {
                NNS_G2dResetCellAnimation((struct NNSG2dAnimController *)s);
            } else {
                s->field_0C = 0;
            }
        }
    } else {
        if (s->field_20 == 1) {
            s->cb_28(s->field_24, s->field_10);
        }
        mode = getMode(s);
        if (mode == 2 || mode == 4) {
            NNS_G2dResetCellAnimation((struct NNSG2dAnimController *)s);
        } else {
            s->field_0C = 0;
        }
    }

    {
        struct Sub *sub = s->sub;
        u32 pos = s->pos;
        u32 bound = sub->ptr_0C + (sub->h0 << 3) - 8;
        if (pos > bound) {
            s->pos = bound;
            return;
        }
        if (pos < sub->ptr_0C) {
            s->pos = sub->ptr_0C;
        }
    }
}
