/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202290C
 * packet:   pkt_0202271C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0202290C, func_0202291C
 *
 * symbols:
 *   func_0209C0A4  0x0209C0A4  arm
 *
 * func_0202290C is a 16-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): it computes
 * (b - a) << 7 and forwards it with the third argument straight to
 * func_0209C0A4.  The pool word carries no Thumb bit and the branch is a
 * plain `bx` rather than `blx`, so the callee is declared `arm`; the image
 * labels it as a real function reached from 161 other call sites.
 *
 * func_0202291C is a plain four-word running-sum accumulator.  It does not
 * fold into an ldm/stm pair the way a whole-object assignment would
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), because each field is
 * added rather than copied.
 *
 * Compiling func_0202291C on its own comes out EXACT* against `one`: its
 * own extent runs to the 2-byte linker fill in front of func_02022940,
 * which is a real function and not an unlabelled follower.  Pairing it
 * with func_0202290C in one translation unit lets `tu` lay out both
 * sections with that fill in between, which reproduces cleanly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202290C.c \
 *       --addr 0x0202290C --thumb
 */

typedef unsigned int u32;
typedef int           s32;

extern s32 func_0209C0A4(s32 shifted, s32 c);

s32 func_0202290C(s32 a, s32 b, s32 c)
{
    return func_0209C0A4((b - a) << 7, c);
}

struct Quad {
    u32 a, b, c, d;
};

void func_0202291C(struct Quad *dst, struct Quad *src)
{
    dst->a += src->a;
    dst->b += src->b;
    dst->c += src->c;
    dst->d += src->d;
}
