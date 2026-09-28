# sdk_overlays_7 lane report (2026-09-28)

Worked only from vendor objects (sdkobj.py, DWARF) and `match.py show`; nothing under sdk/ opened.
All dsi/1.1p1 -O4,p c99 (objects stamped 4.0.0.1025). Permuter seed 10701 (flat).

**Salvage:** no uncommitted leftovers in the territory. The 12 committed setting.o DRAFTs
(src/pending/ov_sdk/ov016_func_021CF3B0 .. 021CF7B0) verify EXACT with `--lang c99`. Five of them
defined the wrong name (`DWCi_SETTINGlIp` for `DWCi_SETTINGlSetIp`, and so on), fixed. All 12 were
moved with `git mv` into src/matched/ov_sdk (the move is staged).

**New, all EXACT, each shard verified twice (0 rewritten the second time):**
- setting.o, pkt_ov016_021CF3B0: 20 (the 12 above plus SetWep, SetSetting, Set, SetRaku, SetAoss,
  ErasePage, EraseAll, ConvAddress). Near miss: write 0x021CFCC8 (3 lines, one store scheduled late).
- scenemenu.o, pkt_ov016_021C1AE8: all 9. Its copies at other scene addresses (procInit x5,
  procInit1 x4, procInit2 x3; bytes identical, each pool word is the copy's own next step):
  pkt_ov016_021C2C94 (12).
- sceneopterase.o, pkt_ov016_021C1F1C: all 9, plus copies (endScene1 x4, procInit1, procConfirm1 x7)
  in pkt_ov016_021C3A68 (12).
- keyboard10.o, pkt_ov016_021BF74C: 16 of 19. Near misses: taskEnd5 0x021C06E8 (the keyboard.o
  &MemKb reload residue), disp 0x021C00A8 (prologue scheduling, unwitnessed @ initialisers).

That is 78 EXACT (66 new, 12 promoted) and 3 DIFF files in src/pending/ov_sdk. The count of open ov016 SDK rows went from 580 to 502 (the 3 pending rows still count as open).
Notes: docs/notes/pkt_ov016_021CF3B0.c.txt, docs/notes/pkt_ov016_021BF74C.c.txt.
New idiom: a-bool-field-set-from-a-compare-in-if-else-arms-keeps-the-zero-first.
manifest --check clean.

**Remainder (next lane):** DWCi_KB10lInit 0x021BF390 (not started), step.o (17 open),
sceneoptmovdisco (17), sceneopterase1.o (16), scenesetedit32.o (16), scenesetusbready (16),
scenesetrakubutt (16). Near misses not revisited: ScanAP, CheckAccessPoint, initGraphics
0x021C84BC, isPush, keyboard.o disp/taskEnd5/DWCi_KBlInit.

**Integrator:** stage the files listed above: 78 src/matched/ov_sdk sources, 3 src/pending/ov_sdk,
6 shards under layout/matched/ov016, 2 notes files and 1 idiom file. Then regenerate the idiom index.
No new seeds: every address is an SDK row.
