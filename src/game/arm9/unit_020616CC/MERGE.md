# unit_020616CC (arm9)

Merge status: 2 files remain.

- `unit_020616CC_p01.c`: func_020616CC (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)
- `unit_020616CC_p02.c`: func_02061808, func_02061824, func_02061840, func_02061860, func_02061878, func_0206188C, func_020618B8, func_020618E4, func_02061908 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)

Blockers between adjacent files:
- `unit_020616CC_p01.c` | `unit_020616CC_p02.c`: settings differ (../2.0/sp2/-O4,p/c99/arm vs dsi/1.1p1/-O4,p/c99/arm); never merged across a settings change.
