# unit_021C4904.c (ov016)

Translation unit 021C4904..021C4BDC, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C4904.c` is blocked by:

- ov016_func_021C4904.c..ov016_func_021C4AF8.c: c99=CCERR: line 103: illegal name overloading | line 120: declarator expected | line 188: declarator expected nolang=CCERR: line 57: undefined identifier '_Bool' | line 74: ';' expected | line 82: ';'
- ov016_func_021C4A74.c..ov016_func_021C4AF8.c: c99=CCERR: line 71: illegal name overloading | line 98: declarator expected nolang=CCERR: line 40: undefined identifier '_Bool' | line 53: ';' expected | line 71: illegal name overloading
- ov016_func_021C4AB4.c..ov016_func_021C4AF8.c: c99=CCERR: line 67: illegal name overloading | line 80: declarator expected nolang=CCERR: line 38: undefined identifier '_Bool' | line 67: illegal name overloading | line 80: expression syntax error

Members, in address order:

- `ov016_func_021C4A74.c`
- `ov016_func_021C4AB4.c`
- `ov016_func_021C4AF8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C4904.c` again.
