# unit_0200D70C (arm9)

Merge status: 2 files remain.

- `unit_0200D70C_p01.c`: func_0200D6EC, func_0200D6FC, func_0200D70C, func_0200D72C,, func_0200D74C, func_0200D760, func_0200D774, func_0200D82C, func_0200D85C, func_0200D868, func_0200D884, func_0200D914, func_0200DA14, func_0200DA28, func_0200DA54, func_0200DA64, func_0200DA6C, func_0200DA80, func_0200DA98, (compiler dsi/1.1p1, flags -O4,p, lang c99, isa thumb)
- `unit_0200D70C_p02.c`: func_0200DD28, func_0200DD8C, func_0200DDA8, func_0200DDD0 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa thumb)

Blockers between adjacent files:
- `unit_0200D70C_p01.c` | `unit_0200D70C_p02.c`: merging changes the code (c99=DIFF); keep separate.

- `unit_0200DD10.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
