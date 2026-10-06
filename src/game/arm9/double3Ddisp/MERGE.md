# double3Ddisp.c (arm9)

Parts merged by lane arm9_lane17 (greedy, address order then reverse): double3Ddisp_p01.c, double3Ddisp_p02.c

Members still separate in this folder: func_0204E8C0.c

Blockers seen by the greedy pass (merge of the running file with the next file failed):

- func_0204E914.c FAIL {'c99': "CCERR: line 88: 'oam' is not a member of class 'struct Double3Ddisp_0204E8C0' | line 89: 'oam' is not a member of class 'struct Double3Ddisp_
- func_0204EA4C.c FAIL {'c99': 'DIFF', 'nolang': 'DIFF'}

c99=DIFF means the merge changes the generated code (shared strings, inlining); settings means another compiler.
Other failures are struct or prototype views that need unifying (check field offsets first).

- `func_0204EA38.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_0204EDD0.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
