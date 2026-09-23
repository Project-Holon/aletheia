# Function scope versus block scope decides the order of spill slots

summary: in a switch whose cases repeat one body, variables declared in each
case block and the same variables declared once at function scope compile to
the same instructions but hand out the spill slots in a different order; a
residue that is only two spill slots swapped between two cases is this
declaration fact, not the body.

Found in: src/matched/func_0202A4B4.c (0x0202A4B4)

tr_tool.c's party builder repeats one per-entry body in four switch cases.
With every local declared inside each case block the function was 1248 bytes
against 1248 with 4 bytes out: the personality spill of case 1 at sp+0x20 and
case 3's at sp+0x1C, the image has them the other way round.  Hill and anneal
permuter runs (1400 compiles) and per-case declaration reorders were flat.
Moving `pid`, `seed`, `j` and `iv` to function scope while `dv`, `level` and
`species` stay in the case blocks (they have per-case homes in the image, at
0x5C..0x64, 0x50..0x58, 0x44..0x4C, 0x38..0x40) is EXACT.  Moving only one of
the four, or all seven, is worse.
