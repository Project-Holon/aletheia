# symbol_map.c (ov010)

Translation unit 0216630C..02167358, 53 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`symbol_map.c` is blocked by:

- func_0216630C.c..ov010_func_0216730C.c: global d_02172BA4 declared two ways (src/matched/ov/ov010_func_02166B0C.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_02166D30.c); prototype of func_020307B0 differ
- func_0216630C.c..ov010_func_02166A00.c: c99=CCERR: line 224: illegal implicit conversion from 'unsigned char *' to | line 224: 'int' | line 411: function call 'func_021663F4(unsigned char *, int, unsigned int)' does not match nolang=CCERR: 
- func_0216630C.c..ov010_func_0216666C.c: c99=CCERR: line 126: illegal implicit conversion from 'unsigned char *' to | line 126: 'int' | line 313: function call 'func_021663F4(unsigned char *, int, unsigned int)' does not match nolang=CCERR: 
- func_0216630C.c..ov010_func_021664CC.c: c99=CCERR: line 109: illegal implicit conversion from 'unsigned char *' to | line 109: 'int' nolang=CCERR: line 109: illegal implicit conversion from 'unsigned char *' to | line 109: 'int'
- func_0216630C.c..ov010_func_021663F4.c: c99=CCERR: line 52: illegal implicit conversion from 'unsigned char *' to | line 52: 'int' nolang=CCERR: line 52: illegal implicit conversion from 'unsigned char *' to | line 52: 'int'
- ov010_func_02166324.c..ov010_func_021663F4.c: prototype of func_0216630C differs between members (src/matched/ov/ov010_func_021663F4.c)
- ov010_func_02166A6C.c..ov010_func_0216730C.c: global d_02172BA4 declared two ways (src/matched/ov/ov010_func_02166B0C.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_02166F1C.c); prototype of func_021907C0 differ
- ov010_func_02166A6C.c..ov010_func_02167080.c: global d_02172BA4 declared two ways (src/matched/ov/ov010_func_02166B0C.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_02166F1C.c)
- ov010_func_02166A6C.c..ov010_func_02166C7C.c: global d_02172BA4 declared two ways (src/matched/ov/ov010_func_02166B0C.c)
- ov010_func_02166A6C.c..ov010_func_02166B2C.c: global d_02172BA4 declared two ways (src/matched/ov/ov010_func_02166B0C.c)
- ov010_func_021670F8.c..ov010_func_0216730C.c: prototype of func_021907C0 differs between members (src/matched/ov/func_021672B4.c); prototype of func_020409B4 differs between members (src/matched/ov/func_021672B4.c)
- func_021671EC.c..ov010_func_0216730C.c: prototype of func_021907C0 differs between members (src/matched/ov/func_021672B4.c); prototype of func_020409B4 differs between members (src/matched/ov/func_021672B4.c)
- func_021671EC.c..func_021672B4.c: prototype of func_021907C0 differs between members (src/matched/ov/func_021672B4.c); prototype of func_020409B4 differs between members (src/matched/ov/func_021672B4.c)
- ov010_func_021671FC.c..func_021672B4.c: prototype of func_021907C0 differs between members (src/matched/ov/func_021672B4.c); prototype of func_020409B4 differs between members (src/matched/ov/func_021672B4.c)

Members, in address order:

- `func_0216630C.c`
- `ov010_func_02166324.c`
- `ov010_func_021663F4.c`
- `ov010_func_02166A6C.c`
- `func_021671EC.c`
- `ov010_func_021671FC.c`
- `func_021672B4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names symbol_map.c` again.
