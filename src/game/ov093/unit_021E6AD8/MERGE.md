# unit_021E6AD8.c (ov093)

Translation unit 021E6AD8..021E6DAC, 7 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E6AD8.c` is blocked by:

- ov093_func_021E6AD8.c..ov093_func_021E6CDC.c: prototype of func_021C8030 differs between members (src/matched/ov/ov093_func_021E6BF4.c); prototype of func_021C8030 differs between members (src/matched/ov/ov093_func_021E6CDC.c)
- ov093_func_021E6AD8.c..func_021E6B20.c: c99=DIFF nolang=DIFF
- ov093_func_021E6BAC.c..ov093_func_021E6CDC.c: c99=DIFF nolang=DIFF
- ov093_func_021E6BF4.c..ov093_func_021E6CDC.c: c99=DIFF nolang=DIFF
- no verified entry for 021E6CC0, 021E6D90

Members, in address order:

- `ov093_func_021E6AD8.c`
- `func_021E6B20.c`
- `ov093_func_021E6BAC.c`
- `ov093_func_021E6BF4.c`
- `ov093_func_021E6CDC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E6AD8.c` again.
