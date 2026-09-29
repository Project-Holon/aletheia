# A call result narrowed in r0 and shifted into r1 is a `u8` local, not an inline cast

summary: when the image emits `lsls r0, r0, #24; lsrs r1, r0, #24` (narrow in r0, shift-copy into r1) for a call result that becomes the second argument of the next call, assign it to a `u8` local first; `f(b, (u8)g(k))` copies to r1 first (`adds r1, r0, #0; lsls r1; lsrs r1`) and is one instruction longer.

Found in: src/matched/ov/ov093_func_021D901C.c (0x021D901C), src/pending/ov/ov093_func_021D8FCC.c (0x021D8FCC)

Both functions call `func_021B9A24(b, func_021D775C(k))` where the original
narrows the returned int to a byte. With the extern's second parameter `u8`
(passed uncast) or `int` with a `(u8)` cast at the call, the compiler emits
`adds r1, r0, #0` and narrows in r1: 2 bytes too long, branch targets shifted.
`u8 k; k = func_021D775C(4); if (func_021B9A24(b, k)) ...` with the extern
taking `int` gives the original `lsls r0; lsrs r1, r0` pair, EXACT*.

Contrast: `func_021D9070` (0x021D9070) needs the opposite spelling, the inline
`(u8)func_021D775C(4)` cast, because there the narrowing happens in r1 in the
original (`adds r1, r0, #0; lsls r1, r1, #24`).
