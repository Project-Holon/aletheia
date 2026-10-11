# unit_0272E9E8.c (twl)

Parts: p01 0272E9E8, p02 0272EBDC, p03 0272F368, p04 0272FB10, p05 0272FD40.

Round 18 (lane L09) wrote func_0272EA74, func_0272F368, func_0272F570, func_0272F740 and func_0272F8A8 as real C (all EXACT). p02, p03 (old) and p04 (old) are now one part (p02). The old p04|p05 boundary is now p02|p03: F0BC (below) lies at its end.

Round 18 (lane L09b): func_0272F9C4 written as real C (EXACT). Its callback registration calls `func_020848EC`, the 12-byte arm9 tail-call stub at 0x020848EC that jumps to func_0273126C (the original bl lands on that stub, not on func_0273126C). Its callback parameter is an unprototyped `void (*cb)()` so that func_0272FE54 (ov172 passes `void (*)(void)`) and func_0272FFC8 (func_02730090) keep their types. func_0272FE54, func_0272FEF4 and func_0272FFC8 were already EXACT C. The f34/f38 callbacks of the ED4C object now take `void *` as second argument, like the other views (func_0272ED4C: `void *a`).

Empty stand-in left (address, bytes):
- p02: func_0272F0BC (684). Best draft: scratch SP/r18/L09b/v3.c, 292 bytes differ (676 bytes against 684). Right: layout arithmetic, both list loops, stack argument order, per*0x14 recomputed after the first loop (needs `hdr->f204 * 0x14` in the nodes_a offset, not the local `per`). Wrong: the original keeps the constant 0x14 in one register (sb) from the first mul to the node loop; we hoist a second `mov #0x14` into the preheader of the pad loop (mwccdbg regalloc: vreg v172 is hoisted to the first loop preheader, separate from the entry-block constant v154). Registers then colour differently (per r5 and psz r4 in the original).
- func_0272EBDC stays asm: same layout formula with base 0. A C version with the same formula (SP/r18/L09b/eb2.c) is 88 bytes against 92: the original has `add r3, r3, #0` and `mov ip, #0` (start is a live variable, probably the layout routine inlined with base 0, shared with F0BC).

Blockers:
- p01|p02: func_0272EA74 is followed by 64 bytes of key data (0x0272EB9C..0x0272EBDC, read by F0BC through data_0272EB9C) that belong to its extent. Until a definition lays out those 64 bytes in .text, the merged TU is DIFF and p01 reports EXACT* in the manifest.
- p02|p03: F0BC stand-in at the end of p02 lays out 0 bytes.
- p01|p02 key data: the repo has no mechanism that puts bytes taken from the user's ROM into .text of a source file (tools/datagen.py only generates separate data translation units under build/data/, gitignored). The 64 bytes at 0x0272EB9C..0x0272EBDC therefore cannot be laid out in the source. The split stays until such a mechanism exists (for example a gitignored generated include read inside the initializer).
- Struct Obj is complete in p02 (field `hash` added), and the p01 view (struct Request, data_02732DA8) is separate.
