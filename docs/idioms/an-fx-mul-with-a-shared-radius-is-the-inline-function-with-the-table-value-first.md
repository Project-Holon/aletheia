# An FX_Mul whose second operand is a shared radius is the inline function with the table value first

summary: when two `_ll_mul` calls take a sin/cos table entry in r0:r1 and the same s32 radius in r2:r3 (the radius kept in a frame slot and its sign word `asrs rX, r0, #0x1f` in a callee-saved register across both calls), the source is the inline `FX_Mul(fx32 a, fx32 b)` with the table value as `a`; the `((s64)(a) * (b) + 0x800) >> 12` macro in either operand order, or the inline function with the radius first, puts the radius in r0:r1 and spills both of its words (368 bytes out of 500).

Found in: src/matched/ov010_func_0216A8F0.c (0x0216A8F0)

The image (Thumb, 1.1p1 -O4,p), `pos.x += FX_Mul(cos, r); pos.z += FX_Mul(sin, r);`:

    str   r0, [sp]             ; r, the quotient
    asrs  r4, r0, #0x1f        ; its sign, kept for both products
    ...
    ldrsh r0, [r0, r1]         ; FX_SinCosTable_[idx + 1]
    ldr   r2, [sp]
    adds  r3, r4, #0
    asrs  r1, r0, #0x1f
    blx   _ll_mul

The C:

    static inline fx32 FX_Mul(fx32 a, fx32 b)
    {
        return (fx32)(((s64)a * b + 0x800LL) >> 12);
    }
    ...
    pos.x += FX_Mul(FX_SinCosTable_[idx + 1], r);
    pos.z += FX_Mul(FX_SinCosTable_[idx], r);

The macro form produces the same instruction count per product but loads the
radius as the first operand in both orders (the front end canonicalises the
cast operand), stores its two words at [sp] and [sp, #4], and grows the frame
from 0x10 to 0x18. Declaring the radius `s64` does not change it. Compare
docs/idioms/a-nested-fx-mul-keeps-the-inner-product-in-r0-only-as-an-inline-function.md,
the nested case of the same macro/function difference.
