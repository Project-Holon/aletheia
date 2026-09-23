# Wave 16, print/font/anime lane (printsys, gf_font, ica_anime, shinka_check, g3d_system)

EXACT 3 (+1 EXACT*), MATCH 0 new, DIFF 7 unchanged, 1 report-only. The lever that closed all four: `const` on a read-only pointer parameter.

- g3d_system 0x02047564: 200/200, 11 out -> EXACT. `const struct G3dOwner *a1` (and the const record field): the a1->f04 load may pass the tag store, so the tag's pool load issues first as in the image. It is not camera code: it allocates an anim record and calls NitroSystem-style anim getters. src/matched/func_02047564.c.
- gf_font 0x0201DBBC: 56/56, 12 out -> EXACT. `const struct Font *f` moves the outgoing stack store of `out` to last. src/matched/sub_0201DBBC.c.
- gf_font 0x0201DBF4: 78/80, 12 out -> EXACT* (2-byte pad). Same lever. src/matched/sub_0201DBF4.c.
- gf_font 0x0201DB20: 15 unchanged (chain-step spellings, block-scope lo/hi, permuter hill chases the 156 extent).
- printsys 0x0201C7D0: 2 (sp2/sp2p2) / 37 (1.1p1) unchanged under const params and globals. 1.2 builds give 64 bytes. The tells are split (kept-constants says 2.0, stacked-u16 base says 1.1p1), so no pin.
- printsys 0x0201D768: 66 unchanged. The residue is a spill-cost tie (split head web against total).
- printsys 0x0201C8BC: 17 unchanged. Hypothesis in the note: done is a spill slot, not a volatile, but the zero gets constant-propagated.
- ica_anime 0x02011688: 26 unchanged. The early-return polarity gives 50/14 with the branch inverted, so not usable.
- ica_anime 0x02011D9C: 14 unchanged, not re-attempted (4<<14 rematerialisation, overlay-capped). 0x020120C0: still MATCH, blocked on ov021_id (0x15 has one pool word image-wide).
- shinka_check 0x0201B2B0: 12 unchanged (const mon/party, HeapID enum, u16 callee params, address-taken pidHigh all flat).

Shards verified twice: pkt_02047564 (func_02047564 EXACT), pkt_0201DB20 (0x0201DBBC EXACT, 0x0201DBF4 EXACT*, 0x0201DC44 EXACT).
Seeds: none (every closure is already a labelled start).
Notes appended: pkt_02047564, sub_0201DBBC (closures); pkt_0201C7D0, func_0201D768.diff, pkt_0201C8BC, sub_0201DB20, pkt_02011688, sub_0201B2B0.
Headers updated: gf_font.h (const prototypes for DBBC/DBF4), g3d_system.h (func_02047564 note).
Lever for other lanes: if a call's stack-argument store or a pool load is scheduled in the wrong place, try `const` on read-only pointer parameters first.
