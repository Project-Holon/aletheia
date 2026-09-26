# A byte that is both a whole `u8` and a `{lo:7, hi:1}` split is a union, and its two writes stay two stores

summary: to get the `lsls #24` / `lsrs #31` top-bit guard *and* the
`bics r,#0x7f` then reload/`orrs r,#0x80` two-store sequence on one byte, the
byte has to be declared as a union of the whole `u8` and a
`struct { u8 lo:7; u8 hi:1; }`; plain masks, a signed test, or two whole-byte
statements each lose one half of the shape.

Found in: src/matched/func_0689B670.c (0x0689B670, ov095)

The original is:

```
ldrb r1, [p,#0x92]
lsls r1, r1, #0x18
lsrs r1, r1, #0x1f
bne  ret
ldrb r2, [p,#0x92]
movs r1, #0x7f
bics r2, r1
strb r2, [p,#0x92]
ldrb r2, [p,#0x92]
movs r1, #0x80
orrs r1, r2
strb r1, [p,#0x92]
```

The guard is the 1-bit bitfield extraction `lsls`/`lsrs` pair (see
`shift-pair-with-no-matching-type-is-a-bitfield.md`), so it has to be read as
a bitfield, not `f & 0x80` (which gives `movs`/`tst`) and not `f < 0` (which
gives `asrs`).  The writes are `bics #0x7f` then `orrs #0x80`, i.e. clearing
the low seven bits and setting the top bit, and the reload between them says
the two writes were separate statements over the same field.

What reproduces all three tells is one declaration:

```c
struct S {
    u8 pad[0x92];
    union {
        u8 raw;
        struct { u8 lo : 7; u8 hi : 1; } b;
    } f;
};

if (s->f.b.hi) return;
s->f.b.lo = 0;   /* bics #0x7f, store */
s->f.b.hi = 1;   /* reload, orrs #0x80, store */
```

Writing `raw &= ~0x7f; raw |= 0x80;` folds the clear to `ands #0x80` and
`raw |= 0x80` alone loses the first store.  Each bitfield assignment is a
read-modify-write of its own field of the shared storage unit, which is why
the compiler does not merge them.
