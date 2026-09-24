# Wave 19, lane strtold_3 (19L)

0x02094B8C (MSL __strtold, ARM, 3864 bytes): 90 -> 62 bytes out, DIFF (size exact).

What moved it: three changes to the 19F best source, all needed together
(alone: 82, 90, 90):
- `unsigned long ui = 0;`, a redundant initialiser at the declaration (the
  tail loop still does `ui = 0`). The dead entry def keeps ui live across the
  scan loop, so it is coloured early and takes r2 as in the image. `ui = ui;`
  anywhere in the scan loop before hex_frac_digit_loop is equivalent.
- `if ((chindex = ++ui) != 0)` in place of `ui + 1`.
- p block-scoped and initialised in the hex branch:
  `unsigned char *p = (unsigned char *)&hexresult;`.
Now ui r2 and chindex r5 match in the first part. The residue is the same
tail instructions with p in r3 (image r4) and uch in r4 (image r3); the
second loop and swap loop follow from that.

Flat or worse (as the brief listed): the 720-order declaration sweep with
ulong ui/chindex (all 90); while loops (90); doubled entry guard (90 or
3872); hexresult at function scope (frame moves, reverted); const p
(illegal), `*const p` (90); `*chptr--` (119). The permuter (tools/permuter.py
anneal --types, 2000 compiles, seed 3101) parses this file once the
multi-line #defines are joined into one line each. It found 62. I minimised
its result with subset sweeps. 25 measurements in all.

Files written:
- docs/notes/pkt_02094B8C.c.txt (19L section, all measurements, new
  best-source marker; the source was re-extracted from the note and checked
  at 62)

Shards verified: none (not exact).

Seeds: none noticed.

Integrator: nothing to stage besides the note. Still MATCH-capped at exact
bytes (__double_huge, two anonymous pool words). Next lever: a permuter run
from the 19L source with --focus p,uch. The redundant-initialiser effect
(a dead def that makes a web span a loop) may deserve an idiom if it closes
something elsewhere.
