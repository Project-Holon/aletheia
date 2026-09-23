# Wave 12: game_beacon.c and pms_draw.c

Nothing committed. There are 6 new EXACT targets and 10 unlabelled leaves filed as witnesses, 16 functions in all. One target is parked as MATCH, two are documented DIFF, and one stays MATCH because nothing can attest its symbol.

## game_beacon.c (0x020266E0..0x020274C8)

| target | result | file | what closed it |
|---|---|---|---|
| 0x02026CE0/28 | EXACT* | src/matched/func_02026CE0.c (pkt_02026CE0) | The old MATCH park had misread the pool word as 0x02021440. The word is 0x02146940, which is g_GameBeacon, so the reference was always attested. I removed src/pending/func_02026CE0.c. |
| 0x02027060/36 | EXACT (under both 1.1p1 and sp2) | src/matched/func_02027060.c (pkt_02027060) | The table at 0x0209FC20 is a word of bitfields `{prio:8; frames:24}`. Reading `(u8)tbl[i]` stays 4 bytes out, the bitfield read matches. |
| 0x020274C8/38 | still MATCH (pending unchanged) | src/pending/func_020274C8.c | The ABS32 is 0xE7, an ov231 overlay-id symbol, and no other pool names it. A plain 0xE7 constant would compile to `movs`, so there is no C spelling that avoids the symbol. This is a wall. |
| 0x02027460/70 | EXACT | src/matched/func_02027460.c (pkt_02027460) | It is an unlabelled leaf. It takes the pointer local `o = &g->own` (which gives the two-step adds) and writes u16 bitfields `{lo:8;a:3;b:5}` at own+0x48, then +0x4a and +0x4c. |
| 0x02026A60/378 | EXACT* | src/matched/func_02026A60.c (pkt_0202685C) | Plain shape: `if (lo<=hi) loop; else {loop lo..29; loop 0..hi}`, with each hit doing `hit=1; break;`. The compiler does the selective cross-jump that the old goto construction was imitating. |
| 0x0202685C/504 | MATCH, 516/516 bytes, every concrete byte right | src/pending/func_0202685C.c (pkt_0202685C) | Blocked on class `label`: the only references to `bl 0x02167394` are these 4 sites. ov009 and ov010 both cover that address and neither labels a function there, and --suggest-split has no cut. The C needed an int-id inline helper (the callees take u8) and a slot pointer `&slots[hi]`. |
| 0x02026D88/530 | EXACT | src/matched/func_02026D88.c (pkt_02026D88) | This is the own-beacon builder. The scratch buffer is an OSOwnerInfo. Word +0 is four bytes and byte 3 is split 7:1. Word +0xC splits 6:3:3:4:10:6. Declaring save, tbl, bag in that order sets the stack order, and 0x02008550 needs an explicit (u8). |

Witnesses (all EXACT): src/matched/sub_02026D04.c, src/matched/sub_02026D48.c (pkt_02026CE0), src/matched/unit_02026BFC.c (tu, 5 leaves, pkt_0202685C).

## pms_draw.c (0x0202DB0C..0x0202E43C)

| target | result | notes |
|---|---|---|
| 0x0202DB0C/180 | EXACT, src/matched/func_0202DB0C.c (pkt_0202DB0C) | Two changes closed it. First, the second allocator's heap is `h = p->heap;` read back right after the store, which keeps r0 live over the field stores. Second, e0 is u8 after all. |
| 0x0202DD24/310 | DIFF, 310/310 bytes, 8 out | Appended to docs/notes/pkt_0202DD24.c.txt. The volatile locals are gone. The shape is `e = p->elems` read once, `src` before `dst`, and `pt.x += dx * 8` in the loop. Only two spill slots are swapped: dst sits at sp+0 and dy at sp+8, where the image has them the other way round. Declaration order, scoping, types, struct/array spellings and the sp2 compiler did not move them. The permuter hill run found no single mutation that improves it. hill --types and anneal 1500 both drift to candidates that match the long listing extent (328 bytes) instead of the real 310-byte body. |
| 0x0202E1F0/406 | DIFF, clean source 400/412 bytes, 369 out | Appended to docs/notes/pkt_0202E1F0.c.txt. The argument orders were wrong in the old note: func_0202E040 is `(actor, a3, p0, p1, v, cs)` and func_02043AF4 ends `0x10, c2`. What remains is allocation: &ws should live in r7, n should be spilled, and c3 should be read twice through an r5 base. sp2 matches the prologue but strength-reduces both loops, so 1.1p1 stays the compiler. Permuter best: `DIFF asm=2160 bytes-out=378 size=412/412`. I discarded it because it is not value-preserving. |

Witness (EXACT): src/matched/unit_0202DE5C.c (tu, 3 setters, pkt_0202DD24). These three setters are why the DD24 listing extent reads 328 instead of the real 312.

## Integrator: seed
None of these saves lr, so function_starts.txt needs:
- 0x02026D04, 0x02026D48 (the followers of func_02026CE0)
- 0x02026BFC, 0x02026C1C, 0x02026C30, 0x02026C78, 0x02026C8C (the follower of func_02026A60 starts this run)
- 0x02027460 (inside func_0202744C's extent)
- 0x0202DE5C, 0x0202DE64, 0x0202DE68

## Docs updated
- Family headers: docs/families/game_beacon.h (open list rewritten, wave-12 layout and prototype section added) and docs/families/pms_draw.h (DB0C closed, DD24 shape, E1F0 callee argument orders, new setters).
- Closure sections appended to docs/notes/func_02026A60.c.txt, docs/notes/pkt_02027060.func_02027060.c.txt and docs/notes/pkt_0202DB0C.c.txt.

## Gates
`manifest --verify --shard` passed for pkt_02026CE0, pkt_02026D88, pkt_02027060, pkt_02027460, pkt_0202685C, pkt_0202DB0C and pkt_0202DD24. The pkt_0202685C run printed "1 entr(ies) are not EXACT" although all five entries it listed are EXACT or EXACT* (func_02026A60 is the EXACT*); the MATCH park func_0202685C is in src/pending, which never enters a shard.
