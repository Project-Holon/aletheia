# unit_02059F6C (arm9)

Merge status: 3 files remain.

- `unit_02059F6C_p01.c`: func_02059F6C (compiler 1.1p1, flags -O4,p, lang c99, isa arm)
- `unit_02059F6C_p02.c`: func_02059FA8 (compiler 1.1p1, flags -O4,p, lang c99, isa arm)
- `unit_02059F6C_p03.c`: func_0205A10C, func_0205A11C (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)

Blockers between adjacent files:
- `unit_02059F6C_p01.c` | `unit_02059F6C_p02.c`: members include "libc/string.h", which match.py cannot find from src/game (no libc/ next to the file, SDK include dir missing in this checkout); the members cannot be re-verified here, so no merge was tried across them.
- `unit_02059F6C_p02.c` | `unit_02059F6C_p03.c`: settings differ (1.1p1/-O4,p/c99/arm vs dsi/1.1p1/-O4,p/c99/arm); never merged across a settings change.
