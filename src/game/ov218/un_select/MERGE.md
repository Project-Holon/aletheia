# un_select: still split in two parts

Parts: un_select_p01.c (0x021B95A0..) and un_select_p02.c (0x021B9C74..).
Both parts verify EXACT/MATCH alone. A pairwise merge fails with a compile error.

Boundary p01 | p02, reason:
- func_021B9AE4 (p01) is written with a stand-in 64-bit parameter:
  `void func_021B9AE4(u8 *p, u8 *a, void *b, unsigned long long cd)`, with c = low word
  and d = high word. Its caller in p02 (func_021B9CDC area, line "func_021B9AE4(*(u8 **)(p + 0x28), ...")
  passes five separate arguments (p, a, b, c, d).
- A real five-parameter definition `(u8 *p, u8 *a, void *b, u32 c, u32 d)` compiles to a
  different register allocation (extra `push {r3}`, frame 0x18 instead of 0x1c, t kept in
  r7 instead of the stack): DIFF. Copying c and d into locals first does not help.
- Building the 64-bit argument at the call site (`((u64)a << 32) | c`) changes the caller: DIFF.
- No cast can reconcile the two prototypes, so the boundary stays until the callee is
  matched with five parameters.

Hidden function added in this part: func_021B9FD4 (`int func_021B9FD4(void) { return 1; }`,
`movs r0,#1; bx lr`, uncovered gap before func_021B9FD8), now at the end of un_select_p02.c.
