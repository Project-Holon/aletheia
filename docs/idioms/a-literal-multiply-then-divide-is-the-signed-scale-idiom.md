# A literal multiply-then-divide in a pointer expression is what emits the signed-scale quartet

summary: mwccarm compiles `idx * 32 / 4` to a five-instruction signed-scale
sequence (`lsl #5`, `asr #1`, `add ..., lsr #30`, `add ..., asr #2`) that the
algebraically identical `idx * 8` never produces -- `idx * 8` folds into a
single `lsl #3` addressing operand. When the original scales an index by what
looks like a power of two and still spends four instructions on it, the source
is a byte offset divided by the element size, not a shift.

Found in: `src/matched/func_02046300.c` (0x02046300)

The original is 136 bytes and its head is

```
02046318  e1a0228a  lsl  r2, sl, #5        ; idx << 5
02046320  e1a000c2  asr  r0, r2, #1        ; (idx << 5) >>s 1
02046328  e0820f80  add  r0, r2, r0, lsr #30
02046334  e0818140  add  r8, r1, r0, asr #2
```

which is `r1 + (idx * 32) / 4` computed with the truncating-division
correction: `asr #1` then `lsr #30` recovers bits 31..30 of the product, which
is the `+3` a signed divide by 4 needs, and the final `asr #2` is the divide.

The obvious spelling of the same address

```c
u8 *p = (u8 *)hdr + hdr[0] + idx * 8;
```

is four bytes shorter and reallocates the function:

```
lsl  r1, r0, #3
add  r0, r4, r0
add  r8, r0, sl, lsl #3
```

The spelling that reproduces the original verbatim is

```c
u8 *p = (u8 *)hdr + hdr[0] + idx * 32 / 4;
```

`idx * 32 / 4` reads like a leftover from an array of 32-byte records indexed
as words, and that is exactly what it is: the original was written as a byte
offset converted to `u32` units before the pointer add. The compiler does not
fold the constant division away because the multiply is signed, so the
division is the only thing that puts the correction sequence in the code.

Two things make this worth remembering. It is a *positive* tell: the quartet
means "there is a divide by a constant here", so the search is over spellings
that divide, not over register pressure -- the same quartet turned up in
`d + j + (i * 32) / 4` in a throwaway probe (`i * 8`, `(u32)(i * 8)`, `i * 8u`
and `i << 3` all give the fold). And it is cheap to try: the two spellings
differ in one token and in 24 bytes of output.
