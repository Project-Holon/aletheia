# unit_021BA290.c (ov218)

Translation unit 021BA290..021BA848, 15 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BA290.c` is blocked by:

- ov218_func_021BA290.c..ov218_func_021BA7A4.c: prototype of func_0204B454 differs between members (src/matched/ov/ov218_func_021BA680.c); prototype of func_0204B404 differs between members (src/matched/ov/ov218_func_021BA680.c); prototype of func_
- ov218_func_021BA61C.c..ov218_func_021BA7A4.c: prototype of func_0204B454 differs between members (src/matched/ov/ov218_func_021BA680.c); prototype of func_0204B404 differs between members (src/matched/ov/ov218_func_021BA680.c); prototype of func_
- ov218_func_021BA61C.c..ov218_func_021BA6E8.c: prototype of func_0204B454 differs between members (src/matched/ov/ov218_func_021BA680.c); prototype of func_0204B404 differs between members (src/matched/ov/ov218_func_021BA680.c); prototype of func_
- ov218_func_021BA61C.c..ov218_func_021BA680.c: prototype of func_0204B454 differs between members (src/matched/ov/ov218_func_021BA680.c); prototype of func_0204B404 differs between members (src/matched/ov/ov218_func_021BA680.c)

Members, in address order:

- `ov218_func_021BA61C.c`
- `ov218_func_021BA680.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BA290.c` again.
