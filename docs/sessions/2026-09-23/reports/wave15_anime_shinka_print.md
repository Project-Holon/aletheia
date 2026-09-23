# Wave 15, anime/shinka/print lane (ica_anime, shinka_check, printsys, gf_font, g3d_system)

EXACT 2, MATCH 0, DIFF 9 (1 greatly improved, 8 unchanged). All headers already existed.

- shinka_check 0x0201B970: 124/126 (20 out) -> EXACT*. Compound `pp += (u8)amount` keeps the new PP in r4 (the missing `adds r2, r4, #0`). src/matched/sub_0201B970.c.
- g3d_system 0x020479D8: 136/136 (22 out) -> EXACT. Library shape: the five globals are one NNS_G3dGlb (0x02148B4C; camPos/camUp/camTarget +0x240.., cameraMtx +0x4C, flag +0xFC) and the body is NitroSystem's inline NNS_G3dGlbLookAt(&ctx->view0, &view1, &view2). src/matched/func_020479D8.c.
- gf_font 0x0201DB20: 154/156, 139 out -> 15 out, size exact. NNSG2dFontCodeMap chain with mapInfo as a member array, `if (m) rebase; else return 0;`, the +0x88 re-read spelled `*(u8 **)((u8 *)f + 0x88)`. Residue: m/lo/hi rotation (r6/r5/r4 vs r4/r5/r6); all 120 declaration orders 15 or 18.
- ica_anime 0x02011688: 52/56, 26 out unchanged. Two shapes each give one of the two copies (named `i = idx % n` gives the multiply copy, `idx %= n` the post-call copy), never both.
- ica_anime 0x02011D9C: 272/272, 14 out unchanged as best. The single-call `off = 0; if (flag == 0) off = 0x191;` fixes the off placement exactly, leaving only the CSE'd 4 of `4 << 14` (268 bytes); that CSE is pressure-dependent (vanishes when a0 spills), no spelling moves it. Overlay-capped at MATCH anyway.
- shinka_check 0x0201B2B0: 1116, 12 out unchanged (heap ldr hoist; 11 more spellings flat or worse).
- printsys 0x0201C7D0: 2 out under sp2 and now sp2p2 too; 1.1p1 37. 0x0201D768: 66 unchanged (enum counter, const, inline ring step, compound all flat or worse). 0x0201C8BC: 17 unchanged (non-constant array initialiser is rejected by mwcc).
- gf_font 0x0201DBBC / 0x0201DBF4: 12 each unchanged under all three compilers; inline wrappers, enum width, by-value out flat. Only matched analogue storing the stack word last has a nested call argument (0x0202DA48).
- g3d_system 0x02047564: 200/200, 11 out unchanged under all three compilers.

Seeds: none (both closures are already labelled starts; 0x0201B970's `*` is the 2-byte pad).

Shards verified twice: pkt_0201B970 (new), pkt_020479D8.
Notes appended: sub_0201B970 (closure), pkt_020479D8 (closure), sub_0201DB20 (new best source), pkt_02011688, pkt_02011D9C, sub_0201B2B0, pkt_0201C7D0, func_0201D768.diff, pkt_0201C8BC, sub_0201DBBC, pkt_02047564.
Headers extended: shinka_check.h, g3d_system.h (NNS_G3dGlb identification), gf_font.h (CMap chain).
Lever for other lanes: 0x02148B4C is NNS_G3dGlb; func_02046B40-style camera code is NNS_G3dGlbLookAt.
