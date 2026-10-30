# A Thumb mid-function pool goes at the last branch after the last new entry

summary: in a long Thumb function, mwcc 1.1p1 dumps the literal pool at the
last block that ends in an unconditional `b`, but only if no new pool entry was
added after that block. The trigger uses estimated sizes, not final sizes. A
pool that lands one block late (with a `b` over it and a pad) means the
estimate reached the trigger just after a new entry.

Found in: `src/game/ov006/event_wificlub.c` (EVENT_WIFICLUB_Main, Japanese
target, dsi/1.1p1, Thumb). Not closed: the Japanese pool sits at the end of
case 18; ours sits inside case 19 after `ldr r1` of the next overlay id.

## The rule (pool placement pass, 0x52C3B0)

- Offsets come from 0x52BCB0: each instruction has a fixed estimated size.
  `bcc` counts 6, `b` counts 4, `bl` counts 4, the rest count 2. Block
  alignment pads only blocks with flag 0x400.
- For every instruction while a pool is pending:
  `insn - (firstRef + 4) >= 0x3FC - 0x60` (0x39C) fires the dump.
- The candidate dump point is the last block that ends in `b` (op 0x97 or
  0x20E). Adding a NEW pool entry clears the candidate. Reusing an entry that
  is already pending does not.
- With a candidate, and if the pool still fits from there, the pool goes after
  that block. Without one, the pass forces a pool at the current point, with a
  `b` over it.

## How to read a residue

Final code identical, pool one block late: the trigger fired just after a new
entry was added. Compute the needed shift from the estimated offsets
(`firstRef` and the trigger instruction). The source must change the estimate
between the first reference and the trigger: one more `b` (+2 against the
final size) or `bcc` (+4) in the pcode, or a constant that is already in the
pool instead of a new one.

## Tool

A breakpoint script on 0x52C483 (insn offset in [ebx+0x24], first ref in edx),
0x52C644 (new entry), 0x52C4D3 (dump at the candidate) and 0x52C6E0 (forced)
prints the decision. Build it on tools/mwccdbg/common.py (FuncTracker, run).
