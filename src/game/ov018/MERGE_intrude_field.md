# intrude_field (ov018)

Round 4 (r4_ov05): 8 parts to 5 (old p04+p05+p06 and p07+p08 merged by the harmonizer, all EXACT).
Open boundaries (adjacent parts, new numbering):
- p01|p02: only one compile error (func_0217B1DC called with an int first argument, prototype takes void *). Casting the argument (void *)a0 fixes the error, but the merged file is then DIFF from +0x1A0 on (literal pool layout after func_0217AE20 moves). Not resolved.
- p02|p03: int passed where void * expected (line 285 of the pair); not tried.
- p03|p04: DIFF without a compile error.
- p04|p05: struct pointer against const struct pointer (two local structs for one object).