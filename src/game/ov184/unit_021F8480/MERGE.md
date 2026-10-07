# unit_021F8480.c (ov184)

Translation unit 021F8480..021F89D0, 10 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F8480.c` is blocked by:

- ov184_func_021F8480.c..ov184_func_021F891C.c: prototype of func_021FD73C differs between members (src/matched/ov/ov184_func_021F8670.c); prototype of func_021FE784 differs between members (src/matched/ov/ov184_func_021F86EC.c); prototype of func_
- ov184_func_021F8670.c..ov184_func_021F891C.c: prototype of func_021FD860 differs between members (src/matched/ov/ov184_func_021F86EC.c)
- ov184_func_021F8670.c..ov184_func_021F86EC.c: prototype of func_021FD860 differs between members (src/matched/ov/ov184_func_021F86EC.c)

Members, in address order:

- `ov184_func_021F8670.c`
- `ov184_func_021F86EC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F8480.c` again.
