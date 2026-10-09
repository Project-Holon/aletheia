# un_select: two parts (un_select_p01.c, un_select_p02.c)

Parts: un_select_p01.c (0x021B95A0..0x021B9C74) and un_select_p02.c (0x021B9C74..0x021BA848).
p02 now includes the former unit_021BA290.c (func_021BA290 .. func_021BA7A4, 1464 bytes), merged in round 5
(MATCH, same as p02 before). un_select_graphic.c is a separate source file: its __FILE__ string
(0x021BB094 "un_select_graphic.c") differs from the one the parts use (0x021BB088 "un_select.c").

Boundary p01 | p02, reason:
- func_021B9AE4 (p01) is written with a stand-in 64-bit parameter:
  `void func_021B9AE4(u8 *p, u8 *a, void *b, unsigned long long cd)`, with c = low word
  and d = high word. Its caller in p02 (func_021B9C8C) passes five separate arguments (p, b, t, c, a).
- A real five-parameter definition `(u8 *p, u8 *a, void *b, u32 c, u32 d)` compiles to a
  different register allocation (extra `push {r3}`, frame 0x18 instead of 0x1c, t kept in r7
  instead of the stack slot 0x18, d reloaded from [sp,#0x30]): DIFF. mwccdbg regalloc shows why:
  the stack parameter d is not a register candidate, each use is a fresh `ldr` from its home, so
  only a and b spill. The original keeps d in r7 (loaded at entry) and spills t.
- Tried in round 5 and unchanged: local copies of c and d (declared first, after t, after r),
  `register u32 d`, `d *= 4` before the index uses, an 8-byte struct parameter {c, d}.
  Only the 64-bit stand-in makes d a real local.
- Building the 64-bit argument at the call site (`((u64)a << 32) | c`) changes the caller: DIFF.
- No cast can reconcile the two prototypes, so the boundary stays until the callee is
  matched with five parameters.

Hidden function added in this part: func_021B9FD4 (`int func_021B9FD4(void) { return 1; }`,
`movs r0,#1; bx lr`, uncovered gap before func_021B9FD8), now inside un_select_p02.c.
