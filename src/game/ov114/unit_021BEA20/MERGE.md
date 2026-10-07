# unit_021BEA20.c (ov114)

Translation unit 021BEA20..021BEF3C, 21 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BEA20.c` is blocked by:

- ov114_func_021BEA20.c..ov114_func_021BEF08.c: global g_021CF984 declared two ways (src/matched/ov_sdk/ov114_func_021BEAB8.c); global g_021CF984 declared two ways (src/matched/ov_sdk/ov114_func_021BEC48.c); global g_021CF984 declared two ways (src
- ov114_func_021BEA20.c..ov114_func_021BEC00.c: global g_021CF984 declared two ways (src/matched/ov_sdk/ov114_func_021BEAB8.c)
- ov114_func_021BEA20.c..ov114_func_021BEB88.c: global g_021CF984 declared two ways (src/matched/ov_sdk/ov114_func_021BEAB8.c)
- ov114_func_021BEA20.c..ov114_func_021BEA64.c: c99=CCERR: line 54: illegal implicit conversion from 'struct  *' to | line 54: 'unsigned char *' nolang=CCERR: line 54: illegal implicit conversion from 'struct  *' to | line 54: 'unsigned char *'
- ov114_func_021BEC10.c..ov114_func_021BEF08.c: c99=CCERR: line 68: struct/union/enum/class tag 'Conn' redefined | line 71: identifier 'Conn' redeclared | line 71: was declared as: 'struct Conn' nolang=CCERR: line 68: struct/union/enum/class tag 'C
- ov114_func_021BEC10.c..ov114_func_021BED04.c: c99=CCERR: line 60: struct/union/enum/class tag 'Conn' redefined | line 63: identifier 'Conn' redeclared | line 63: was declared as: 'struct Conn' nolang=CCERR: line 60: struct/union/enum/class tag 'C
- ov114_func_021BEC48.c..ov114_func_021BED04.c: c99=CCERR: line 59: struct/union/enum/class tag 'Conn' redefined | line 62: identifier 'Conn' redeclared | line 62: was declared as: 'struct Conn' nolang=CCERR: line 59: struct/union/enum/class tag 'C
- ov114_func_021BEC74.c..ov114_func_021BED04.c: c99=CCERR: line 51: struct/union/enum/class tag 'Conn' redefined | line 54: identifier 'Conn' redeclared | line 54: was declared as: 'struct Conn' nolang=CCERR: line 51: struct/union/enum/class tag 'C

Members, in address order:

- `ov114_func_021BEA20.c`
- `ov114_func_021BEA64.c`
- `ov114_func_021BEC48.c`
- `ov114_func_021BEC74.c`
- `ov114_func_021BED04.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BEA20.c` again.
