# The pool word for a far field of a global is the symbol plus the field offset masked by the load's reach

summary: a global too big for one Thumb immediate is reached through several
different literal pool words, and each one is the symbol plus the field offset
with the low bits of that access width's reach cleared, 0x7F for a word, 0x3F
for a halfword, 0x1F for a byte; reading those pool words as separate objects
splits one symbol into five and costs the file every relocation it has.

Found in: `src/matched/unit_020065D8.c` (0x020065D8, 0x02006674),
`src/matched/unit_020066E8.c` (0x020066E8, 0x02006734, 0x0200674C, 0x02006768)

`docs/MATCHING.md` and `src/matched/unit_020057DC.c` already record that a
field of `table[i]` with a run time `i` puts the member offset in the
relocation addend rather than in the instruction. That case is forced: Thumb's
register-offset `str` has no immediate at all, so the base has to be the exact
address of the field. This is the other half of the same behaviour, and it is
not forced, so it takes a rule to predict.

One 0xB0 byte record lives at 0x02140484: a halfword, three 0x34 byte entries
at +0x04, and five scalars in the tail at +0xA0, +0xA2, +0xA4, +0xA8 and +0xAC.
Five distinct words appear in the literal pools of the functions that touch it:

```
0x02140484   the symbol, +0x00
0x02140488   +0x04    &entries[0]
0x02140504   +0x80    the base for the four fields at +0xA0..+0xA8
0x02140524   +0xA0    the base for the byte at +0xAC
0x02140534   +0xB0    an address taken just past the record
```

0x02140504 and 0x02140524 are ten and two words apart and both reach the same
neighbourhood, which invites the reading that they are two objects. They are
one. The rule is

```
pool word = symbol + (field offset & ~reach_mask)
immediate = field offset & reach_mask
```

with `reach_mask` 0x7F for `ldr`/`str`, 0x3F for `ldrh`/`strh` and 0x1F for
`ldrb`/`strb`, which are exactly the ranges
`docs/idioms/thumb-immediate-reach-costs-an-adds.md` tabulates. So

* the `strh` at +0xA0 and +0xA2 and the `str` at +0xA4 and +0xA8 all mask down
  to 0x80 and share the one pool word 0x02140504 with immediates 0x20, 0x22,
  0x24 and 0x28;
* the `strb` at +0xAC masks down to 0xA0 instead, because 0x2C does not fit a
  byte immediate, and gets its own pool word 0x02140524 with immediate 0xC;
* the `ldr` at +0x04 in `sub_02006650` masks down to 0, so that function's pool
  word is the bare symbol 0x02140484 and the instruction is `ldr r1, [r1, #4]`.

The masking is per access, not per function and not per base register, so one
function can hold two pool words that differ by 0x20 and mean the same object.

Why it is worth a file rather than a sentence: the choice decides whether the
range can be matched at all. `attest()` is applied to the *symbol* address the
relocation names, not to `symbol + addend`, so declaring five objects means
five addresses that each need a witness outside the compared range, and here
0x02140504, 0x02140524 and 0x02140534 are each named by pool words that are all
inside this one packet. Declared as one symbol at 0x02140484 there is a single
address to attest, every other pool word is an addend the resolver computes,
and the two witnesses the image does have, 0x020065C0 and 0x02006670, are
enough to carry four files.

The same reasoning runs backwards when reading a listing: two pool words whose
difference is a small multiple of 0x20 are one object, and the gap between them
tells you the width of the access that forced the second one.
