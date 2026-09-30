# A vendor front end's parameter-to-callee-saved register SET cannot be forced by source

summary: When a function is byte-identical in instruction *schedule and opcodes*
and the only difference is which callee-saved register each incoming parameter
is homed into, that is the front end's register allocator, not a source shape.
Declaration-order permutations, statement reorders, moving a local's declaration
across others, and adding a same-typed local are all inert. Park the row and log
the register set; do not re-derive the spelling.

Found in: `src/pending/ov_sdk/ov009_func_0217E504.c` (0x0217E504, ov009,
gsiLargeIntMultM, gslargeint.o). Vendor object stamp 4.0.0.1025; nearest tree
front end `dsi/1.1p1` is 1024.

The whole 704-byte body lines up instruction for instruction: same `push`,
same `sub sp,#0x218`, the `Mult` call, the memset fold, the Montgomery inner
loop, the Compare/Sub/memcpy/clear epilogue. The residue is 149 concrete bytes
that are pure register renames, and the first divergence is the parameter
homing order in the prologue:

```
image:  mov r5, r1   /* y -> r5 */   mov r4, r2   /* m -> r4 */   mov r7, r0   /* x -> r7 */
ours:   mov r4, r2   /* m -> r4 */   mov r7, r1   /* y -> r7 */   mov r8, r0   /* x -> r8 */
```

Both home three `struct *` parameters and a stack-array base; the vendor build
picks `{r4,r5,r7,r8}` (m,y,x,temp) where 1.1p1 picks `{r4,r6,r7,r8}`
(m,temp,y,x). The later `r6` loop counter / `r5` reuse follows from that set,
so the whole body recolours.

Levers tried and inert (all stayed at 149, byte for byte):
- moving `unsigned int temp[128] = {0};` to be declared last, after every
  pointer local;
- a same-typed local `struct gsLargeInt_s *yp = y;` used for the callee's
  second struct argument (copy-propagated away, no `mov` added);
- every declaration order of the DWARF locals (prior lane), and a full
  statement-order sweep of the vendor GameSpy body.

Rule: distinguish this from `a-vendor-front-end-homed-parameter-cannot-be-forced-by-source.md`,
which is about a *frame spill / redundant live pointer copy*. This one has no
spill and no extra live value; the instruction count and schedule are already
exact and only the callee-saved assignment differs. No C spelling reaches a
different front end's allocator state, so the row parks on the register set.
