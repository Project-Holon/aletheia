# field_fog (ov021)

Five parts, every one EXACT (was 6; round 4 merged old p01 and p02). Round 4 (r4_ov06): the 8-byte
veneer-shaped leaves at 021A00F4 and 021A00FC (`ldr r3,[pc]; bx r3; .word target`) are the hidden
functions func_021A00F4 (calls func_021A00E0) and func_021A00FC (calls func_021A006C), both
`void f(u32 a) { g(a); }`. They are now inside p01. The merged p01 has no prototype for func_0219FE9C
(defined with four u32 parameters, called with q + 4): the merge tool hoists one; it was deleted by hand.
Open boundaries (numbers are the new ones; old numbers in brackets):
- p01|p02 [old p02|p03]: d_021D872C is `const u8 []` in one part and an array of Mode rows (update/exit/init) in the other.
- p02|p03, p03|p04 [old p03|p04, p04|p05]: func_021A0EE4 is declared as (u32 *), (u32, u32), (void *, u32) and (u32 x4). The
  definition in p02 is named ov021_func_021A0EE4, so two symbols share one address; decide which callers mean it.
- p04|p05 [old p05|p06]: DIFF.
