# button_man (arm9)

Round 6 (lane w11c): 10 parts -> 5. Old p03..p08 and the 1.2 pieces after them are merged into
p03 (func_0205312C .. func_020583CC, compiler ../1.2/sp2, -O4,p, EXACT). The flag `-proc arm946e` on old
p04, p05 and p07 changes nothing (EXACT with and without), so those headers now read `-O4,p`.
One canonical Bf16/BfHw/BfSel/BfZero/Bf28/SubD/SubC/SubX/SubB/Obj/S block (offsets checked against all
views; Bf23 is BfZero, its `sel` is BfZero `flag`). Scalar alias typedefs (fx32_0205312C and similar)
folded into fx32/s16/s32.
Note: the functions inside these files are in descending address order; merge with `rev`.

Boundaries left:
- p01 (1.1p1) | p02: real, func_02051788.. builds DIFF under ../1.2/sp2.
- p02 | p03: struct views of one object. Obj_02052FC8 = Obj_0205312C (pad[11], f2c void *, f40 Blk *);
  p02 also has Obj/Obj_02052984 (f2c as Row * / Row_02052984 *, f32). Blk/Sub/Desc/Node differ:
  p02 Blk {pad0[5], f14 Node *, pad1[2], f20 Sub *}, Sub {f00, pad[4], f14 Desc * (u16 flags)};
  p03 Blk {pad[2], f08 Node *, pad[5], f20 Sub *}, Sub {f00 Desc * (u32 flags, f47)}, Node {next, pad[10], f2c}.
  Canonical plan: Blk {pad[2], f08, pad[2], f14, pad[2], f20}, Sub {f00 DescWide *, pad[4], f14 Desc *}, two
  Desc types, f2c kept void * with casts at the Row uses. Node_020524C8 (4 flag bits) is a prefix of
  Node_02052770 (5 bits, f4c): use Node_02052770.
- p03 | p04 (old 02057EF8.. ../1.2/sp2): Obj_02057EF8 {u16 f00, f02} against Obj_0205312C; Node_02057EF8 and
  Node_02056420 differ in volatile.
- p04 | p05: p05 (func_0205841C) is 1.1p1 -proc arm7tdmi, DIFF under 1.2: real.
