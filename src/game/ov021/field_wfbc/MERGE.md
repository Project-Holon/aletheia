# field_wfbc (ov021)

14 files (was 15). Round 3: the stand-in wrappers func_02193904, func_02193B04, func_02193B20 are typed void
functions, and the old p01+p02 merged once func_021938FC became an old-style (K&R) definition (it forwards two
arguments to func_02193E54 but its one caller passes one; byte-exact, kept on purpose).
Remaining boundaries:
- p01|p02: func_02194038 returns a struct Cell where a u32 stand-in is used; the harmonizer emits illegal
  `(Cell_02193FE8 (*t)[8])` casts.
- p02|p03: func_02082BCC u32 against void *; Cell views through unsigned char *.
- p03|p04: func_02194418 (u32) against (u32, int). p04|p05: DIFF.
- p05..p07: u32 against void * / struct pointer arguments of globals and callbacks (func_0219545C, func_02048AFC).
- later pairs: Obj_021966B0 / Obj_02196B24 / Obj_02196B94 / Obj_02196D24 / Obj_02196ECC are one heap object;
  func_02196030 / func_02196034 argument lists differ; Req is two different structs.