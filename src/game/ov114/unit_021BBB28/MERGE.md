# unit_021BBB28.c (ov114)

Translation unit 021BBB28..021BBE94, 4 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BBB28.c` is blocked by:

- ov114_func_021BBB28.c..ov114_func_021BBDFC.c: prototype of func_021BB210 differs between members (src/matched/ov_sdk/ov114_func_021BBDFC.c)
- ov114_func_021BBCF0.c..ov114_func_021BBDFC.c: prototype of func_021BB210 differs between members (src/matched/ov_sdk/ov114_func_021BBDFC.c)

Members, in address order:

- `ov114_func_021BBCF0.c`
- `ov114_func_021BBDFC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BBB28.c` again.
