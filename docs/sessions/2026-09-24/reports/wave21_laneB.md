# Wave 21, lane B: 0x02016C60 (mcss.c)

Verdict: DIFF 16, 870 bytes against the 872-byte listing (2 of them pad), dsi/1.1p1. It was DIFF 29
(27 with wave 20's best header order).

## The lever

Split h2 across the pass-2 header:

    w2 = R->f2c >> 12;  h2 = R->f30 >> 12;  sx2 = R->f34 >> 12;  i2 = 0;
    sy2 = R->f38 >> 12;  h2 <<= 1;  y = 0;

The first h2 web now stays in a register across the sx2/i2/sy2 statements. It is coloured before the
record pointer, so the pointer goes to r1 (`adds r1, r1, r0`) and the sx2 temporary to r3, which is
what the image does. This is the first measurement in five waves that moved the pointer's register.
+0x1D0..+0x1E8 now matches the image.

## Residue

16 bytes, +0x1EA..+0x1FE, the tail of the header. i2's zero sits inside the h2 web, so it takes r3,
and sy2's load takes r1 (the dying pointer's register). The image has both zeros in r0 and sy2 in r3.
Every order that moves `i2 = 0` below `h2 <<= 1` loses the pointer colouring again.

## Measured (about 300 hand compiles plus 3935 permuter compiles; all listed in the notes)

- Chained zeros: 30-32.
- char / signed char / u32 casts on the record sum (42 compiles): flat.
- Named pointer: flat.
- Pass-2 outer loop as a `for` loop: 31-33.
- h2 split in 8 orders: 16-81; the late half spelled four ways: all 26.
- 24 + 96 statement-order permutations: best 16.
- sx2 split: 16-29. sy2 split: moves the frame, 154-488.
- Shared sx2/sy2 temporary through 7 locals: 16 (copy propagated).
- w2 through the guard: 16.
- 64 self-assignments: all 16.
- Permuter, run through a scratch-only wrapper that sets the target extent to 870:
  - from the 27 source, anneal, 935 compiles (stopped early): flat.
  - from the 16 source, anneal `--types`, 3000 compiles: flat at 16.

No front-end re-sweep: wave 20 already measured every dsi build, and there is no byte evidence for a
pin.

## Files touched

- docs/notes/pkt_02016C60.c.txt (appended a dated section, with the 16-byte best source)
- this report

No source file was filed and no shard was written, because the verdict is DIFF. No other
decompilation or reconstruction was consulted.
