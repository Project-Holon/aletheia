# Wave 19, lane 19B (mcss_onebyte)

## Per address
- 0x020111BC: 3 -> 0, EXACT, filed (dsi/1.1p1, 44/44, 4/4 relocations). The lever: an s32 return type with no return statement on the 0x30 path. The original falls off the end and hands back v, still in r0, and r1 is then free for the mode load. With an explicit `return v;` the paths join through a copy (48 bytes). The s64 form puts the load in r3 (3 out) and a void function is 2 out.
- 0x02016C60: 29 -> 29, DIFF. Tried: 10 pass-2 pointer spellings (u8 pointer, register, `&tbl[k]` 771, an inline rec_at, pass 2 as an inline function 101, a named k*0x30, the image's load order); a self-assignment sweep (150 compiles); the permuter (870-extent wrapper, 1500 compiles, seed 2201). All 29 or worse.
- 0x0204A7A0: 1 -> 1, DIFF. Tried: a none local, a NONE enum member and a goto to a shared return (47 / 47 / 185); every form that returns i stays at 1. A self-assignment sweep on the return -1 form stayed at 47.
- 0x0209128C: 1 -> 1 under 1.1p1. 12 spellings (if/else in both orders, `? 1 : x`, switch, a pointer store, an inline setter, goto arms, signed char) are all 1 or worse. Left as is.
- 0x02067080: 2 -> 2 (../2.0/sp2). Tried: self-assignment sweeps, long widths and y operand order.
- 0x0204A6C8: 4 -> 4. Tried: a self-assignment sweep, a named zero three ways, compound masking on the u16 parameter (99).
- 0x02034D60: 5 -> 5. The base as an extern data symbol gives the image's registers, but it pools g+0x4000 instead of the add (10 out). This is recorded in the note.

## Files
- src/matched/func_020111BC.c
- docs/idioms/a-missing-return-hands-back-the-parameter.md
- notes appended under 2026-09-24 wave-19 markers: pkt_02016C60, func_0204A7A0, func_0209128C, pkt_02066E30, sub_0204A6C8, sub_02034D60, func_020111BC
- this report

## Shards
`manifest --verify --shard pkt_0201104C` run twice: 3 entries EXACT, the second pass rewrote nothing.

## Seeds
2201 (permuter). No unlabelled starts noticed.

## Integrator
- Regenerate the idiom index.
- The missing-return lever may fit other near misses where one path returns the untouched parameter and a join copy costs 4 bytes.
