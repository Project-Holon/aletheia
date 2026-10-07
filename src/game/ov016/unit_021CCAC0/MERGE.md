# unit_021CCAC0.c (ov016)

Translation unit 021CCAC0..021CCC70, 4 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021CCAC0.c` is blocked by:

- func_021CCAC0.c..ov016_func_021CCC4C.c: c99=DIFF nolang=CCERR: line 66: undefined identifier '_Bool' | line 89: ';' expected | line 90: ';' expected
- ov016_func_021CCC0C.c..ov016_func_021CCC4C.c: c99=DIFF nolang=CCERR: line 45: undefined identifier '_Bool' | line 64: ';' expected | line 65: ';' expected

Members, in address order:

- `ov016_func_021CCC0C.c`
- `ov016_func_021CCC4C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021CCAC0.c` again.
