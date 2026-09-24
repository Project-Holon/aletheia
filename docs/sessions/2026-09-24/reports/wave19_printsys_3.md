# Wave 19 lane printsys_3 (19M)

Per address, bytes out before -> after, verdict, what moved it:

- 0x0201D768 (92 bytes): 66 -> 63, DIFF. The base half of the residue is closed: the second def of base is written from p again (`base = (u8 *)p + 0x18`) with the start read between the two defs (permuter anneal, seed 3201). The compile then keeps both base stores, places base [sp,#8] and start [sp,#0xc] as the image does, defines them before the entry guard, and the return reads both slots exactly. `base = base + 0x18` in the same position stays 66. What remains is only the head/total spill tie: sweeps of 600 (types x scope x declaration order) and 44 (statement positions x loop form) compiles from the new source reach 63 at best. Also flat: base before p, base as a parameter, a narrow u8 offset, base as u32, a return temporary (66); `u8 *volatile base` 70.
- 0x0201DB20 (154 of 156): 15, unchanged, DIFF. 12 measurements: hi/lo as an array or struct (18), m in an inner block, for-init, inline GetMap/Rebase/Search helpers (15 or 18), a function-scope u32 offset, a u16 flag, a u16 count temporary (15).
- 0x0201C7D0: 2 (sp2) / 37 (1.1p1), unchanged, DIFF, no pin. Sharper mechanism: 1.1p1 schedules the stacked fifth argument (`str r4, [sp]`, z) straight after the first call, so z dies and the cached address takes r4; the image stores it last. sp2 does the same on some spellings. The z width sweep (25), array/struct/accumulator forms, volatile w/v/z, and schedule/peephole pragmas: 37 at best. The sp2 v/w width sweep (60): 2 at best. There is no documented sp2 tell, so no pin.

Files written: new dated sections at the end of docs/notes/func_0201D768.diff.c.txt (with the 63 best source), docs/notes/sub_0201DB20.c.txt and docs/notes/pkt_0201C7D0.c.txt; this report.

Shards verified: none (nothing EXACT).

Seeds: none new. Permuter seed used: 3201 (0x0201D768 only).

For the integrator: stage the three notes and this report. No idiom was written because nothing closed. 0x0201D768 now differs only in the head/total colouring, which is the same tie shape as 0x0201DB20's m/hi rotation.
