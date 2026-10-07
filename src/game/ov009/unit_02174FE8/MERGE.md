# unit_02174FE8.c (ov009)

Translation unit 02174FE8..02175760, 8 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02174FE8.c` is blocked by:

- ov009_func_02174FE8.c..ov009_func_02175698.c: prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_02175530.c); prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_02175560.c)
- ov009_func_02175530.c..ov009_func_02175698.c: prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_021755D4.c); prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_02175698.c)
- ov009_func_02175530.c..ov009_func_02175560.c: c99=CCERR: line 20: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 20: the file '../arm9_sdk/libc/string.h' cannot be opened

Members, in address order:

- `ov009_func_02175530.c`
- `ov009_func_02175560.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02174FE8.c` again.
