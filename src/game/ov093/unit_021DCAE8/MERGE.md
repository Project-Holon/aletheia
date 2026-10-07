# unit_021DCAE8.c (ov093)

Translation unit 021DCAE8..021DD588, 55 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DCAE8.c` is blocked by:

- ov093_func_021DCAE8.c..ov093_func_021DD514.c: c99=DIFF nolang=DIFF
- ov093_func_021DCAE8.c..ov093_func_021DD068.c: c99=DIFF nolang=DIFF
- ov093_func_021DCAE8.c..ov093_func_021DCE48.c: c99=DIFF nolang=DIFF
- ov093_func_021DCAE8.c..ov093_func_021DCC5C.c: c99=DIFF nolang=DIFF
- ov093_func_021DCAE8.c..ov093_func_021DCBE8.c: c99=DIFF nolang=DIFF
- ov093_func_021DCB38.c..ov093_func_021DCBE8.c: c99=DIFF nolang=DIFF
- ov093_func_021DCC80.c..ov093_func_021DCE48.c: c99=DIFF nolang=DIFF
- ov093_func_021DD080.c..ov093_func_021DD514.c: c99=DIFF nolang=DIFF
- ov093_func_021DD1D8.c..ov093_func_021DD514.c: c99=DIFF nolang=DIFF
- ov093_func_021DD1D8.c..ov093_func_021DD320.c: prototype of func_021DD39C differs between members (src/matched/ov/ov093_func_021DD320.c)
- ov093_func_021DD1D8.c..ov093_func_021DD26C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov093_func_021DCAE8.c`
- `ov093_func_021DCB38.c`
- `ov093_func_021DCBE8.c`
- `ov093_func_021DD1D8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DCAE8.c` again.
