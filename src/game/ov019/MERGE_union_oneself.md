# union_oneself (ov019)

Round 3: 10 parts to 6, all EXACT. Round 5 (r5s09): 6 parts to 3, all EXACT.
- func_0216DA30 takes one argument (the matched definition overwrites its second parameter with 1):
  func_0217FACC is now `(u32 *p)` and calls `func_0216DA30(p[0])`.
- One `struct E` (the E_0217FCE4, E_0217FD04, E_0217FD38 copies are gone), d_02180814 is `const char[]` everywhere.
- One `struct Self` (sys, win2804, msg2808, f2818, sub at 0x2830, f352C, f3530) replaces Self_0217EE28 and Self_0217F2A8.
- func_020084F4 is `const void *(const void *)` in all parts.

Boundary left: p01|p02 and p02|p03.
- p02|p03: prototype conflicts (func_020120F4, func_0217357C, func_02012934 and others), and `Ctx_0217DC94` is
  declared inside a parameter list (needs one forward-declared `struct Ctx` before the prototypes).
- p01|p02: `typedef Ctx` differs between the two (unify by offset), func_0217F268 takes `char *` in p01 and `u8 *`
  in p02, func_02012934 prototype differs.
