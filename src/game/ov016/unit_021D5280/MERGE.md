# unit_021D5280.c (ov016)

Translation unit 021D5280..021D53DC, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D5280.c` is blocked by:

- ov016_func_021D5280.c..ov016_func_021D5394.c: c99=CCERR: line 118: illegal implicit conversion from 'struct  *' to | line 118: 'struct  *' nolang=CCERR: line 33: undefined identifier '_Bool' | line 62: illegal function definition | line 111: ille
- ov016_func_021D52D4.c..ov016_func_021D5394.c: c99=CCERR: line 93: illegal implicit conversion from 'struct  *' to | line 93: 'struct  *' nolang=CCERR: line 31: undefined identifier '_Bool' | line 52: illegal function definition | line 86: illegal

Members, in address order:

- `ov016_func_021D52D4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D5280.c` again.
