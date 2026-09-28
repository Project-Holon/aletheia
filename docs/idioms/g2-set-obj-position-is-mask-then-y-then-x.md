# G2_SetOBJPosition is spelled mask first, then y, then x

summary: the inline OAM position setter that matches every libdwcutil scene is
`attr01 = (attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16)`; the x-first spelling
also matches when y is the constant 0 (the or vanishes), but reverses the two `orr`s
whenever y is live.

Found in: src/matched/ov016_func_021C6034.c (0x021C6034, setOffset in scenesetaplist.o);
also src/matched/ov016_func_021C98E4.c (setOffset in scenesetlist.o)

The original emits `and rA, rA, mask` / `orr rA, rA, y&0xff` / `orr rA, rA, x<<23 lsr 7`.
With `((x & 0x1FF) << 16) | (attr & mask) | (y & 0xFF)` (the spelling in dispObj,
ov016_func_021C9610.c, where y is 0) the compiled order is mask, x, y. The mask-first
spelling reproduces setOffset in both scenes and still matches dispObj and every keyboard.o
function, so it is the one definition to use.
