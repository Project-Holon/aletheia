# Wave 16 lane: areaman, pms_draw, musical_dist_save, bmp_menu, bgwinfrm, double3Ddisp

EXACT 0 / MATCH 0 / DIFF 7 (two moved a long way, five flat).

- pms_draw.c 0x0202E1F0 (Thumb, 412): 400/412 at 371 -> 412/412 at 21. Lever: the stack parameter w reused as the ws pointer (`func_02024570(ws, w); w = ws;`, later calls pass w), which is the image's promoted r7; plus n declared before cnt (spill slots). Residue: o/w swapped r6/r7, nothing else. Permuter only finds `return o` (not value-preserving).
- double3Ddisp.c 0x0204E914 (ARM, 248): 35 -> 15. All 120 declaration orders compiled; `i, x, y, k, oam` fixes the counter coalescing (k ip, clear counter and x r2). Residue: in-place oam base and the attr01/attr2 registers in the inner loop (extra push of r3/sb).
- bmp_menu.c 0x0201FDA0 (Thumb, 276): 2 -> 2. 432-point parameter type grid (base/pal/pos x heap), callee prototypes from callee bodies (F73C, F9D0, 020450F0), MI_CpuClear8 inline, anneal 1500: flat.
- areaman.c 0x0203422C 17 -> 17 and 0x020343C0 44 -> 44: declaration facts once each (non-const tables, flexible `bits[]`, int start, callee widths, const callee pointer, unprototyped callees): flat.
- musical_dist_save.c 0x0200CA98 (Thumb, 392): 147 -> 147. Parameter reuse in the tail (id/form/acc/j), id u16 grid, operand orders: flat; ClrBit/SetBit inlines 468 bytes.
- bgwinfrm.c 0x0202CC70 (Thumb, 238): 236/176 unchanged; image reading added (bound-first guard loads, one ldrh for w/h, y's three copies).
- Compilers: ../2.0/sp2 and sp2p2 tried on pms (436) and E914 (240); 1.1p1 stays everywhere.

Notes appended: pkt_0202E1F0, func_0204E914 (both with the new best source), pkt_0201FC5C, pkt_0203422C, sub_020343C0, pkt_0200CA98, func_0202CC70 (.c.txt). Headers: pms_draw.h (w reuse), double3Ddisp.h (15-byte state).

New lever worth an idiom: a stack parameter dead after its first use, reassigned to a local's address (`w = ws`), keeps that address in a callee-saved register; a fresh pointer local is copy-propagated and rematerialised instead.

Seeds: none. Shards verified: none (nothing filed; no packet's entries changed).
