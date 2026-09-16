# Pointer + integer normalises to pointer-first; casting the pointer keeps the source order

summary: `p + n` and `n + p` both compile to `add rd, rp, rn` no matter which
way round they are written, because the front end normalises pointer
arithmetic before the operand-order rule ever sees it; writing the same
address as `n + (u32)p` makes it an ordinary integer add and the source order
is kept, which is the only way to reach `add rd, rn, rp`.

Found in: `src/matched/func_02060ABC.c` (0x02060ABC), against
`src/matched/func_02060A08.c` (0x02060A08)

`docs/idioms/commutative-operand-order-names-the-temporary.md` says a value
reaches a commutative operator's left slot only when a named local holds it.
That rule is about integers. Pointer arithmetic does not obey it, and trying
to apply it wastes a sweep.

## The tell

One byte out at an `add` whose operands are a pointer and a size, and neither
spelling of the addition moves it:

```
  original                    compiled
  add r6, r8, sb              add r6, sb, r8
```

with `sb` the block's data start and `r8` the block's size. Both

```c
u8 *end = base + block->size;
u8 *end = block->size + base;
```

give `add r6, sb, r8`. Binding the load to a named local first, which is what
the commutative-order idiom prescribes, does not help either: it moves the
whole allocation around (19 bytes out instead of 2) and still emits the
pointer first.

## What fixes it

Cast the pointer and write the addition as integer arithmetic in the order the
original has:

```c
u8 *end = (u8 *)(block->size + (u32)base);   /* add r6, r8, sb */
```

Nothing else in the 176-byte function changes.

## Rule

When an `add` mixes a pointer and an integer and the operand order is wrong,
do not reach for a temporary. The C is telling you the original wrote the
address as an integer expression: a `u32` cast on the pointer, or a helper
that returns `u32`. Read it backwards too, since it is evidence about the
source: an `add` with the size in the left slot was written with the pointer
cast to an integer, and one with the pointer on the left was written as plain
pointer arithmetic, whichever order the operands appear in the C.
