# bmp_menulist (arm9)

Translation unit starting at 0201FF30. Four files; round 3 greedy-merged the old p01..p07 and
p10 into them (old p01+p02+p03, p04+p05, p06, p07+p10).

Boundaries left (only the first was diagnosed):

- p01|p02 (0201FF30.. | 020208B8..): CCERR. `func_02020A34` is declared with
  `struct Obj_0201FF30 *` in p01 and `struct Obj_02020970 *` in p02, and p01's
  `struct Obj_020200CC *` is passed to a function that p02 declares with
  `struct Obj_02020970 *`. All are views of the one menu-list object. Build one canonical
  struct by offset (canon36.py) from p01's Obj_0201FF30, Obj_020200CC, Obj_02020268,
  Obj_02020408, Obj_0202055C, Obj_020206C0, Obj_02020780 and p02's Obj_020208B8,
  Obj_02020970.
- p02|p03 (020208B8.. | 02020A34..): CCERR, `struct Obj_02020970` (p02) against p03's `struct Obj`
  (fields differ).
- p03|p04 (02020A34.. | 02020CA0..): DIFF. p04 has its own `struct Obj`, `D`, `Desc`,
  `Handle` and calls func_020206C0 with `struct Obj *`.
