# worldtrade_adapter (ov135)

Parts left: worldtrade_adapter_p01.c .. _p04.c (was 12 in the previous pass, 48 files before that).

Done in this pass:
- Generic typedef names whose layouts differ between parts (Work, Obj, Ctx, State, Rec, Menu, CurPos,
  ObjPos) were renamed per part with a _vADDR suffix, so parts no longer clash. `struct Obj` is an
  opaque tag shared by every part and keeps its name.
- Hidden functions added (each verifies EXACT in the merged part): func_0220207C (p04, 24-byte
  counter leaf), func_02201DBC (p04, `return 2` stub), func_0220078C (p04, 20-byte state setter).
- func_021F4E98 now takes `void *` as first parameter (callers passed char * and u8 *).
- Old p07+p08 -> p03; old p03+p04+p05 -> p02/p03 area; old p06+p07+p08+p09+p10+p11+p12 -> p04.

Remaining boundaries:
- p01 | p02: func_020185F0 is called with an argument in p02 but declared with none in p01 (arity),
  and p02 passes u8 * where the local Work struct pointer is expected.
- p02 | p03: Work_vC8CC (p02) and Work_vCFD8 (p03) are different views of one object; the merge
  needs one canonical Work by offset (see scratchpad/ol036/canon36.py).
- p03 | p04: a merge compiles after casts, tbl_02203D38 as struct SelTbl, one Rec layout, func_021FF50C
  taking void * and several u32/void * argument casts, but the result is DIFF: callees from
  func_021FFB00 on land 8 bytes later than in the original, so some function before that point is
  8 bytes longer in the merged build (not located yet; pure code diff, no address mismatch in the
  header symbols).
