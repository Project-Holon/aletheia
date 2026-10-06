# unit_02069D14 (arm9)

Merge status: 3 files remain.

- `unit_02069D14_p01.c`: func_02069D14, func_02069D68 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)
- `unit_02069D14_p02.c`: func_02069E20 (compiler ../2.0/sp2, flags -O4,p -proc arm946e, lang c99, isa arm)
- `unit_02069D14_p03.c`: func_02069E88, func_02069F08, func_02069F7C, func_02069FD0, func_02069FE4, func_02069FF8, func_0206A00C (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)

Blockers between adjacent files:
- `unit_02069D14_p01.c` | `unit_02069D14_p02.c`: settings differ (dsi/1.1p1/-O4,p/c99/arm vs ../2.0/sp2/-O4,p -proc arm946e/c99/arm); never merged across a settings change.
- `unit_02069D14_p02.c` | `unit_02069D14_p03.c`: settings differ (../2.0/sp2/-O4,p -proc arm946e/c99/arm vs dsi/1.1p1/-O4,p/c99/arm); never merged across a settings change.
