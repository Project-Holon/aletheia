# unit_021E072C.c (ov093)

Translation unit 021E072C..021E0A80, 11 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E072C.c` is blocked by:

- ov093_func_021E072C.c..ov093_func_021E0998.c: c99=DIFF nolang=DIFF
- ov093_func_021E0900.c..ov093_func_021E0998.c: c99=DIFF nolang=DIFF
- ov093_func_021E0900.c..ov093_func_021E0920.c: c99=DIFF nolang=DIFF
- ov093_func_021E0944.c..ov093_func_021E0998.c: c99=DIFF nolang=DIFF
- no verified entry for 021E08E0, 021E08F0, 021E0A64

Members, in address order:

- `ov093_func_021E0900.c`
- `ov093_func_021E0920.c`
- `ov093_func_021E0944.c`
- `ov093_func_021E0998.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E072C.c` again.
