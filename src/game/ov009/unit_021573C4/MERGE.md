# unit_021573C4 (ov009): 8 parts left (was 34), all EXACT

Round 17 (L02): shared header cps_types.h (CPSNetVars for g_021A826C, _CPSSoc, _OSThread,
OSThreadInfo, three thread objects). Every part uses it; the greedy pass then merged 34 -> 9,
and the u8 g_021A1CC0 / func_02157D8C / func_02157F60 / func_0215781C / func_02157808 type fixes
joined p01+p02 as far as types go.

Remaining boundaries (new numbering):
- p01|p02: .bss layout. p02's send_ping (func_02158524) needs a FUNCTION-LOCAL
  `static u16 pingseq` (a file-level static changes scheduling), but then mwcc registers it
  after the file-level u32 statics of p01 and every p01 u32 static lands 4 bytes low (24 bytes
  differ). p01 as a standalone part keeps pingseq at file level. Needs the .bss ordering rule
  (observed: objects are laid out in registration order with alignment, not by size).
- Later pairs (p02|p03 .. p07|p08, p08|p09 in the old greedy order) not retried after the
  fixes above: old failures were func_02157D8C prototype (fixed), arity of func_021578C8 /
  func_0215938C, DIFF at p04|p05 old, CPSFragTable_0215B67C incomplete type, and duplicate
  static definitions (u8 vs unsigned char spelling; p07/p08 define cps and CPSMyMac
  separately although CPSMyMac lies inside the cps struct).
Tools: scratchpad r17/L02 (apply.py, raw.py, pair.py, mi.sh).
