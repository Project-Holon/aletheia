# unit_0217CA2C.c (ov009)

Translation unit 0217CA2C..0217CF5C, 10 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217CA2C.c` is blocked by:

- ov009_func_0217CA2C.c..ov009_func_0217CF24.c: prototype of func_0217CA20 differs between members (src/matched/ov_sdk/ov009_func_0217CA40.c); prototype of func_0217CA20 differs between members (src/matched/ov_sdk/ov009_func_0217CB88.c); prototype 
- ov009_func_0217CA2C.c..ov009_func_0217CCCC.c: prototype of func_0217CA20 differs between members (src/matched/ov_sdk/ov009_func_0217CA40.c); prototype of func_0217CA20 differs between members (src/matched/ov_sdk/ov009_func_0217CB88.c); prototype 
- ov009_func_0217CA2C.c..ov009_func_0217CA40.c: prototype of func_0217CA20 differs between members (src/matched/ov_sdk/ov009_func_0217CA40.c)
- ov009_func_0217CB5C.c..ov009_func_0217CCCC.c: c99=CCERR: line 49: struct/union/enum/class tag 'GSTask' redefined | line 64: identifier 'GSTask' redeclared | line 64: was declared as: 'struct GSTask' nolang=CCERR: line 49: struct/union/enum/class 
- ov009_func_0217CB88.c..ov009_func_0217CCCC.c: c99=CCERR: line 59: struct/union/enum/class tag 'GSTask' redefined | line 62: identifier 'GSTask' redeclared | line 62: was declared as: 'struct GSTask' nolang=CCERR: line 59: struct/union/enum/class 
- ov009_func_0217CD94.c..ov009_func_0217CF24.c: c99=CCERR: line 70: struct/union/enum/class tag 'GSTask' redefined | line 78: identifier 'GSTask' redeclared | line 78: was declared as: 'struct GSTask' nolang=CCERR: line 70: struct/union/enum/class 
- ov009_func_0217CE48.c..ov009_func_0217CF24.c: c99=CCERR: line 49: struct/union/enum/class tag 'GSTask' redefined | line 57: identifier 'GSTask' redeclared | line 57: was declared as: 'struct GSTask' nolang=CCERR: line 49: struct/union/enum/class 
- ov009_func_0217CECC.c..ov009_func_0217CF24.c: c99=CCERR: line 37: struct/union/enum/class tag 'GSTask' redefined | line 41: identifier 'GSTask' redeclared | line 41: was declared as: 'struct GSTask' nolang=CCERR: line 37: struct/union/enum/class 

Members, in address order:

- `ov009_func_0217CA2C.c`
- `ov009_func_0217CA40.c`
- `ov009_func_0217CB5C.c`
- `ov009_func_0217CB88.c`
- `ov009_func_0217CCCC.c`
- `ov009_func_0217CE48.c`
- `ov009_func_0217CECC.c`
- `ov009_func_0217CF24.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217CA2C.c` again.
