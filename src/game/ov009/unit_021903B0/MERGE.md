# unit_021903B0.c (ov009)

Translation unit 021903B0..02192F24, 7 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021903B0.c` is blocked by:

- ov009_func_021903B0.c..ov009_func_02192E10.c: prototype of func_0217EAB0 differs between members (src/matched/ov_sdk/ov009_func_021905A4.c); prototype of func_02189D78 differs between members (src/matched/ov_sdk/ov009_func_0219091C.c); prototype 
- ov009_func_021906E0.c..ov009_func_02192E10.c: prototype of func_021905A4 differs between members (src/matched/ov_sdk/ov009_func_021908B0.c); prototype of func_02193734 differs between members (src/matched/ov_sdk/ov009_func_0219091C.c); prototype 
- ov009_func_021906E0.c..ov009_func_021908B0.c: prototype of func_021905A4 differs between members (src/matched/ov_sdk/ov009_func_021908B0.c)
- ov009_func_0219091C.c..ov009_func_02192E10.c: prototype of func_0217EAB0 differs between members (src/matched/ov_sdk/ov009_func_02192E10.c); prototype of func_02193734 differs between members (src/matched/ov_sdk/ov009_func_02192E10.c)

Members, in address order:

- `ov009_func_021906E0.c`
- `ov009_func_021908B0.c`
- `ov009_func_0219091C.c`
- `ov009_func_02192E10.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021903B0.c` again.
