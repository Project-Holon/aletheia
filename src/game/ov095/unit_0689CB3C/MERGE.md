# ov095 unit_0689CB3C: boundaries left

Each boundary below is a real file boundary for now (uncovered bytes, an ARM/Thumb switch, a lang change, or an asm veneer).

- unit_0689CB3C_p01.c | unit_0689CB3C_p02.c: 132 uncovered bytes before the next part (stub, pool or padding)
- unit_0689CB3C_p02.c | unit_0689CB3C_p03.c: 16 uncovered bytes before the next part (stub, pool or padding)
- unit_0689CB3C_p03.c | unit_0689CB3C_p04.c: 48 uncovered bytes before the next part (stub, pool or padding)

Round 3 note (lane r3_ov08): p01 | p02 gap 0x0689CCB4..0x0689CD37 (132 bytes) is two unmatched thumb leaf functions at 0x0689CCB4 and 0x0689CCF8 (push {r3,r4}; loops over a byte count at +0x42 comparing words at +0..; first returns two halfwords sum, second returns one halfword via r2). They need to be matched as hidden functions before p01 and p02 can merge. The other gaps are 16-byte linker veneers (bx pc, ldr ip, bx ip, .word).
