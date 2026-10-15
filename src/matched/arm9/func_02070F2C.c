/*
 * function: NNSi_G3dTexMtxScaleRotTrans4x4
 * address:  0x02070F2C
 * packet:   pkt_02070DDC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The 64-bit sibling of src/matched/NNSi_G3dTexMtxRotTrans4x4.c (docs/notes/pkt_02070DDC.c.txt),
 * and the member of the 0x02071CDC constructor family that carries the full
 * s32 2x2 block AND the f24/f28 cross terms.
 *
 * THE LEVER THE NOTE WAS MISSING, and it closes the 12-byte residue the note
 * records at this address: THE TWO f18 PRODUCTS ARE COMPUTED x7 (f18*f20)
 * FIRST, x6 (f18*f22) SECOND, even though x6 is the one stored first, to
 * d->f00.  Writing them in store order (x6 then x7) gives the allocator's
 * choice, r7 for x6 and r6 for x7, which is exactly the image's pair
 * REVERSED: 14 concrete bytes out, in the six instructions at +0x3C..+0x4C
 * plus `str`/`add`/`mul` at +0x68/+0x94/+0xF8.  Swapping the two statements
 * takes it to 0.  Declaration order (x7,x6), the commutative order of the
 * `x7 + x6` addend, and reversing each smull's operands are all 13-14 out.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md) in its
 * scheduling form.  The image loads the two s16 fields in the order f22 then
 * f20 -- `ldrsh r5, [sb, #0x22]` (`f2 52 d9 e1`) at 0x02070F54 and
 * `ldrsh r0, [sb, #0x20]` (`f0 02 d9 e1`) at 0x02070F5C, straddling the
 * `ldr r3, [sb, #0x18]` -- and then consumes them in the OPPOSITE order,
 * f22's product into r6 and f20's into r7.  1.1p1 -O4,p refuses to separate
 * the load from its first use: it swaps the two `ldrsh`es to match the
 * consumption order and carries the swap through both lsr/orr pairs, the same
 * 264 bytes with 8 concrete bytes out.  No source ordering reaches 0 under
 * 1.1p1, because whichever statement order is written, 1.1p1 reorders the
 * loads to follow it.  Under the pin the same C is 264 bytes, 0 mismatches.
 *
 * symbols:
 *   FX_DivAsync       0x0207C930  arm
 *   FX_GetDivResult   0x0207C86C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

struct Src { u8 pad_00[0x18]; s32 f18; s32 f1c; s16 f20; s16 f22;
             s32 f24; s32 f28; u16 f2c; u16 f2e; };
struct Dst { s32 f00; s32 f04; u8 pad_08[8]; s32 f10; s32 f14;
             u8 pad_18[0x18]; s32 f30; s32 f34; };

extern void FX_DivAsync(s32 num, s32 den);
extern s32  FX_GetDivResult(void);

void NNSi_G3dTexMtxScaleRotTrans4x4(struct Dst *d, struct Src *s)
{
    s32 c, e;
    s32 a, b, p, r;
    s32 x6, x7, x5, x4;
    s32 n;

    c = (s32)s->f2c << 12;
    e = (s32)s->f2e << 12;
    FX_DivAsync(e, c);

    a = (s32)s->f22;
    p = s->f18;
    b = (s32)s->f20;
    r = s->f1c;

    x7 = (s32)(((s64)p * b) >> 12);
    x6 = (s32)(((s64)p * a) >> 12);
    x5 = (s32)(((s64)r * b) >> 12);
    x4 = (s32)(((s64)r * a) >> 12);

    d->f00 = x6;
    d->f14 = x4;
    d->f04 = ((0 - x5) * FX_GetDivResult()) >> 12;

    FX_DivAsync(c, e);

    n = s->f18 - (x7 + x6);
    d->f30 = ((s32)s->f2c * n << 3)
           - ((s32)s->f2c * (s32)(((s64)s->f18 * s->f24) >> 8));
    n = ((x5 - x4) - s->f1c) + 0x2000;
    d->f34 = ((s32)s->f2e * (s32)(((s64)s->f1c * s->f28) >> 8))
           + ((s32)s->f2e * n << 3);

    d->f10 = (x7 * FX_GetDivResult()) >> 12;
}
