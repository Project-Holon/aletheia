/*
 * unit:     yes
 * address:  0x02016FC8
 * packet:   pkt_02016FC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02016FC8
 *
 * 310 bytes, one function, and two bytes of linker fill after it before the
 * next function at 0x02017100; the range this entry owns is 0x02016FC8 plus
 * 310, which is why it is written as a unit rather than as a single function
 * entry (`match.py one` measures the extent to the next label, sees 312 and
 * reports EXACT* over two bytes the compiler never emitted).
 *
 * The 4x4 fixed-point transform of a three-component vector: the ordinary
 * Nitro row-vector convention, out = v * M with the translation row added
 * afterwards, computed in 64 bit and shifted back down by the 12 fractional
 * bits at the end of each component.  The fourth component does not go into
 * the destination vector; it is written through a separate `s32 *`, which is
 * what makes this the projection form rather than MTX_MultVec: the caller
 * gets x, y, z and w separately and divides by w itself.
 *
 *   dst->x = (s32)((vx * m[0][0] + vy * m[1][0] + vz * m[2][0]) >> 12)
 *            + m[3][0];        and the same for columns 1, 2 and 3
 *
 * Every product is a call to the compiler's 64 bit multiply helper at
 * 0x0209C054, twelve of them, and the `asrs rN, rM, #0x1f` in front of each
 * operand is the sign extension an `s32` costs on the way to `long long`; see
 * docs/idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md
 * for the same family of helpers seen from the division side.  The name the
 * relocation carries is `_ll_mul`, not `_ull_mul`: both spellings name the
 * same routine at 0x0209C054 (`umull` plus two `mla` is correct for either
 * signedness), and which one mwccarm emits follows the signedness of the
 * operands, so `src/matched/unit_020056A0.c` pins the same address under the
 * other name.  The helper's contract is r0:r1 and r2:r3 in, r0:r1 out.
 *
 * The 64 bit shift is not a call.  `lsls r0, rHi, #0x14` / `lsrs r1, rLo, #0xc`
 * / `orrs r1, r0` is the low word of a `>> 12` on a 64 bit value with the high
 * word dead, which is what the cast back to `s32` makes of it; the shift of
 * the low half is `lsrs` and not `asrs` whatever the sign of the value,
 * because it is a bit-field splice and not an arithmetic shift.
 *
 * ---------------------------------------------------------------------------
 * WHAT COST THE TIME
 * ---------------------------------------------------------------------------
 * **The shifted product needs a named local, or the translation row is loaded
 * ten bytes too early.**  Written as one expression,
 *
 *     dst->x = (s32)((...) >> 12) + mtx->m[3][0];
 *
 * the compiler loads `mtx->m[3][0]` before the last two adds of the 64 bit
 * accumulation, which then needs two register copies to get the helper's
 * result out of r0:r1; the function grows twelve bytes and 248 concrete bytes
 * differ, all of them scheduling.  Splitting the statement,
 *
 *     r = (s32)((...) >> 12);
 *     dst->x = r + mtx->m[3][0];
 *
 * is EXACT.  Holding the 64 bit sum in an `s64` local instead and casting at
 * the store is byte-identical, so the image does not say which of the two the
 * source wrote, only that it was not one expression.
 *
 * **The three vector components are read into locals, and the sign extension
 * is what they are read for.**  `v` is `const` and `dst` is not, so a store
 * through `dst` may alias `v`; written as `v->x` inside all twelve products
 * the compiler reloads and re-extends each component for every output and
 * comes out four bytes short with the whole body rescheduled.  Three `s32`
 * locals assigned at the top make the six words of sign-extended vector one
 * CSE that lives on the stack at sp+4 through sp+0x18 for the whole function,
 * which is the original's frame.  The same three values held as `s64` locals
 * are twelve bytes longer, so the source's locals are 32 bit and the cast is
 * at the multiply.
 *
 * Nothing here is version specific: every constant is a matrix offset or the
 * fixed-point shift.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02016FC8.c  *       --addr 0x02016FC8 --thumb
 *
 * symbols:
 *   _ll_mul  0x0209C054  arm
 */
typedef signed int       s32;
typedef signed long long s64;

struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
};

struct MtxFx44 {
    s32 m[4][4];
};

void func_02016FC8(const struct VecFx32 *v, const struct MtxFx44 *mtx,
                   struct VecFx32 *dst, s32 *w)
{
    s32 vx;
    s32 vy;
    s32 vz;
    s32 r;

    vx = v->x;
    vy = v->y;
    vz = v->z;

    r = (s32)(((s64)vx * mtx->m[0][0] + (s64)vy * mtx->m[1][0]
                    + (s64)vz * mtx->m[2][0]) >> 12);
    dst->x = r + mtx->m[3][0];
    r = (s32)(((s64)vx * mtx->m[0][1] + (s64)vy * mtx->m[1][1]
                    + (s64)vz * mtx->m[2][1]) >> 12);
    dst->y = r + mtx->m[3][1];
    r = (s32)(((s64)vx * mtx->m[0][2] + (s64)vy * mtx->m[1][2]
                    + (s64)vz * mtx->m[2][2]) >> 12);
    dst->z = r + mtx->m[3][2];
    r = (s32)(((s64)vx * mtx->m[0][3] + (s64)vy * mtx->m[1][3]
                    + (s64)vz * mtx->m[2][3]) >> 12);
    *w = r + mtx->m[3][3];
}
