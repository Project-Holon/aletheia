# fld_trade (ov021): 4 parts (was 5)

Round 7 (s21a): old p01|p02 merged (battle-subway mon object is one Obj_021CC390; func_021CC098 takes an
unused trailing parameter). Generic typedefs (Obj, Req) were renamed per distinct body by address.

Remaining boundaries (p01|p02 is the next one; the merge compiles with these errors):
- p01|p02 (0x021CD050): func_021CD1AC takes u32 in one part and Obj_021CC810 * in the other;
  func_021CD004 / func_021CD038 / func_021CCE48 (void against int return); func_02049238 and func_020124E8
  prototypes differ; Obj_021CD1AC and Obj_021CD050 are views of one object.
- p02|p03 (0x021CE3E8): u32 against struct pointer; void against int (func_021CD038).
- p03|p04: not diagnosed.
