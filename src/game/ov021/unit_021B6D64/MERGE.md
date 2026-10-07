# unit_021B6D64.c (ov021)

Translation unit 021B6D64..021B6DC0, 2 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B6D64.c` is blocked by:

- ov021_func_021B6D64.c..ov021_func_021B6D98.c: c99=CCERR: line 35: identifier 'Entry' redeclared | line 35: was declared as: 'struct ' | line 35: now declared as: 'struct ' nolang=CCERR: line 35: identifier 'Entry' redeclared | line 35: was declar

Members, in address order:

- `ov021_func_021B6D64.c`
- `ov021_func_021B6D98.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B6D64.c` again.
