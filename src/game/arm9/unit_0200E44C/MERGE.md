# unit_0200E44C.c (arm9)

Parts merged by lane arm9_lane17 (greedy, address order then reverse): unit_0200E44C_p01.c, unit_0200E44C_p02.c, unit_0200E44C_p03.c, unit_0200E44C_p04.c

Members still separate in this folder: func_0200EA14.c

Blockers seen by the greedy pass (merge of the running file with the next file failed):

- unit_0200E44C_p04.c FAIL {'c99': 'DIFF', 'nolang': 'DIFF'}
- unit_0200E44C_p06.c FAIL {'c99': 'DIFF', 'nolang': 'DIFF'}
- func_0200EA14.c FAIL {'c99': 'DIFF', 'nolang': 'DIFF'}
- unit_0200E44C_p08.c FAIL {'c99': 'DIFF', 'nolang': 'DIFF'}

c99=DIFF means the merge changes the generated code (shared strings, inlining); settings means another compiler.
Other failures are struct or prototype views that need unifying (check field offsets first).

- `unit_0200E730.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_0200E9DC.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
