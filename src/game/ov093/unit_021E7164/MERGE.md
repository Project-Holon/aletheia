# unit_021E7164.c (ov093)

Translation unit 021E7164..021E74E4, 11 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E7164.c` is blocked by:

- ov093_func_021E7164.c..ov093_func_021E7420.c: c99=DIFF nolang=DIFF
- ov093_func_021E7164.c..ov093_func_021E727C.c: c99=DIFF nolang=DIFF
- ov093_func_021E71E4.c..ov093_func_021E727C.c: c99=DIFF nolang=DIFF
- ov093_func_021E7300.c..ov093_func_021E7420.c: c99=DIFF nolang=DIFF
- ov093_func_021E7300.c..ov093_func_021E732C.c: c99=DIFF nolang=DIFF
- ov093_func_021E7388.c..ov093_func_021E7420.c: c99=DIFF nolang=DIFF
- no verified entry for 021E7260, 021E72D4, 021E72E4, 021E74C8

Members, in address order:

- `ov093_func_021E7164.c`
- `ov093_func_021E71E4.c`
- `ov093_func_021E727C.c`
- `ov093_func_021E7300.c`
- `ov093_func_021E732C.c`
- `ov093_func_021E7388.c`
- `ov093_func_021E7420.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E7164.c` again.
