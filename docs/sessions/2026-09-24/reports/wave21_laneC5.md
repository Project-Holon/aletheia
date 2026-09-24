# Wave 21, lane C5: 0x02067080 (g2d DoAffineTransforme_)

**Verdict: DIFF 2, unchanged.** I re-verified the wave-13 source in `docs/notes/pkt_02066E30.c.txt`
with `match.py one` under `../2.0/sp2`: 704/704, 2 bytes out. The y read at +0x21C lands in
ip, where the image has r6. No spelling measured in this lane beats 2.

## What was done (about 45 compiles)

- **match.py one:** 20 runs.
- **Probe TUs:** 6.
- **Whole-function diagnostics:** 7 `-proc` compiles and 3 pragma checks.
- **Variant TUs:** 10, holding 478 renamed copies of the function, each scored
  instruction by instruction against the image.

Every spelling reported with bytes out was run through `match.py one`. The notes section
"2026-09-24, wave 21 (lane C5)" lists every spelling and probe.

## The allocator model, fixed

I rewrote lane C4's simulator (`/tmp/aletheia_laneC5/sim/sim2.py`). There were two bugs in it:

- Predicated `moveq`/`movne` pairs merged with an older web through a phantom use.
- Its listing had absolute branch targets, so the CFG had no branch edges.

Three new rules close the "long values take callee-saved early" gap:

1. **Chaitin sweep simplify.** Each pass walks the webs in creation order and removes every
   web whose degree is below K (K anywhere from 9 to 15 fits). A web that only drops below K
   after the sweep has passed it waits for the next pass. Long, high-degree webs therefore
   land in pass 2 and are coloured first. These are effect, halfW, halfH, the MulMtx22 pV
   pointer, hw12 and hh12.
2. **Multiply numbering.** A multiply result is numbered just before an operand that is
   loaded fresh inside the same expression. smull's hi half is numbered after lo.
3. **The two shift temporaries.** hw12 and hh12 have to be numbered lowest. This was fitted,
   not derived. Probes p32 and p33 show that an ordinary CSE'd or named shift keeps its source
   number, so the cause is still open.

Lane C4's list rule and its rd != rm rule stay as they were.

## Simulator accuracy (webs mismatched)

| Listing | Mismatched webs |
| --- | --- |
| `-proc v4` | 0/122 |
| `-proc xscale`, numbered from v4 | 0/122 |
| arm7tdmi | 24/122 |
| arm946e (the match.py build) and arm9tdmi | 35/122 |
| arm946e after a pre-allocation order search (annealed dependency-legal swaps) | 24/122 |
| Lane C4's `sim.py`, for comparison | 70/119 |

For arm946e the whole-function simulation clearly fails. Scheduling after allocation hides the
order the allocator saw. For example, `cmp r4,#0x300` is hoisted to +0x1FC, and +0x1BC takes lr
while no ip web is live there.

## What the model says about the residue

I enumerated all 5040 visit orders of the seven webs from +0x20C to +0x228 against every set of
callee-saved registers already handed out. The image pair (y r6, dy1 r7) needs one of two
things:

- **dy0 numbered above dy1.** The rsb would have to be created inside the mla's own expression,
  after the result is allocated. The IR serialises every such spelling away.
- **An r6 or r7 web coloured before the window.** In the image, every later-created web and
  every pass-2 web sits in r0-r5, ip or lr.

So the image's own instruction stream cannot give the pair under this model. That matches lanes
C2-C4, and it now follows from rules rather than a fixed order.

## Spellings (bytes out, 704 bytes unless stated)

- **dy through inline helpers:**
  - H1-H5: 2 each (the base residue, or the item-1 residue).
  - The `return acc + a*b` form: 700/168 on the base, 700/181 on item 1 (re-associated).
- **Assignment inside the dy expression:**
  - E1, E6, E7: 2.
  - E2-E5: 700/168 and 700/181.
- **Product split into a local `p`:** I swept all 448 dependency-legal orders of the eight
  statements. 23 orders stay at the 2-byte residue and none does better. Representatives:
  2, 2, 8, 76, 82, 100, 116.
- **Pragmas:** `#pragma scheduling off` and `#pragma peephole off` leave the output unchanged.
  The IR dump pragmas write nothing.

## Files touched

- `docs/notes/pkt_02066E30.c.txt`: one appended section, "2026-09-24, wave 21 (lane C5)".
- `docs/sessions/2026-09-24/reports/wave21_laneC5.md`: this report.

Nothing went to `src/matched/` or `src/pending/`, and no shard was written, because nothing
reached MATCH or EXACT. `tools/` and `layout/` are untouched. Scratch is under
`/tmp/aletheia_laneC5`.
