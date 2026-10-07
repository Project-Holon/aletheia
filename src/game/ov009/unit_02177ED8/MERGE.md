# unit_02177ED8.c (ov009)

Translation unit 02177ED8..02178C88, 14 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02177ED8.c` is blocked by:

- ov009_func_02177ED8.c..ov009_func_02178C48.c: global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_02177FFC.c); global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_021780A8.c); global g_021AB184 declared two ways (src
- ov009_func_02177ED8.c..ov009_func_021781DC.c: global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_02177FFC.c); global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_021780A8.c); global g_021AB184 declared two ways (src
- ov009_func_02177ED8.c..ov009_func_02177FFC.c: global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_02177FFC.c)
- ov009_func_02177EE8.c..ov009_func_02177FFC.c: global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_02177FFC.c)
- ov009_func_02178224.c..ov009_func_02178C48.c: global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_021782B4.c); global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_021783BC.c); global g_021AB184 declared two ways (src
- ov009_func_02178224.c..ov009_func_021783BC.c: global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_021782B4.c); global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_021783BC.c)
- ov009_func_02178678.c..ov009_func_02178C48.c: global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_02178C48.c)
- ov009_func_02178A94.c..ov009_func_02178C48.c: global g_021AB184 declared two ways (src/matched/ov_sdk/ov009_func_02178C48.c)

Members, in address order:

- `ov009_func_02177ED8.c`
- `ov009_func_02177EE8.c`
- `ov009_func_02177FFC.c`
- `ov009_func_02178224.c`
- `ov009_func_02178A94.c`
- `ov009_func_02178C48.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02177ED8.c` again.
