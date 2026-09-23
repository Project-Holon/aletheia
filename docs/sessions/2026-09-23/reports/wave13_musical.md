# Wave 13: musical_dist_save / game_data / field_status lane

5 of the target functions are now EXACT or EXACT*, plus 1 new witness leaf. That is 6 files filed in src/matched. Nothing was committed.

## Filed EXACT (src/matched), shards verified
| function | size | packet | verdict | what closed it |
|---|---|---|---|---|
| func_02014698 | 96 | pkt_02014698 | EXACT | No goto or labels. Each switch arm has its own `(*mode)++; break;`, and case 2 is `if (poll()==0) (*mode)++;`. The compiler's cross-jumping then gives the tail branch the image has. |
| func_0201493C | 204 (212 incl. pool) | pkt_0201493C | EXACT | The 7th parameter is `u16 heap` (the ov094 caller loads it with ldrh). It is used as `(heap&0x7fff)\|0x8000` at all four uses. Both "back-end tie-breaks" in the old note disappear. |
| func_0200CC40 | 402 | pkt_0200CC40 | EXACT | `u16 id` parameter: the image stores id to its home slot and then reloads it (the narrow-parameter tell). The row tests go through `TestSpecies(row, id)`, which forms `u16 x = id-1` inside, so each inlined copy rebuilds the mask and offset. |
| func_0200D064 | 72 | pkt_0200D064 | EXACT | Written with a u16-row accessor `DistRow(p, i)` and `TestSpecies`, returning 1 from inside the loop. |
| func_0200D144 | 322 | pkt_0200D144 | EXACT* | The last two arms are `TestSpecies(a)\|\|TestSpecies(b)`. EXACT* only because the follower below has no label. |
| func_0200D288 | 16 | pkt_0200D144 | EXACT | New witness: the unlabelled leaf `u32 f(struct Blk37 *p, u32 which){ if(which==0) return p->unk4D0; return 0; }` |

I ran `python3 tools/match.py manifest --verify --shard` for pkt_02014698, pkt_0201493C, pkt_0200CC40, pkt_0200D064 and pkt_0200D144. All new entries come out EXACT or EXACT*. pkt_0200D144 reports "3 entries are not EXACT": that is D144's own EXACT* plus the pre-existing EXACT* entries func_0200D2B0 and func_0200D2C4.

## Still DIFF (sections appended to the notes)
- **func_0200CA98**: now 392 against 392 bytes, 147 concrete bytes out, compiler 1.1p1. It was 380/358. The remaining residue is register colouring only. Permuter best: hill `expand(row) ; expand(m)`, then anneal `cast(u32)` gives `DIFF asm=2310 bytes-out=147 size=392/392`; a second anneal found nothing more. What fixed the shape: the form-row clears are written `q = p + K; q += o; *q &= m`, and the tail uses named off/bit/nm. Note: docs/notes/pkt_0200CA98.c.txt.
- **func_0200C52C**: 120 against 120 bytes, 56 concrete bytes out, 1.1p1, with the real prototypes. func_020073D8 takes 3 arguments (its body forwards r2); the third is the literal 0 that also feeds the stores. func_020072CC's heap parameter is not u8 at this call. The wave-11 "36 out" result depended on a wrong 2-argument prototype. The wall is still the allocator: the image spills sys and keeps sv and the id 6 in r7. Permuter: hill 800 and anneal 2000 only improve through a u16/u8-truncated result, which is rejected (`DIFF asm=725 bytes-out=33 size=120/120`, `type:l(r:u32->u8)`). Note: docs/notes/pkt_0200C52C.c.txt.

## Skipped (walls, re-verified, unchanged)
- **game_data**: func_020124F4 (MATCH) and func_02012704 (MATCH*). Both are blocked on unlabelled callees in ov009/ov010.
- **field_status**: sub_02014488 (MATCH*), func_0201450C (MATCH*) and func_020145CC (MATCH) are blocked on overlay callees. func_02014878 (MATCH) is blocked on its own pool words: two absolute constants with no second referrer.

## Lessons (added to the family headers)
- A "per-copy index" helper, `TestSpecies(row, id)` with `u16 x = id - 1` inside, explains why the image rebuilds mask, offset and address at every join. It closed three functions that no open-coded spelling reached. Recorded in docs/families/musical_dist_save.h.
- The cause was in the declarations twice more: a u16 parameter (0201493C, CC40) and a 3-argument callee (C52C).
- The goto/label switch shapes left by earlier lanes can be wrong readings; plain arms plus cross-jumping matched (02014698).
- Permuter caution: from D064 it reported 19 and 15 bytes out, but those candidates used a variable before assigning it (a `reorder` mutation). I discarded them.

## Integrator: seed
- 0x0200D288 (thumb): a leaf after func_0200D144. Its witness is src/matched/func_0200D288.c. Seed it in layout/function_starts.txt.
- Also: src/matched/func_02014728.c carries a stale blocker line for `+002C ABS32 func_02014698`. That site can now resolve through the `matched` class.

## Files touched
- **New in src/matched:** func_02014698.c, func_0201493C.c, func_0200CC40.c, func_0200D064.c, func_0200D144.c, func_0200D288.c
- **Shards:** layout/matched/arm9/pkt_02014698.json (new), pkt_0201493C.json (new), pkt_0200D064.json (new), pkt_0200CC40.json, pkt_0200D144.json
- **Notes (appended):** docs/notes/pkt_0200D064.c.txt, pkt_0200D144.c.txt, pkt_0200CC40.c.txt, pkt_0200CA98.c.txt, pkt_0200C52C.c.txt, func_02014698.c.txt, pkt_0201493C.c.txt
- **Family headers:** docs/families/musical_dist_save.h, docs/families/field_status.h
