# A u8-stepped counter that is re-truncated at every narrow argument is a 32-bit counter with a u8 increment

summary: a loop counter whose increment is `adds #1; lsls #0x18; lsrs #0x18`
(so it wraps as a `u8`) but which still gets its own `lsls`/`lsrs` pair each
time it is passed to a `u8`/`u16` callee parameter is an `unsigned int`
counter stepped with `i = (u8)(i + 1)`; declared `u8`, the front end knows
the value already fits and drops every argument-side pair, and the spare
register can even stop the counter spilling.

Found in: src/matched/ov/ov042_func_021F36C0.c (0x021F36C0),
src/matched/ov/ov041_func_021F36C0.c (0x021F36C0)

ov042's first loop in the original:

```
021F3714  lsls r0, r5, #0x18
021F3716  lsrs r6, r0, #0x18      ; (u8)i, recomputed every pass
021F3718  adds r0, r4, #0
021F371A  adds r1, r7, #0
021F371C  adds r2, r6, #0
021F371E  bl   func_021BE480      ; u16 parameter
...
021F3742  adds r0, r5, #1
021F3744  lsls r0, r0, #0x18
021F3746  lsrs r5, r0, #0x18      ; the increment wraps as a u8
021F3748  cmp  r5, #9
021F374A  blo                     ; unsigned compare
```

A `u8 i` with `i++` gives the same increment and `blo`, but the argument
pair vanishes (the value is known to fit) and the body is short. An `int i`
with `i = (u8)(i + 1)` keeps the pairs but compares with `blt`. What
reproduces both is:

```c
u32 i;
for (i = 0; i < 9; i = (u8)(i + 1))
    e = func_021BE480(s, 0, (u8)i);
```

In ov041 the counter is passed to `u16` parameters (`lsls #0x10; lsrs
#0x10` at each use) while the increment narrows to 24 bits. There the
`(u16)i` conversion becomes a separate loop-invariant value next to `i`, and
the extra pressure is what spills `i` to `[sp, #4]` and reloads it with
`ldr` before each conversion; a `u8` counter kept it in a register and moved
every register in the function.
