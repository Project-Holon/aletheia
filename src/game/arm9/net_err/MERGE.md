# net_err (arm9)

Round 6 (lane sa9): old p01+p02 merged (EXACT). g_0214617C is `u32 g_0214617C[]` in that part now
(`*(u32 *)(g + 0x44) == 1` became `g_0214617C[0x11] == 1`). 3 parts left (new p02 = old p03, p03 = old p04).

Remaining boundaries p01|p02|p03:
- The module object at 0x0214617C is viewed through `u8 g_0214617C[]` plus `u8 *g` locals (p02), `u32 g_0214617C[]` (p01),
  `NetErrWork *` (p03, struct with state +0x2C, 0x44 bytes). Merging p01 with p02 gives CCERR (u32[] to u8 * conversion).
  The code in p02 (func_0200FC0C, sub_0200FD38) goes through a local `u8 *g = g_0214617C` because the extern spelled
  directly folds to a second pool word; a struct global must be tried with a local struct pointer to keep that.
  Needs ONE canonical struct for +0x00..+0x64 (state +0x2C, count +0x44, +0x59 byte, +0x5C, +0x60 words).
- p03: G2_SetBG1Control redeclared with different parameter enums (typedef enums GXBGScrSizeText and friends clash):
  unify the enum typedefs first.
