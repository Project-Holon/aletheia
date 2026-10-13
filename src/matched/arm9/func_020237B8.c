/*
 * function: WIPE_SUB_CalcCircleSpan
 * address:  0x020237B8
 * packet:   pkt_0202363C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Compiled to 146 bytes; the listing's inferred 148-byte extent (to
 * 0x0202384C, the next labelled function) runs 2 bytes past what the
 * compiler actually emits here, never a byte difference: EXACT*.
 *
 * Fixed-point vertical-band test: a0/128 (signed division, the classic
 * sign-spread rounding-toward-zero idiom) is a limit compared against the
 * absolute difference of two row indices a2/a3. If the row distance
 * reaches or exceeds the limit, both outputs are zeroed and the function
 * returns immediately (void; the original never sets a return value on
 * either path). If the row distance is inside the limit, the function
 * computes
 * sqrt(round(limit'^2) - round(dist'^2)) where limit' = limit<<12 and
 * dist' = |a3-a2|<<12, each square taken in 64 bit through the compiler's
 * signed multiply helper _ll_mul (contract r0:r1 * r2:r3 -> r0:r1, see
 * docs/idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md)
 * and each rounded by +0x800 before its own >>12 splice. FX_Sqrt of the
 * difference gives a radius r (already >>12'd back to a plain s32 by the
 * asrs after the call); *out0 = a1 - r (clamped to 0) and
 * *out1 = *out0 + 2*r (clamped to 0xff).
 *
 * symbols:
 *   _ll_mul   0x0209C054  arm
 *   FX_Sqrt   0x0207C7B4  arm
 */

typedef signed int       s32;
typedef signed long long s64;

extern s32 FX_Sqrt(s32 x);

void WIPE_SUB_CalcCircleSpan(s32 a0, s32 a1, s32 a2, s32 a3, s32 *out0, s32 *out1)
{
    s32 limit = a0 / 128;
    s32 dist = a3 - a2;
    s32 r;

    if (dist < 0) {
        dist = -dist;
    }

    if (dist >= limit) {
        *out0 = 0;
        *out1 = 0;
        return;
    }

    {
        s64 sq_limit = (s64)(limit << 12) * (s64)(limit << 12);
        s64 sq_dist  = (s64)(dist  << 12) * (s64)(dist  << 12);
        s32 t0 = (s32)((sq_limit + 0x800) >> 12);
        s32 t1 = (s32)((sq_dist  + 0x800) >> 12);

        r = FX_Sqrt(t0 - t1) >> 12;
    }

    *out0 = a1 - r;
    if (*out0 < 0) {
        *out0 = 0;
    }
    *out1 = *out0 + r * 2;
    if (*out1 > 0xff) {
        *out1 = 0xff;
    }
}
