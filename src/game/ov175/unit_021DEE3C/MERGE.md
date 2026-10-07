# unit_021DEE3C.c (ov175)

Translation unit 021DEE3C..021DF7FC, 30 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DEE3C.c` is blocked by:

- ov175_func_021DEE3C.c..ov175_func_021DF734.c: global g_021E4D08 declared two ways (src/matched/ov_sdk/ov175_func_021DEF58.c); prototype of func_0217CCCC differs between members (src/matched/ov_sdk/ov175_func_021DEF58.c); prototype of func_02059F5
- ov175_func_021DEE3C.c..ov175_func_021DF298.c: global g_021E4D08 declared two ways (src/matched/ov_sdk/ov175_func_021DEF58.c); prototype of func_021DF5E4 differs between members (src/matched/ov_sdk/ov175_func_021DEF58.c); prototype of func_0217CCC
- ov175_func_021DEE3C.c..ov175_func_021DF09C.c: global g_021E4D08 declared two ways (src/matched/ov_sdk/ov175_func_021DEF58.c); prototype of func_021DF5E4 differs between members (src/matched/ov_sdk/ov175_func_021DEF58.c); prototype of func_0217CCC
- ov175_func_021DEE3C.c..ov175_func_021DEFC4.c: global g_021E4D08 declared two ways (src/matched/ov_sdk/ov175_func_021DEF58.c); prototype of func_021DF5E4 differs between members (src/matched/ov_sdk/ov175_func_021DEF58.c); prototype of func_0217CCC

Members, in address order:

- `ov175_func_021DEE3C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DEE3C.c` again.
