# sdk_overlays_5 lane report (2026-09-28)

Relaunched after the cut. Worked only from vendor objects (sdkobj.py, DWARF); nothing under sdk/ opened.
libdwcutil's scene objects are stamped 4.0.0.1025, so they stay on dsi/1.1p1 -O4,p c99 (sp1p2 measured worse).

**Salvaged** (previous run, dwc_mov_wh.o): 32 sources src/matched/ov016_func_021D298C.c ... 021D39C0.c, shard
pkt_ov016_021D39C0 (32 EXACT), notes docs/notes/pkt_ov016_021D39C0.c.txt (DWCi_MOV_WH_Initialize 0x021D3638, DIFF 15,
register pair only). All re-verified EXACT, shard verified twice.

**New, scenesetlist.o** (root endScene2 0x021C8F20, shard pkt_ov016_021C8F20, 27 EXACT): every open function except the
three below. Levers: statics as scenesetlist_bss / scenesetlist_rodata, local array initialisers declared as the
compiler's @NNNNN copied by struct, scene pointers declared `arm`, `_Bool` for DWARF bool (new idiom), `const` on
drawAddress's addr, if/else in moveFocus case 11 (new idiom), `break` not `return` in pushButtonYesNo, operand order
of the inlined G2_SetOBJPosition in dispObj. Plus procInit1 0x021CD3B8 (same body, next scene's range; shard
pkt_ov016_021CD3B8, EXACT).

**Near misses** (src/pending, docs/notes/pkt_ov016_021C8F20.c.txt; permuter seeds 9202 to 9204 flat): initGraphics
0x021C84BC (17 lines, last six register writes), setOffset 0x021C98E4 (8-byte frame for x, y), isPush 0x021C9A94
(AREA copy scheduling, 16 bytes short).

Both new shards verified twice (0 rewritten on the second pass); manifest --check clean.

**Not started (next lane):** keyboard.o (25 open, dumps in scratch/sdk_overlays_5/kb), scenesetaplist.o (23), fresh
drafts of ScanAP 0x021B9BF8 and CheckAccessPoint 0x021B9A2C.

**Integrator:**
- Stage src/matched/ov016_func_021C*.c / 021CA*.c / 021CD3B8.c (27 + 1), the three src/pending ov016 files, both
  shards, the notes, two idiom files, and the salvaged dwc_mov_wh set.
- Staged already: git mv of src/pending/ov016_func_021C8C88.c (draw, now EXACT) and git rm of superseded
  src/pending/func_021C9F58.c and func_021C84BC.c.
- Regenerate the idiom index.
