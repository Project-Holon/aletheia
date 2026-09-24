# Wave 19, lane backup_fresh (19E)

0x02031FE0 (backup_system.c, ARM, 1704 bytes): 9 -> 0 bytes out, EXACT.

What moved it: two changes to the wave-12 source, both required.
- `unsigned long AB;` in place of `u32 AB;` (the A + B record-end sum).
- Loop-local declaration order AB, pa, pb, i, A, B (was B, pa, pb, AB, A, i).

The order alone with u32 AB gives 22; ulong AB with the old order gives 13
(a three-register rotation). The permuter (anneal, --types, budget 2000,
seed 2501) started from the ulong-AB source and found EXACT; I minimised its
result by hand to these two changes. The earlier 720-order sweeps all used u32 AB, which is
why they missed it. The allocator's real prototype (u32 heap, u16 tag, an
explicit (u16)heap at the call) is filed, as wave 13 asked. It is EXACT with
either prototype.

Measurements (25 hand, all 1704 bytes): 10 self-assignment placements
(`B = B;` / `AB = AB;`), all 9; long on A/B/AB in all 7 combinations (9, 13 or 31); B as
a one-element array 22; B/AB as a local struct 22; B block-scoped 22; AB
block-scoped 9; the operand order of the compares, two spellings, both 9. All are recorded in
the note.

Files written:
- src/matched/func_02031FE0.c (new, status EXACT)
- docs/notes/pkt_02031FE0.c.txt (wave-19 section appended)
- docs/idioms/a-long-index-colours-apart-from-an-int.md (wave-19 paragraph
  appended: when long moves a swap without closing it, sweep the declaration
  order again with the long type in place)
- layout/matched/arm9/pkt_02031FE0.json (rewritten by manifest --verify)

Shards verified: pkt_02031FE0, manifest --verify twice (1 rewritten, then 0).
Both entries in the packet are EXACT.

Seeds: none noticed.

Integrator: stage src/matched/func_02031FE0.c and
layout/matched/arm9/pkt_02031FE0.json, then update the coverage figures and
the README milestones.
