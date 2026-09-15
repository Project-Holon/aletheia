/*
 * unit:     no
 * function: sub_0204B728
 * address:  0x0204B728
 * packet:   pkt_0204B728
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0206380C  0x0206380C  arm
 *
 * Install a transform into the object at +0x40: query the two axis slots
 * through the predicate at 0x0206380C, then copy all five words in.
 *
 * 0x0206380C is a pure reader (`return m->w[axis + 2] != -1;`, 28 bytes,
 * no store), so the source pointer is genuinely `const` here.  Both call
 * results are discarded, which is what an assertion-shaped call looks like
 * once the check itself is compiled out.
 *
 * The `const` is load-bearing for codegen, not decoration: with a plain
 * `struct Xform *` source this front end emits the destination address
 * (`add ip, r5, #0x40`) before the source block load, and with `const` it
 * emits the `ldm r4!, {r0, r1, r2, r3}` first, which is the original's
 * order.  That is the whole content of the DIFF recorded in
 * docs/notes/sub_0204B728.c.txt, and the reason nine non-const spellings
 * there all failed identically.  See
 * docs/idioms/const-source-pointer-schedules-the-block-load-first.md.
 *
 * The copy is twenty bytes, under the unroll threshold, so it inlines to a
 * writeback `ldm`/`stm` pair plus a trailing word for the odd fifth
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B728.c \
 *       --func sub_0204B728 --addr 0x0204B728 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Xform {
    u32 w[5];
};

struct Obj {
    u8           pad_00[0x40];
    struct Xform unk_40;
};

extern void sub_0206380C(const struct Xform *m, u32 axis);

void sub_0204B728(struct Obj *o, const struct Xform *m)
{
    sub_0206380C(m, 1);
    sub_0206380C(m, 2);
    o->unk_40 = *m;
}
