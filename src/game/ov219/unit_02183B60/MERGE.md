# unit_02183B60.c (ov219)

Translation unit 02183B60..02185CF4, 46 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02183B60.c` is blocked by:

- ov219_func_02183B60.c..ov219_func_02185C84.c: type typedef Record differs between members (src/matched/ov/ov219_func_02184734.c); prototype of func_0201DD78 differs between members (src/matched/ov/ov219_func_02184CB0.c); prototype of func_0201FF3
- ov219_func_02183B60.c..ov219_func_02184D70.c: type typedef Record differs between members (src/matched/ov/ov219_func_02184734.c); prototype of func_0201DD78 differs between members (src/matched/ov/ov219_func_02184CB0.c)
- ov219_func_02183B60.c..ov219_func_021846B8.c: c99=CCERR: line 719: illegal implicit conversion from 'char *' to | line 719: 'struct  *' | line 732: illegal implicit conversion from 'char *' to nolang=CCERR: line 719: illegal implicit conversion f
- ov219_func_02184470.c..ov219_func_021846B8.c: c99=CCERR: line 165: illegal implicit conversion from 'char *' to | line 165: 'struct  *' | line 178: illegal implicit conversion from 'char *' to nolang=CCERR: line 165: illegal implicit conversion f
- ov219_func_021845A4.c..ov219_func_021846B8.c: c99=CCERR: line 79: illegal implicit conversion from 'char *' to | line 79: 'struct  *' | line 92: illegal implicit conversion from 'char *' to nolang=CCERR: line 79: illegal implicit conversion from 
- ov219_func_021845B4.c..ov219_func_021846B8.c: c99=CCERR: line 66: illegal implicit conversion from 'char *' to | line 66: 'struct  *' | line 79: illegal implicit conversion from 'char *' to nolang=CCERR: line 66: illegal implicit conversion from 
- ov219_func_02184734.c..ov219_func_02184D70.c: prototype of func_0201DD78 differs between members (src/matched/ov/ov219_func_02184CB0.c)
- ov219_func_02184EAC.c..ov219_func_02185C84.c: prototype of func_0201FF30 differs between members (src/matched/ov/ov219_func_02184FC8.c); prototype of func_0201F81C differs between members (src/matched/ov/ov219_func_021850EC.c); prototype of func_
- ov219_func_02184EAC.c..ov219_func_0218544C.c: prototype of func_0201FF30 differs between members (src/matched/ov/ov219_func_02184FC8.c); prototype of func_0201F81C differs between members (src/matched/ov/ov219_func_021850EC.c); prototype of func_
- ov219_func_02184EAC.c..ov219_func_021850EC.c: prototype of func_0201FF30 differs between members (src/matched/ov/ov219_func_02184FC8.c); prototype of func_0201F81C differs between members (src/matched/ov/ov219_func_021850EC.c)
- ov219_func_02185580.c..ov219_func_02185C84.c: global d_02185DF4 declared two ways (src/matched/ov/ov219_func_02185794.c); prototype of func_02048AFC differs between members (src/matched/ov/ov219_func_02185AC8.c); prototype of func_0207B388 differ
- ov219_func_02185848.c..ov219_func_02185C84.c: prototype of func_0207B388 differs between members (src/matched/ov/ov219_func_02185B74.c)

Members, in address order:

- `ov219_func_021845A4.c`
- `ov219_func_021845B4.c`
- `ov219_func_021846B8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02183B60.c` again.
