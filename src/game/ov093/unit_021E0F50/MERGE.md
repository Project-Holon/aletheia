# unit_021E0F50.c (ov093)

Translation unit 021E0F50..021E10D8, 6 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E0F50.c` is blocked by:

- func_021E0F50.c..ov093_func_021E1074.c: c99=DIFF nolang=DIFF
- func_021E0F50.c..ov093_func_021E0FB8.c: c99=DIFF nolang=DIFF
- ov093_func_021E101C.c..ov093_func_021E1074.c: c99=DIFF nolang=DIFF
- func_021E1050.c..ov093_func_021E1074.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_021E0F50.c`
- `ov093_func_021E101C.c`
- `func_021E1050.c`
- `ov093_func_021E1074.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E0F50.c` again.
