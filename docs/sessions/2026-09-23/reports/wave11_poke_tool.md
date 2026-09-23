# Wave 11 -- poke_tool.c + backup_system.c lane

**14 EXACT** (12 poke_tool.c, 2 backup_system.c), 4 DIFF documented, nothing parked in src/pending.

Note: the coordinator committed the 12 poke_tool files mid-run (9e418e0 "wave 11 (first set)"). The following are uncommitted:
- src/matched/func_02032CD0.c and func_02031C30.c
- layout/matched/arm9/pkt_02032CD0.json (new) and pkt_02031C30.json
- docs/families/poke_tool.h and backup_system.h
- docs/notes/pkt_02031FE0.c.txt, sub_0203335C.c.txt and func_02031F54.c.txt

## Filed EXACT (all dsi/1.1p1 -O4,p; every manifest --verify gate passed)

| addr | size | isa | packet | status | lever |
| --- | --- | --- | --- | --- | --- |
| 0x020173F0 | 58 | thumb | pkt_020173F0 | EXACT | id is ONE `u64` (r2:r3) |
| 0x02017430 | 70 | thumb | pkt_020173F0 | EXACT | u64 id + u64 rnd, heap is the LAST param |
| 0x0201756C | 28 | thumb | pkt_0201756C | EXACT | u64 id (r3 + stack word) |
| 0x02017588 | 118 | thumb | pkt_0201756C | EXACT* | u64 id/rnd; the star is only the 2 alignment bytes (follower 0x02017600 is labelled) |
| 0x02017600 | 28 | thumb | pkt_0201756C | EXACT | u64 id |
| 0x0201761C | 680 | thumb | pkt_0201756C | EXACT | u64 id/rnd sentinels, non-shiny retry loop `id=(u32)(rnd+1)`, IV draws `(u64)rand*32>>32`, **func_02017550 takes obj** (last 10 prologue bytes), gMsgBank/gNameBuf were swapped in the old note |
| 0x02017A20 | 250 | thumb | pkt_02017A20 | EXACT | 12-byte table copied by value AFTER the guard (struct copy from a named extern; really a local initializer whose anon symbol can't go in `symbols:`); v/val u32 so truncations land at calls |
| 0x02017FB0 | 210 | thumb | pkt_02017FB0 | EXACT | ONE loop variable reused for both phases; learnset struct copies |
| 0x02018328 | 246 | thumb | pkt_02018328 | EXACT | five explicit `{u16 move; u16 level}` struct locals in frame order (e,d,f,t,cur); pointer-taking terminator inline in the `while` condition; species u16 / form u32 |
| 0x0201862C | 150 | thumb | pkt_0201862C | EXACT | id key as a block-scoped local, `k ^ (u16)v` |
| 0x020186C8 | 196 | thumb | pkt_0201862C | EXACT | case 0 **falls through** into case 2; cases 1 and 2 each carry the bit-16 fix |
| 0x020189F0 | 12 | thumb | pkt_020189F0 | EXACT | `tbl[nature][stat]`: 2nd arg is an index, not a base pointer |
| 0x02032CD0 | 1220 | arm | pkt_02032CD0 | EXACT | first transcription of the 12-state save-write machine; one decl swap (`st` before `done`) |
| 0x02031C30 | 400 | arm | pkt_02031C30 | EXACT | case 4 written unequal-first with `state++` in the else (fall-through arm = source order) |

Bytes: poke_tool 2046, backup_system 1620. The worklist gives 68 and 36 for 0x02032CD0 and 0x02031C30, but those are `code` fields. The real sizes are 1220 and 400.

Evidence notes:
- These resolve by `sole-ref`:
  - 0x02017A20's table 0x0209E298 (data)
  - func_02017BC8 (code)
  - 0x020189F0's table 0x0209E2A4, which is no longer capped
  - func_020180FC (called from 0x02017FB0)
- Every other site resolves by label, literal or matched.

## Pushed to DIFF, notes appended with best source and permuter line

- **0x02031FE0** (1692, arm, pkt_02031FE0): first whole-body transcription. It is 1704/1704 bytes with **42 concrete bytes out**.
  - The residue is in two places:
    1. The heap-truncation schedule of the alloc call.
    2. The B / A+B register swap.
  - Permuter hill 800 and anneal 2000 are both flat. A 120-order declaration brute force fixed the rest of the loop allocation.
  - Every dsi compiler gives the same result; `2.0/*` is 400+ lines out.
- **0x02032688** (596, arm): 600/600 bytes with **10 concrete bytes out**, up from 57% byte identity.
  - What fixed the rest:
    - a redundant re-test in the source
    - fall-through-first tail
    - `u8 *h`
    - h declared first and i declared last
  - Residue is a 4-instruction argument schedule in the func_020335E8 call. About 15 spellings failed, and hill and anneal are flat.
- **0x0203335C** (156, arm): stays at 21 bytes out. The natural `for` spelling is also size-exact, but all 120 declaration orders miss. The same 14 lines appear on every front end, including 2.0/sp2.
- **0x02031F54** (64, arm): 16 bytes out. A struct-typed footer moves the residue from allocation to pure scheduling. Hill is flat; anneal only found volatile hacks.

Nothing skipped for being a 2-4 byte allocator tie or for an unlabelled overlay callee.

## Family headers updated
- **poke_tool.h**:
  - Section 11 was rewritten: the "one remaining codegen wall" was a `u64` parameter.
  - New exact prototypes for 0x020173F0, 0x02017430, 0x0201756C, 0x02017588, 0x02017600, 0x0201761C, func_02017550 and func_02017ED8, including the sentinel values.
  - Added `struct Learn`, func_0201ADD0, func_0201808C and func_02018094.
  - 0x0209E2A4 is uncapped.
- **backup_system.h**:
  - func_02032CD0: state map, the u16 handle at +0x20C, fields +0x14/+0x19/+0x144..0x150.
  - func_02031C30 (two-record driver).
  - The Footer struct for func_02031F54.
  - The 0x02031FE0 / 0x02032688 descriptions.

## Integrator: seed
None. 0x02017588's EXACT* is only alignment padding; its follower 0x02017600 already has a label.

## Worth knowing for other lanes
A forwarder whose "last register argument gets a memory home" survives every lever may be taking two adjacent u32s that are really one u64. Here the 64-bit `mvn/eors/orrs` compares in the callee were the tell.
