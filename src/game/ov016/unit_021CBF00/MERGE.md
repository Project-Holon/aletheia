# unit_021CBF00.c (ov016)

Translation unit 021CBF00..021CBFA8, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021CBF00.c` is blocked by:

- ov016_func_021CBF00.c..ov016_func_021CBF68.c: c99=DIFF nolang=CCERR: line 46: undefined identifier '_Bool' | line 65: ';' expected | line 66: ';' expected

Members, in address order:

- `ov016_func_021CBF00.c`
- `ov016_func_021CBF68.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021CBF00.c` again.
