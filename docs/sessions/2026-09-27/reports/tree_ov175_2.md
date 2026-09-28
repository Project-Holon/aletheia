# tree_ov175_2 report (relaunch, 2026-09-28)

## Salvaged from the cut run (re-verified; shards verified twice, second pass 0 rewritten)

- src/matched/func_021D9F04.c + layout/matched/ov175/pkt_021D9F04.json: EXACT*. Closed by an enum-typed result local (existing idiom an-enum-typed-zero-keeps-its-own-web...). Note marker added.
- src/pending/func_021D9C34.c now verifies EXACT* (0x021E8844 got its label): promoted to src/matched/func_021D9C34.c + new shard pkt_021D9C34. Lever: final state test is a switch.
- src/pending/func_021D7E18.c (root): MATCH* (0 concrete bytes). Six call sites stay wildcarded on unlabelled leaves outside my territory: 0x021E8AB4 x3, 0x021E8AB8 (ov177), 0x02156F50 (ov009), 0x02009EC8 (arm9). Blocker text updated.
- src/pending/func_021D965C.c: MATCH. Blocked by unlabelled arm9 leaf 0x0200DFD8 (x3).

## New work

- 0x021D98E4: still DIFF 6. The residue is register allocation only. New brute forces (listed in the note) and none closes it.
- 0x021DA6B8: the tool no longer refuses it. It measures DIFF, 1776/1780, 1102 bytes out, most of that cascade from the 4-byte shortfall. Residues unchanged. It needs a fresh draft, which I did not attempt because of the context budget.
- ov172 0x021BC7FC: fresh draft, DIFF 35/908. Levers are in the note. Two residues: early-materialised `same = 1` (8 bytes) and an i/j register swap in the removal loop (27 bytes). Permuter seed 8801: no gain.
- ov172 0x021BBF2C (1724 bytes): not started.

## Files

Notes: docs/notes/pkt_{021D98E4,021DA6B8,021D9C34,021D9F04}.c.txt (appended), docs/notes/pkt_ov172_021BC7FC.c.txt (new). manifest --check clean.

## Integrator

- Seeds (labels would lift root 0x021D7E18 and 0x021D965C to EXACT*): 0x021E8AB4 (ov177, `str r1,[r0,#0xc]; bx lr`), 0x021E8AB8 (ov177), 0x02156F50 (ov009), 0x02009EC8 (arm9 thunk), 0x0200DFD8 (arm9).
- 0x021DA6B8: 0x021DC2D8, 0x021DADB4 and 0x021DAE00 are matched ov175 functions, but the resolver still reports "no witness outside" for them, even with an ov175 hint.

## Next lane

ov175: 021DA6B8 (fresh draft), 021D98E4. ov172: 021BBF2C (fresh), 021BC7FC (35 bytes, start from the note). Permuter seeds used: 8801.
