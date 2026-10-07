# unit_0218D7CC.c (ov009)

Translation unit 0218D7CC..0218DD88, 8 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0218D7CC.c` is blocked by:

- ov009_func_0218D7CC.c..ov009_func_0218DA40.c: c99=CCERR: line 51: struct/union/enum/class tag 'GPIKey' redefined | line 56: struct/union/enum/class tag 'GPIConnection' redefined nolang=CCERR: line 51: struct/union/enum/class tag 'GPIKey' redefine
- ov009_func_0218D878.c..ov009_func_0218DA40.c: c99=CCERR: line 43: struct/union/enum/class tag 'GPIKey' redefined nolang=CCERR: line 43: struct/union/enum/class tag 'GPIKey' redefined
- ov009_func_0218D9A8.c..ov009_func_0218DA40.c: c99=CCERR: line 41: struct/union/enum/class tag 'GPIKey' redefined nolang=CCERR: line 41: struct/union/enum/class tag 'GPIKey' redefined

Members, in address order:

- `ov009_func_0218D9A8.c`
- `ov009_func_0218DA40.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0218D7CC.c` again.
