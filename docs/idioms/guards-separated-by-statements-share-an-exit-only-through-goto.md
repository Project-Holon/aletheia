# Guards that are separated by statements can only share one exit block through `goto`

summary: `docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md`
reads several conditional branches to one block at the end of a function as one
`&&`, and that reading is unavailable when statements sit between the guards;
there the only source shape that produces the shared block is an explicit
`goto`, and writing the guards as separate `return`s gives each one its own
copy of the epilogue.

Found in: `src/matched/unit_0201EC64.c` (the 0x0201EC74 near miss), which is
where the shape was pinned; the same shape is EXACT in
`src/matched/unit_0201F47C.c` for the conjunction case

A constructor that allocates three things in a row has to check each one, and
the checks cannot be one expression because each depends on the allocation
before it.  The original reaches one shared exit from all of them:

```
0201EC94  beq  0x201ecfa        /* the object */
0201ECC0  beq  0x201ecfa        /* the string buffer */
0201ECEC  beq  0x201ecfa        /* the slot array */
...
0201ECF2  bne  0x201ecfa        /* the loop did not run to completion */
0201ECF4  add  sp, #0xc
0201ECF6  adds r0, r6, #0
0201ECF8  pop  {r4, r5, r6, r7, pc}
0201ECFA  movs r0, #0           /* the one shared failure block */
0201ECFC  add  sp, #0xc
0201ECFE  pop  {r4, r5, r6, r7, pc}
```

Written the way a decompiler first writes it,

```c
p = alloc(...);
if (p == NULL) {
    return NULL;
}
...
if (p->buf == NULL) {
    return NULL;
}
```

mwccarm emits a three-instruction epilogue at each guard and the conditional
branch skips over it, so the function grows twelve bytes and every later
branch target moves.  It does not cross-jump them at `-O4,p`, exactly as
`guard-chain-sharing-one-exit-block-is-a-single-conjunction.md` records for the
uninterrupted case.  Replacing every `return NULL;` with `goto fail;` and
putting one `fail: return NULL;` at the end reproduces the branch structure
above, and the diff on this function fell from 388 concrete bytes to 14.

So the decision procedure for a run of failure checks is:

* **no statements between the tests** and one shared block: a single `&&` or
  `||` expression;
* **statements between the tests** and one shared block: separate `if`s with
  `goto` to a label at the end;
* **each test skipping its own inline epilogue**: separate `if`s with separate
  `return`s.

The three are visibly different and the third is the one that is written by
accident.

The remaining 14 bytes of 0x0201EC74 are unrelated to this and are a prologue
scheduling difference: the original spills its heap-id parameter as the second
instruction of the function and reloads it for the first call, where every
source shape tried keeps it in its incoming register and copies.  That is
recorded here so that nobody re-derives the control flow half of it.
