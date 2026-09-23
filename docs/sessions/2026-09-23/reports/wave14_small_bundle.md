# Wave 14, small bundle lane (gfl_use, ica_anime, time_icon, shinka_check, areaman, palanm)

EXACT 9 (7 targets plus 2 witness leaves), MATCH 1 new, DIFF improved 4, unchanged 6.

- gfl_use.c: EXACT 0x0200545C (pool misassigned in the old note, Hi before Lo; header docs/families/gfl_use.h written). 0x02005B6C is a linker veneer into arm9i, not C (not attempted).
- ica_anime.c: EXACT* 0x020120B4 (forwards all 4 args, live r3 blocks the sibling call). 0x020120C0 stays MATCH (ov021_id), 0x02012164 stays MATCH (ov010 callee). DIFF 0x02011D9C improved to 272/272, 14 out (call in both arms), still evidence-capped. DIFF 0x02011688 unchanged (4-byte copy).
- time_icon.c: EXACT 0x02030D28 (the documented loop-carried near miss was callback arity: fn(node, arg)). EXACT 0x0202FAB0 (4-byte follower). EXACT 0x0202F768 and 0x0202F774 (callback leaves, witnesses for 0x0200545C, shard pkt_0202F768). MATCH* 0x0202F9F8 (src/pending; was DIFF; blocked on 2 overlay ids and 3 overlay proc descriptors). DIFF 0x0202FB34 improved to 120/120, 74 out (step constant folded instead of kept in lr). DIFF 0x0202F1B4 unchanged, 129 out.
- shinka_check.c: EXACT 0x0201B7EC ((u64)rand * 2 >> 32, random below 2). DIFF 0x0201B2B0 first transcription: 1116/1116, 12 out, all 39 relocs resolve (so no longer evidence-capped); only the gate's heap load is scheduled early. DIFF 0x0201B970: u8 max, 124/126, one copy missing.
- areaman.c: 0x0203422C, 0x020343C0 unchanged (same r1/r3/r2 rotation; full front-end sweep flat).
- palanm.c: 0x02021848, 0x0202173C unchanged (DIFF 33 each). Home-area entries confirmed by the earlier 500-byte zero-pad tu; not filed.

Seeds (ISA, witness file):
- 0x0202FAB0 thumb, src/matched/func_0202FAB0.c (follower inside func_0202F9F8's extent)
- 0x0202F768 thumb, src/matched/func_0202F768.c
- 0x0202F774 thumb, src/matched/func_0202F774.c
- palanm home-area starts 0x0202173C and 0x02021848 thumb: confirmed by layout, no matched source yet, so no seed.

Near misses (the one diverging instruction):
- 0x0201B2B0: `ldr r2, [sp, #0x68]` (heap) hoisted above the pidHigh ands/shift/str.
- 0x0201B970: missing `adds r2, r4, #0` (new pp kept in r2, image in r4).
- 0x02011D9C: `movs r1,#4; lsls r2,r1,#14` where the image materialises 4 twice, plus the `off = 0` placement.

Shards verified twice: pkt_0202F768, pkt_02005454, pkt_020120B4, pkt_0202F9F8, pkt_02030D28, pkt_0201B7EC.
Notes appended: sub_0201B2B0, sub_0201B970, pkt_02011D9C, sub_0202FB34, func_0202F1B4, pkt_0203422C and the closure lines for each closed address.
