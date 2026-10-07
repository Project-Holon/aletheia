# unit_02178F00.c (ov009)

Translation unit 02178F00..02178F4C, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02178F00.c` is blocked by:

- ov009_func_02178F00.c..ov009_func_02178F30.c: c99=CCERR: line 52: identifier 'func_02058FB4(struct DWCAuthWiFiId *)' redeclared as 'void (void *)' | line 34: identifier 'func_02058FB4(struct DWCAuthWiFiId *)' was originally declared as 'void (str

Members, in address order:

- `ov009_func_02178F00.c`
- `ov009_func_02178F30.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02178F00.c` again.
