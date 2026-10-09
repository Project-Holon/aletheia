# worldtrade_enter: merge blockers (lane 046)

Parts p01..p04 remain (19 before). Done: func_021C7C1C, func_021C866C, func_021C8658 externs
changed to unprototyped `()` declarations (callers disagree on arity; each part stays EXACT).
Remaining boundaries:
- const u32 array passed where `void *` expected (one call, p03 boundary).
- Several local structs (fields flags/bank, pos/last/cursor, page/total/items) not unified:
  merged file sees them as one anonymous or renamed struct. Needs a canonical struct per
  object (scratchpad/ol041/unif41.py, ol036/canon36.py).
