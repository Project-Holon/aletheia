# unit_0205CCE4 (arm9)

Merge status: 2 files remain.

- `unit_0205CCE4_p01.c`: func_0205CCE4, func_0205CD24, func_0205CE84 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)
- `unit_0205CCE4_p02.c`: func_0205CF30 (compiler 1.1p1, flags -O4,p, lang c99, isa arm)

Blockers between adjacent files:
- `unit_0205CCE4_p01.c` | `unit_0205CCE4_p02.c`: settings differ (dsi/1.1p1/-O4,p/c99/arm vs 1.1p1/-O4,p/c99/arm); never merged across a settings change.

- `func_0205CF24.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
