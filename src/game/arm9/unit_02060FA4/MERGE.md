# unit_02060FA4 (arm9)

Merge status: 2 files remain.

- `unit_02060FA4_p01.c`: func_02060FA4 (compiler ../2.0/sp2, flags -O4,p -proc arm946e, lang c99, isa arm)
- `unit_02060FA4_p02.c`: func_02060FEC, func_02061048, func_020610A0, func_020610B4, func_020610E0, func_02061118, func_02061124, func_02061158, func_02061184 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)

Blockers between adjacent files:
- `unit_02060FA4_p01.c` | `unit_02060FA4_p02.c`: settings differ (../2.0/sp2/-O4,p -proc arm946e/c99/arm vs dsi/1.1p1/-O4,p/c99/arm); never merged across a settings change.
