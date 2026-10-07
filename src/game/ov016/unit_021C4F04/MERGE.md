# unit_021C4F04.c (ov016)

Translation unit 021C4F04..021C4FAC, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C4F04.c` is blocked by:

- ov016_func_021C4F04.c..ov016_func_021C4F70.c: c99=DIFF nolang=CCERR: line 40: undefined identifier '_Bool' | line 44: ';' expected | line 45: ';' expected

Members, in address order:

- `ov016_func_021C4F04.c`
- `ov016_func_021C4F70.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C4F04.c` again.
