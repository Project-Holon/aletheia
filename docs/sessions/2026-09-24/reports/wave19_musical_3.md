# Wave 19, lane musical_3 (19P)

0x0200CA98 (musical_dist_save.c, Thumb, 392 bytes): 147 -> 114 bytes out, DIFF.
The instruction score (permuter --explain) went from 2310 to 1580.

What moved it:
- The form-loop mask is a named s32 `m = (1 << (x & 7)) ^ 0xFF`, computed
  before `o = x >> 3`. With this, the loop body comes out in the image's
  instruction order, with x in r2 and the mask in r5.
- `unsigned long j` (the long recipe, applied to the form-loop index). With
  it the table walk is exact, including the home-store order (id before sel)
  and acc in r1.
- `u8 cnt` (found by the permuter). This one is a scoring artefact: it adds a
  `lsls/lsrs #0x18` pair that the image does not have, and it drops a p
  reload to pay for it. The note flags it.
- A named `base = p + 0x1AC` before `off`, with the two 0x1AC arms written
  through base. This puts the tail preheader in the image's order, but it
  costs 2 bytes through colouring, so it is not in the 114 source. It is
  recorded as the image-shaped alternative: 388 bytes, score 1660.

No effect:
- The dying-local lever: writing into a dying local produced byte-identical
  code (mwcc gives every definition its own web).
- The long declaration-order sweeps (long i, long acc, 720 orders each):
  every order gave 147 or 152.
- A narrow clear-loop counter: 396.
- Lever 4 does not apply: the function makes no calls.

31 measurements. One permuter run (anneal, --types, seed 3501). I stopped it
at 1761 compiles when I moved to a better starting point, and did not rerun
it.

Files written:
- docs/notes/pkt_0200CA98.c.txt: a dated wave-19 section with every
  measurement, the image register map by block against the best compile, the
  best source (114) and the image-shaped alternative.
- this report.

Shards verified: none (not closed).

Seeds: none noticed.

Integrator: nothing to stage except the note. Next lane: start from the
image-shaped alternative (without u8 cnt). The two remaining colour swaps are
row1 against {x&7, o} in the form loop, and y in r0 where the image has r4 in
the tail. Each swap also removes one instruction.
