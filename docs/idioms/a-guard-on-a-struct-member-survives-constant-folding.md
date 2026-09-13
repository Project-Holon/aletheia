# A test on a struct member is emitted even when the value stored in it is a constant

summary: mwccarm constant folds through a local scalar but not through a
member of a local aggregate, so a live `tst`/`bics` pair on a value that a
literal pool already holds is a guard the source really wrote, and rewriting
it over a plain local silently folds it away and loses twelve bytes.

Found in: `src/matched/unit_02006DAC.c` (0x02006DD8)

`sub_02006DD8` fills a seven word parameter record on the stack and rounds one
of its fields down to a multiple of 32.  The value being rounded is the
constant 0x1FF4, which arrives from the function's own literal pool, and the
original still tests it at run time:

```
ldr  r1, [pc, #0x24]      /* 0x00001FF4 */
movs r0, #0x1f
str  r1, [sp, #8]
tst  r0, r1
beq  .done
movs r0, #0x1f
bics r1, r0
str  r1, [sp, #8]
.done:
```

Two stores to the same slot, a test whose outcome is known at compile time,
and the mask materialised twice because Thumb has no immediate `bic`.  That is
what the source says, and the source is

```c
param.unk08 = 0x1FF4;
if (param.unk08 & 0x1F) {
    param.unk08 &= ~0x1Fu;
}
```

The obvious tidier spelling, which computes the value first and stores it once,

```c
u32 v = 0x1FF4;
if (v & 0x1F) {
    v &= ~0x1Fu;
}
param.unk08 = v;
```

is folded completely: the compiler evaluates the guard, keeps only
`param.unk08 = 0x1FE0;`, and the unit comes out twelve bytes short and DIFF.
So the difference is not the arithmetic, it is which object the value passes
through.  This front end's value numbering follows a scalar local but stops at
a member of an aggregate, even an aggregate whose address has not escaped yet
at that point in the function.

The reverse reading is what makes this worth a file.  A run time test of a
constant is not dead code the optimiser missed and it is not evidence that the
value is really a variable somewhere else: it is evidence that the source
applied the guard to the *field*, in place, after assigning it.  Reading it the
other way and hoisting the computation is a plausible cleanup that destroys the
match, and the diff it leaves (a shorter function, not a wrong one) does not
point at its own cause.
