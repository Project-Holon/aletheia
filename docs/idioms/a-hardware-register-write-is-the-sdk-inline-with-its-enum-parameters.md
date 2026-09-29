# A hardware register write is the SDK inline with its enum parameters

summary: A store to a 0x04xxxxxx display register, above all a
read-modify-write whose constants stay unfolded or whose field extractions
all happen before any shift, is an SDK `static inline` from
`sdk/TwlSDK/include/nitro/gx/g2.h` or `gx_bgcnt.h`: copy the inline's body,
its enum or BOOL parameters and its `volatile` register macro, and call it
with the game's arguments; rewriting its effect by hand does not match.

Found in: src/matched/ov/ov082_func_021F5648.c (0x021F5648),
src/matched/ov/ov091_func_021B907C.c (0x021B907C); earlier precedent
src/matched/arm9/sub_0200FEBC.c.

- ov082 0x021F5648 writes BG3CNT (0x0400000E) from four bitfields. The
  original extracts all four fields, then shifts and ORs them in the order
  D, C, B, A: that is `G2_SetBG3ControlText(screenSize, colorMode,
  screenBase, charBase)` evaluating its arguments before its body. Twelve
  hand-written extraction orders, u16 and u32 locals and a bitfield struct
  all stayed 16 bytes out; the inline with its four enum-typed parameters is
  EXACT.
- ov091 0x021B907C writes WIN0H/WIN0V, WININ (0x04000048), WINOUT
  (0x0400004A) and BLDCNT (0x04000050). The original keeps `| 0x1f` and
  `| 0x20` apart where every constant spelling folds them into `0x3f`: that
  is `G2_SetWnd0InsidePlane(wnd, effect)` and `G2_SetWndOutsidePlane`,
  whose `if (effect) tmp |= 0x20;` stays a separate step. The blend call is
  `G2_SetBlendBrightness`, which passes `(u32)&reg_G2_BLDCNT` to
  func_0207D658.

The register macros are `(*(volatile u16 *)0x0400xxxx)`; the file needs a
` * volatile:` header line naming the registers.
