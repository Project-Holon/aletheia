# Wave 21, lane E4: blink_palanm 0x0202E1F0

Every verdict comes from `tools/match.py one` (dsi/1.1p1, -O4,p, Thumb). 35 hand compiles, no permuter.
Stopped early on the integrator's instruction.

## Result

| function | before | after | where |
|---|---|---|---|
| 0x0202E1F0 blink_palanm (412 B) | DIFF 2 | DIFF 2 | `docs/notes/pkt_0202E1F0.c.txt`, new dated section |

The residue is unchanged: +008E `adds r0, r7, #0` (image) against `add r0, sp, #0x38` (compile). The best
source is still the wave-19 one.

## What was measured

1. **Nine no-code o references** designed to survive the optimiser and vanish at code generation
   (a default-only `switch` on o, ternaries and `if/else` with identical arms, `o == o`, `o - o`, a
   store-forwarded re-read of `o->f00`, pointer algebra that cancels) all come out at 21 with o in r7:
   each is removed before costing.
2. **The backend's algebraic simplifier** does cancel `(o+0x20+i*4) - (o+0x20)` (an 8-byte
   `lsls/asrs` pair remains), but the cancelled o uses do not count either (o=r7). The form
   `o + (X - o)` is not simplified at all.
3. **Live-range length is not in the cost.** An extra tail call after w's range keeps o=r6.
4. **A single added plain w use anywhere after loop 1** (four positions) flips the pair, and is emitted as
   a register copy. **One loop-1 w use outweighs twelve plain uses**: with it removed, w is spilled until
   five or six plain uses are added back, and o stays in r6 with twelve. The order is a real cost
   comparison dominated by the loop uses; the residue is one plain unit, as lane E3 said.
5. A def of w inside loop 1 gives 360 out (o=r7); kept in B0 as well, w folds to the constant (408 bytes).

Not reached: web-structure probes on the bitfield tail, a test of whether w's entry web is costed
separately from its post-def web, and degree probes. The remaining unmeasured reference class is one
the allocator creates itself (a copy that survives coalescing, or a split of w's entry web).

## Files touched

- `docs/notes/pkt_0202E1F0.c.txt` (dated lane E4 section appended, every spelling with bytes-out and
  the o/w register)
- `docs/sessions/2026-09-24/reports/wave21_laneE4.md` (this file)

No source filed to `src/matched/` or `src/pending/`; no shard written (no EXACT or MATCH). `tools/`,
`layout/` and 0x0206DC00 untouched. No other decompilation or reconstruction was consulted. Scratch
files are in `/tmp/aletheia_laneE4`.
