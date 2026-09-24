# Wave 21, lane B2: 0x02016C60 (mcss.c)

Verdict: EXACT* from `match.py one` (dsi/1.1p1, 870 bytes; the 872-byte listing extent includes
2 pad bytes). It was DIFF 16. The shard was verified twice: both runs gave EXACT*, and the second
rewrote nothing.

## The lever

Read w2 raw into the guard and shift it later. The pass-2 header then follows pass 1's order, and
the h2 split is no longer needed:

    w2 = R->f2c;
    if (w2 != 0) {
      sx2 = R->f34 >> 12;  sy2 = R->f38 >> 12;  w2 >>= 12;
      h2 = (R->f30 >> 12) << 1;  i2 = 0;  y = 0;

The raw w2 web spans the sx2/sy2 reads, and it is coloured before the record pointer. The pointer
therefore lands in r1. The two zeros come last, so each takes r0 as in the image, and sx2 and sy2
share r3. I wrote this up as a new idiom file,
docs/idioms/a-guard-read-raw-into-its-local-and-shifted-later-pushes-the-pointer-off-r0.md.

## Measured (about 90 compiles, no permuter; every spelling and its result is in the notes)

- Enum-typed zero for i2, y, or both, at every header position: 16 to 31. The copy is coalesced
  into i2's spilled definition, so the zero never forms a web of its own.
- Loop-carried copy on i2++ or y += step: 16, or 872 bytes when the tail order changes.
- Natural order without the w2 split: 32. The zeros are right, but the pointer is in r0.
- `w2 >>= 12` swept through the natural order, then all 24 orders of {h2, sx2, sy2, shift}:
  EXACT* for sx2, sy2, shift, h2. The next best are sy2, sx2, shift, h2 at 4 and h2, sy2, shift,
  sx2 at 12.

## Files written

- src/matched/func_02016C60.c (house header, status EXACT)
- layout/matched/arm9/pkt_02016C60.json (written by `manifest --verify --shard pkt_02016C60`)
- docs/notes/pkt_02016C60.c.txt (new dated section appended)
- docs/idioms/a-guard-read-raw-into-its-local-and-shifted-later-pushes-the-pointer-off-r0.md
- this report

The docs/MATCHING.md idiom index is now stale. The integrator regenerates it with
`match.py idioms`. The follower at 0x02016FC8 comes after the 2-byte pad, which is why the verdict
has the `*`. No other decompilation or reconstruction was consulted.
