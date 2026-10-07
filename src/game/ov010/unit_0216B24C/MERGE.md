# unit_0216B24C.c (ov010)

Translation unit 0216B24C..0216BF38, 40 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0216B24C.c` is blocked by:

- ov010_func_0216B24C.c..ov010_func_0216BEC0.c: prototype of func_02082BCC differs between members (src/matched/ov/ov010_func_0216B340.c); prototype of func_02188CB4 differs between members (src/matched/ov/ov010_func_0216BBD4.c); prototype of func_
- ov010_func_0216B24C.c..func_0216B91C.c: prototype of func_02082BCC differs between members (src/matched/ov/ov010_func_0216B340.c)
- ov010_func_0216B24C.c..ov010_func_0216B5AC.c: prototype of func_02082BCC differs between members (src/matched/ov/ov010_func_0216B340.c)
- ov010_func_0216B24C.c..ov010_func_0216B3A8.c: prototype of func_02082BCC differs between members (src/matched/ov/ov010_func_0216B340.c)
- ov010_func_0216B2E4.c..ov010_func_0216B3A8.c: c99=CCERR: line 115: illegal implicit conversion from 'int[3]' to | line 115: 'struct  *' | line 116: illegal implicit conversion from 'int[3]' to nolang=CCERR: line 115: illegal implicit conversion f
- ov010_func_0216B340.c..ov010_func_0216B3A8.c: c99=CCERR: line 88: illegal implicit conversion from 'int[3]' to | line 88: 'struct  *' nolang=CCERR: line 88: illegal implicit conversion from 'int[3]' to | line 88: 'struct  *'

Members, in address order:

- `ov010_func_0216B2E4.c`
- `ov010_func_0216B340.c`
- `ov010_func_0216B3A8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0216B24C.c` again.
