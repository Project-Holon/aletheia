# unit_021C5550.c (ov016)

Translation unit 021C5550..021C55B4, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C5550.c` is blocked by:

- ov016_func_021C5550.c..ov016_func_021C5590.c: c99=DIFF nolang=CCERR: line 45: undefined identifier '_Bool' | line 64: ';' expected | line 65: ';' expected

Members, in address order:

- `ov016_func_021C5550.c`
- `ov016_func_021C5590.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C5550.c` again.
