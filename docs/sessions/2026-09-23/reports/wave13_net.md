# Wave 13, net lane (net_err, net_ring_buff, net_save, net_lower_data)

Result: **11 EXACT**, 2 parked MATCH, 7 DIFF notes appended. Nothing committed.
All compiles are dsi/1.1p1. I tried ../2.0/sp2 on every residue, and it never did better.

## EXACT (filed in src/matched, shards verified)
| addr | function | bytes | packet | how it closed |
|---|---|---|---|---|
| 0x0200FAAC | sub_0200FAAC | 120 | pkt_0200FAAC | The parked MATCH had a typo in its global: 0x0202617C where the pool says 0x0214617C. Moved out of src/pending. |
| 0x02010158 | sub_02010158 | 124 | pkt_02010068 | Pool words were misread before. They are 0x0214617C, 0x0209DEB0 and 0x0209DED0 (sole-ref/data). Case 0x3F7 shares case 0x3EE's block. |
| 0x0200FC0C | func_0200FC0C | 300 | pkt_0200FC0C | The +0x2C test is a wrapping if. The module object goes through a named local `u8 *g`, which gives the `adds #0x59` access and the reloaded pool. |
| 0x0200FD38 | sub_0200FD38 | 388 | pkt_0200FC0C | NitroSDK gx/g2 inlines. The backup copies bind dst, then src, to named locals. |
| 0x020101D4 | func_020101D4 | 376 | pkt_02010068 | idx = 1 on the non-link arm shares the constant 1. The permuter anneal closed the last scr/x pair: decl order plus a named local for the screen pointer. |
| 0x0200F83C | func_0200F83C | 584 | pkt_0200F83C | Written from the SDK window and dispcnt inlines. Exact on the first compile. |
| 0x02036640 | func_02036640 | 44 | pkt_02036640 | The body of the matched func_020365E8 inlined (volatile re-reads). Moved out of src/pending. |
| 0x02036428 | func_02036428 | 172 | pkt_02036428 | Ring write cursor +0x0E declared `volatile short`. |
| 0x020367C4 | func_020367C4 | 252 | pkt_020367C4 | Exact on the first compile. |
| 0x0203EC7C | func_0203EC7C | 92 | pkt_0203EC7C | The first guard is a wrapping positive test that falls through to a single trailing `return 0`. |
| 0x0203EA9C | func_0203EA9C | 360 | pkt_0203EA9C | A plain if / else-if chain with no gotos. Exact on the first compile. |

Manifests verified with `manifest --verify --shard`, all entries EXACT: pkt_0200FAAC, pkt_02010068, pkt_0200FC0C, pkt_0200F83C, pkt_02036640, pkt_02036428, pkt_020367C4, pkt_0203EC7C, pkt_0203EA9C.

## Parked MATCH (src/pending, byte-exact, blocked on evidence)
- **0x02010AC4 func_02010AC4** (212 B). This was DIFF before. Four ABS32 sites have no outside witness: the overlay-id symbols 0x73 and 0x7B and the overlay-resident procs 0x021D6338 and 0x021D654C.
- **0x02010C34 func_02010C34** (356 B, pkt_02010BB8). Five sites have no outside witness: ids 0x73 and 0xBB, and procs 0x021D6338, 0x0220B294 and 0x021D654C.

## Integrator: seed
- The literal pools at **0x02010B84..0x02010B97** (func_02010AC4) and **0x02010D84..0x02010D97** (func_02010C34) are printed by disasm.py as Thumb instructions, so the pool-word index never sees them. Both pools hold 0x00000073, 0x021D6338 and 0x021D654C. If they are seeded as `.word`, each function becomes the other's `literal` witness for those three sites. That leaves AC4 with 0x7B only and C34 with 0xBB and 0x0220B294.
- No new unlabelled leaves or EXACT* followers came up in this lane. sub_0200FB38 is already known.
- src/pending/sub_0200F734.c is unchanged. It stays blocked on the overlay callee 0x02156460: ov009 labels it, but the only branch to it is inside the compared range.
- src/matched/func_0200F7B8.c still carries a stale "blocker: 0200FC0C" line. 0x0200FC0C is now matched.

## DIFF, notes appended (each section has the best-source marker and the permuter line)
- sub_0200FEBC: 43 B out of 408, size exact (docs/notes/sub_0200FEBC.c.txt). Everything matches except how the G2_SetBG1Control bitfield unpack of the saved word is scheduled. Hill, two anneals and about 12 hand spellings made no progress.
- func_02036568: 25 B (pkt_02036568.c.txt). The loop-bound reload has to be hoisted above the dst store. It looks like an aliasing and declaration question.
- func_0201104C: 108 → 10 B (pkt_0201104C.c.txt). Two real levers moved it: the wrapping if, and reassigning the parameter from func_0201AB28.
- func_020110CC (7 B) and func_020111BC (3 B) share one residue with func_0201104C: the first four instructions, where the image loads the pool word into r1 before copying a0 to r4. It looks like one property of net_save.c; whatever fixes one should fix all three. 0x0209BE5C is `_ll_sdiv`.
- func_02010DF4 / func_02010DCC: the note's "reading 1" levers are now tried (inline bound, parameter bound, local bound, while loop). All still fold the loop guard.

## Family headers written
docs/families/net_err.h, docs/families/net_ring_buff.h and docs/families/net_lower_data.h. They hold the struct layouts, prototypes and the spelling rules that closed these functions.
- In net_lower_data, the manager has 8 channel slots, not 0xE.
- func_0203ED84 and func_0203EC04 actually return int, because func_0203EA9C tests their results. Their matched files spell them void.
