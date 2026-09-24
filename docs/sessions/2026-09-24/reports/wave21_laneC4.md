# Wave 21, lane C4: 0x02067080 (g2d DoAffineTransforme_)

**Verdict: DIFF 2, unchanged.** I re-verified the wave-13 source in `docs/notes/pkt_02066E30.c.txt`
with `match.py one` under `../2.0/sp2`: 704/704, 2 bytes out. The y read at +0x21C lands in
ip, where the image has r6. No spelling measured in this lane beats 2.

## What was done (about 72 compiles)

- **Probes.** 7 probe files holding 44 functions, compiled with the exact match.py command
  line, in `/tmp/aletheia_laneC4/p`.
- **Variant TUs.** 7 TUs of the whole function, each variant a renamed copy with its own
  adjust inline, scored instruction by instruction against the image.
- **Verification.** Every target spelling that is reported was re-run through
  `match.py one`: 47 spellings, plus the base and item 1.
- **Diagnostics.** 2 compiles under `-proc` arm7tdmi/v4, and a scratch colouring simulator.

The notes section "2026-09-24, wave 21 (lane C4)" lists every probe and every spelling with its
bytes-out figure.

## The allocator model

These rules come from the probes.

1. **Visit order is the reverse of web creation.** Creation follows the source (IR) order,
   not the final instruction order. In p15d a short web sits between two blocks: the later
   block is coloured before it, the earlier block after it.
2. **The colour is the first free register in a dynamic list:**
   r0-r3, then the callee-saved registers already given to an earlier-coloured web
   (ascending), then ip, lr, then fresh callee-saved (ascending).
   - p14c, p15a and p15c: a short web takes r4 over a free ip once a later block used r4.
   - This is why lane C3 saw "lr, ip, r3": it is r3, ip, lr handed out in reverse visit order.
   - It is also why the first block and MulMtx22 never touch ip or lr.
3. **In mla/mul, rd never equals rm; rd may equal rs or rn.** The operand slot does not decide
   which freed register a following load takes. The list does (p10, p11, p16). This answers
   lane C3's suggested probe.
4. **A store decides a local's creation point.**
   - A single-use local read with no store before its use is re-created at the use, so it
     gets a late index.
   - A store in between keeps the early index, while the scheduler still sinks a stack
     load to its use.
   - That is item 1's mechanism. The split point is the x store, not the `_01` load
     (B2: y read before `_01` but after the store still gives ip).
5. **Scheduling runs before allocation as well as after.** A `-proc v4` diagnostic shows the
   near-source order, including `cmp r4` sitting next to `moveq`.

## What the model says about the target

These rules reproduce the base (y ip, dy1 r7), item 1 (y r6, dy1 ip), and the swapped-slot
spellings F1/F2 exactly. F2 was predicted before it was compiled: dy1 r6, y r7.

For the image's pair (y r6, dy1 r7), the model needs two things at once:

- r6 already handed out when y is visited. Item 1's early read supplies this.
- ip barred, or r7 already handed out, when dy1 is visited. Nothing supplies this:
  - every r7 web is created before dy1;
  - nothing after dy1 holds r7 or ip in the image.

So no ordering of the image's own instructions produces it under these rules. This agrees with
lanes C2 and C3, now derived from the list rule.

One spelling does make dy1 skip a free ip: C4, where dy1 is defined before the x store and used
after it. It gives y r6 and dy1 r7, the image's pair. But `_01` and dy0 then live across the
store (r8/r9), which costs 76 bytes.

## Negative results

- A whole-function Chaitin simulator (`sim.py`, `fit_t.py`) with rules 1-3 still mismatches
  64 of 116 webs. The misses are mostly the long, high-degree webs, so a callee-saved
  preference for long webs is the missing piece.
- `restrict` on pM changes nothing (2). On pV the output grows to 712 bytes.
- Late hw/hh consts are CSE'd, and a self-store barrier does nothing.
- No compiler pass was seen deleting a recomputation after allocation.

## Files touched

- `docs/notes/pkt_02066E30.c.txt`: one appended section, "2026-09-24, wave 21 (lane C4)".
- `docs/sessions/2026-09-24/reports/wave21_laneC4.md`: this report.

Nothing went to `src/matched/` or `src/pending/`, and no shard was written, because nothing
reached MATCH or EXACT. `tools/` and `layout/` are untouched. Scratch is under
`/tmp/aletheia_laneC4`.
