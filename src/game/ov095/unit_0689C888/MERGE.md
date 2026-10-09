# ov095 unit_0689C888: boundaries left

Each boundary below is a real file boundary for now (uncovered bytes, an ARM/Thumb switch, a lang change, or an asm veneer).

- unit_0689C888_p01.c | unit_0689C888_p02.c: 114 uncovered bytes before the next part (stub, pool or padding)
- unit_0689C888_p02.c | unit_0689C888_p03.c: 140 uncovered bytes before the next part (stub, pool or padding)

Round 3 note (lane r3_ov08): both gaps (0x0689C8AC..0x0689C91B and 0x0689C980..0x0689CA0B) are runs of 16-byte tail thunks (ldr r1,=data; ldr r3,=func_0689C888; movs r2,#N; bx r3; .word; .word) plus a few small leaf functions near 0x0689C9C0 and 0x0689C9E4 (compare-and-table readers). Thunks of this shape did not compile as plain C in earlier lanes (two constant pool words); the leaves are unmatched functions.
