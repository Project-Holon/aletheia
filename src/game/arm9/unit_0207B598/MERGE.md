# unit_0207B598 (arm9)

Real file boundaries (instruction set changes inside the unit):

- unit_0207B598_p01.c: ARM (func_0207B598, func_0207B5C0)
- MTX_Scale43_.c: Thumb (0x0207B5F4)
- func_0207B60C.c: ARM, single function (its merge with p02 changes the code: c99=DIFF, nolang=DIFF)
- unit_0207B598_p02.c: ARM (func_0207B65C..func_0207BCA0)

- `func_0207B640.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
