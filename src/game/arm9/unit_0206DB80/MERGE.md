# unit_0206DB80 (arm9)

Merge status: 4 files remain.

- `unit_0206DB80_p01.c`: func_0206DB80 (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)
- `unit_0206DB80_p02.c`: func_0206DBDC, func_0206DBF4 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)
- `unit_0206DB80_p03.c`: func_0206DC00 (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)
- `unit_0206DB80_p04.c`: func_0206DDA4, func_0206DE88 (compiler dsi/../2.0/sp2, flags -O4,p, lang c99, isa arm)

Blockers between adjacent files:
- `unit_0206DB80_p01.c` | `unit_0206DB80_p02.c`: settings differ (../2.0/sp2/-O4,p/c99/arm vs dsi/1.1p1/-O4,p/c99/arm); never merged across a settings change.
- `unit_0206DB80_p02.c` | `unit_0206DB80_p03.c`: settings differ (dsi/1.1p1/-O4,p/c99/arm vs ../2.0/sp2/-O4,p/c99/arm); never merged across a settings change.
- `unit_0206DB80_p03.c` | `unit_0206DB80_p04.c`: the same compiler (dsi/../2.0/sp2 is ../2.0/sp2), but the two members use struct GxState with different fields (busy, f8 missing in the other view): struct GxState needs one unified definition.
