# pokeparty (arm9)

Parts p01..p12 (from 16 members). Compiler: p05, p09, p10 use plain 1.1p1 (not dsi/1.1p1): real boundaries.
Left:
- p02|p03: c99=DIFF.
- p04..p08: struct Waza has four local views (Waza_0201B7B4, Waza_0201BEB8, Waza_0201C020, Waza_0201C1C8);
  merging gives illegal implicit conversions between them. Needs one canonical Waza by offset.
- p10|p11: PrintCtx_0201C7A4 vs Scratch views of one object.
- p11|p12: c99=DIFF.

Round 4 note: the header 'compiler: 1.1p1' (p05, p09, p10) compiles with the same dsi/1.1p1 compiler (restructure.py raises no settings conflict, and tcbl/ui/time_icon parts of that kind merged EXACT). So p05/p09/p10 are type boundaries, not compiler boundaries. p09|p10: sub_0201C808 takes void * in p09 but callers pass u32 (line 115).
