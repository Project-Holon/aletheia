# unit_020911D4 (arm9)

10 parts (round 16, lane L10; was 14). Part numbers below are the new ones.

Closed this round:
- Old p01+p02+p03: the four Thumb wrappers and their 16-byte veneers (0x020911D8..0x02091283) are
  `#pragma thumb on` ... `#pragma thumb reset` inside the ARM file (needs the per-symbol ISA of locals
  in tools/match.py, so a Thumb to ARM call between functions of one file resolves to BLX).
- Old p03|p04: g_02153BD4 is `extern u8 g_02153BD4[]` in the whole file.
- Old p04|p05: `func_02091374` is `double f(const char *)` (nan, tail call of `_f2d`); the 76 bytes after
  `func_020921F4` were two hidden leaves, `func_02092264` (mbtowc) and `func_0209229C` (wctomb).

Boundaries left:
- p01 (libc, 1.1p1; also EXACT under 1.2) | p02 | p03 (fdlibm, 1.2 only; p02 and p03 are EXACT under 1.2,
  DIFF under 1.1p1). p02|p03: both define file-scope statics `zero`, `one`, `two24`: two fdlibm source files.
  p01|p02 could join under 1.2; not done (different source files).
- p04..p10 (compiler runtime: double arithmetic, comparators, converters, ll_divmod): the members of
  the archive are interleaved in the image (p05 and p07 do not lay out contiguously), checked per
  function with match.py one; pair merges p08|p09, p09|p10 are DIFF. p05 and p07 keep their verdict note.
