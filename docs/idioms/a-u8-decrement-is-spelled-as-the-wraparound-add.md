# A `u8` decrement is spelled as the wrap-around add

summary: `add rX, rX, #0xff` followed by `and rX, rX, #0xff` is `x + 0xff` in
the source, not `x - 1`; the two wrap to the same `u8` but this compiler emits
the constant exactly as written, so `- 1` gives `sub rX, rX, #1` instead.

Found in: src/matched/sub_02039338.c (0x02039338)

The original narrows a mode byte and tests the narrowed value against a small
bound:

```
02039358  ldrb r0, [r0, #0x65]
0203935C  add  r0, r0, #0xff
02039360  and  r0, r0, #0xff
02039364  cmp  r0, #1
```

The obvious C is a decrement:

```c
u8 sel = rec->unk65 - 1;
if (sel <= 1) { ... }
```

That is correct in value, and it produces the same `and` mask and the same
`cmp`, but the subtraction comes out as `sub r0, r0, #1`: two bytes different
and nothing else to distinguish the two spellings. The constant folder never
rewrites a small immediate into its 8-bit complement, so what reaches the
encoder is whatever the source wrote. The form that reproduces the original is
the wrap-around add:

```c
u8 sel = rec->unk65 + 0xff;
if (sel <= 1) { ... }
```

The tell is the operand: `add #0xff` on a value that is immediately masked to
eight bits is always a decrement written the long way, and `sub #1` in the same
position is always the short way. The same reasoning scales: a `u16` decrement
written as `+ 0xffff` comes out as an `add` of the pooled constant rather than
a `sub #1`.

This is the narrow-type cousin of
`out-of-range-immediate-subtract-costs-a-pool-word.md`: there the compiler has
no choice because the immediate will not encode, here it has one and follows
the source.
