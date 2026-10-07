# unit_0219E9F4.c (ov009)

Translation unit 0219E9F4..0219F0D8, 16 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0219E9F4.c` is blocked by:

- ov009_func_0219E9F4.c..ov009_func_0219F078.c: c99=CCERR: line 112: struct/union/enum/class tag 'SBServer' redefined | line 219: warning: types that are declared in parameter lists ('ServerBrowser') go out of scope at the end of the function decla
- ov009_func_0219E9F4.c..ov009_func_0219EF60.c: c99=CCERR: line 102: struct/union/enum/class tag 'SBServer' redefined | line 184: warning: types that are declared in parameter lists ('ServerBrowser') go out of scope at the end of the function decla
- ov009_func_0219E9F4.c..ov009_func_0219ED4C.c: c99=CCERR: line 89: struct/union/enum/class tag 'SBServer' redefined nolang=CCERR: line 89: struct/union/enum/class tag 'SBServer' redefined
- ov009_func_0219E9F4.c..ov009_func_0219EBC4.c: c99=CCERR: line 78: struct/union/enum/class tag 'SBServer' redefined nolang=CCERR: line 78: struct/union/enum/class tag 'SBServer' redefined
- ov009_func_0219ED80.c..ov009_func_0219EF60.c: c99=CCERR: line 106: illegal implicit conversion from 'struct ServerBrowser *' to | line 106: 'struct  *' nolang=CCERR: line 106: illegal implicit conversion from 'struct ServerBrowser *' to | line 10
- ov009_func_0219ED80.c..ov009_func_0219EED4.c: c99=CCERR: line 93: illegal implicit conversion from 'struct ServerBrowser *' to | line 93: 'struct  *' nolang=CCERR: line 93: illegal implicit conversion from 'struct ServerBrowser *' to | line 93: '

Members, in address order:

- `ov009_func_0219E9F4.c`
- `ov009_func_0219EBC4.c`
- `ov009_func_0219ED80.c`
- `ov009_func_0219EED4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0219E9F4.c` again.
