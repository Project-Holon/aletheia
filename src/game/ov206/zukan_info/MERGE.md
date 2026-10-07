# zukan_info.c (ov206)

Translation unit 021B9DE0..021BC0E4, 55 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`zukan_info.c` is blocked by:

- ov206_func_021B9DE0.c..ov206_func_021BC0E0.c: prototype of func_020450F0 differs between members (src/matched/ov/ov206_func_021BAFC4.c); prototype of func_0204B404 differs between members (src/matched/ov/ov206_func_021BB79C.c)
- ov206_func_021B9DE0.c..ov206_func_021BB214.c: prototype of func_020450F0 differs between members (src/matched/ov/ov206_func_021BAFC4.c)
- ov206_func_021B9DE0.c..ov206_func_021BA890.c: c99=CCERR: line 387: illegal implicit conversion from 'char *' to | line 387: 'struct  *' nolang=CCERR: line 387: illegal implicit conversion from 'char *' to | line 387: 'struct  *'
- ov206_func_021B9DE0.c..ov206_func_021BA4F4.c: c99=DIFF nolang=DIFF
- ov206_func_021B9DE0.c..ov206_func_021BA2CC.c: c99=DIFF nolang=DIFF
- ov206_func_021BB23C.c..ov206_func_021BC0E0.c: prototype of func_0204B404 differs between members (src/matched/ov/ov206_func_021BB79C.c)
- ov206_func_021BB23C.c..ov206_func_021BBBD8.c: prototype of func_0204B404 differs between members (src/matched/ov/ov206_func_021BB79C.c)
- ov206_func_021BB23C.c..ov206_func_021BB534.c: c99=CCERR: line 252: illegal implicit conversion from 'char *' to | line 252: 'struct  *' nolang=CCERR: line 252: illegal implicit conversion from 'char *' to | line 252: 'struct  *'
- ov206_func_021BB304.c..ov206_func_021BB534.c: c99=CCERR: line 212: illegal implicit conversion from 'char *' to | line 212: 'struct  *' nolang=CCERR: line 212: illegal implicit conversion from 'char *' to | line 212: 'struct  *'
- ov206_func_021BB4E0.c..ov206_func_021BB534.c: c99=CCERR: line 114: illegal implicit conversion from 'char *' to | line 114: 'struct  *' nolang=CCERR: line 114: illegal implicit conversion from 'char *' to | line 114: 'struct  *'
- ov206_func_021BB79C.c..ov206_func_021BBBD8.c: c99=CCERR: line 308: illegal implicit conversion from 'struct S *' to | line 308: 'struct S_021BBBD8 *' nolang=CCERR: line 308: illegal implicit conversion from 'struct S *' to | line 308: 'struct S_0
- ov206_func_021BB9E0.c..ov206_func_021BBBD8.c: c99=CCERR: line 132: illegal implicit conversion from 'struct S *' to | line 132: 'struct S_021BBBD8 *' nolang=CCERR: line 132: illegal implicit conversion from 'struct S *' to | line 132: 'struct S_0
- ov206_func_021BBC04.c..ov206_func_021BC0E0.c: prototype of func_021BBAB0 differs between members (src/matched/ov/ov206_func_021BBC68.c)
- ov206_func_021BBC04.c..ov206_func_021BBE5C.c: prototype of func_021BBAB0 differs between members (src/matched/ov/ov206_func_021BBC68.c)
- ov206_func_021BBC04.c..ov206_func_021BBC68.c: prototype of func_021BBAB0 differs between members (src/matched/ov/ov206_func_021BBC68.c)

Members, in address order:

- `ov206_func_021B9DE0.c`
- `ov206_func_021BB4E0.c`
- `ov206_func_021BB534.c`
- `ov206_func_021BBC04.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names zukan_info.c` again.
