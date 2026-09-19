# Parenthesise the offset sum: `base + (i * stride + k)` and `(base + i * stride) + k` are different code

summary: a pointer plus a scaled index plus a constant folds two different
ways -- the constant added to the scaled index first, or the base added to
the scaled index first -- and which one the source wrote shows up as the
order of the two `add`s, one instruction of size and the register the
multiply is allowed to use.

Found in: `src/matched/sub_0202D214.c` (packet pkt_0202D1AC)

Three of the four copy loops in that function are `base + i * size` and the
fourth is `base + (i * size + 0xc00)`.  Writing the fourth as
`base + i * size + 0xc00` -- which is the same arithmetic, since `+` is
left-associative -- compiles to

```
muls r1, r7, r1         ; r1 = i * size
adds r2, r4, r1         ; r2 = base + (i * size)
movs r1, #3
lsls r1, r1, #0xa       ; r1 = 0xc00
adds r1, r2, r1
```

while the original has

```
adds r2, r7, #0
muls r2, r1, r2         ; r2 = size * i, in a copy of the index
movs r1, #3
lsls r1, r1, #0xa
adds r1, r2, r1         ; r1 = (i * size) + 0xc00
adds r1, r4, r1         ; r1 = base + that
```

i.e. the constant is folded into the *index* term first and the base added
last, which also forces the multiply out of the stride register (it is
needed later as the constant) into a fresh copy of the index.  Four bytes
and one register, from two characters of parentheses.

The same function also shows the mirror-image mistake: `i` declared `u32`
gives `blo` on the loop-back branch where the original has `blt`, so the
loop counter is an `int`.  Both were pinned by holding the rest of the
216-byte function fixed and changing one spelling at a time.
