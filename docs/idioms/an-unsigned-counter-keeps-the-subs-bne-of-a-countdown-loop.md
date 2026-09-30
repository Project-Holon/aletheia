# An unsigned counter keeps the `subs`/`bne` of a countdown loop

summary: a hand-unrolled clear loop written with a **signed** `n` is
normalised by the front end into a bottom-tested `cmp n,#0` + `bgt` with the
decrement hoisted into the body, and the two loop-local scratch registers come
out in the opposite order; the same loop with an **unsigned** `n` keeps
`subs n, n, #1` + `bne` with the decrement on the back edge, and declaring the
counter before the cursor puts the counter in `r1` and the cursor in `r2`.

Found in: `src/matched/ov_sdk/ov175_func_021DFBB8.c` (0x021DFBB8, scSubmitReport)

The 16-byte `mChecksum` of the report header is cleared four bytes at a time
and the original is a real four-iteration loop, not an unrolled one:

```
021dfbb8+0038  ldr r4, [r7, #0x124]     ; header
021dfbb8+003c  mov r1, #4               ; the counter, unsigned
021dfbb8+0040  add r2, r4, #8           ; p = &mChecksum[0]
021dfbb8+0044  mov r0, #0
021dfbb8+0048  strb r0, [r2]
021dfbb8+004c  strb r0, [r2, #1]
021dfbb8+0050  strb r0, [r2, #2]
021dfbb8+0054  strb r0, [r2, #3]
021dfbb8+0058  add r2, r2, #4
021dfbb8+005c  subs r1, r1, #1
021dfbb8+0060  bne #0x21dfc00           ; back to the first strb
```

`docs/idioms/a-post-decrement-in-the-loop-condition-splits-the-compare-from-the-subtract.md`
says the rule for the `cmp`/`sub` split: a `subs` on the counter immediately
before the back edge is the decrement written in the body, and a separate
`cmp` is the post-decrement written in the condition. That still leaves the
sign of `n` undecided, and here it decides the shape. With `int n` every one
of

```c
while (n) { ...; n--; }
while (n--) { ...; }
do { ...; } while (--n);
do { ...; } while (--n != 0);
```

compiles to the same twelve bytes: the front end rotates the loop, hoists the
decrement to the top of the body, and tests the decremented value with a
signed `bgt`,

```
   strb r0, [r1]
   sub  r2, r2, #1        /* hoisted out of the condition */
   strb r0, [r1, #1]
   ...
   cmp  r2, #0
   add  r1, r1, #4
   bgt  loop
```

which is 216 bytes for the whole function against the original's 212 and shifts
everything after the loop. `unsigned int n` — same trip count, same source
shape otherwise — is byte for byte the `subs`/`bne` above, because the exit
test after the decrement is "is it zero" rather than "is it still positive",
so there is nothing to compare and the `subs` flags are the branch condition.
`unsigned char n` is not a way out either: it emits an extra
`ands r1, r1, #0xff` to re-truncate the counter, and `unsigned short n` emits
the `lsl`/`asr` pair.

Two things have to be right together. The counter must be declared **before**
the cursor, because the two of them are the loop's scratch registers and the
declaration order picks which gets `r1`: declaring the cursor first reproduces
every byte of the loop except that `r1` and `r2` swap, and that swap is ten
differing bytes in an otherwise byte-exact 212-byte function. And the two
locals have to be declared ahead of `GSMD5_CTX md5`; with `md5` first, the
allocator gives it `r8` and drops the whole parameter block one register, which
is 32 differing bytes rather than ten. The house sibling
`src/matched/ov_sdk/ov175_func_021E26BC.c` shows the same ordering rule for the
same three callees.

The unsigned counter is also what makes the loop *this* loop rather than a
sixteen-iteration byte loop: a plain `for (i = 0; i < 16; i++)` is not
strength-reduced and unrolled by `-O4,p`, it stays a 16-trip byte loop of 32
bytes, and the function comes out 12 bytes short.
