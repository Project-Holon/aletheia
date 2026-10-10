# unit_02064D70 (arm9)

Round 12 state: 4 files remain (was 15), all byte-exact (tools/match.py).

- `unit_02064D70_p01.c`: func_02064D70 .. func_02065134 (compiler 1.1p1; was p01 to p03)
- `unit_02064D70_p02.c`: func_020651B8 .. func_02065DB4 (compiler ../2.0/sp2; was p04 to p12)
- `unit_02064D70_p03.c`: func_0206615C, func_02066380, func_020663D0 (../2.0/sp2; was p13)
- `unit_02064D70_p04.c`: func_020664CC .. func_02066754 (../2.0/sp2; was p14 and p15)

All parts now use one canonical set of types (RendererBss, RendererData,
NNSG2dRendererInstance, NNSG2dRenderSurface, MCMMtxState, MtxFx32, ...) by offset,
except p03 (see below).

Boundaries:
- p01 | p02: compiler change. func_02065020 and func_02065134 need 1.1p1 (2.0 loses the
  predication); the 2.0 pieces use 2.0 only features. Tested both ways in round 5.
- p02 | p03 and p03 | p04: p03 (func_0206615C, func_02066380, func_020663D0) is
  byte-exact only when g_02147B88 is the small 0x10-byte struct (fields up to
  stackPos_) with g_02147B98, g_02147C18, g_02147D18, g_02148018 as separate externs.
  With the big RendererBss (the arrays inside, which p02's func_02064EDC and p04's
  func_020664CC/func_02066620 need for their member spellings) the scheduler hoists
  the stackPos_ load above the stores to the local matrix in func_020663D0 (44 bytes
  out). The same effect in reverse breaks p04 with the small struct (176 bytes out).
  Tried: dropping any one array, padding the small struct to the same size, cast
  views of the small head, a local slot copy, member spelling inside the function.
  None closes both. One declaration of g_02147B88 cannot serve both, so the boundary
  stays.
