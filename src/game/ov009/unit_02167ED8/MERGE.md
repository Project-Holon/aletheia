# unit_02167ED8.c (ov009)

Translation unit 02167ED8..02168250, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02167ED8.c` is blocked by:

- ov009_func_02167ED8.c..ov009_func_02168124.c: prototype of DWC_Alloc differs between members (src/matched/ov_sdk/ov009_func_02168064.c)
- ov009_func_02168040.c..ov009_func_02168124.c: c99=CCERR: line 67: identifier 'NalCnt' redeclared | line 67: was declared as: 'struct NalCnt' | line 67: now declared as: 'struct ' nolang=CCERR: line 67: identifier 'NalCnt' redeclared | line 67: wa
- ov009_func_02168064.c..ov009_func_02168124.c: c99=CCERR: line 55: identifier 'NalCnt' redeclared | line 55: was declared as: 'struct NalCnt' | line 55: now declared as: 'struct ' nolang=CCERR: line 55: identifier 'NalCnt' redeclared | line 55: wa

Members, in address order:

- `ov009_func_02168040.c`
- `ov009_func_02168064.c`
- `ov009_func_02168124.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02167ED8.c` again.
