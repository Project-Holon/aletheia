# net_state (arm9)

Translation unit 020353B0..0203E5F8, 413 functions, confidence weak (tools/tuboundary.py).

State after round 4 (lane r4_a902): 87 parts became 75 parts (net_state_p01.c..net_state_p75.c), all EXACT.
Part numbers below are the NEW numbers.

Done this round
- p01 = old p01..p07 (0x020353B0..0x02036738). One struct Sys now covers every view of the object that
  func_02035224 returns (old UiCtx, UiCtx_020353B0, UiCtx_0203545C, Ctx, Tp, Sys). g_021469BC is one
  Desc { struct Sys *sys; int (*f04)(S12 *, S12 *); }. Machine one-liners in this range were rewritten as
  typed C (func_02036254, func_02036290, func_020363B8/D4/F0, func_0203660C, func_02036B4C, func_02036E74).
- p03 = old p09..p15 (0x02036B4C..0x02037478). One struct Notifier (u16 unk00; u16 unk02:14, mode:2;
  struct Handler *handler) for g_021469C8. func_02082BCC is declared once as
  void *func_02082BCC(void *dst, int val, u32 size) in p01, p02, p03 and p33; other parts still use
  their own void or int-argument declaration of it (old p37, p39: casts needed).
  func_020371AC takes (unsigned short a, unsigned short b); the u16 parameter is what made the bitfield
  insert match (this was the DIFF case there).

Still split, and why
- p01|p02: func_0203675C calls func_02036738(char *q, int v) with three arguments in its first call. The
  definition has two parameters, so a merge cannot compile. The original had no prototype in view there.
- p03|p04 and the whole of p04..p29 (old p16..p32): g_021469D0 is viewed through about 14 local structs
  (Net_02037478, Net, Struct_02037B08, State, Handle, T_020394F0, char *, u8 *, u32 *, void *, u32).
  The offsets seen so far: 0x00/04/08/0c/10/14 pointers (f00..f14), 0x1c/2c/3c/4c record blocks,
  0xcc and 0xf4 sub-objects, 0x11c record array, 0x19c, 0x1b0 u32, 0x1b4 array of 8, 0x1d7 u8[8],
  0x1e0 u32 (record size), 0x1e8/0x1ea/0x1eb/0x1ec/0x1ed bytes, 0x1ac..0x1b8 words (p32 T_020394F0).
  Next step: one struct Net for g_021469D0 in the first part (see scratchpad/ol036/canon36.py), then
  turn the u8 + offset code into named fields part by part. func_0203D798 and func_0203D788 are declared
  with six different return types in these parts (void *, char *, struct Oth *, struct Mode *,
  struct LinkRoot *, int); pick one.
- g_021469DC parts (old p41..p62), g_021469E0 (old p62..p76) and g_021469F0 (old p76..p87): not started.
  Each is viewed as u8 *, u32 *, int, void *, or a different local struct (Sys, NetState, Card0203C5EC,
  Card0203C600, Card0203CB00, Singleton, Mod, Wrap, Ctx, Ctx_0203DC4C, S0203DC04, G_021469F0).
- Machine one-liners with raw addresses (0x21469D0, 0x21469DC) remain in old p26, p47, p48, p51, p54,
  p57, p64, p66 (func_02038D30, func_02038D4C, func_0203B22C, func_0203B2A8, func_0203B688,
  func_0203B6B4, func_0203C044, func_0203C464, func_0203D0DC, func_0203D10C). Rewrite them as typed C
  before merging.
- Functions with two prototypes: func_02036BD4, func_02039658, func_0203B52C, func_0203DC68 (same
  parameter, differently named local struct such as struct Ctx_0203DC4C vs struct Ctx).
- c99=DIFF cases of the earlier round still unexamined: around func_02037680/func_020377B8,
  func_02038380, func_02038524, func_0203B1D8, func_0203D210, func_0203D634, func_0203D5AC.
  Greedy merges of the old neighbours showed DIFF at old p10|p11 (fixed), p17, p18, p24..p26, p28, p32,
  p36, p38, p47, p49, p68, p71, p73, p78. Run scratchpad/r4a902/pair902.py and mm902.py on them.

Tools: scratchpad/r4a902/pair902.py N M ... merges the numbered parts and prints compile errors;
inst902.py installs a verified merge; go902.py is the greedy pass (no apply); vall902.py re-verifies all.
