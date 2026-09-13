# A shift pair with unequal amounts is a narrowing cast folded with a shift, not a bitfield

summary: `lsls #a` / `asrs #b` with `a != b` is `(s<32-b>)(x << (a - b))`, and
`lsls #a` / `lsrs #b` is the unsigned twin; only the equal-amount pair is the
type conversion or bitfield that `shift-pair-with-no-matching-type-is-a-bitfield.md`
describes, so reading an unequal pair as a bitfield invents a struct that is
not there.

Found in: `src/matched/unit_02007B54.c` (0x02007B68, 0x02007BD0)

`docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md` covers
`lsls #n` / `lsrs #n`, where the two amounts are the same: 32 minus n is the
width, and a width that is not 8, 16 or 32 is a bitfield. When the two amounts
differ the rule is a different one, because the pair is then doing two things
at once.

The compiler emits a cast to an 8 or 16 bit type as a shift up and a shift
back, and it folds any adjacent shift in the source into the first of the two.
So the second amount alone gives the width of the cast, and the difference of
the two amounts gives the shift the source actually wrote:

```
lsls r5, r5, #0x1c      /* 28 */
asrs r7, r5, #0x18      /* 24 */          =  (s8)(v << 4)

lsls r4, r4, #0x14      /* 20 */
lsrs r4, r4, #0x18      /* 24 */          =  (u8)(v >> 4)
```

32 - 24 is 8 in both, so both casts are to a byte; 28 - 24 is a left shift of
four and 20 - 24 is a right shift of four. The sign of the second shift picks
`s8` against `u8`, exactly as it does for the equal-amount case.

Both of these are in `sub_02007B68`, which expands a byte holding two signed
four bit samples into eight bytes:

```c
s8 a = (s8)((s8)((u8)(src[i] & 0xF) - 8) << 4);
...
s8 b = (s8)((s8)((u8)(src[i] >> 4) - 8) << 4);
```

Two things about the C are load bearing and neither is obvious from the bytes.

**The truncation has to be materialised, so the value needs a name.** Writing
the shift straight into the store, `dest[o + j] = y << 4;`, is a `lsls #4`
alone: the store is a `strb` and truncates for free, so the compiler drops the
cast. It is the assignment to an `s8` local before the store loop that forces
the pair. The same applies to the `u8` half of `sub_02007BD0`, where
`p->data[j] |= (u8)(hi << 4)` keeps `lsls #28` / `lsrs #24` only because the
`(u8)` is written out.

**Four is not a bitfield here.** 32 - 28 is four, and the equal-amount rule
would read that as a four bit field. It is not: the second amount is 24, the
width is eight, and the four is the shift. A bitfield read would have produced
a struct declaration, and every offset derived from it would have been wrong.
