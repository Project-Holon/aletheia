# unit_020911D4 (arm9)

16 parts remain (round 4: p02..p05 of round 3 merged into one Thumb part, the rest renumbered).
Boundaries:
- p01|p02, p02|p03: ARM and Thumb alternate (p02 is Thumb, p01 and p03 are ARM), settings differ.
  p02 now holds the four Thumb wrappers and their three veneers in one file; each veneer is an
  `asm void f(u32 ...)` with the wrapper's argument list, so one prototype serves both.
- p03|p04: the merge compiles to CCERR: g_02153BD4 is declared two ways (p03 and p04 view the same
  global through different types, illegal implicit conversion u32 to u8 * at merged lines 1095 and 1202).
  Needs one canonical type for g_02153BD4 and the stand-in u8 * parameters of both parts.
- p04|p05: p05 is MATCH, not EXACT (see below); not tried again in round 4.
- p05 is MATCH because __ctype_map, s_020A8A40 and similar symbols have no symbols rows.
- p06 (compiler 1.2), p07 (1.1p1), p08 (1.2), p09 (1.1p1): the compiler alternates, so these stay apart.
  p06 and p08 verify with --cc 1.2.
- p10..p15 (compiler runtime: double arithmetic, comparators, converters, ll_divmod): manifest kind
  runtime, checked per function with match.py one; do not merge.
  p11 (comparators) and p13 (converters) are EXACT per function (10 of 10 and 9 of 9, re-run in
  round 4) but match.py tu reports DIFF for them: their members are not contiguous (_fgeq in p12 sits
  between the double and the float comparators; the converters are spread over 0x0209B750..0x0209C554).
  Their header status stays EXACT with a verdict note.
- p14|p15, p15|p16: c99=DIFF.
