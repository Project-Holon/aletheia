# unit_021C3518.c (ov016)

Translation unit 021C3518..021C35F0, 4 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C3518.c` is blocked by:

- ov016_func_021C3518.c..func_021C35BC.c: c99=DIFF nolang=CCERR: line 36: undefined identifier '_Bool' | line 40: ';' expected | line 41: ';' expected
- ov016_func_021C3518.c..ov016_func_021C3540.c: c99=DIFF nolang=CCERR: line 37: undefined identifier '_Bool' | line 41: ';' expected | line 42: ';' expected

Members, in address order:

- `ov016_func_021C3518.c`
- `ov016_func_021C3540.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C3518.c` again.
