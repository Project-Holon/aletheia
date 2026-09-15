# A one-bit bitfield assigned `bic` + one predicated `orr` was written as two arms, not as a boolean

summary: assigning a comparison result to a one-bit bitfield materialises the
boolean in a register first (`moveq`/`movne`/`and #1`) and then inserts it;
writing the same thing as an `if`/`else` with a literal in each arm lets the
compiler clear the bit once with `bic` and predicate the set back onto the
entry compare, twelve bytes shorter.

Found in: `src/matched/func_0204BA20.c` (0x0204BA20)

## The tell

Six instructions, one `bic`, one predicated `orr`, and no register anywhere
holding a 0/1 value:

```
0204BA20  cmp   r1, #0
0204BA24  ldr   r1, [r0, #0x64]
0204BA28  bic   r1, r1, #1
0204BA2C  orreq r1, r1, #1
0204BA30  str   r1, [r0, #0x64]
0204BA34  bx    lr
```

The `bic` is unconditional and the `orr` carries the condition, so the source
never computed a value for the field: it chose between two constants.

## The two spellings

With `u32 hidden : 1;` at +0x64, the natural-looking

```c
a->hidden = (v == 0);
```

compiles to nine instructions and 36 bytes: `moveq r1, #1` / `movne r1, #0` /
`and r1, r1, #1` to build the boolean, then `bic` / `orr` to insert it. `!v`
and `v ? 0 : 1` are the same. The field's own width does not save the `and`,
because the value being inserted is an `int` as far as the insert sequence is
concerned.

The two-arm form

```c
if (v == 0) {
    a->hidden = 1;
} else {
    a->hidden = 0;
}
```

compiles to the image. Each arm is a store of a literal into the same bit, the
compiler factors the common `ldr`/`bic`/`str` out of both arms and is left with
one conditional `orr`, which if-converts.

## Rule

A predicated insert with no boolean materialisation is a two-arm `if`. The
generalisation is the same accounting as
`a-factored-tail-lets-the-compiler-predicate-the-arms.md`: give the compiler
two arms that differ in one instruction and it predicates that instruction;
give it one expression and it has to compute the expression.
