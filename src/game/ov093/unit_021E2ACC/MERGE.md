# unit_021E2ACC.c (ov093)

Translation unit 021E2ACC..021E2ED4, 12 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E2ACC.c` is blocked by:

- ov093_func_021E2ACC.c..ov093_func_021E2E90.c: c99=DIFF nolang=DIFF
- ov093_func_021E2C88.c..ov093_func_021E2E90.c: c99=DIFF nolang=DIFF
- ov093_func_021E2C88.c..ov093_func_021E2D5C.c: c99=DIFF nolang=DIFF
- ov093_func_021E2D20.c..ov093_func_021E2D5C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov093_func_021E2C88.c`
- `ov093_func_021E2D20.c`
- `ov093_func_021E2D5C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E2ACC.c` again.
