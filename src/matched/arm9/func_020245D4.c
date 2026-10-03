/*
 * unit:     no
 * function: func_020245D4
 * address:  0x020245D4
 * packet:   pkt_020245D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * pmsi_param.c's word-array validator: guards the (category, page) pair
 * against the per-category count, asks func_02024498 how many words the
 * page carries, and runs each word through the same two-arm check
 * func_020246C8 performs on a single word.
 *
 * THE LEVER that closed this (it was DIFF, 132 bytes against 136, for the
 * whole of the previous wave -- see docs/notes/func_020245D4.diff.c.txt):
 * BOTH arms of the two-arm check write the `ok = 0; goto ret;` tail out,
 * and the label `setfail` sits INSIDE THE FIRST ARM'S COPY.  That is the
 * mixed case of docs/idioms/two-arms-write-the-tail-out-and-the-third-
 * branches-back-into-one.md.  The original spends a conditional AND an
 * unconditional branch at +0x64/+0x66 (`bne <loop increment>; b <setfail>`)
 * exactly because the two arms did not cross-jump; every shape that shares
 * one copy behind a single label folds them into one inverted `beq`, loses
 * four bytes and shifts every later branch target.
 *
 * Equally load-bearing: the `!= 0` arm is written FIRST
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  With the
 * `== 0` arm first the two call sites swap and 17 bytes differ.
 *
 * `sel` must be a named local: the guard reads p->f02 once and the same
 * value is handed to func_02024498, which is what keeps r5 live across the
 * func_02024584 call.
 *
 * symbols:
 *   func_02024584  0x02024584  thumb
 *   func_02024498  0x02024498  thumb
 *   sub_02024508   0x02024508  thumb
 *   sub_02024520   0x02024520  thumb
 *   func_020248D8  0x020248D8  thumb
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020245D4.c \
 *       --func func_020245D4 --addr 0x020245D4 --thumb --cc 1.1p1
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct T {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
};

typedef unsigned char  u8;
extern u8 func_02024584(u32 i);
extern u32 func_02024498(u32 a0, u32 a1, u32 a2);
extern u32 sub_02024508(u32 x);
extern u32 sub_02024520(u32 x);
extern int func_020248D8(u32 v, u32 *a1, u32 *a2);

u32 func_020245D4(struct T *p, u32 a1)
{
    u32 ok;
    u32 n;
    u32 i;
    u32 y, x;
    u32 sel;

    if (p->f00 >= 7) {
        goto fail;
    }
    sel = p->f02;
    if (sel >= func_02024584(p->f00)) {
        goto fail;
    }

    n = func_02024498(p->f00, sel, (u16)((a1 & 0x7FFF) | 0x8000));
    ok = 1;
    for (i = 0; i < n; i++) {
        struct T *q = (struct T *)((u16 *)p + i);

        if (sub_02024508(q->f04) != 0) {
            s32 v = sub_02024520(q->f04);

            if (v >= 1 && v < 11) {
                continue;
            }
setfail:
            ok = 0;
            goto ret;
        } else {
            if (func_020248D8(q->f04, &x, &y) != 0) {
                continue;
            }
            ok = 0;
            goto ret;
        }
    }
ret:
    return ok;
fail:
    return 0;
}
