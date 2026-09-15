# An in-range `add #0xfd` where `sub #3` would do says the source added, not subtracted

summary: mwccarm does not canonicalise a byte-truncated `x - k` into `x + (256-k)`
or back, so a bias whose immediate is the unsigned two's-complement of a small
number is what the source literally wrote; `sub`/`add` is the one-instruction
tell that separates the two spellings of the same range test.

Found in: `src/matched/func_0203D26C.c` (0x0203D26C),
`src/matched/func_0203D29C.c` (0x0203D29C), and inlined inside
`src/pending/func_0203D2CC.c` (0x0203D2CC)

The existing
[out-of-range immediate subtract](out-of-range-immediate-subtract-costs-a-pool-word.md)
idiom covers the case where the constant cannot be encoded at all. This is the
opposite situation: the subtract *is* encodable, in one instruction, and the
original still uses the add form.

## The shape

A "state is in [lo, hi]" test on a `u8` field compiles to a bias, a truncation
and one unsigned compare:

```
    ldrb r0, [r0, #0x65]
    add  r0, r0, #0xfd        <- the bias
    and  r0, r0, #0xff        <- the (u8) cast
    cmp  r0, #1
    movls r0, #1
```

`#0xfd` is `(u8)-3`, and `sub r0, r0, #3` is a perfectly legal ARM
data-processing immediate that would leave the following `and` with the same
value. The compiler emits whichever one the source asked for:

```c
    (u8)(s->mode - 3) <= 1        ->   sub r0, r0, #3
    (u8)(s->mode + 0xfd) <= 1     ->   add r0, r0, #0xfd
```

Both are byte-for-byte identical everywhere else, so a wrong guess here is a
one-instruction `DIFF` in an otherwise finished function, which is easy to
misread as an addressing or scheduling problem.

## What it is not

It is not a `switch`. The same range test written as

```c
    switch (s->mode) {
    case 1:
    case 2:
        return 1;
    }
```

lowers to a shorter sequence (44 bytes against the original's 48 at
0x0203D29C), because the switch lowering folds the bias into the compare and
drops the `and`. If the `and r0, r0, #0xff` is present, the truncation is a
cast in the source and the construct is an `if`, not a `switch`.

## Rule

Read the bias immediate literally. `add #0xNN` with `0xNN >= 0x80` under a
byte truncation means the source wrote `+ 0xNN`; only `sub #k` means it wrote
`- k`. Do not "normalise" the constant while writing the C.
