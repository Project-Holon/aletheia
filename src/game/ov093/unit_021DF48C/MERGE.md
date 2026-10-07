# unit_021DF48C.c (ov093)

Translation unit 021DF48C..021DF740, 14 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DF48C.c` is blocked by:

- ov093_func_021DF48C.c..ov093_func_021DF728.c: prototype of func_021E8A58 differs between members (src/matched/ov/ov093_func_021DF5F4.c); prototype of func_021D7D18 differs between members (src/matched/ov/ov093_func_021DF640.c); prototype of func_
- ov093_func_021DF48C.c..ov093_func_021DF548.c: c99=DIFF nolang=DIFF
- ov093_func_021DF48C.c..ov093_func_021DF4BC.c: c99=DIFF nolang=DIFF
- ov093_func_021DF4A4.c..ov093_func_021DF4BC.c: c99=DIFF nolang=DIFF
- ov093_func_021DF4D4.c..ov093_func_021DF548.c: c99=DIFF nolang=DIFF
- ov093_func_021DF594.c..ov093_func_021DF728.c: prototype of func_021E8A58 differs between members (src/matched/ov/ov093_func_021DF5F4.c); prototype of func_021D7D18 differs between members (src/matched/ov/ov093_func_021DF6AC.c)
- ov093_func_021DF594.c..ov093_func_021DF640.c: prototype of func_021E8A58 differs between members (src/matched/ov/ov093_func_021DF5F4.c)
- ov093_func_021DF5F4.c..ov093_func_021DF640.c: c99=DIFF nolang=DIFF
- ov093_func_021DF6AC.c..ov093_func_021DF728.c: c99=DIFF nolang=DIFF
- ov093_func_021DF6AC.c..ov093_func_021DF6F8.c: c99=DIFF nolang=DIFF
- ov093_func_021DF710.c..ov093_func_021DF728.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov093_func_021DF48C.c`
- `ov093_func_021DF4A4.c`
- `ov093_func_021DF4BC.c`
- `ov093_func_021DF594.c`
- `ov093_func_021DF5F4.c`
- `ov093_func_021DF640.c`
- `ov093_func_021DF6AC.c`
- `ov093_func_021DF6F8.c`
- `ov093_func_021DF710.c`
- `ov093_func_021DF728.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DF48C.c` again.
