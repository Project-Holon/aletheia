# Wave 21, lane D: 0x02048744 (g3d_util.c, 456 code bytes)

**Verdict: DIFF 14, unchanged.** The best source is still the wave-16 long source in
`docs/notes/pkt_02048330.c.txt`. Re-verified today by `match.py one`: 468/468 bytes,
14 concrete bytes out, 9 of 9 relocations resolved. The residue is the same single swap:
resIdx is r7 in the image and sb in the compile, and i is sb in the image and r7 in the compile.

## What was tried (all new, none repeats a documented spelling)

About 190 manual compiles, plus one permuter run:

- **Dead-parameter lever:** unitIdx reused as the loop counter (long, int, u32, u16), 472/404
  and 480/406. This is the only variant that puts i in sb, and it pays a `mov sb, r1`
  coalescing copy. resIdx computed into the dead unitIdx, 480/410 and 472/388.
- **Inline helpers against open-coded reads:** all 31 subsets of the five getRes/useRes
  sites. The getRes sites are inert (14); open-coding a useRes site gives 35 or 472.
- **Statement order:** the unit reads and `i = 0`, all 24 orders, with long and with int.
  Floors 14 and 18.
- **Casts:** (int) or (long) on i at each subset of its four uses. Flat at 14 and 18.
- **Front ends**, as a diagnostic probe only: dsi/1.1, 1.2p1, 1.2p2, 1.3, 1.3p1, 1.6sp1 and
  1.6sp2 all give 14 with the same pair. ../1.2/sp2, ../1.2/sp4 and ../2.0/sp2p4 give a
  different size. This is not a pin question.
- **New inline-helper structure:** getTex 14; createAnm 42 (a wider rotation); a whole-object
  createObj 480.
- **Loop spellings:** `objCount > i`, `++i`, `i += 1`, and inner `>`. All flat.
- **objIdx and objCount types:** 34 new combinations. Floor 14.
- **Block scoping:** per-object locals in the loop body 47; i in a block 25; resIdx in a
  block 472.
- **Permuter:** `tools/permuter.py --mode anneal --types --budget 5000 --seed 9021`, starting
  from the long source. Best 14, no improving mutation. The previous maximum budget on this
  function was 2000.

## Best bytes out

14 (unchanged).

## Files touched

- `docs/notes/pkt_02048330.c.txt`: appended the dated section "2026-09-24, wave 21 (lane D)".
- `docs/sessions/2026-09-24/reports/wave21_laneD.md` (this report).

Nothing was filed in `src/matched/` or `src/pending/`. No shard was written.
Scratch work is in /tmp/aletheia_laneD.
