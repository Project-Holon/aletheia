# net_err (arm9)

Merged by lane r3_a903: 5 parts became 4. p01 now holds p01+p02 (func_0203CF5C declared unprototyped,
`extern u32 func_0203CF5C();`, because p01 calls it with an argument and p02 without).

Remaining boundaries p01|p02|p03|p04 (new numbering):
- The module object at 0x0214617C is viewed five ways: `u8 g_0214617C[]`, `unsigned int g_0214617C[]` (p03),
  `u32 *g = (u32 *)0x0214617C` (fixed-address casts in p01 and p04), NetErrWork (p04, p05 style typedef,
  0x44 bytes) and struct Obj03039 casts. Merging p03 into p01 gives DIFF because the `unsigned int` view
  becomes `u8`-typed: func_0200FB38 and func_0200FB4C change ldr/str to ldrb/strb. Needs ONE canonical
  struct for 0x0214617C covering +0x00..+0x64 (state +0x2C, count +0x44, +0x59 byte, +0x5C, +0x60 words);
  NetErrWork in net_err_p04.c is the start of it.
- p04 vs the rest: `void *` + int arithmetic on func_0203D798() in one view, `u8 *` in another (casts needed).
- p05 vs rest: G2_SetBG1Control redeclared with different parameter enums (typed enum names clash with the
  per-part typedef enums GXBGScrSizeText and friends); unify the enum typedefs first.
