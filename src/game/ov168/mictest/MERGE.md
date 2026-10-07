# mictest.c (ov168)

Translation unit 02183B60..0218484C, 45 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`mictest.c` is blocked by:

- ov168_func_02183B60.c..ov168_func_0218483C.c: global d_02184A20 declared two ways (src/matched/ov/ov168_func_02184398.c)
- ov168_func_02184138.c..ov168_func_0218483C.c: c99=CCERR: line 392: illegal implicit conversion from 'char *' to | line 392: 'struct  *' | line 451: illegal implicit conversion from 'void *' to nolang=CCERR: line 392: illegal implicit conversion f
- ov168_func_0218441C.c..ov168_func_0218483C.c: c99=CCERR: line 181: illegal implicit conversion from 'char *' to | line 181: 'struct  *' | line 240: illegal implicit conversion from 'void *' to nolang=CCERR: line 181: illegal implicit conversion f
- ov168_func_0218441C.c..ov168_func_021845AC.c: c99=CCERR: line 129: illegal implicit conversion from 'char *' to | line 129: 'struct  *' nolang=CCERR: line 129: illegal implicit conversion from 'char *' to | line 129: 'struct  *'
- ov168_func_0218449C.c..ov168_func_021845AC.c: c99=CCERR: line 68: illegal implicit conversion from 'char *' to | line 68: 'struct  *' nolang=CCERR: line 68: illegal implicit conversion from 'char *' to | line 68: 'struct  *'
- ov168_func_021845E0.c..ov168_func_0218483C.c: c99=CCERR: line 110: illegal implicit conversion from 'void *' to | line 110: 'int' nolang=CCERR: line 110: illegal implicit conversion from 'void *' to | line 110: 'int'
- ov168_func_021845E0.c..ov168_func_02184680.c: c99=CCERR: line 98: illegal implicit conversion from 'void *' to | line 98: 'int' nolang=CCERR: line 98: illegal implicit conversion from 'void *' to | line 98: 'int'
- ov168_func_02184600.c..ov168_func_02184680.c: c99=CCERR: line 86: illegal implicit conversion from 'void *' to | line 86: 'int' nolang=CCERR: line 86: illegal implicit conversion from 'void *' to | line 86: 'int'

Members, in address order:

- `ov168_func_0218449C.c`
- `ov168_func_021845E0.c`
- `ov168_func_02184600.c`
- `ov168_func_02184680.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names mictest.c` again.
