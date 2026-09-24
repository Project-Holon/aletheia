# Wave 21, lane D3: 0x02048744 (g3d_util.c, 468 bytes), what lifts the outer counter

**Verdict: DIFF 14, unchanged.** Best source is still the wave-16 long source in
`docs/notes/pkt_02048330.c.txt` (re-verified at the start: 468/468, 14 out, 9 of 9
relocations, resIdx sb / i r7 against the image's r7 / sb). 87 compiles, no permuter,
stopped at the integrator's wrap-up call.

## What is new

1. **Only a sign-extended narrow counter rises.** D2 read `short i` as "narrowness";
   measured with ranks, `short`, `signed char` and `char` i all give the image ranking
   (i sb > tbl/j r8 > res r7, 476/45), while `u8` i (472/60) and `u16` i (476/86) fall to
   the bottom band exactly like `long`. A `union {long; short}` counter ranks as long.
2. **The EXACT sibling 0x02048330 as a probe.** Its `int i, j` keeps i in sl only because
   of its two `util->objStat[objIdx + i] |= n` statements: removing either one drops i to
   r8; with `long i, j` it still keeps sl. So two real extra uses of i (ldrb/strb pairs)
   outrank an int j and beat the long penalty. Every codeless way of adding a reference
   to i in this function (self-assignments, `i * 0`, `i - i`, `i & 0`, `i + 0`, dead
   conditionals, unused inline parameters carrying i, increments through inline helpers
   by pointer or by value, cross-type copies of the increment, every do-while/while
   form of either loop) is folded before costing: 18 on the int base, 14 on the long base.
3. **Webs are per variable.** Reusing `tex` for `rnd` (both r4 in the image) or `mdl`
   for `anm` (both r5) changes nothing in the instructions but reallocates the whole
   callee-saved set (42/25 int, 49/21 long). This is the only lever that moved the pair
   at 468 bytes; it moves r4-r6 with it.
4. Types of the short-lived webs (mdl/tex/rnd/anm/a as u32/long), parameter types
   (int/u32/long/short unitIdx and heapID), and `const` on os are inert. `const` on
   `setup` is required (476/355 without it).

Reading: the ranking behaves like a priority of cost over degree. A zero-extending
truncation adds an interfering temporary and drops i; two real uses lift it; a
sign-extended narrow web is costed as if its reloads were dearer. Nothing 32-bit and
codeless raises i above an int j.

## Files touched

- `docs/notes/pkt_02048330.c.txt`: appended "2026-09-24, wave 21 (lane D3)".
- `docs/sessions/2026-09-24/reports/wave21_laneD3.md` (this report).

Nothing filed in `src/matched/` or `src/pending/`; no shard written (no EXACT or
MATCH). Scratch in /tmp/aletheia_laneD3/w (`log.txt`, one line per compile with the
register readout). No outside decompilation or reconstruction was consulted.
