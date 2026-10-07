# zknsearch_main.c (ov210)

Translation unit 021BC3F0..021C0234, 158 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`zknsearch_main.c` is blocked by:

- ov210_func_021BC3F0.c..ov210_func_021C01C0.c: prototype of func_020434DC differs between members (src/matched/ov/ov210_func_021BC578.c); prototype of func_02043598 differs between members (src/matched/ov/ov210_func_021BC578.c); prototype of func_
- ov210_func_021BE324.c..ov210_func_021C01C0.c: prototype of func_021B6AE4 differs between members (src/matched/ov/ov210_func_021BE564.c); prototype of func_02045EC0 differs between members (src/matched/ov/ov210_func_021BE564.c); prototype of func_
- ov210_func_021BF080.c..ov210_func_021C01C0.c: prototype of func_021BEDF0 differs between members (src/matched/ov/ov210_func_021BF418.c); prototype of func_021B93B8 differs between members (src/matched/ov/ov210_func_021BF89C.c)
- ov210_func_021BF080.c..ov210_func_021BF89C.c: prototype of func_021BEDF0 differs between members (src/matched/ov/ov210_func_021BF418.c); prototype of func_021B93B8 differs between members (src/matched/ov/ov210_func_021BF89C.c)
- ov210_func_021BF080.c..ov210_func_021BF500.c: prototype of func_021BEDF0 differs between members (src/matched/ov/ov210_func_021BF418.c)
- ov210_func_021BF38C.c..ov210_func_021BF500.c: prototype of func_021BEDF0 differs between members (src/matched/ov/ov210_func_021BF418.c)
- ov210_func_021BF38C.c..ov210_func_021BF418.c: prototype of func_021BEDF0 differs between members (src/matched/ov/ov210_func_021BF418.c)

Members, in address order:

- `ov210_func_021BF38C.c`
- `ov210_func_021BF418.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names zknsearch_main.c` again.
