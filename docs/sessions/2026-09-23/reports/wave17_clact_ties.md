# Wave 17, lane 17C (clact_ties): clact.c and pkt_0206EB00 near misses

EXACT 1 / MATCH 0 / DIFF 9.

Per address, bytes out before -> after:
- 0x0206FC5C: 8 -> 0 EXACT (../2.0/sp2, sp2p2 the same). The two key arrays as pointer locals computed once (`oa = (s16 *)((u8 *)h + h->f0c)`, NitroSystem's pArrayRot3/9) instead of u32 offsets, then a 200-order declaration sample (several orders EXACT). src/matched/func_0206FC5C.c.
- 0x02069BA0: 14 -> 6 without volatile. Arms swapped (`have < n` refill arm first) fixes the then-arm pair; with the wave-16 `volatile Bits *b` device it is EXACT (not filed). Left: `mov r2, #8` / `mov r1, r6` order. 720 declaration orders and anneal seed 1701: 6.
- 0x0204B49C: 20 -> 13 (76 against 80). The image keeps value in one web from parameter to call; `o = value; if (...) o += origin.x; else o += origin.y;` fixes the parameter homes, the final copy is still elided. Anneal seed 1705: only an invalid ret-var point.
- 0x0206ECE0: 14 -> 14. Identified as the NNS joint-rotation fetch (pivotUtil_[][4] as one 2D table); NNS-shaped source recorded, same 14; 400 declaration orders flat.
- 0x0206F4C8: 7 -> 7 (y-pair spellings; anneal seed 1702).
- 0x0204A7A0 37, 0x0204A6C8 4, 0x02051C88 19 (all 720 orders), 0x02071104 6, 0x02067080 2: unchanged, levers recorded.

Files written: src/matched/func_0206FC5C.c; docs/idioms/array-bases-as-pointer-locals-reopen-a-flat-declaration-order.md; notes appended (best-source markers): func_02069BA0, sub_0204B49C, sub_0204A6C8, func_0204A7A0, pkt_02051C88, pkt_02071104, pkt_02066E30, pkt_0206EB00, pkt_0206F4C8.

Shard verified: pkt_0206EB00 (13 entries), final pass 0 rewritten. Already committed in e1ec86d.

Seeds used: 1701 (9BA0), 1702 (F4C8), 1705 (B49C). No new unlabelled starts seen.

Integrator: run `python tools/match.py idioms` (new idiom). docs/families/cluster_0206EB00.h still lists 0x0206FC5C with offset (not pointer) key tables: update the prototype or comment. tools/match.py was mid-edit once during this lane (a transient syntax error); all measurements are from after it parsed again.
