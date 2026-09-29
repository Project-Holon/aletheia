# A negated byte loaded with `ldrb` but read elsewhere with `ldrsb` is a u8 field, cast to s8 where it is passed plain

summary: when one call passes `-(field)` as `ldrb; rsbs; lsls #24; asrs #24` and
another call passes the same field as `ldrsb` with no narrowing, declare the
field `u8`, pass the negated one as `-s->f` into an `s8` parameter and the
plain one as `(s8)s->f`; declaring the field `s8` turns the negated load into
`movs rN,#off; ldrsb` (one instruction longer, everything after shifts).

Found in: src/matched/ov/ov067_func_021B8B74.c (0x021B8B74),
src/matched/ov/ov067_func_021B806C.c (0x021B806C)

Both call `func_021B8434(s, a, b, c, d)` whose second parameter the callers
narrow to s8. The original:

```
ldrb  r1, [r4, #0xb]      ; -(u8)fb, then (s8)
rsbs  r1, r1, #0
lsls  r1, r1, #0x18
asrs  r1, r1, #0x18
...
movs  r1, #0xb            ; the other arm: (s8)fb, no narrowing
ldrsb r1, [r4, r1]
```

With `s8 fb;` both arms load with `ldrsb` (the register-offset form needs the
`movs #0xb`), so the negated arm is 2 bytes longer and every byte after it
shifts.
With `u8 fb;`, `-s->fb` keeps the `ldrb` (only the low byte matters after the
s8 narrowing), and `(s8)s->fb` folds into `ldrsb` with nothing after it. The
same holds for an indexed byte (`s->fb[s->f95]`, 0x021B806C cases 2 and 3).

The extern's parameter is `s8`: the `asrs` pair is the caller's narrowing to
that type. A sibling that passes an untruncated `muls` result
(ov067_func_021B8DF0) declares the same parameter `int`.
