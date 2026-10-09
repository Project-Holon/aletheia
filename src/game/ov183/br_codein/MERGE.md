# br_codein (ov183): 6 parts left (was 7; round 5 lane s10)

Round 5: merged old p02|p03 (func_021DF388..func_021E0618 region) into p02. Fixes: func_021DF3DC takes
u16 a (the caller of func_021DF620 passes it without narrowing), prototype and definition both.
Open boundaries (current numbering):
- p01|p02: func_021DD0AC call arity (hoisted prototype must be `()`), plus the 17-byte DIFF near func_021DF3DC
  seen before is the u16 a issue above and should be gone once p01 and p02 are merged by hand.
- p02|p03 (old p03|p04): m_br_codein pair merge needs: Triple_021E06D0 renamed to Triple_021DF388 (same
  layout), (int) casts on ((struct Obj00143 *)p)->f344 args of func_021FC124. After that the only
  difference is func_021E07A4: the original narrows heap before func_020457B0(n + 1, heap) with
  lsls/lsrs placed differently (the u16 cast at the call gives 69 differing bytes, no cast gives 53).
- p03|p04, p04|p05, p05|p06: pointer/array view mismatches (char * vs struct *, int[2] vs struct *).
