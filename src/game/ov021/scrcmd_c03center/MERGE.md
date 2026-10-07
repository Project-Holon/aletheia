# scrcmd_c03center.c (ov021)

Translation unit 021B5A18..021B6D0C, 43 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`scrcmd_c03center.c` is blocked by:

- ov021_func_021B5A18.c..ov021_func_021B6BDC.c: prototype of func_02159B10 differs between members (src/matched/ov/ov021_func_021B636C.c)
- ov021_func_021B5A18.c..ov021_func_021B631C.c: c99=CCERR: line 421: illegal implicit conversion from 'unsigned short[]' to | line 421: 'struct  *' | line 428: illegal implicit conversion from 'unsigned short[]' to nolang=CCERR: line 421: illegal i
- ov021_func_021B5A18.c..ov021_func_021B5EB8.c: c99=CCERR: line 390: illegal implicit conversion from 'unsigned short[]' to | line 390: 'struct  *' | line 397: illegal implicit conversion from 'unsigned short[]' to nolang=CCERR: line 390: illegal i
- ov021_func_021B5C80.c..ov021_func_021B5EB8.c: c99=CCERR: line 212: illegal implicit conversion from 'unsigned short[]' to | line 212: 'struct  *' | line 219: illegal implicit conversion from 'unsigned short[]' to nolang=CCERR: line 212: illegal i
- ov021_func_021B5DD0.c..ov021_func_021B5EB8.c: c99=CCERR: line 106: illegal implicit conversion from 'unsigned short[]' to | line 106: 'struct  *' | line 113: illegal implicit conversion from 'unsigned short[]' to nolang=CCERR: line 106: illegal i
- ov021_func_021B636C.c..ov021_func_021B6BDC.c: prototype of func_02159B10 differs between members (src/matched/ov/ov021_func_021B647C.c); prototype of func_02159B10 differs between members (src/matched/ov/ov021_func_021B654C.c); prototype of func_
- ov021_func_021B6934.c..ov021_func_021B6BDC.c: c99=CCERR: line 298: illegal implicit conversion from 'void *' to | line 298: 'unsigned int' nolang=CCERR: line 298: illegal implicit conversion from 'void *' to | line 298: 'unsigned int'
- func_021B6AAC.c..ov021_func_021B6BDC.c: prototype of func_021B6AA4 differs between members (src/matched/ov/ov021_func_021B6AFC.c)
- ov021_func_021B6AFC.c..ov021_func_021B6BDC.c: prototype of func_021B6AA4 differs between members (src/matched/ov/ov021_func_021B6B6C.c)

Members, in address order:

- `ov021_func_021B5DD0.c`
- `ov021_func_021B6AFC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names scrcmd_c03center.c` again.
