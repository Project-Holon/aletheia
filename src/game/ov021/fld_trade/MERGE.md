# fld_trade (ov021)

Seven parts, every one EXACT (was 15). Open boundaries:
- p01|p02: func_021CC098 called with five arguments, prototype has four.
- p02|p03: func_021CD1AC takes u32 in one part and Obj_021CC810 * in the other (task object views).
- p03|p04, p04|p05, p05|p06, p06|p07: DIFF without compile error; p04 calls func_021904C8, func_02190E74 and
  func_0204ADA4 with `a + 152` style offsets that hide a struct. Needs one struct per task object
  (Obj_021CBFB0, Obj_021CC720, Obj_021CC810).