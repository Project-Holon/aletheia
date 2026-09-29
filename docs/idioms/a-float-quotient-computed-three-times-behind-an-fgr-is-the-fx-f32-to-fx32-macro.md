# A float quotient computed three times behind an `_fgr` is the FX_F32_TO_FX32 macro

summary: `_fflt`/`_fdiv` run once for `_fgr(q, 0)`, then again in each arm
before `_fmul(4096.0f, q)` and `_fadd(0.5f, ...)` / `_fsub(..., 0.5f)` and a
shared `_ffix`: that is the SDK macro `FX_F32_TO_FX32(x)` with `x` an
expression, pasted three times. Do not bind the quotient to a local.

Found in: `src/matched/ov/ov021_func_021C7584.c`,
`src/matched/ov/ov021_func_021C7940.c`,
`src/matched/ov/ov021_func_021C7B1C.c` (and the earlier
`src/matched/ov/ov021_func_021C6F30.c`, which uses it on a variable)

The original's shape, in Thumb with soft-float helpers:

```
        blx _fflt / _ffltu    (cnt)       ; first evaluation, for the test
        blx _fflt / _ffltu    (max)
        blx _fdiv
        movs r1, #0
        blx _fgr
        bls  .neg
        blx _fflt ... blx _fdiv           ; evaluated again
        ldr  r0, =4096.0f
        blx _fmul                         ; r0 = 4096.0f, r1 = q
        movs r0, #0x3f; lsls r0, #24      ; 0.5f
        blx _fadd                         ; r0 = 0.5f,   r1 = product
        b    .fix
.neg:   blx _fflt ... blx _fdiv           ; and a third time
        ldr  r0, =4096.0f
        blx _fmul
        movs r1, #0x3f; lsls r1, #24
        blx _fsub                         ; r0 = product, r1 = 0.5f
.fix:   blx _ffix
```

The spelling that reproduces it:

```c
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

t = FX_F32_TO_FX32((f32)w->cnt / (f32)w->max);
```

The constant lands in r0 for `_fmul` and `_fadd` even though the macro writes
it second: the compiler canonicalises the constant operand of a commutative
soft-float call to the first argument, so there is no need to reorder the
source. `_fsub` keeps the source order. Binding the quotient to a local
evaluates it once and drops two `_fflt`/`_fdiv` triples; the repeated calls
are the tell that the argument was an expression. Use `_ffltu` for unsigned
operands (the helper address says which), and a spill of the first `_fflt`
result to the stack instead of a callee-saved register only means the
function ran out of r4-r7.
