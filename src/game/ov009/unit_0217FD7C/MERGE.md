# unit_0217FD7C.c (ov009)

Translation unit 0217FD7C..021800CC, 9 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217FD7C.c` is blocked by:

- ov009_func_0217FD7C.c..ov009_func_02180080.c: type typedef execute differs between members (src/matched/ov_sdk/ov009_func_0217FE68.c)
- ov009_func_0217FD7C.c..ov009_func_0217FF14.c: c99=CCERR: line 56: struct/union/enum/class tag 'GSSoapTask' redefined | line 64: identifier 'GSSoapTask' redeclared | line 64: was declared as: 'struct GSSoapTask' nolang=CCERR: line 56: struct/union
- ov009_func_0217FE68.c..ov009_func_0217FF14.c: c99=CCERR: line 55: struct/union/enum/class tag 'GSSoapTask' redefined | line 63: identifier 'GSSoapTask' redeclared | line 63: was declared as: 'struct GSSoapTask' nolang=CCERR: line 55: struct/union
- ov009_func_0217FF70.c..ov009_func_02180080.c: c99=CCERR: line 34: struct/union/enum/class tag 'GSSoapTask' redefined | line 48: identifier 'GSSoapTask' redeclared | line 48: was declared as: 'struct GSSoapTask' nolang=CCERR: line 34: struct/union
- ov009_func_0217FF70.c..ov009_func_0217FF94.c: c99=CCERR: line 30: struct/union/enum/class tag 'GSSoapTask' redefined | line 44: identifier 'GSSoapTask' redeclared | line 44: was declared as: 'struct GSSoapTask' nolang=CCERR: line 30: struct/union
- ov009_func_0218002C.c..ov009_func_02180080.c: c99=CCERR: line 28: struct/union/enum/class tag 'GSSoapTask' redefined | line 37: identifier 'GSSoapTask' redeclared | line 37: was declared as: 'struct GSSoapTask' nolang=CCERR: line 28: struct/union

Members, in address order:

- `ov009_func_0217FE68.c`
- `ov009_func_0217FF14.c`
- `ov009_func_0217FF70.c`
- `ov009_func_0217FF94.c`
- `ov009_func_0218002C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217FD7C.c` again.
