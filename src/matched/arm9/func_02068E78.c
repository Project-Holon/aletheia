/*
 * function: NNSi_G2dInitPen
 * address:  0x02068E78
 * packet:   pkt_02068E78
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The text-context initialiser: seven arguments straight into six fields of a
 * 0x18-byte pen/draw context, with no computation at all.  A leaf, and the
 * image proves it -- it never pushes and returns with a bare `bx lr`.
 *
 * TWO THINGS THE BYTES FORCED:
 *
 *   1. THE STORE ORDER IS THE SOURCE ORDER, and it is deliberately not the
 *      field order: +0x04, +0x08, +0x0c, +0x00, +0x14, +0x10.  Writing the
 *      fields in ascending order instead lets the front end fuse the first two
 *      into `stm r0, {r1, r2}` (which is what 1.1p1 does even with the source
 *      order, see the pin below), and the function changes shape.  This
 *      compiler never reorders independent stores to the same object, so the
 *      image's order IS the original statement order -- the same reading rule
 *      as docs/idioms/the-fall-through-arm-is-the-source-order.md applied to
 *      straight-line code.
 *
 *   2. +0x0c IS A BYTE.  `strb r2, [r0, #0xc]` with the value arriving as a
 *      full stack word, so the parameter is an `int` and the field is `u8`;
 *      the narrowing is at the store, not at the call.
 *
 * THE ARITY AND THE ARGUMENT ORDER are not guessed: the caller
 * src/matched/NNSi_G2dInitPenSimple.c (already EXACT) spells the call as
 *
 *     NNSi_G2dInitPen((char *)a, b, c, d, e, 0x020A18DC, c);
 *
 * which fixes seven arguments, three in registers and four on the stack at
 * [sp+0], [sp+4], [sp+8], and shows the last argument repeating the third.
 * The other caller, NNS_G2dCharCanvasInitForVRAM at 0x02069064, agrees.
 *
 * THE `../2.0/sp2` PIN.  dsi/1.1p1 cannot produce a leaf here at all: it
 * spends `r4` and `lr` on the three stack arguments and therefore opens
 * `push {r4, lr}` and returns through `pop {r4, pc}`, which also shifts every
 * stack-argument displacement by 8 and lets it fuse `str r1, [r0]` with
 * `str r2, [r0, #4]` into one `stm`.  Nine of the ten instructions differ.
 * ../2.0/sp2 and ../1.2/sp2 both reproduce the image byte for byte with the
 * same C.  ../2.0/sp2 is recorded because the adjacent matched member of this
 * cluster, src/matched/NNSi_G2dCharCanvasDrawChar.c, is independently pinned to it (on the
 * "kept constants" re-read tell) and because the other function filed into
 * this cluster in the same pass, src/matched/NNS_G2dCharCanvasInitForVRAM.c, is 2.0 and NOT
 * 1.2.  Since two front ends agree on this row it is not usable as evidence
 * for either pin on its own, and it is deliberately not offered as one in
 * docs/FRONTEND-PINS.md -- but the symptom is worth naming: A LEAF THAT GROWS
 * A PROLOGUE is a front-end question, not a spelling one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dInitPen.c \
 *       --func NNSi_G2dInitPen --addr 0x02068E78 --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 40 = original 40, 0 relocation sites
 */

typedef unsigned char u8;

struct Pen {
    int  f00;
    int  f04;
    int  f08;
    u8   f0c;
    u8   pad0d[3];
    int  f10;
    int  f14;
};

void NNSi_G2dInitPen(struct Pen *p, int a1, int a2, int a3, int a5, int a6, int a7)
{
    p->f04 = a2;
    p->f08 = a3;
    p->f0c = (u8)a5;
    p->f00 = a1;
    p->f14 = a6;
    p->f10 = a7;
}
