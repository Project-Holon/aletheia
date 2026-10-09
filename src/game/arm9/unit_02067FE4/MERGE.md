# unit_02067FE4 (arm9)

Round 4 state: 5 files remain, all byte-exact and all compiler ../2.0/sp2, -O4,p, c99. The old 1.1p1 members (func_020682DC, func_02068A18/A68, func_02068FC4, func_02069818) were proven EXACT under ../2.0/sp2 and joined their neighbours, so no compiler boundary is left. No uncovered code between files.

- `unit_02067FE4_p01.c`: func_02067FE4 .. func_020682DC
- `unit_02067FE4_p02.c`: func_020682F8 .. func_02068A68
- `unit_02067FE4_p03.c`: func_02068AE8 .. func_02068FC4
- `unit_02067FE4_p04.c`: func_02068FF0 .. func_020696F4
- `unit_02067FE4_p05.c`: func_02069818

Blockers (all struct or prototype views, none is a compiler change):
- p01 | p02: NNSG2dFont, NNSG2dFontInformation, NNSG2dFontGlyph, NNSG2dFontWidth are now one definition each (done this round, both files still EXACT). The merge now stops at a global or parameter seen as `struct Shift` in one part and a plain u32 in the other (merged line ~623).
- p02 | p03: merge compiles but the bytes change (DIFF). Not yet located.
- p03 | p04: p04 has a declaration the merge cannot parse (`;` expected, merged line ~115) and an anonymous struct versus int conversion (line ~194).
- p04 | p05: `;` expected (merged line ~84); functions func_020694D8 and func_020696F4 have an arity mismatch with their callers.
