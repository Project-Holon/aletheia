# unit_02175C40.c (ov011)

Translation unit 02175C40..021766A8, 36 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02175C40.c` is blocked by:

- ov011_func_02175C40.c..ov011_func_02176504.c: c99=CCERR: line 602: illegal implicit conversion from 'unsigned char[20]' to | line 602: 'struct  *' | line 645: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 602: illegal implici
- ov011_func_02175C40.c..ov011_func_02175F34.c: c99=CCERR: line 346: illegal implicit conversion from 'unsigned char[20]' to | line 346: 'struct  *' nolang=CCERR: line 346: illegal implicit conversion from 'unsigned char[20]' to | line 346: 'struct
- ov011_func_02175DCC.c..ov011_func_02175F34.c: c99=CCERR: line 217: illegal implicit conversion from 'unsigned char[20]' to | line 217: 'struct  *' nolang=CCERR: line 217: illegal implicit conversion from 'unsigned char[20]' to | line 217: 'struct
- ov011_func_02175EB8.c..ov011_func_02175F34.c: c99=CCERR: line 126: illegal implicit conversion from 'unsigned char[20]' to | line 126: 'struct  *' nolang=CCERR: line 126: illegal implicit conversion from 'unsigned char[20]' to | line 126: 'struct
- ov011_func_02175EE8.c..ov011_func_02175F34.c: c99=CCERR: line 98: illegal implicit conversion from 'unsigned char[20]' to | line 98: 'struct  *' nolang=CCERR: line 98: illegal implicit conversion from 'unsigned char[20]' to | line 98: 'struct  *'
- ov011_func_02175EFC.c..ov011_func_02175F34.c: c99=CCERR: line 89: illegal implicit conversion from 'unsigned char[20]' to | line 89: 'struct  *' nolang=CCERR: line 89: illegal implicit conversion from 'unsigned char[20]' to | line 89: 'struct  *'
- ov011_func_02175FB4.c..ov011_func_02176504.c: c99=CCERR: line 329: illegal implicit conversion from 'struct  *' to | line 329: 'struct  *' | line 443: illegal implicit conversion from 'void *' to nolang=CCERR: line 329: illegal implicit conversio
- ov011_func_02175FB4.c..ov011_func_02176230.c: c99=CCERR: line 165: illegal implicit conversion from 'struct  *' to | line 165: 'struct  *' nolang=CCERR: line 165: illegal implicit conversion from 'struct  *' to | line 165: 'struct  *'
- ov011_func_02175FB4.c..ov011_func_02176158.c: c99=CCERR: line 148: illegal implicit conversion from 'struct  *' to | line 148: 'struct  *' nolang=CCERR: line 148: illegal implicit conversion from 'struct  *' to | line 148: 'struct  *'
- ov011_func_02176194.c..ov011_func_02176230.c: c99=DIFF nolang=DIFF
- ov011_func_02176194.c..ov011_func_021761EC.c: c99=DIFF nolang=DIFF
- ov011_func_02176258.c..ov011_func_02176504.c: c99=CCERR: line 227: illegal implicit conversion from 'void *' to | line 227: 'unsigned short' | line 231: illegal implicit conversion from 'void *' to nolang=CCERR: line 227: illegal implicit convers
- ov011_func_02176258.c..ov011_func_021762D8.c: c99=CCERR: line 100: illegal implicit conversion from 'void *' to | line 100: 'unsigned short' | line 104: illegal implicit conversion from 'void *' to nolang=CCERR: line 100: illegal implicit convers
- ov011_func_021762C0.c..ov011_func_021762D8.c: c99=CCERR: line 66: illegal implicit conversion from 'void *' to | line 66: 'unsigned short' | line 70: illegal implicit conversion from 'void *' to nolang=CCERR: line 66: illegal implicit conversion 

Members, in address order:

- `ov011_func_02175EE8.c`
- `ov011_func_02175EFC.c`
- `ov011_func_02175F34.c`
- `ov011_func_02176194.c`
- `ov011_func_021761EC.c`
- `ov011_func_021762C0.c`
- `ov011_func_021762D8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02175C40.c` again.
