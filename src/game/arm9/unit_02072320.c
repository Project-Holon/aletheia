/*
 * file:     unit_02072320.c
 * function: func_02072320
 * address:  0x02072320
 * packet:   pkt_02071DD4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The identity-scale member of the 0x02071CDC constructor family: the 2x2
 * block is the unit matrix (0x1000 on the diagonal, zeroes off it) and only
 * the f30/f34 translation pair carries work, each a plain 32-bit
 * `(u16 field * negated s32 field) << 4`.
 *
 * Two sub-problems, both recorded in docs/notes/pkt_02071DD4.c.txt. The
 * first is solved in the C: the double negation of the f34 term,
 * `(0 - f2e) * (0 - f28)`, only survives if the two negations are SEPARATE
 * named locals assigned before the `d->f30` store (folded together the
 * function comes out 68 bytes, separated it is the right 84).
 *
 * The second is the pin. Under dsi/1.1p1 -O4,p the f00 and f04 stores merge
 * into one `stm r0, {r2, lr}`, giving 80 bytes against the original's 84:
 * the image instead writes `str r2, [r0]` at 0x02072328 and `str r2,
 * [r0, #0x14]` at 0x0207232C and materialises the zero LATE, `mov lr, #0`
 * (`00 e0 a0 e3`) at 0x02072330, only then storing `str lr, [r0, #4]`.
 * Store order (all six permutations), a `z` local, `d->f14 = d->f00`, and
 * hoisting all three constants were measured and the merge survives every
 * one. It is the "kept constants" tell of docs/FRONTEND-PINS.md, the same
 * already pinned for func_02074A6C, func_02072D20 and func_020713A4; note
 * also the image's `push {r3, lr}` / `pop {r3, pc}` with NO call in the
 * body, lr spent as a scratch, which is exactly what the merge denies.
 * Under the pin the same C is 84 bytes, 0 mismatches.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef int            s32;

struct SRC {
    u8  pad_00[0x24];
    s32 f24;
    s32 f28;
    u16 f2c;
    u16 f2e;
};

struct DST {
    s32 f00;
    s32 f04;
    u8  pad_08[8];
    s32 f10;
    s32 f14;
    u8  pad_18[0x18];
    s32 f30;
    s32 f34;
};

void func_02072320(struct DST *d, struct SRC *s)
{
    s32 a, b, c;

    d->f00 = 0x1000;
    d->f14 = 0x1000;
    d->f04 = 0;

    a = 0 - s->f24;
    b = 0 - s->f28;
    d->f30 = ((s32)s->f2c * a) << 4;
    c = 0 - (s32)s->f2e;
    d->f34 = (c * b) << 4;

    d->f10 = 0;
}
