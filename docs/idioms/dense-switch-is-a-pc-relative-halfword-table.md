# A dense switch is a PC-relative halfword table, and the table lists the cases

summary: a `cmp`/`bhi` followed by `add r1, pc` / `ldrh` / `add pc, r1` is an
ordinary C switch, and the table of signed halfword displacements says exactly
which case labels the source had and which it did not.

Found in: `src/matched/unit_0200ADB8.c` (0x0200AE54, 0x0200AEE8, 0x0200B078,
0x0200B110, 0x0200B214, 0x0200B254)

For a switch over a contiguous range mwccarm emits a nine-instruction preamble
and then a table of signed halfwords immediately after it, in the same section:

```
cmp  r1, #0x16          /* the highest case label */
bhi  .default
adds r1, r1, r1         /* index * 2 */
add  r1, pc             /* the table is at pc + 6 */
ldrh r1, [r1, #6]
lsls r1, r1, #0x10      /* sign-extend the halfword */
asrs r1, r1, #0x10
add  pc, r1
.hword  0x2C, 0x2E, 0x32, ...
```

The two PC reads are four bytes apart and both are the Thumb `pc + 4`, so the
table base is `&(add r1, pc) + 4 + 2` and a displacement `d` selects
`&(add pc, r1) + 4 + d`. `disasm.py` classifies the table as data, so all of
this arrives in the listing as a run of `.word`s with the case bodies
following; the bodies decode as Thumb, the table does not.

Nothing special is needed to reproduce it. A plain

```c
switch (id) {
case 0:  v = p->unk00; break;
...
case 22: v = p->unkBB; break;
}
```

produces the preamble, the table and the bodies byte for byte, in source order,
at `-O4,p`. Six of them in one file came out EXACT on the first attempt.

The table is the useful part, because it is the case list. Every entry that
points at the function's common exit is a case label the source did **not**
have: the range `0..22` is set by the `cmp`, and in `func_0200AE54` entries 9,
10 and 14 point at the exit while the other twenty point at real bodies, so the
source has twenty case labels and three gaps. Guessing empty `case 9: break;`
arms instead produces the same table and the same bytes here, but the gap
reading is the one that matches what those three ids turn out to be elsewhere
in the file: not scalars at all, but the three bitmaps a different function
tests.

Two neighbouring traps:

* the range check is on the *switch value*, not on a case body. `cmp r1, #0x16`
  / `bhi` is the compiler's, and writing a `if (id > 22) return;` guard in the
  source adds a second compare.
* a switch whose function has no `return` after it leaves the default arm as a
  bare `bx lr` with a garbage result. `func_0200B078` does exactly that and
  returns its incoming pointer for an unknown id. Adding `return 0;` to make
  the C well formed adds an instruction and shifts every case body, so the
  missing return is part of the match.
