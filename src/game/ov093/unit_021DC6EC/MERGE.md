# unit_021DC6EC.c (ov093)

Translation unit 021DC6EC..021DC960, 9 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DC6EC.c` is blocked by:

- ov093_func_021DC6EC.c..ov093_func_021DC908.c: c99=DIFF nolang=DIFF
- ov093_func_021DC820.c..ov093_func_021DC908.c: c99=DIFF nolang=DIFF
- func_021DC864.c..ov093_func_021DC908.c: c99=DIFF nolang=DIFF
- ov093_func_021DC894.c..ov093_func_021DC908.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_021DC864.c`
- `ov093_func_021DC894.c`
- `ov093_func_021DC908.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DC6EC.c` again.
