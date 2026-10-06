# unit_02070D18.c (arm9)

Translation unit 02070D18..02071A24, 14 functions, confidence weak (tools/tuboundary.py).

The compiler changes between neighbouring functions, so the range cannot be one
file. In address order:

- `unit_02070D18_p01.c`: 02070D18..02070F2C, ../2.0/sp2
- `unit_02070D18/func_02071034.c`: 1.1p1
- `unit_02070D18_p02.c`: 02071104..020712A8, ../2.0/sp2 (func_020712A8 merged in)
- `unit_02070D18/func_02071360.c`: 1.1p1, no -lang flag
- `unit_02070D18/func_020713A4.c`: ../2.0/sp2
- `unit_02070D18/func_020713C8.c`: 1.1p1
- `unit_02070D18_p03.c`: 02071510..02071858, ../2.0/sp2

Same-compiler neighbours that were adjacent are merged. The rest alternate between
1.1p1 and ../2.0/sp2, which is a change of compiler, so they stay separate. The
tuboundary confidence for this range is weak; the alternation suggests it is
several original source files.
