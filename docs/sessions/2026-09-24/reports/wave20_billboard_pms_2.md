# Wave 20, lane billboard_pms_2 (20K)

Seeds used: 4801 (0x0204EEC8), 4802 (0x0202E1F0).

| address | before -> after | verdict | what moved it |
|---|---|---|---|
| 0x0204EEC8 | 14 -> 0 | EXACT | `dst->f04 = 1 << (sb + 3)` written after the three table stores (f14, f18, f1c). Every earlier store sweep held f04 first. The sb field, sb + 3 and the constant 1 then colour ip / lr / r5 as the image. Inert (all 14): sb + 3 declared before sb in a block, a `one` local with one or two uses, in any declaration order, and the size-table load before sb. Permuter 800 found 11 only through an uninitialised local, which I discarded |
| 0x0202E1F0 | 2 -> 2 | DIFF | nothing. Extra uses of o that the optimiser deletes (duplicate stores, up to five in loop 1) are all 21: the use count is taken after dead-store elimination. Other attempts: a union alias at the g call 30; an unsigned long prototype for func_02024368 21 with w and 2 with the void * copy; an unsigned long copy 21; a fresh unsigned long local for &ws 374. Permuter 800 (seed 4802, from the 21 source) found the wave-19 copy again (2) |

Files written:
- src/matched/func_0204EEC8.c (EXACT, 5 of 5 relocations)
- layout/matched/arm9/pkt_0204EE0C.json (written by manifest --verify: one new entry)
- docs/idioms/a-store-moved-below-the-table-loads-recolours-its-operands.md
- docs/notes/pkt_0204EEC8.c.txt and docs/notes/pkt_0202E1F0.c.txt (new wave-20 sections with every measurement; pms best source unchanged)
- this report

Shards verified: pkt_0204EE0C, `manifest --verify --shard` run three times. The first pass added the entry, the next two rewrote 0. All 5 entries are EXACT.

Seeds (unlabelled starts): none noticed.

Integrator: stage the five files above. Exact coverage gains one function (144 bytes). Rebuild the idiom index. For pms_draw, the o/w colouring flips only when the g call does not read w, and that same condition makes the copy fold to &ws. No code-free use-count change reaches the allocator.
