# unit_0207ADC4.c (arm9)

Parts merged by lane arm9_lane17 (greedy, address order then reverse): unit_0207ADC4_p01.c, unit_0207ADC4_p02.c, unit_0207ADC4_p03.c

Members still separate in this folder: func_0207AE38.c

Blockers seen by the greedy pass (merge of the running file with the next file failed):

- func_0207AE38.c FAIL {'c99': 'DIFF', 'nolang': 'DIFF'}
- unit_0207ADC4_p02.c FAIL settings
- func_0207AF50.c FAIL settings

c99=DIFF means the merge changes the generated code (shared strings, inlining); settings means another compiler.
Other failures are struct or prototype views that need unifying (check field offsets first).

- `func_0207AE24.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
