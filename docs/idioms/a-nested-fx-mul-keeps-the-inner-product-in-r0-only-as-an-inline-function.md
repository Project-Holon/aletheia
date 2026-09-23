# A nested FX_Mul keeps the inner product in r0:r1 only when FX_Mul is an inline function

summary: `FX_Mul(FX_Mul(a, b), c)` written with the FX_MUL macro moves the
inner product to r2:r3 and loads `c` into r0:r1 (and swapping the operands
changes nothing); written as a `static inline fx32 FX_Mul(fx32, fx32)` the
inner result stays in r0:r1 and `c` goes to r2:r3, which is the Nitro
game-code shape.

Found in: docs/notes/pkt_02014D2C_boundary.c.txt (0x02014D2C, mcss.c frame
walker, 21 `_ll_mul` sites, wave 12)

The original, for every chained product:

```
blx  _ll_mul              ; inner product in r0:r1
movs r2, #2 / lsls r2, #0xa / adds r2, r0, r2 / adcs r1, <zero>
lsrs r0, r2, #0xc / lsls r1, r1, #0x14 / orrs r0, r1   ; >> 12 into r0
ldr  r2, [field]          ; the next factor straight into r2
asrs r1, r0, #0x1f / asrs r3, r2, #0x1f
blx  _ll_mul
```

With `#define FX_MUL(v1, v2) ((fx32)(((fx64)(v1) * (v2) + 0x800LL) >> 12))`
the compiler instead copies the inner 64-bit product to r2:r3, does the
rounding add there, and loads the field into r0: two extra moves per
chained product, 60 bytes over the function, and a push list one register
wider ({r3-r7,lr} for {r4-r7,lr}).  `FX_MUL(c, FX_MUL(a, b))` compiles to the
identical bytes as `FX_MUL(FX_MUL(a, b), c)`: the compiler canonicalises the
operand order of the macro form, so no operand swap reaches the image.

The inline function (the SDK's own FX_MulInline body, which the SDK only
selects for ARM code; in Thumb FX_Mul is a call to FX_MulFunc) binds the
inner result to a parameter first, and that evaluation order is what the
image shows:

```c
static inline fx32 FX_MUL(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}
```

In that function the non-nested products (`FX_Mul(pose.sy, w->ff0)` and
the like) were already right with the macro; it was the chained ones that
told the two spellings apart.
