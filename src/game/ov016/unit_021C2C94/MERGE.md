# unit_021C2C94.c (ov016)

Translation unit 021C2C94..021C2D60, 3 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C2C94.c` is blocked by:

- ov016_func_021C2C94.c..ov016_func_021C2D3C.c: c99=DIFF nolang=CCERR: line 45: undefined identifier '_Bool' | line 64: ';' expected | line 65: ';' expected
- ov016_func_021C2CFC.c..ov016_func_021C2D3C.c: c99=DIFF nolang=CCERR: line 45: undefined identifier '_Bool' | line 64: ';' expected | line 65: ';' expected

Members, in address order:

- `ov016_func_021C2C94.c`
- `ov016_func_021C2CFC.c`
- `ov016_func_021C2D3C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C2C94.c` again.
