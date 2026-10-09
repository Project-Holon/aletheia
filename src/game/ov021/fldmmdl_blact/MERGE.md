# fldmmdl_blact (ov021): 14 parts

Round 7 (s21b): 14 parts, all EXACT, none joined. Fixed this round (parts verified EXACT after):
- func_0219C74C, func_0219C7B4, func_0219C7EC now return u32 (`return func_0219C6B8(...)`,
  `return func_0219C780(...)`, `return func_0219C74C(...)`); p02 and p04 prototypes follow;
  p04 local `r` is u32 (a u16 local added a narrowing the original lacks).

Remaining boundaries (greedy run, forward order, each fails on its own):
- p01|p02: merged file compiles but is DIFF: the compiled output matches up to the end of
  func_0219C780 (+0x304) and the diff row is the pool word and tail; cause not found (p01 and p02
  alone are EXACT). Check pool placement of the 0xFFFF literal of func_0219C780.
- p02|p03: func_0219CA00 takes `u32 *s` in its definition but is called with `(a + 20)` (u32) in
  p03; func_0219CA40 takes `Tbl *` and is called with `o + 0x14` (u8 *). The caller's `a`/`o`
  should be a pointer (wide caller narrow callee does not apply: pointer types).
- p04|p05: func_0219DB0C declared void in one part, called with `return` (int) in the other.
- p05|p06: func_0216D7CC defined with one parameter (u8 *), declared with four in p05.
- p09|p10: func_0219E784 takes `short *`, called with u32; func_0219EA78 prototype differs
  (u32 against `u32 *`), also seen in p10|p11 and p12|p13.
- p13|p14: func_0219EF14 takes `u8 *`, called with `(a + 8)` where a is u32.
- p06|p07, p07|p08, p08|p09 (arity of func_0216D89C, func_0219E00C, func_021B8028): DIFF or
  struct views; not examined this round.
Fix: one prototype per function (the definition's), the caller's parameter typed as the pointer.
