# unit_021C04CC.c (ov210)

Translation unit 021C04CC..021C06FC, 10 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C04CC.c` is blocked by:

- ov210_func_021C04CC.c..ov210_func_021C06C4.c: c99=DIFF nolang=DIFF
- ov210_func_021C04CC.c..ov210_func_021C05F0.c: c99=DIFF nolang=DIFF
- ov210_func_021C0584.c..ov210_func_021C05F0.c: c99=DIFF nolang=DIFF
- ov210_func_021C05BC.c..ov210_func_021C05F0.c: c99=DIFF nolang=DIFF
- ov210_func_021C0608.c..ov210_func_021C06C4.c: c99=DIFF nolang=DIFF
- ov210_func_021C0678.c..ov210_func_021C06C4.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov210_func_021C0584.c`
- `ov210_func_021C05BC.c`
- `ov210_func_021C05F0.c`
- `ov210_func_021C0678.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C04CC.c` again.
