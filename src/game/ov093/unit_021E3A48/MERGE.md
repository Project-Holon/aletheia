# unit_021E3A48.c (ov093)

Translation unit 021E3A48..021E3B64, 5 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E3A48.c` is blocked by:

- ov093_func_021E3A48.c..ov093_func_021E3B14.c: c99=DIFF nolang=DIFF
- ov093_func_021E3A48.c..ov093_func_021E3A78.c: c99=DIFF nolang=DIFF
- ov093_func_021E3AC4.c..ov093_func_021E3B14.c: c99=DIFF nolang=DIFF
- func_021E3AF0.c..ov093_func_021E3B14.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov093_func_021E3A48.c`
- `ov093_func_021E3A78.c`
- `ov093_func_021E3AC4.c`
- `func_021E3AF0.c`
- `ov093_func_021E3B14.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E3A48.c` again.
