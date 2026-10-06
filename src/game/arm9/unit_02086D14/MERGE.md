# unit_02086D14 (arm9)

Merge status: 2 files remain.

- `unit_02086D14_p01.c`: OS_SetProtectionRegionParam (compiler 1.1p1, flags -O4,p, lang c99, isa arm)
- `unit_02086D14_p02.c`: func_02086DB0 (compiler 1.1p1, flags -O4,p, lang c99, isa arm)

Blockers between adjacent files:
- `unit_02086D14_p01.c` | `unit_02086D14_p02.c`: merging changes the code (c99=DIFF) once the asm definition of OS_SetProtectionRegionParam takes the same parameters as its caller prototype; keep separate.
