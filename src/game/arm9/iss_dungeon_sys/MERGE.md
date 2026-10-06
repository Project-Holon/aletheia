# iss_dungeon_sys.c (arm9)

Parts merged by lane arm9_lane17 (greedy, address order then reverse): iss_dungeon_sys_p01.c, iss_dungeon_sys_p02.c, iss_dungeon_sys_p03.c

Members still separate in this folder: func_0202B42C.c

Blockers seen by the greedy pass (merge of the running file with the next file failed):

- func_0202B42C.c FAIL {'c99': 'DIFF', 'nolang': 'DIFF'}
- iss_dungeon_sys_p03.c FAIL {'c99': 'DIFF', 'nolang': 'DIFF'}
- iss_dungeon_sys_p04.c FAIL {'c99': "CCERR: line 89: illegal implicit conversion from 'unsigned int' to | line 89: 'unsigned char *'", 'nolang': "CCERR: line 89: illegal implicit

c99=DIFF means the merge changes the generated code (shared strings, inlining); settings means another compiler.
Other failures are struct or prototype views that need unifying (check field offsets first).

- `func_0202B424.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_0202B434.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
