# unit_021C818C.c (ov016)

Translation unit 021C818C..021C81D4, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C818C.c` is blocked by:

- ov016_func_021C818C.c..ov016_func_021C81B4.c: c99=DIFF nolang=CCERR: line 37: undefined identifier '_Bool' | line 41: ';' expected | line 42: ';' expected

Members, in address order:

- `ov016_func_021C818C.c`
- `ov016_func_021C81B4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C818C.c` again.
