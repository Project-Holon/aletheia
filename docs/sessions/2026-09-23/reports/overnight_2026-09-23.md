# Overnight summary, 2026-09-22 23:30 to 2026-09-23 09:30

## Numbers
- exact coverage: 71.16 percent (3920 functions) at d7cd2db -> 82.96 percent (4069 functions) at 70ecace
- reproduced coverage: 71.86 -> 83.80 percent
- denominator: 394940 -> 395520 bytes (seed rounds 3 and 4: 11 unlabelled starts now counted)
- 19 commits, all pushed, ROM byte-identical at every source-changing commit, both maps regenerated each time
- 172 new exact functions in 10 hours: wave 10 (79, 12 lanes), wave 11 (41, 10 lanes), wave 12 so far (52, 7 of 10 lanes done)

## What closed
- Whole families/clusters finished: poke_tool.c (14), pkt_0206A17C (5, NitroSystem g3d bind), pkt_02069078 (4, g2d CharCanvas), pkt_020737C0 (6 targets + 4 leaves), game_beacon.c + pms_draw.c (16), billboard.c + billboard_act.c (8), symbol_save/app_taskmenu/game_data (10), net_system/net_handle/gf_standard (7), bg_sys.c (7 across two waves), bmp.c (8 + 2), wipe_sub/printsys (10), mcss.c quad drawer (1064 B), MSL parse_format and qsort, __pformatter (2220 B, via a unit member line fix).
- What worked, in order of yield: (1) identifying the library: NitroSystem g2d/g3d and MSL functions close in a few compiles once written in the library's shape; the owner has since allowed cross-referencing the public NitroSystem decompilation for SDK library shapes; (2) declaration facts: a callee's real argument list (registers that look like leftovers are loaded values), real prototype widths (s16, u16), struct by value; (3) reading fixes: a constant pool word mistaken for a global, a callee address off by one pool word, main vs sub engine register base; (4) shape levers: inline helpers else-first with early returns, a wrapping if instead of an early return, a named local for a call result, loop-role ints declared without initialisers, split-assign, a call written in both arms, plain `x = x == 0`.

## Owner decisions waiting (all in scratchpad/waves.md)
1. 0x02081E7C is TwlSDK libmath SHA-1 compression, not the game's MD5 transform (2026-09-19 decision moot). Reproduced as a 796-byte CodeWarrior asm body, EXACT, held out in scratchpad/heldout/: keep as coverage, or drop and move to the SDK exclusion.
2. Eight disasm starts are interiors of MI_CpuCopy/MI_CpuMove (SDK asm): let the sdk class cover a symbol's full size or drop the starts (1188 B leave the open pool). Tool change.
3. The 13 genuine-SDK conflicts from the earlier audit, same denominator question.
4. Seed round 5 queue: 0x02008450 thumb, 0x0200EC14 thumb, 0x0200E874/0x0200E878 thumb, 0x02050080 arm (getter; the existing seed 0x02050084 is only its bx lr), and the game_beacon followers 0x02026D04, 0x02026D48, 0x02026BFC, 0x02026C1C, 0x02026C30, 0x02026C78, 0x02026C8C. Applied between waves.

## Rules added tonight
- No top-ups: a wave runs to completion before the next starts; max 8 agents per wave from wave 13.
- Long wine builds run in the background with -j 4; match.py compile timeout raised 180 -> 900 s (build.py -j default was tripping it under load). One first-TU compile (func_0200421A.c) still timed out under 10-lane load; recheck the whole-image build between waves.

## Running at 09:30
- Wave 12 lanes B (pkt_02064B68 + pkt_02074A34), C (mcss.c), J (upper-half singles), resumed after the 08:50 limit reset. Seven of J's files are on disk awaiting its shard pass.
- Remaining open after wave 12: about 15 KB in upper-half clusters (mostly documented ties: pkt_0206EB00, pkt_02063000, pkt_020682DC, __dec2num) and the anchored residues (clact.c ties, mcss.c 3-row function, backup_system 0x02031FE0).
