# unit_021DFABC.c (ov093)

Translation unit 021DFABC..021DFCB8, 5 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DFABC.c` is blocked by:

- ov093_func_021DFABC.c..ov093_func_021DFC00.c: c99=DIFF nolang=DIFF
- ov093_func_021DFABC.c..ov093_func_021DFB4C.c: c99=DIFF nolang=DIFF
- func_021DFB94.c..ov093_func_021DFC00.c: c99=DIFF nolang=DIFF
- ov093_func_021DFBAC.c..ov093_func_021DFC00.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov093_func_021DFABC.c`
- `ov093_func_021DFB4C.c`
- `func_021DFB94.c`
- `ov093_func_021DFBAC.c`
- `ov093_func_021DFC00.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DFABC.c` again.
