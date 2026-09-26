# A named zero argument keeps a live zero in a callee-saved register and pins the caller-side truncation

summary: in a loop that passes a constant zero as a call argument, spelling the
zero as a named local (`int j = 0;`) keeps it live in a callee-saved register;
spelling it as a literal `0` lets the compiler fold the zero and hoist a
repeated `(u16)i` conversion into that same register, shifting every register
in the loop.

Found in: src/matched/func_021BBB48.c (0x021BBB48)

The original loops over 0x3d records, calls an accessor with a constant third
argument, and returns the zero-extended index on a hit:

```
021BBB48  push {r3, r4, r5, r6, r7, lr}
021BBB4A  movs r4, #0
021BBB4C  adds r6, r0, #0
021BBB4E  adds r5, r1, #0
021BBB50  adds r7, r4, #0        /* the named zero, copied off the counter's 0 */
021BBB52  lsls r1, r4, #0x10
021BBB54  adds r0, r6, #0
021BBB56  lsrs r1, r1, #0x10     /* (u16)i, recomputed every iteration */
021BBB58  adds r2, r7, #0        /* the constant zero argument */
021BBB5A  bl   #0x21bbb3c
021BBB5E  cmp  r5, r0
...
```

The obvious C

```c
if (func_021BBB3C(a0, (u16)i, 0) == a1)
    return (u16)i;
```

compiles to a different body: the compiler folds the `0` into `movs r2, #0`
and common-subexpression-eliminates the two `(u16)i` conversions into r7, so
the index conversion is hoisted out of the loop and every register moves.
Naming the zero keeps r7 occupied:

```c
int j = 0;
...
if (func_021BBB3C(a0, i, j) == a1)   /* callee parameter declared u16 */
    return (u16)i;
```

Now r7 holds `j`, the truncation of `i` cannot land there, and it is
recomputed in the argument register (r1) on every pass, exactly as the image
does. The `int` index passed to a `u16` parameter supplies the `lsls`/`lsrs`
pair; passing an already-`u16` local suppresses it.
