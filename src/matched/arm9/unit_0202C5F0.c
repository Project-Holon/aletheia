/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C5F0
 * packet:   pkt_0202C5F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ISS_SWITCH_Update, ISS_SWITCH_UpdateOn, ISS_SWITCH_UpdateOff
 *
 * symbols:
 *   sub_0202C6B8  0x0202C6B8  thumb
 *   sub_0202C638  0x0202C638  thumb
 *   sub_0202C654  0x0202C654  thumb
 *
 * One of the four open trampoline targets of src/pending/unit_0202C548.c
 * (reached through sub_0202C580's pool-word-and-bx tail call). A dense
 * switch over the window's state accessor
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md); two of
 * its four callees are the trivial `bx lr` stubs at 0x0202C630 and
 * 0x0202C634, which carry no prologue and so no label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md) and sit
 * between the switch and the next labelled function, which is why the
 * whole 72-byte range is one unit rather than one function.
 *
 * What closed the codegen half, after this range spent a wave as a
 * documented near miss in docs/notes/near-miss-0202C5F0.c.txt: the
 * dispatch sequence that folds the switch value into the jump-table
 * offset used r1 where the original uses r0, six bytes across five
 * instructions, and nothing about the switch itself moved it. The
 * function returns **void**. Written with a `u32` return and the arms
 * spelled `return ISS_SWITCH_UpdateOn(p);`, the callee's result is live out of
 * every arm, r0 is therefore not free at the dispatch and the index takes
 * r1; written `ISS_SWITCH_UpdateOn(p); break;` with no return value at all, r0
 * is dead across the table computation and the allocator puts the index
 * there. The stubs at 0x0202C630 and 0x0202C634 are `void` for the same
 * reason. Renaming the switch variable, hoisting it into a local, adding
 * a `default:`, casting it to `int` and marking it `register` are all
 * byte-for-byte identical to each other and all wrong; the return type is
 * the only thing that moves those six bytes. See
 * docs/idioms/a-void-return-frees-r0-for-the-switch-dispatch-index.md.
 *
 * What closed the evidence half: sub_0202C638 and sub_0202C654 are each
 * reached only from inside this range, but both are EXACT entries of
 * their own (src/matched/sub_0202C638.c, src/matched/sub_0202C654.c), so
 * the `matched` class witnesses both with no cut.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C5F0.c \
 *       --addr 0x0202C5F0 --thumb
 */

typedef unsigned int u32;

struct Obj0202C6B8;
extern u32 sub_0202C6B8(struct Obj0202C6B8 *p);
extern u32 sub_0202C638(void *p);
extern u32 sub_0202C654(void *p);

void ISS_SWITCH_UpdateOn(void *p);
void ISS_SWITCH_UpdateOff(void *p);

void ISS_SWITCH_Update(void *p)
{
    switch (sub_0202C6B8(p)) {
    case 0:
        ISS_SWITCH_UpdateOn(p);
        break;
    case 1:
        ISS_SWITCH_UpdateOff(p);
        break;
    case 2:
        sub_0202C638(p);
        break;
    case 3:
        sub_0202C654(p);
        break;
    }
}

void ISS_SWITCH_UpdateOn(void *p)
{
}

void ISS_SWITCH_UpdateOff(void *p)
{
}
