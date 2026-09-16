# A `+ 0xFFFF` bias is two `add`s; `- 1` is one `sub`

summary: in ARM code a range test biased by minus one is four bytes longer when
the source writes the bias as the unsigned 16-bit constant 0xFFFF, because that
splits into `add #0xff` plus `add #0xff00` while `- 1` is a single `sub #1`.

Found in: `src/matched/sub_02046F50.c` (0x02046F50)

`docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md` records the
Thumb accounting, where the constant lands in a literal pool. In ARM there is no
pool: 0xFFFF is not a rotated immediate, so the front end splits it into the two
rotated immediates 0xFF and 0xFF00 and emits an `add` for each.

## The tell

A `u16`-narrowed range test that reads

```
    add r0, r0, #0xff
    add r0, r0, #0xff00
    lsl r0, r0, #0x10
    lsr r0, r0, #0x10
    cmp r0, #1
    movls r0, #1
    movhi r0, #0
```

is `return (u16)(v + 0xFFFF) <= 1;`. The arithmetically identical
`return (u16)(v - 1) <= 1;` gives the same seven-instruction shape with the two
`add`s replaced by one `sub r0, r0, #1`, which is four bytes short and the only
difference in the whole function. Both spellings mean "v is 1 or 2" after the
narrowing, so there is no semantic evidence either way; only the byte count
decides, and the image is the only witness.

## The other half of the same function

Do not read the range form as the compiler's own rewrite of a disjunction. This
front end does not fold `v == 1 || v == 2` into a biased comparison: in the same
`switch`, the non-contiguous `v == 1 || v == 3` and the contiguous pair both
come out as `cmp` / `cmpne` / `moveq` / `movne` when written as disjunctions.
The range form appears only when the C is written as a range.
