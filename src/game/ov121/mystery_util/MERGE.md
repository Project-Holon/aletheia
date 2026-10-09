# Merge blockers (lane r2_13)

Parts in ../ are in address order (p01 to p04). Names below are the current part numbers.

- p01 already holds the old p01 to p03 (func_021D9624 to func_021DA3EB). p01 and p02 do not merge: func_021DA1BC (in p01) is called from func_021DA3EC (p02) with a word argument for its fifth stack parameter (`e`, declared u16). With the prototype in one file the caller adds a narrowing (lsls/lsrs 0x10) that the original does not have, and making `e` u32 changes func_021DA1BC itself. Needs an unprototyped or K&R style definition, or a different parameter split.
- p02 (func_021DA3EC to func_021DB937, includes the merged blend() helper and func_021DAAA4/func_021DAB50) and p03 do not merge yet:
  - the two Rect unions (Rect_021DA3EC with s16 h[4], Rect_021DB938 with u16 h[4]) are one object seen two ways; the struct Obj_021DB938 / Obj_021DBCC8 / Obj_021DAEF0 variants (same pool of slots at 0xA7C, different tails) need one canonical struct with named fields;
  - func_0204B3B4, func_0204B404, func_0204B3DC, func_0200A348, func_020490F4 have different prototypes in the two members (struct Obj * versus the local object pointers, const Vec2 *);
  - func_021DBDF4 is called with a non-const record pointer where a const struct pointer is declared;
  - d_021DF86E is declared as const Rect[] and as u8[] (p03/p04 boundary, line 482 data_021DF86E in the merged part).
- p03 and p04 (func_021DC030 onward): not tried in this pass; the same prototype set (func_02082BCC, func_020457B0, func_0204B3xx) applies.

Round 4 (lane r4_ov09) findings:
- p01|p02: unifying Pair_021DA3EC with Pair_021D9624 (same layout) fixes the Rect/pair call, but the merged
  func_021DA4DC (p02) grows 4 bytes at the call func_021DA1BC(..., (u32)in->bank, ...): in->bank is a pointer
  passed to the u16 `e` stack parameter. The original passes the word unnarrowed, so the callee has no usable
  prototype in view. Needs a form that keeps `ldrh` in the callee and no shift pair at the caller.
- p02|p03 and p03|p04: struct Obj_021DB938 / Obj_021DBCC8 / Obj_021DAEF0 views and the const Rect d_021DF86E
  (Rect union s16 versus u16, and a u8[] view of the same symbol) are still not unified.
