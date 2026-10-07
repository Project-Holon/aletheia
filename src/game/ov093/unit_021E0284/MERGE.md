# unit_021E0284.c (ov093)

Translation unit 021E0284..021E0518, 10 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E0284.c` is blocked by:

- ov093_func_021E0284.c..ov093_func_021E0468.c: c99=DIFF nolang=DIFF
- func_021E03D8.c..ov093_func_021E0468.c: c99=DIFF nolang=DIFF
- ov093_func_021E03F8.c..ov093_func_021E0468.c: c99=DIFF nolang=DIFF
- ov093_func_021E0434.c..ov093_func_021E0468.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov093_func_021E03F8.c`
- `ov093_func_021E0434.c`
- `ov093_func_021E0468.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E0284.c` again.
