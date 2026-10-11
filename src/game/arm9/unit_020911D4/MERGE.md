# unit_020911D4 (arm9)

8 parts (round 17, lane L04; was 10). All parts are compiler 1.2 now.

Closed this round:
- Old p01+p02 (libc + fdlibm pow/rem_pio2/cos): the 1.1p1 tag was not real, the merged file is EXACT under 1.2.
- Every runtime piece (old p04..p10) is also EXACT under 1.2; the compiler is no boundary.
- Old p03 + p04 merged (the string compare and the 1.1p1 runtime piece next to it).
  `func_0209AB80` is `double f(double, double)` (tail call of `func_020979BC`), not `void f(void)`.

Boundaries left:
- p01 | p02: both files define file-scope statics `zero`, `one`, `two24`, `huge`
  (two fdlibm source files); a merge fails with "object redefined".
- p03 and p05 are non-contiguous runtime pieces (members interleaved in the image): each function is EXACT
  with match.py one, the TU compare cannot line them up. Pair merges of the other runtime pieces are DIFF.
