# A four-term `|` chain of shifts is emitted right-associated, and each pair's materialised operand is the right one

summary: in ARM, a chain like `v | (v<<4) | (v<<8) | (v<<12)` comes out as one
bare `lsl` followed by three `orr`s with shifter operands, and reading the
emission order back tells you the parenthesisation: the single `lsl` is the
innermost pair's *second* operand, so the source is nested to the right and the
two operands of each inner pair are the reverse of the order they appear in.

Found in: `src/matched/func_02040C14.c` (0x02040C14)

Replicating a 4-bit pixel value across a 32-bit word, and the same for an
8-bit one, gives two chains in the two arms of one `if`. The original:

```
02040D40  lsl r0, r8, #8            /* 4bpp arm */
02040D44  orr r0, r0, r8, lsl #12
02040D48  orr r0, r0, r8, lsl #4
02040D4C  orr r0, r8, r0
02040D50  orr r8, r0, r0, lsl #16
```

The obvious C, left to right in increasing shift order, is wrong:

```c
u32 t = value | (value << 4) | (value << 8) | (value << 12);   /* wrong */
```

That is left-associated, `(((v | v<<4) | v<<8) | v<<12)`, and compiles to
`lsl r0, v, #0xc` first, then `orr` with `v<<8`, `v<<4` and `v`: the same five
instructions with the first two shift amounts swapped.

The spelling that reproduces the original is fully parenthesised to the right,
with the innermost pair written high-shift-first:

```c
u32 t = value | (value << 4 | (value << 12 | value << 8));
value = t | (t << 16);
```

and, in the 8bpp arm of the same `if`,

```c
value = value | (value << 8 | (value << 24 | value << 16));
```

## How to read the listing back

ARM's shifter operand means only one operand of each `orr` is materialised, so
the emission order names the tree exactly:

* the one bare `lsl` is the innermost pair's operand that got a register; the
  other operand of that pair is the shift folded into the first `orr`. Write
  that pair with the *folded* one first.
* every later `orr` folds one more operand into the accumulator, so each one
  is the next level out, and each of those is written with the folded operand
  first and the accumulator second.
* the last `orr` is the outermost, and its plain register operand (here
  `orr r0, r8, r0`, the un-shifted `value`) is the outermost left operand.

This is the ARM counterpart of
`docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md`,
which covers the Thumb case where every operand needs its own register and the
question is which one the accumulator starts in. Here nothing needs a register
except the accumulator, so the tell is not register pressure but which single
shift got materialised.
