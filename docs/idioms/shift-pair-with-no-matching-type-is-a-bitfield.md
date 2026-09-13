# A shift pair whose width is not an integer type is a bitfield, because every mask spelling folds back to `ands`

summary: `lsls #8` / `lsrs #8` on a loaded word cannot be written as a mask
or as two shifts, both of which this compiler turns into a pool word and an
`ands`; only a 24 bit unsigned bitfield survives to the shift pair.

Found in: src/matched/unit_020064B8.c (0x020064CC)

docs/MATCHING.md already records that `lsls #16` / `lsrs #16` is what a
conversion to `u16` looks like and that `& 0xFFFF` gives `movs` / `ands`
instead. The 24 bit case looks like the same finding and is not, because
there is no 24 bit integer type to convert to. The original is

```
ldr  r0, [r0]
lsls r0, r0, #8
lsrs r0, r0, #8
blx  #0x207466c
```

and both of the obvious spellings produce the same six bytes as each other
and not these four:

```c
func_0207466C(*p & 0xFFFFFF);     /* ldr r0,[pc,#..] ; ands r0,r1 ; + pool word */
func_0207466C(*p << 8 >> 8);      /* the same: the two shifts are folded into the AND */
```

The second one is the surprise. Writing the shifts out by hand does not
preserve them: the optimiser recognises the pair as a mask and re-materialises
0x00FFFFFF, which costs a literal pool word the original does not have.
Breaking the expression into two statements over a `u32` local does not help
either.

What does reproduce it is declaring the field:

```c
struct Head {
    u32 unk00 : 24;
    u32 unk03 : 8;
};

func_0207466C(p->unk00);
```

A bitfield extraction is generated as the shift pair directly and is never
re-derived as a mask, so the pair survives.

The general rule: a `lsls #n` / `lsrs #n` pair is a type conversion when `32 -
n` is 8, 16 or 32, and a bitfield when it is anything else. The second case
is a statement about the *declaration* of the object being read, which is
worth more than the value it computes: 0x02074450 returns a pointer to a
structure whose first word is packed, and that is only visible here.
