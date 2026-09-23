# Wave 14, net lane (net_state, wm_icon, net_err, net_save)

EXACT 12 functions (11 worklist targets plus the leaf 0x0203B01C), MATCH 3, DIFF 1.
- net_state: EXACT 0x0203B018 (unit_0203B018 with leaf 0x0203B01C), 0x0203B52C (the pool word is 0x0203C00C, not 0x0203B40C: a header misread), 0x0203AE20 (NitroSDK MATHRandContext64 / MATH_InitRand64).
- wm_icon: EXACT 0x02036DC8 (a fourth switch label, 1D_256K 0x00300010), 0x02036CA8 (the SDK G2_SetOBJAttr inline). New header docs/families/wm_icon.h.
- net_err: EXACT 0x0200FEBC (G2_SetBG1Control with the SDK's enum parameter types). MATCH 0x0200F734 (src/pending/sub_0200F734.c; header now pins `thumb ov009`).
- net_save: EXACT 0x02010DCC, 0x02010DF4 (enum loop counter), 0x0201104C, 0x020110CC (callee arity: func_0201BA34(box), func_0201AB08(box), func_02017D30(rec); the record is its own local). MATCH 0x02010AC4, 0x02010C34 (pool-as-Thumb wall at 0x02010B84..97 / 0x02010D84..97, not worked, blockers already in their headers). DIFF 0x020111BC (appended to docs/notes/func_020111BC.c.txt).

Seeds (integrator):
- 0x0203B01C, ARM, witness src/matched/unit_0203B018.c (a unit member; listed on its function: line).

Overlay callee that needs evidence:
- 0x02156460, Thumb, ov009. It is already labelled in ov009, but its only caller image-wide is 0x0200F7A8 inside sub_0200F734. It needs a sole-ref/code rule for overlay labels (a tool change) or a matched ov009 entry.

Near misses:
- 0x020111BC: 44/44 bytes, 3 bytes out (s64-return form). The image loads the pool pointer into r1 (`ldr r1, [pc, #0x20]`), the compile into r3. The s32 forms are 48 bytes because mwcc coalesces the returned value with the _ll_mul operand copy.

New idiom: docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
Headers updated: net_state.h (the B018/B40C "exceptions" are closed), net_save.h, net_err.h. Notes appended: pkt_0203AE20, pkt_02036DC8, pkt_02036CA8, sub_0200FEBC, pkt_02010DCC, pkt_0201104C, pkt_0201104C.sub_020110CC, func_020111BC.
Tool caveat: match.py's `matched` class refuses any source outside the repo (source_key), so scratch-dir runs under-report. Test in src/pending.
Deleted pending files (now in src/matched): func_0203B52C.c, func_02010DCC.c, func_02010DF4.c.

Shards verified twice, all entries EXACT: pkt_0203B018, pkt_0203B038, pkt_0203B52C, pkt_0203AE20, pkt_02036DC8, pkt_02036CA8, pkt_0200FEBC, pkt_02010DCC, pkt_0201104C.
