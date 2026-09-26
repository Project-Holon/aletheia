# Clearing a small bitfield is `bics` with the field mask, not `ands` with its complement

summary: `p->f = 0` on a 3-bit field compiles to `movs r2,#0x38; bics r3,r2`; the
equivalent `p[4] &= ~0x38` compiles to `movs r2,#0xc7; ands r3,r2`, so the
`bics`/`ands` choice and the constant (`0x38` vs `0xc7`) are the tell that a
bitfield exists.

Found in: docs/notes/ov023-func_02186A04.c.txt (0x02186A04)

The original clears bits 3..5 of byte 4 of a 6-byte record:

```
ldrb r3, [r4, #4]
movs r2, #0x38
bics r3, r2
strb r3, [r4, #4]
```

A first spelling used a plain byte mask:

```c
u8 *p = dst + 6 * i;
p[4] &= ~0x38;
```

which compiles instead to

```
ldrb r3, [r4, #4]
movs r2, #0xc7        /* the complement, kept as a positive constant */
ands r3, r2
strb r3, [r4, #4]
```

Same semantics, two different bytes. Writing the byte as a struct whose
bits 3..5 are a 3-bit field and assigning the field clears the compiler's
choice to the field mask:

```c
typedef struct { u8 a,b,c,d; u8 e:3; u8 f:3; u8 g:2; u8 h; } Rec;
((Rec *)dst)[i].f = 0;
```

So when a byte clear shows `movs #0x38; bics` rather than `movs #0xc7; ands`,
reach for a bitfield of that exact width at that bit offset. The same works in
reverse: an `ands` with a low constant where you expected a clear means your
mask spelling does not match a declared field.
