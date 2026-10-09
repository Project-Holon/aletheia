# ui_scene (ov067): 3 parts left (was 8, then 5)

Done in r2_09: the local `S` structs of the old p02..p05 and p08 got unique names. p01+p02 and p03+p04+p05 merged.

Round 5 (r5s09): the old p03, p04 and p05 (func_021B8DF0 .. func_021B941C) are one part now (p03, EXACT).
One canonical `struct Scene` (named fields by offset, with `struct Ops`, `struct Pair`, `struct Elem`) replaces
the eight local views S_021B8DF0, S_021B8EA0, S_021B8FE4, S_021B90B8, S_021B9138, S_021B91D0, S_021B9228,
S_021B92F0, S_p08. func_021B9280 and the func_021B9394..func_021B93C0 getters are now typed on Scene.
func_021B91D0 and func_021B9228 take `s8 a2` (the callee func_021B90B8 takes s8).

Boundaries left:
- p01 | p02: func_021B6608 (in p01) calls func_021B6738 (in p02) with an unnarrowed heap in the last (u16)
  parameter while a3 is narrowed. A typed prototype narrows heap, an unprototyped `();` declaration breaks
  the u8 constant sharing in func_021B6608. Also `Entry` is defined twice and the S_021B63D0 / S_021B66FC views differ.
- p02 | p03: p02 already has a fuller view of the same object, `struct S_021B8460` (f1c Ent *, f20 Ops *,
  f2c, f34, f46..f4a, f4c..f54, f5c, f62, f64, f66.., bitfields count/ready/drag/trigger at 0x86, f87..f8c, f90).
  The merged part needs that struct and the new Scene to become one (f28 is u32 in p02 and Pair * in Scene; f30 u32
  against void *; f38/f3c/f40 are padding in p02; f5c/f62 are `s16_021B7CF8` in p02). p02 also casts the object
  through `struct S_021B7BE0 *` and `struct S_p05 *` for func_021B92F0. Also func_020410D0 is `u8 index` in p03
  (func_021B90B8) and `u32 index` in the matched definition and in p02: with `u32 index` func_021B90B8
  swaps the registers of t and id (`u8 id` and `(u8)id` variants stay DIFF).
