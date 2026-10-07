# unit_02189D78.c (ov009)

Translation unit 02189D78..0218A1D0, 4 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02189D78.c` is blocked by:

- ov009_func_02189D78.c..ov009_func_0218A0E4.c: c99=CCERR: line 287: illegal implicit conversion from 'struct GPICallbackData_0218A0E4 *' to | line 287: 'struct GPICallbackData *' | line 305: illegal implicit conversion from 'struct GPICallbackData
- ov009_func_02189EA0.c..ov009_func_0218A0E4.c: c99=CCERR: line 87: struct/union/enum/class tag 'GPICallbackData' redefined | line 92: identifier 'GPICallbackData' redeclared | line 92: was declared as: 'struct GPICallbackData' nolang=CCERR: line 8

Members, in address order:

- `ov009_func_02189EA0.c`
- `ov009_func_0218A0E4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02189D78.c` again.
