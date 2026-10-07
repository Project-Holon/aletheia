# unit_02184C78.c (ov020)

Translation unit 02184C78..02185EB0, 43 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02184C78.c` is blocked by:

- ov020_func_02184C78.c..ov020_func_02185D38.c: prototype of func_02014184 differs between members (src/matched/ov/ov020_func_02184E40.c); prototype of func_02014184 differs between members (src/matched/ov/ov020_func_02185050.c); prototype of func_
- ov020_func_02184C78.c..ov020_func_021854B0.c: prototype of func_02014184 differs between members (src/matched/ov/ov020_func_02184E40.c); prototype of func_02014184 differs between members (src/matched/ov/ov020_func_02185050.c); prototype of func_
- ov020_func_02184FD4.c..ov020_func_021854B0.c: prototype of func_02014184 differs between members (src/matched/ov/ov020_func_02185050.c); prototype of func_02014184 differs between members (src/matched/ov/ov020_func_021850A8.c); prototype of func_
- ov020_func_02184FD4.c..ov020_func_02185140.c: prototype of func_02014184 differs between members (src/matched/ov/ov020_func_02185050.c); prototype of func_02014184 differs between members (src/matched/ov/ov020_func_021850A8.c); prototype of func_
- ov020_func_02184FD4.c..ov020_func_02185050.c: prototype of func_02014184 differs between members (src/matched/ov/ov020_func_02185050.c)
- ov020_func_021854CC.c..ov020_func_02185D38.c: prototype of func_02014184 differs between members (src/matched/ov/ov020_func_02185588.c)
- ov020_func_021854CC.c..ov020_func_02185928.c: prototype of func_02014184 differs between members (src/matched/ov/ov020_func_02185588.c)
- ov020_func_0218571C.c..ov020_func_02185928.c: c99=CCERR: line 207: illegal implicit conversion from 'int' to | line 207: 'void *' nolang=CCERR: line 207: illegal implicit conversion from 'int' to | line 207: 'void *'
- ov020_func_021859F0.c..ov020_func_02185D38.c: c99=CCERR: line 413: illegal implicit conversion from 'int' to | line 413: 'void *' nolang=CCERR: line 413: illegal implicit conversion from 'int' to | line 413: 'void *'
- ov020_func_02185B88.c..ov020_func_02185D38.c: c99=CCERR: line 275: illegal implicit conversion from 'int' to | line 275: 'void *' nolang=CCERR: line 275: illegal implicit conversion from 'int' to | line 275: 'void *'
- ov020_func_02185C4C.c..ov020_func_02185D38.c: c99=CCERR: line 196: illegal implicit conversion from 'int' to | line 196: 'void *' nolang=CCERR: line 196: illegal implicit conversion from 'int' to | line 196: 'void *'

Members, in address order:

- `ov020_func_02184FD4.c`
- `ov020_func_02185050.c`
- `ov020_func_02185C4C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02184C78.c` again.
