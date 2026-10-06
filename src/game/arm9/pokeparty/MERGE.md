# pokeparty.c (arm9)

Remaining after the merge lane: 12 part file(s) and 4 member file(s) in this folder.

Why it is not one file:

Members share locals (struct WazaTool, PrintCtx, PrintSys, Mon, gWazaTool, g_02146534, g_0214655C) viewed through different local structs, and several prototypes (func_020185F0, func_02020FE4, func_0201D7C4, func_0201D6D8, sub_0201C808, sub_0201C724) differ between members. Field offsets were not compared; a struct pass should unify them. Pairs that came out DIFF when merged (shared strings or inlining) are kept apart.

Members left in this folder, in address order:

- `unit_0201BEB8.c`
- `unit_0201C6B4.c`
- `unit_0201C6FC.c`
- `sub_0201C724.c`

- `func_02019D84.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
