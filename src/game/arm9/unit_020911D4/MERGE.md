# unit_020911D4 (arm9)

14 parts (round 6, lane sa9). Round 6 retag: old p07 and p09 (tagged 1.1p1) build EXACT under 1.2 and DIFF under 2.0;
old p06 and p08 are DIFF under 1.1p1, so the whole run p06..p09 is compiler 1.2. Greedy merge then joined
old p06+p07 into p06 (e_pow style, statics zero/one/...) and old p08+p09 into p07.

Boundaries:
- p01|p02, p02|p03: ARM and Thumb alternate (p02 is Thumb), settings differ; p02 holds the four Thumb wrappers and their veneers.
- p03|p04: CCERR/DIFF, g_02153BD4 is declared two ways (needs one canonical type and the u8 * stand-in parameters of both parts).
- p04|p05: p05 is MATCH, not EXACT (__ctype_map, s_020A8A40 have no symbols rows).
- p06|p07: both define file-scope statics `zero`, `one`, `two24` (fdlibm constants); in one file they would be redefinitions.
  The two halves are two fdlibm source files: a real boundary (same name defined twice).
- p08..p13 (compiler runtime: double arithmetic, comparators, converters, ll_divmod): manifest kind runtime, checked per
  function with match.py one; do not merge. p09 (comparators) and p11 (converters) are EXACT per function but match.py tu
  reports DIFF (members not contiguous). Their header status stays EXACT with a verdict note.
- p12|p13, p13|p14: c99=DIFF.
