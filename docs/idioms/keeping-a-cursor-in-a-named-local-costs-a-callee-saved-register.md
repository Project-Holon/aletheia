# Keeping a cursor pointer in a named local costs a callee-saved register; re-reading the field does not

summary: `p = s->cursor; a = p[0]; s->cursor = p+1; b = p[1];` needs a register
that survives the store, which is `r4`/`r5` and a `push`/`pop`; re-reading
`*s->cursor` fresh after each `s->cursor = s->cursor + 1` needs only the
scratch registers the two loads already use, and is four bytes shorter.

Found in: `src/matched/unit_02011330.c` (0x02011330, 0x0201134C)

Both functions read successive bytes off a stream cursor stored in a struct
field and advance the field after each byte. The original never needs to
save a register:

```
ldr r2, [r0, #0x14]     /* cursor */
ldrb r3, [r2]           /* b0 */
adds r1, r2, #1         /* cursor + 1 */
str  r1, [r0, #0x14]    /* store it back */
ldrb r2, [r2, #1]       /* b1, off the OLD cursor + 1 */
```

Written with a local that survives across the store,

```c
u8 *c = s->cursor;
u8 b0 = c[0];
s->cursor = c + 1;
u8 b1 = c[1];
```

the compiler keeps `c` live across the call-clobbering-free store anyway and
still ends up wanting a fourth working register once there are three or four
bytes to read, which for a leaf function means `push {r4, r5}` it would
otherwise not need: 28 bytes against the original's 26 for the two-byte
version, 50 against 48 for the four-byte one, and the accumulated address
arithmetic differs by more than a register name once the push is there to
fill.

Written so nothing survives the store,

```c
u8 b0 = *s->cursor;
s->cursor = s->cursor + 1;
u8 b1 = *s->cursor;
s->cursor = s->cursor + 1;
```

each read is a fresh dereference of the field, computed after the field's
own new value has already been written back, and the two loads fit in the
registers the arguments arrived in. This reproduces the original exactly,
including for a four-byte version chained the same way. The two forms are
not an optimisation the compiler is free to find either way: only the second
is the original's register allocation, because only the second never needs a
pointer alive across the store.
