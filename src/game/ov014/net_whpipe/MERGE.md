# net_whpipe.c (ov014)

Translation unit 0217721C..02177C08, 36 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`net_whpipe.c` is blocked by:

- ov014_func_0217721C.c..ov014_func_02177BFC.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_0217771C.c); global g_021797A4 declared two ways (src/matched/ov/ov014_func_021777FC.c); global g_021797A4 declared two ways (src/matched
- ov014_func_0217721C.c..ov014_func_02177744.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_0217771C.c)
- ov014_func_0217721C.c..ov014_func_02177560.c: c99=CCERR: line 59: struct/union/enum/class tag 'W' redefined | line 190: illegal implicit conversion from 'struct W *' to | line 190: 'struct  *' nolang=CCERR: line 59: struct/union/enum/class tag 'W
- ov014_func_0217721C.c..ov014_func_02177280.c: c99=DIFF nolang=DIFF
- ov014_func_02177310.c..ov014_func_02177560.c: c99=CCERR: line 47: struct/union/enum/class tag 'W' redefined | line 117: illegal implicit conversion from 'struct W *' to | line 117: 'struct  *' nolang=CCERR: line 47: struct/union/enum/class tag 'W
- ov014_func_021773E0.c..ov014_func_02177560.c: c99=CCERR: line 39: struct/union/enum/class tag 'W' redefined nolang=CCERR: line 39: struct/union/enum/class tag 'W' redefined
- ov014_func_0217758C.c..ov014_func_02177744.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_0217771C.c)
- ov014_func_02177660.c..ov014_func_02177744.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_0217771C.c)
- ov014_func_02177704.c..ov014_func_02177744.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_0217771C.c)
- ov014_func_0217771C.c..ov014_func_02177744.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_02177744.c)
- ov014_func_0217778C.c..ov014_func_02177BFC.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_021777FC.c); global g_021797A4 declared two ways (src/matched/ov/ov014_func_02177AA8.c); global g_021797A4 declared two ways (src/matched
- ov014_func_0217778C.c..ov014_func_02177AA8.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_021777FC.c); global g_021797A4 declared two ways (src/matched/ov/ov014_func_02177AA8.c)
- ov014_func_0217778C.c..ov014_func_0217796C.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_021777FC.c)
- ov014_func_0217778C.c..ov014_func_021777FC.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_021777FC.c)
- ov014_func_02177ACC.c..ov014_func_02177BFC.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_02177AEC.c); global g_021797A4 declared two ways (src/matched/ov/ov014_func_02177B2C.c); global g_021797A4 declared two ways (src/matched
- ov014_func_02177ACC.c..ov014_func_02177B58.c: global g_021797A4 declared two ways (src/matched/ov/ov014_func_02177AEC.c); global g_021797A4 declared two ways (src/matched/ov/ov014_func_02177B2C.c); global g_021797A4 declared two ways (src/matched

Members, in address order:

- `ov014_func_021773E0.c`
- `ov014_func_02177704.c`
- `ov014_func_0217771C.c`
- `ov014_func_02177744.c`
- `ov014_func_0217778C.c`
- `ov014_func_021777FC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names net_whpipe.c` again.
