/*
 * unit:     no
 * function: func_02023E9C
 * address:  0x02023E9C
 * packet:   pkt_02023E0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialises the 0x20-byte interpolation record the packet's other two
 * functions drive. The two stack arguments are widened through the usual
 * lsls/lsrs #0x18 pair into the full words at +0x00 and +0x04, so they are
 * int-typed parameters narrowed with a (u8) cast, not u8 parameters.
 *
 * Field roles: f08 = step count, f0a = from, f1a = to, f12 = |to - from|,
 * f10 = the sign (+1 or -1), f14 = per-step delta, f16 = its remainder,
 * f18 = the running accumulator (cleared here), f1c = the active flag.
 *
 * Three spellings are load-bearing and were each isolated against the
 * bytes:
 *   - `p->f1c = 1;` must be the FIRST statement. The constant 1 has to
 *     land in r0 before the two stack arguments are widened; written
 *     anywhere later in the block the allocator promotes it to r6 and the
 *     whole entry block shifts register bank (19 and 14 bytes wrong for
 *     the two later positions tried).
 *   - the negation re-reads the field: the original is `ldrsh` + `subs
 *     r1,#0x13` + `muls`, four bytes more than the `rsbs` the compiler
 *     folds from a cached value. The volatile-qualified read is what
 *     defeats that fold; without it the function compiles 84 bytes, not
 *     88. The `-1` multiplier and the `-1` stored to f10 in the other arm
 *     share one register, derived from the 0x12 field offset.
 *   - `/` and `%` on the same operands are two separate _s32_div_f calls
 *     (docs/idioms/div-and-mod-are-two-calls.md); f14 takes the quotient
 *     from r0 and f16 the remainder from r1.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Interp {
    u32 f00;
    u32 f04;
    u16 f08;
    u16 f0a;
    u16 f0c;
    u16 f0e;
    signed char f10;
    u8  f11;
    s16 f12;
    s16 f14;
    s16 f16;
    u16 f18;
    s16 f1a;
    u32 f1c;
};

void func_02023E9C(struct Interp *p, u16 steps, s16 from, s16 to,
                   u32 a4, u32 a5)
{
    p->f1c = 1;
    p->f00 = (u8)a4;
    p->f04 = (u8)a5;
    p->f12 = to - from;
    p->f08 = steps;
    p->f1a = to;
    p->f0a = from;

    if (p->f12 > 0) {
        p->f10 = -1;
    } else {
        p->f10 = 1;
        p->f12 = *(volatile s16 *)&p->f12 * -1;
    }

    p->f14 = p->f12 / steps;
    p->f16 = p->f12 % steps;
    p->f18 = 0;
}
