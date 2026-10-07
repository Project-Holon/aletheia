# unit_0219E274.c (ov009)

Translation unit 0219E274..0219E8F8, 9 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0219E274.c` is blocked by:

- ov009_func_0219E274.c..ov009_func_0219E8D4.c: prototype of func_0219E01C differs between members (src/matched/ov_sdk/ov009_func_0219E3CC.c); prototype of func_0209477C differs between members (src/matched/ov_sdk/ov009_func_0219E5B8.c); prototype 
- ov009_func_0219E274.c..ov009_func_0219E3CC.c: prototype of func_0219E01C differs between members (src/matched/ov_sdk/ov009_func_0219E3CC.c)
- ov009_func_0219E33C.c..ov009_func_0219E3CC.c: prototype of func_0219E01C differs between members (src/matched/ov_sdk/ov009_func_0219E3CC.c)

Members, in address order:

- `ov009_func_0219E33C.c`
- `ov009_func_0219E3CC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0219E274.c` again.
