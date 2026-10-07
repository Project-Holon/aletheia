# unit_021B6100.c (ov093)

Translation unit 021B6100..021B7488, 22 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021B6100.c` is blocked by:

- ov093_func_021B6100.c..ov093_func_021B73C4.c: c99=CCERR: line 192: identifier 'Callback' redeclared | line 192: was declared as: 'struct ' | line 192: now declared as: 'struct ' nolang=CCERR: line 192: identifier 'Callback' redeclared | line 192:
- ov093_func_021B6100.c..ov093_func_021B6994.c: c99=CCERR: line 168: identifier 'Callback' redeclared | line 168: was declared as: 'struct ' | line 168: now declared as: 'struct ' nolang=CCERR: line 168: identifier 'Callback' redeclared | line 168:
- ov093_func_021B6100.c..ov093_func_021B66D4.c: c99=CCERR: line 149: identifier 'Callback' redeclared | line 149: was declared as: 'struct ' | line 149: now declared as: 'struct ' nolang=CCERR: line 149: identifier 'Callback' redeclared | line 149:
- ov093_func_021B64CC.c..ov093_func_021B66D4.c: c99=CCERR: line 63: identifier 'Callback' redeclared | line 63: was declared as: 'struct ' | line 63: now declared as: 'struct ' nolang=CCERR: line 63: identifier 'Callback' redeclared | line 63: was 
- ov093_func_021B6500.c..ov093_func_021B66D4.c: c99=CCERR: line 61: identifier 'Callback' redeclared | line 61: was declared as: 'struct ' | line 61: now declared as: 'struct ' nolang=CCERR: line 61: identifier 'Callback' redeclared | line 61: was 
- ov093_func_021B6818.c..ov093_func_021B6994.c: c99=CCERR: line 102: illegal implicit conversion from 'struct T_021B6848 *' to | line 102: 'struct T_021B68D8 *' nolang=CCERR: line 102: illegal implicit conversion from 'struct T_021B6848 *' to | lin

Members, in address order:

- `ov093_func_021B64CC.c`
- `ov093_func_021B6500.c`
- `ov093_func_021B66D4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021B6100.c` again.
