# unit_021BE6BC.c (ov114)

Translation unit 021BE6BC..021BEA20, 11 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BE6BC.c` is blocked by:

- ov114_func_021BE6BC.c..ov114_func_021BE9F8.c: prototype of func_021BEF58 differs between members (src/matched/ov_sdk/ov114_func_021BE79C.c); prototype of func_021BEF58 differs between members (src/matched/ov_sdk/ov114_func_021BE8E8.c)
- ov114_func_021BE6BC.c..ov114_func_021BE7FC.c: prototype of func_021BEF58 differs between members (src/matched/ov_sdk/ov114_func_021BE79C.c)
- ov114_func_021BE6BC.c..ov114_func_021BE6EC.c: c99=CCERR: line 42: illegal implicit conversion from 'int' to | line 42: 'struct  *' nolang=CCERR: line 42: illegal implicit conversion from 'int' to | line 42: 'struct  *'
- ov114_func_021BE748.c..ov114_func_021BE7FC.c: prototype of func_021BEF58 differs between members (src/matched/ov_sdk/ov114_func_021BE79C.c)
- ov114_func_021BE79C.c..ov114_func_021BE7FC.c: prototype of func_021BEF58 differs between members (src/matched/ov_sdk/ov114_func_021BE7FC.c)
- ov114_func_021BE838.c..ov114_func_021BE9F8.c: prototype of func_021BEF58 differs between members (src/matched/ov_sdk/ov114_func_021BE8E8.c)
- ov114_func_021BE8E8.c..ov114_func_021BE9F8.c: prototype of func_021BEF58 differs between members (src/matched/ov_sdk/ov114_func_021BE9C8.c)

Members, in address order:

- `ov114_func_021BE6BC.c`
- `ov114_func_021BE6EC.c`
- `ov114_func_021BE748.c`
- `ov114_func_021BE79C.c`
- `ov114_func_021BE7FC.c`
- `ov114_func_021BE8E8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BE6BC.c` again.
