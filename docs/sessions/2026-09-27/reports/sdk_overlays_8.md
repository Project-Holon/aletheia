# sdk_overlays_8 lane report (2026-09-28)

Worked only from vendor objects (sdkobj.py, DWARF) and `match.py show`; nothing under sdk/ opened.
All dsi/1.1p1 -O4,p c99. Permuter seeds 11101 (compile error on step.o, not chased), 11102, 11103, 11104 (all flat).
File naming follows the existing ov016 ov_sdk files (`ov016_func_<ADDR>.c`, vendor names inside).

**Results: 77 EXACT (75 new, 2 promoted from src/pending), 6 DIFF in src/pending. Every shard verified twice (0 rewritten the second time); manifest --check clean.**

- keyboard10.o: DWCi_KB10lInit 0x021BF390 EXACT (pkt_ov016_021BF74C). taskEnd5 0x021C06E8 promoted.
- keyboard.o: taskEnd5 0x021BF2B0 promoted (pkt_ov016_021BD8D8).
- step.o, pkt_ov016_021D0040: 15 of 17. DIFF: taskBegin4 0x021D04BC, taskEnd0 0x021D06A4 (12 bytes each, one store scheduled early).
- sceneoptmovdisco: all 17. The object's own functions are in pkt_ov016_021C3BBC (6). Its copies are in pkt_ov016_021C4F04 (11).
- sceneopterase1.o: all 16. Own functions in pkt_ov016_021C231C (7), copies in pkt_ov016_021C3490 (9).
- scenesetedit32.o: 15 of 16, in pkt_ov016_021C6588 (13) and pkt_ov016_021C72AC (2). DIFF: input 0x021C687C (switch dispatch order). The row 0x021C7738 (endScene1) calls DWCi_KB10lEnd, so it is a sibling scene's step and not a copy. Its header says so.
- scenesetusbready: 11 of 16. The archive has two members whose names truncate to this name, and sdkobj reads only the first. pkt_ov016_021CDCAC (3) holds the first member. pkt_ov016_021CE1B0 (8) holds the second, with no DWARF. DIFF: endScene2 0x021CDF98, endScene1 0x021CE2F4, endScene2 0x021CE364 (constant CSE across calls). Not started: DWCi_SceneSetUsbReady1 0x021CE070, cbUsb 0x021CE45C.

**Lever that closed three functions:** these objects read a file static through its .bss section symbol and take `&var` through the variable's own symbol, which puts a second pool word on the free. In C: reads go through a one-member section struct (`keyboard_bss`, `keyboard10_bss`, `scenesetedit32_bss`) and the free keeps `&MemX`. That is the existing idiom a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address, so there is no new idiom file.

**Files:**
- Sources in src/matched/ov_sdk, `ov016_func_<ADDR>.c` for each of: 021BF390 021C231C 021C23C0 021C23FC 021C2428 021C2484 021C24AC 021C24CC 021C3490 021C34BC 021C3518 021C3540 021C3560 021C374C 021C3774 021C3BBC 021C3C28 021C3C64 021C3CA8 021C3CEC 021C3D58 021C4F04 021C4F70 021C4FE4 021C50A0 021C6588 021C6764 021C684C 021C6A2C 021C6A5C 021C6B30 021C6C30 021C6D24 021C6D8C 021C6DE4 021C6E90 021C7018 021C7044 021C72AC 021C7738 021C818C 021C81B4 021CB1D8 021CB294 021CD5B0 021CD61C 021CD870 021CDBBC 021CDC78 021CDCAC 021CDE0C 021CDE48 021CE1B0 021CE1EC 021CE218 021CE28C 021CE2D4 021CE564 021CE5B0 021CE604 021D0040 021D013C 021D021C 021D02FC 021D03DC 021D0558 021D0580 021D05BC 021D0734 021D0808 021D08DC 021D09B0 021D0A84 021D0AB0 021D0AFC.
- Moved with `git mv` (staged) from src/pending to src/matched/ov_sdk: ov016_func_021C06E8.c and ov016_func_021BF2B0.c.
- src/pending/ov_sdk: ov016_func_021C687C.c 021CDF98 021CE2F4 021CE364 021D04BC 021D06A4.
- Shards in layout/matched/ov016: pkt_ov016_021BF74C, pkt_ov016_021BD8D8 (both modified), and new pkt_ov016_021D0040, 021C3BBC, 021C4F04, 021C231C, 021C3490, 021C6588, 021C72AC, 021CDCAC, 021CE1B0.
- Notes: docs/notes/pkt_ov016_021D0040.c.txt, 021C6588, 021CDCAC (new); 021BF74C and 021BD8D8 (appended).

**Remainder:** scenesetrakubutt (16, not started), DWCi_SceneSetUsbReady1, cbUsb, the 6 DIFFs above, and the older near misses (write 0x021CFCC8, disp 0x021C00A8, keyboard.o disp and DWCi_KBlInit, ScanAP, CheckAccessPoint, initGraphics 0x021C84BC, isPush).

**Integrator:** stage the lists above. There are no seeds, because every address is an SDK row. Four things to note:
- The old-style matched siblings src/matched/ov_sdk/func_021C66A8.c, func_021C67CC.c and func_021D0684.c are for the names_audit lane.
- ov016_func_021C6A10.c is an `asm` body filed as EXACT; it needs a C rewrite.
- src/pending/ov_sdk/ov107_func_021F3CB8.c also exists in src/matched. This is not from this lane.
- The same section lever may close other ov016 residues that show a second pool word.
