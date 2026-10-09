# unit_021F36C0 (ov038): remaining blockers

All parts verify EXACT on their own. Both boundaries are likely real file boundaries
(checked 2026-10-08, lane r2_16). The cause is the same on both: the callee func_021BE674
(and friends) is called with and without argument narrowing in the original.

- p01|p02: p01 calls func_021BE480/4B4/674/700/6CC through u16 parameters (narrowing at the
  call, lsls/lsrs #16 in the loop). p02 passes the same arguments with no narrowing
  (`adds r3, r7, #0`); a u16 parameter adds the narrowing and breaks p02. Explicit (u16)
  casts at the p01 call sites change register allocation (tested).
- p02|p03: func_021BE674 takes (unsigned j, int k) in p02 and (int j, u16 k) in p03. With p03's
  prototype p02 is DIFF (581 bytes differ from func_021F3B3C: narrowing added at every call);
  with p02's prototype and (u16)i casts p03 is DIFF too (the narrowing is hoisted out of the
  loop). One prototype cannot serve both files.