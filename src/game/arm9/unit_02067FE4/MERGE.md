# unit_02067FE4 (arm9)

Translation unit 02067FE4..020698F8. Parts left (11), all byte-exact:

- The parts alternate between compiler 1.1p1 and ../2.0/sp2 by address
  (p01 2.0, p02 1.1p1, p03/p04 2.0, p05 1.1p1, p06 2.0, p07 1.1p1, p08..p10 2.0,
  p11 1.1p1). One file cannot use two compilers, so these stay separate; the
  TU boundary is probably wrong (a later boundary pass should split it).
- p03 + p04: same compiler, but the merged file gives DIFF (the shared static
  inline helpers GetCharacterSize, NNS_G2dFontGetCellHeight/Width/Bpp change the
  code when written once).
- p10 merges func_02069184..func_020696F4 (Ctx unified: void *f08, s32 f0C).
