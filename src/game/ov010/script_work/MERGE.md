# script_work.c (ov010)

Translation unit 02157954..021592F0, 137 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`script_work.c` is blocked by:

- ov010_func_02157954.c..func_021592C0.c: prototype of func_02175B14 differs between members (src/matched/ov/ov010_func_02158630.c); prototype of func_02175B14 differs between members (src/matched/ov/ov010_func_02158678.c); prototype of func_
- ov010_func_02157954.c..func_021589F4.c: prototype of func_02175B14 differs between members (src/matched/ov/ov010_func_02158630.c); prototype of func_02175B14 differs between members (src/matched/ov/ov010_func_02158678.c); prototype of func_
- ov010_func_02157954.c..ov010_func_021584A4.c: c99=DIFF nolang=DIFF
- ov010_func_02157954.c..ov010_func_02157E08.c: c99=DIFF nolang=DIFF
- ov010_func_02157954.c..ov010_func_02157AC8.c: c99=DIFF nolang=DIFF
- ov010_func_02157954.c..ov010_func_021579B0.c: c99=DIFF nolang=DIFF
- func_021584F4.c..func_021589F4.c: prototype of func_02175B14 differs between members (src/matched/ov/ov010_func_02158630.c); prototype of func_02175B14 differs between members (src/matched/ov/ov010_func_02158678.c); prototype of func_
- func_02158824.c..func_021589F4.c: c99=CCERR: line 265: function call 'func_021588B0(int, int)' does not match | line 265: 'func_021588B0(int, int, int)' | line 268: illegal implicit conversion from 'int' to nolang=CCERR: line 265: fun
- ov010_func_02158A10.c..func_021592C0.c: global d_0217289C declared two ways (src/matched/ov/ov010_func_0215909C.c); prototype of func_020307B0 differs between members (src/matched/ov/ov010_func_021590D4.c); prototype of func_02082A7C differ
- ov010_func_02158A10.c..func_02158F90.c: c99=DIFF nolang=DIFF
- ov010_func_02158A10.c..func_02158DBC.c: c99=DIFF nolang=DIFF
- ov010_func_02158A10.c..ov010_func_02158B00.c: c99=DIFF nolang=DIFF
- ov010_func_02158A10.c..ov010_func_02158A90.c: c99=DIFF nolang=DIFF
- ov010_func_02158A34.c..ov010_func_02158A90.c: c99=DIFF nolang=DIFF
- ov010_func_02158F94.c..func_021592C0.c: prototype of func_020307B0 differs between members (src/matched/ov/ov010_func_021590D4.c)
- ov010_func_02158F94.c..func_0215911C.c: prototype of func_020307B0 differs between members (src/matched/ov/ov010_func_021590D4.c)
- ov010_func_02158F94.c..func_02159030.c: c99=CCERR: line 100: illegal implicit conversion from 'void *' to | line 100: 'int' nolang=CCERR: line 100: illegal implicit conversion from 'void *' to | line 100: 'int'
- func_02158FD0.c..func_02159030.c: c99=CCERR: line 57: illegal implicit conversion from 'void *' to | line 57: 'int' nolang=CCERR: line 57: illegal implicit conversion from 'void *' to | line 57: 'int'
- func_02158FD0.c..ov010_func_02158FE0.c: c99=CCERR: line 50: illegal implicit conversion from 'void *' to | line 50: 'int' nolang=CCERR: line 50: illegal implicit conversion from 'void *' to | line 50: 'int'
- ov010_func_02159058.c..func_0215911C.c: prototype of func_02158FD0 differs between members (src/matched/ov/ov010_func_021590D4.c)
- ov010_func_02159058.c..func_021590F4.c: prototype of func_02158FD0 differs between members (src/matched/ov/ov010_func_021590D4.c)

Members, in address order:

- `ov010_func_02158A34.c`
- `ov010_func_02158A90.c`
- `func_02158FD0.c`
- `ov010_func_02158FE0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names script_work.c` again.
