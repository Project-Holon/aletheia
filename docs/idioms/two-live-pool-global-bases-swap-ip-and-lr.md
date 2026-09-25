# Two live pool-global bases: the one whose store comes first in the source gets `lr`, the other gets `ip`

summary: with two fixed-address globals both live in the opening block, mwccarm
hands the first base to `lr` and the second to `ip`, and which is "first" is
decided by the source order of their first stores, not by the emitted
instruction order; putting the second global's store after a pointer local,
`volatile`, or a repositioned clamp does nothing, but moving it ahead of the
other global's stores flips the pair.

Found in: src/matched/ov172_func_021C4B9C.c (0x021C4B9C)

`SSP_ExifEncode` (libssp exifenc.o, ov172) opens with two global bases both
live at once:

```
021C4BA4  ldr ip, pool_021C4D00      /* ip = g_021CAE90 */
021C4BA8  mov r4, #0x1000
021C4BAC  ldr lr, pool_021C4D04      /* lr = g_021CADF0 */
021C4BB0  strh r4, [ip]              /* g_021CAE90.f0 = 0x1000 */
...
021C4BC0  str r0, [lr, #0x14]        /* g_021CADF0.f14 = a0 */
```

The obvious spelling — config block first, `g_021CADF0.f14 = a0;` after the
first two config fields — compiles to the mirror image: `ldr lr,=g_021CAE90`
then `ldr ip,=g_021CADF0`, a 7-byte diff with every other instruction and the
literal pool identical.  Neither base's live range crosses a call, so both are
allocated to scratch, and this front end apparently keeps the two address
constants in definition order with `lr` preferred for the earlier one.

What does **not** move it: a `struct Ae90 *cfg` pointer local (either
declaration order, assigned at the top or mid-block), a pointer-to-`volatile`
config, `#define` raw-constant casts, joining the `g_021CADF0` declare order
before `g_021CAE90`, or moving the clamp around.  Some of those flip `ip` into
`lr` but then perturb the surrounding schedule or unfold the neighbouring
constants, so the diff grows.

What does: move `g_021CADF0.f14 = a0;` **ahead of** the `g_021CAE90` config
stores:

```c
g_021CADF0.f14 = a0;
g_021CAE90.f0 = 0x1000;
g_021CAE90.f2 = 7;
...
```

The scheduler still emits the two `ldr`s and the two stores in the original
interleaved order and the function becomes `EXACT*`.  The `g_021CAE90` base is
now the *second* address constant the compiler materialises, so it lands in
`ip`, and `g_021CADF0` lands in `lr`, which is what the image has.  A named
local for a reused `(s16)a2` cast is not needed; the reorder alone is.

So a diff that is *only* an `ip`/`lr` swap across two simultaneously-live
fixed-address bases is not an allocator dead end: reorder the two globals'
first stores before touching types or pointer locals.
