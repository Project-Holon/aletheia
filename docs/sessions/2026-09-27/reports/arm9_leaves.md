# arm9_leaves (relaunch)

Result: ARM9 game code 100.0000 percent (400674 / 400674 bytes), open 0, 5613 functions.

Salvaged from the cut run (all re-verified with `match.py one`, headers correct):
- src/matched/func_02013128.c EXACT*, func_02015C78.c EXACT*, func_02015EE8.c EXACT*,
  func_02015F0C.c EXACT*, func_02015F14.c EXACT, func_02015F1C.c EXACT*,
  func_02015F50.c EXACT*, func_0201600C.c EXACT, func_02016020.c EXACT*,
  func_0204784C.c EXACT*, func_02051B04.c EXACT
- shards layout/matched/arm9/pkt_02015C78, pkt_02015EE8, pkt_02015F50, pkt_0204784C, pkt_02051B04
- layout/function_starts.txt (two lines: 0x0204784C arm, 0x02051B04 arm), layout/units_arm9.json, layout/worklist.json
- ov195: src/matched/ov195_func_02208AB0.c (11/11 relocs) and ov195_func_0220887C.c (13/13) verify EXACT;
  shards layout/matched/ov195/pkt_02208AB0.json, pkt_0220887C.json

New this run:
- layout/matched/arm9/pkt_02013128.json (shard was missing)

All eight shards verified twice, second pass 0 rewritten. worklist --refresh run.

For the integrator: `manifest --check` reports one duplicate outside this lane:
func_021605C0 in both layout/matched/ov010/pkt_021605C0.json and pkt_ov010_021605C0.json (ov010 lane).
