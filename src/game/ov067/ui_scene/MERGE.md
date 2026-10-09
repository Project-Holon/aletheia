# ui_scene (ov067): 5 parts left (was 8)

Done in r2_09: the local `S` structs of the old p02, p03, p04, p05 and p08 got unique names
(S_021B65C8, S_021B66FC, S_021B69A4, S_021B6DC0, S_p05, S_p08). func_0204AC18 and func_0204A6C8
take a u32 last parameter, func_021B62E0 takes a u16 heap, func_021B67F8 takes (u32, void *, void *,
void *, u32, u16), func_020355D8 takes u8 (local `save` is u8). p01+p02 and p03+p04+p05 merged.

Boundaries left:
- p01 | p02 (old p02|p03): func_021B6608 (in p01) calls func_021B6738 (in p02) with an unnarrowed
  heap in the last (u16) parameter while a3 is narrowed. A typed prototype narrows heap, an
  unprototyped `();` declaration breaks the u8 constant sharing in func_021B6608. Needs the
  original declaration order (the call site precedes the definition).
- p02 | p03 (old p05|p06): func_020410D0 is `u8 index` in p03 (func_021B90B8) and `u32 index` in
  the matched definition and in p02. With `u32 index` func_021B90B8 swaps the registers of t and
  id (id lives at [sp,#0x1c]); `u8 id` and `(u8)id` variants were tried and stay DIFF.
- p03 | p04 (old p06|p07): p04 declares func_021B90B8 and func_021B9138 with `int a2`; p03
  defines them with `s8 a2`, so the calls need s8 variables.
- p04 | p05 (old p07|p08): p04 S_021B92F0, S_021B91D0, S_021B9228 and p05 S_p08 view one scene
  object (f20 Ops *, f24, f5c, f60, f62); the two `struct Ops` have different layouts (fn at 0
  against f4 at 4), so one canonical Scene struct plus one Ops is needed first.
