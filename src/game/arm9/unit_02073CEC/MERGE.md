# unit_02073CEC (arm9)

Merge status: 2 files remain.

- `unit_02073CEC_p01.c`: func_02073CEC, func_02073D5C, func_02073D7C (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)
- `unit_02073CEC_p02.c`: func_02073DFC (compiler ../2.0/sp2, flags , lang , isa arm)

Blockers between adjacent files:
- `unit_02073CEC_p01.c` | `unit_02073CEC_p02.c`: settings differ (dsi/1.1p1/-O4,p/c99/arm vs ../2.0/sp2///arm); never merged across a settings change.
