# bmp_menulist (arm9)

Round 5 lane s12: 4 parts -> 3 (old p02+p03 merged by greedy pass, EXACT).

Boundaries left:
- p01|p02 (0201FF30.. | 020208B8..): CCERR. The one menu-list object is viewed through Obj_0201FF30, Obj_020200CC,
  Obj_02020268, Obj_02020408, Obj_0202055C, Obj_020206C0, Obj_02020780 (p01) and Obj_020208B8, Obj_02020970,
  Obj (p02). The views differ in their bitfield layout at +0x1A (3/4/2/6/1, 3/4/8/1, 7/2/7 bits), so a
  canonical struct needs a union at +0x1A, not a plain merge (unif41.py skips bitfields). Other fields by
  offset: arr +0, unk04 (hook in the 0202055C view) +4/+8, count +0x10, rows +0x12, f14..f19, f28 (target),
  f2C, f30, f34..f38 nibbles, f3C, f40, f42, f44..f48.
- p02|p03 (020208B8..02020CA0 | 02020CA0..): DIFF with the greedy pass (headers show p03 is a separate view); p03 has its own `struct Obj`, `D`, `Desc`, `Handle` and calls
  func_020206C0 with `struct Obj *`.
