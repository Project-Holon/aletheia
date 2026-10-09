# unit_02072374 (arm9)

Round 4 state: 2 files remain, both byte-exact (tools/match.py). Both are compiler ../2.0/sp2, -O4,p, c99.

- `unit_02072374_p01.c`: func_02072374 .. func_02072758
- `unit_02072374_p02.c`: func_02072794, func_020727B4, func_02072894, func_020728E8

Boundary between them:
- 0x02072788, 12 bytes (`ldr ip, [pc]; bx ip; .word`) that no function covers. It is a linker veneer, so a real file boundary. It cannot be written in C.

Done this round: the three 1.1p1 parts were proven EXACT under ../2.0/sp2 (headers set), then merged. g_0214BAC0 is one `struct Sys` in every part (idx, pending, tag, f0c, cb10, cb20).
