# unit_021F39C0.c (ov055)

Translation unit 021F39C0..021F45A4, 33 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F39C0.c` is blocked by:

- ov055_func_021F39C0.c..ov055_func_021F459C.c: c99=CCERR: line 299: illegal implicit conversion from 'char *' to | line 299: 'struct S_021F3E84 *' | line 302: illegal implicit conversion from 'struct S *' to nolang=CCERR: line 299: illegal implici
- ov055_func_021F39C0.c..ov055_func_021F3F9C.c: c99=CCERR: line 227: illegal implicit conversion from 'char *' to | line 227: 'struct S_021F3E84 *' | line 242: function call 'func_021F3CE4(char *)' does not match nolang=CCERR: line 227: illegal imp
- ov055_func_021F39C0.c..ov055_func_021F3CF4.c: c99=CCERR: line 182: function call 'func_021F3CE4(char *)' does not match | line 182: 'func_021F3CE4(char *, int)' nolang=CCERR: line 182: function call 'func_021F3CE4(char *)' does not match | line 1
- ov055_func_021F39C0.c..ov055_func_021F3B20.c: c99=DIFF nolang=DIFF
- ov055_func_021F3AA4.c..ov055_func_021F3B20.c: c99=DIFF nolang=DIFF
- ov055_func_021F405C.c..ov055_func_021F459C.c: c99=CCERR: line 318: illegal implicit conversion from 'struct S *' to | line 318: 'struct S_021F4510 *' nolang=CCERR: line 318: illegal implicit conversion from 'struct S *' to | line 318: 'struct S_0

Members, in address order:

- `ov055_func_021F3AA4.c`
- `ov055_func_021F3B20.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F39C0.c` again.
