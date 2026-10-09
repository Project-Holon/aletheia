# worldtrade_box: merge blockers (lane 046)

Parts p01..p07 remain (25 before). Failing boundaries at last greedy run (old numbering):
- p03/p04: array of struct vs `struct *` implicit conversion at one call (struct views differ).
- p08/p09: `unsigned char *` passed where a local struct pointer is expected.
- func_021F68A4: local struct `Work` redeclared with different layouts; Obj_021F68A4 vs Obj not unified.
- ov135_func_021F8358: pure code DIFF when merged (needs mm27/dd27 diagnosis).
- ov135_func_021FA7C4: struct pointer type clash.
- p25: const struct array vs `const struct *` conversion.
Next: run scratchpad/ol041/unif41.py once, then ol039 tools per boundary.
