# zukan_detail_graphic (ov208): 7 parts (was 13)

w13c (2026-10-10): merged old p01+p02+p03, p04..p07, p12+p13 (all EXACT). Shared layouts
(Ov208Mgr, Ov208Rec, Ov208Bg, Ov208ActDesc/List/Src, Ov208Slot, Ov208Scene) now live in
zukan_detail_types.h. Remaining boundaries (new numbering), none proven real:
- p01|p02: ov208_func_021BD574 is defined with u16 heap but called from func_021BD444 with an
  unnarrowed u32 heap (implicit call in the original; removing the extern and a K&R definition
  both give DIFF). Needs a way to model an undeclared call.
- p02|p03: func_0204B294 prototype (p03 has u32 form; casting at its call gives DIFF);
  func_021BF4FC / func_021BC3A4 key is int in p03 vs int * in p02 (ov208_ alias names with two
  prototypes); func_021BF664 now typed as Ov208Scn.
- p03|p04: func_021C06A0 is called with 3 arguments (void *, char *, void *) in p03, defined as
  (int, S *) in p04: needs a shared S type and unused trailing parameter.
- p04|p05, p05|p06, p06|p07: func_0204B878 is (struct Obj *, u16) in p04/p06 but (u32, u32) in
  p05/p07 (callers pass unnarrowed u32; a prototyped u16 gives DIFF).
- Ov208Main / Ov208Scn (p02) are two views of one object, not yet one struct.
