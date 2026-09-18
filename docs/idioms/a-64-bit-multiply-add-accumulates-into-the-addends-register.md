# A 64-bit multiply-plus-add accumulates into the loaded addend's register only when the addend stays inline in the multiply's statement

summary: for `r = a * b + c` on 64-bit values, mwcc accumulates the low word
into the register the addend came from when the addend is a dereference
written inside the multiply's own statement and the result is stored back as
one 64-bit store; with the addend in a named local, or with the two halves
stored separately, the same expression accumulates into `ip` and the high
half moves to a second scratch register, a five-instruction difference in
register choice with identical lengths.

Found in: src/matched/func_0203B9D4.c (0x0203B9D4)

The original advances a 64-bit accumulator and stores it back:

```
0203BA40  umull ip, r3, r2, r0     ; ip = low(C * A), r3 = high
0203BA44  mla   r3, r2, r1, r3     ;   += C * B
0203BA50  mla   r3, r1, r0, r3     ;   += D * A
0203BA54  adds  r2, r2, ip         ; low  accumulator is the *addend's* register
0203BA60  adc   r3, r1, r3         ; high accumulator is the umull's own
```

`r2` is where the third `u64` was loaded, and the compiler adds the product
*into* it; only r3 stays the umull's destination.  Every C spelling of the
same arithmetic that names the addend compiles to

```
    adds ip, r2, ip                ; low  accumulator is the umull's
    adc  r2, r1, r3                ; high moves to a second scratch register
```

same length, same flags, five instructions coloured differently, and the
bytes at the two `str`s and the following `umull` disagree.

What reproduces the original, measured both ways:

```c
    x = *(u64 *)(p + 0x0C);
    y = *(u64 *)(p + 0x14);
    r = y * x + *(u64 *)(p + 0x1C);      /* addend inline        */
    ...
    *(u64 *)(p + 0x0C) = r;              /* one 64-bit store     */
```

What does not, with a named addend (`u64 z = *(u64 *)(p + 0x1C);` and any of
`z = z + y * x`, `r = z + y * x`, `z += y * x`) or with the low and high
halves stored by two `u32` stores.  The multiply's own operand order is
load-bearing the same way: `y * x` with the pointer at +0x14 named first
emits the `ldr` of +0x14 before the one of +0x0C, and `x * y` swaps them.
