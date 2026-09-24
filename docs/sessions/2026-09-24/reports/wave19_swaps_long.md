# Wave 19, lane swaps_long (19G)

Recipe: long on one swapped variable at a time, an order sweep with the long in place (script: one
`match.py one` per order), then one permuter anneal --types at 2000 from the long source. Seeds
2701 to 2706.

| address | before -> after | verdict | what moved it |
|---|---|---|---|
| 0x02048744 | 14 -> 14 | DIFF | nothing: ulong i 17, ulong j 16, ulong resIdx (with the helpers) 58; six 720-order sweeps floor 14; permuter 25 |
| 0x0202E1F0 | 21 -> 2 | DIFF | `unsigned long w` (the reused stack parameter) plus a copy `wp = (void *)w;` before loop 1, passed to func_02024368. Each alone is 21. Found by the permuter and cut down by hand. Residue at +008E: the copy is folded to &ws, where the image passes r7 |
| 0x0202173C | 33 -> 33 | DIFF | nothing: long/ulong a, i, keep, done; sweeps flat; permuter 33 |
| 0x02021848 | 33 -> 33 | DIFF | nothing: permuter 31 only with a volatile d and u8 keep (rejected) |
| 0x0209D7D4 | 43 -> 43 | DIFF | nothing: long count, zero local, callee param, handle; 24-order sweep 43; permuter follows the 76-byte extent |
| 0x0204EEC8 | 58 -> 20 | DIFF | long has no effect here. A full 720-order store sweep (f06 after the table loads) gives 56, `u32 st` (permuter) 21, and a second sweep with u32 st 20. Residue: a prologue register rotation, 5 of 5 relocations |

Files written:
- docs/notes/pkt_02048330.c.txt, pkt_0202E1F0.c.txt, func_0202173C.c.txt, func_0209D7D4.c.txt,
  pkt_0204EEC8.c.txt: a dated wave-19 swaps_long section with every measurement. The new best
  sources for 0x0202E1F0 (2) and 0x0204EEC8 (20) are appended.
- docs/idioms/a-long-index-colours-apart-from-an-int.md (paragraph added: the long went on a reused
  pointer parameter and needed a copy)
- docs/idioms/a-masked-locals-declared-width-is-invisible-in-the-diff-and-decides-its-register.md
  (paragraph added: u32 st gives 148 bytes in the old store order and pays only after the reorder)

Shards verified: none (nothing is EXACT). Nothing filed in src/.

Seeds: none noticed.

Integrator: stage the five notes and two idiom files. No figures change. Two things for the next
wave. On 0x0202E1F0, find a spelling that keeps the copy's colouring effect without the copy being
propagated. When a sweep script scores 0x0204EEC8, it must penalise unresolved relocations, because
orders with the wrong pool order score lower.
