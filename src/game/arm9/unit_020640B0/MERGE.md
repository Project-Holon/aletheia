# unit_020640B0 (arm9)

Merge status: 2 files remain.

- `unit_020640B0_p01.c`: func_020640B0 (compiler 1.1p1, flags -O4,p, lang c99, isa arm)
- `unit_020640B0_p02.c`: func_020640DC, func_02064100, func_02064120 (compiler 1.1p1, flags -O1, lang c99, isa arm)

Blockers between adjacent files:
- `unit_020640B0_p01.c` | `unit_020640B0_p02.c`: settings differ (1.1p1/-O4,p/c99/arm vs 1.1p1/-O1/c99/arm); never merged across a settings change.
