# b_plist_main.c (ov198)

Translation unit 0220F060..02211A40, 90 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`b_plist_main.c` is blocked by:

- ov198_func_0220F060.c..ov198_func_02211A24.c: prototype of func_0204B404 differs between members (src/matched/ov/ov198_func_0220F2DC.c); prototype of func_0220AFDC differs between members (src/matched/ov/ov198_func_0220F4E0.c); prototype of func_
- ov198_func_022107A8.c..ov198_func_02211A24.c: prototype of func_02041B6C differs between members (src/matched/ov/ov198_func_02210D4C.c); prototype of func_02045EC0 differs between members (src/matched/ov/ov198_func_02211190.c); prototype of func_
- ov198_func_022107A8.c..ov198_func_022110E0.c: prototype of func_02041B6C differs between members (src/matched/ov/ov198_func_02210D4C.c)
- ov198_func_022107A8.c..ov198_func_02210ED4.c: prototype of func_02041B6C differs between members (src/matched/ov/ov198_func_02210D4C.c); prototype of func_02210F4C differs between members (src/matched/ov/ov198_func_02210DA8.c)
- ov198_func_02210BFC.c..ov198_func_02210ED4.c: prototype of func_02041B6C differs between members (src/matched/ov/ov198_func_02210D4C.c)
- ov198_func_02210BFC.c..ov198_func_02210D4C.c: prototype of func_02041B6C differs between members (src/matched/ov/ov198_func_02210D4C.c)

Members, in address order:

- `ov198_func_02210BFC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names b_plist_main.c` again.
