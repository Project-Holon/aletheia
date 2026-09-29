# A store written out in each arm (no early return) is cross-jumped into one shared store block

summary: when the image has one `movs r0,#0x73; lsls r0,r0,#2; str r1,[r5,r0]` block that several arms reach with `movs r1,#k; b`, and the last arm also ends at the shared epilogue with `b`, write the identical store in every arm and let the function fall out of the if/else chain; a `return v;` in the last arm or a single `s = k;` store after the chain gives a private epilogue or a hoisted constant.

Found in: src/matched/ov/ov099_func_021BC620.c (0x021BC620), src/matched/ov/ov099_func_021BC468.c (0x021BC468)

021BC620: three arms set the state word at +0x1CC to 0x96 / 0xa6 / 0x52 (the last also calls
func_021BA8EC) and the else arm stores 0x8a after a byte store. The image shares one store block
between them. Spelling each `*(u32 *)(p + 0x1CC) = k;` in its own arm, with the `if (r == -1)
return v;` guard the only early return, is exact; an `int s` set per arm with one store after
the chain, or `return v;` inside the third arm, is 4 bytes long with its own `pop`.

A related `for` lever from func_021BCC58: `i < 8u` (unsigned bound on a signed counter that is
also used for signed `% 4` and `/ 4`) gives `blo` where `i < 8` gives `blt`, and a `u32 m = x &
mask` local declared before the `int i` puts the mask in r3 and the counter in r4.
