# unit_021B6100.c (ov173)

Translation unit 021B6100..021B75E0, 47 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B6100.c` is blocked by:

- ov173_func_021B6100.c..ov173_func_021B75C8.c: prototype of func_0201C7D0 differs between members (src/matched/ov/ov173_func_021B6CC0.c); prototype of func_0201C7D0 differs between members (src/matched/ov/ov173_func_021B6FDC.c)
- ov173_func_021B6B0C.c..ov173_func_021B75C8.c: prototype of func_0201C7D0 differs between members (src/matched/ov/ov173_func_021B6CC0.c); prototype of func_0201C7D0 differs between members (src/matched/ov/ov173_func_021B6FDC.c)
- ov173_func_021B6B0C.c..ov173_func_021B7128.c: prototype of func_0201C7D0 differs between members (src/matched/ov/ov173_func_021B6CC0.c); prototype of func_0201C7D0 differs between members (src/matched/ov/ov173_func_021B6FDC.c)
- ov173_func_021B71B8.c..ov173_func_021B75C8.c: c99=DIFF nolang=DIFF
- ov173_func_021B74D8.c..ov173_func_021B75C8.c: c99=DIFF nolang=DIFF
- ov173_func_021B7590.c..ov173_func_021B75C8.c: c99=DIFF nolang=DIFF
- ov173_func_021B75B0.c..ov173_func_021B75C8.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov173_func_021B7590.c`
- `ov173_func_021B75B0.c`
- `ov173_func_021B75C8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B6100.c` again.
