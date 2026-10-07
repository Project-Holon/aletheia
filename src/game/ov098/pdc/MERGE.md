# pdc.c (ov098)

Translation unit 021B6100..021B6CDC, 38 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`pdc.c` is blocked by:

- ov098_func_021B6100.c..ov098_func_021B6C90.c: prototype of func_02034AC4 differs between members (src/matched/ov/ov098_func_021B6578.c); prototype of func_02034A5C differs between members (src/matched/ov/ov098_func_021B6578.c); prototype of func_
- ov098_func_021B6100.c..ov098_func_021B644C.c: c99=CCERR: line 261: illegal implicit conversion from 'int' to | line 261: 'void *' nolang=CCERR: line 261: illegal implicit conversion from 'int' to | line 261: 'void *'
- ov098_func_021B6504.c..ov098_func_021B6C90.c: prototype of func_0204E720 differs between members (src/matched/ov/ov098_func_021B6750.c); prototype of func_0201F02C differs between members (src/matched/ov/ov098_func_021B694C.c); prototype of func_
- ov098_func_021B6504.c..ov098_func_021B694C.c: prototype of func_0204E720 differs between members (src/matched/ov/ov098_func_021B6750.c); prototype of func_0201F02C differs between members (src/matched/ov/ov098_func_021B694C.c); prototype of func_
- ov098_func_021B67D4.c..ov098_func_021B694C.c: prototype of func_0201F02C differs between members (src/matched/ov/ov098_func_021B694C.c); prototype of func_0201F250 differs between members (src/matched/ov/ov098_func_021B694C.c); prototype of func_
- ov098_func_021B6910.c..ov098_func_021B694C.c: prototype of func_0201F02C differs between members (src/matched/ov/ov098_func_021B694C.c); prototype of func_0201F250 differs between members (src/matched/ov/ov098_func_021B694C.c); prototype of func_
- ov098_func_021B6A00.c..ov098_func_021B6C90.c: c99=CCERR: line 92: illegal implicit conversion from 'int' to | line 92: 'char *' nolang=CCERR: line 92: illegal implicit conversion from 'int' to | line 92: 'char *'

Members, in address order:

- `ov098_func_021B6910.c`
- `ov098_func_021B694C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names pdc.c` again.
