# unit_021BA594.c (ov099)

Translation unit 021BA594..021BA81C, 19 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BA594.c` is blocked by:

- func_021BA594.c..func_021BA810.c: prototype of func_02061CA4 differs between members (src/matched/ov/ov099_func_021BA6DC.c)
- func_021BA594.c..ov099_func_021BA6DC.c: prototype of func_021BA764 differs between members (src/matched/ov/ov099_func_021BA6DC.c); prototype of func_02061CA4 differs between members (src/matched/ov/ov099_func_021BA6DC.c)
- ov099_func_021BA60C.c..ov099_func_021BA6DC.c: prototype of func_021BA764 differs between members (src/matched/ov/ov099_func_021BA6DC.c); prototype of func_02061CA4 differs between members (src/matched/ov/ov099_func_021BA6DC.c)
- func_021BA660.c..ov099_func_021BA6DC.c: prototype of func_021BA764 differs between members (src/matched/ov/ov099_func_021BA6DC.c); prototype of func_02061CA4 differs between members (src/matched/ov/ov099_func_021BA6DC.c)
- ov099_func_021BA674.c..ov099_func_021BA6DC.c: prototype of func_021BA764 differs between members (src/matched/ov/ov099_func_021BA6DC.c)
- func_021BA764.c..func_021BA810.c: c99=CCERR: line 107: illegal implicit conversion from 'unsigned char *' to | line 107: 'struct  *' | line 112: illegal implicit conversion from 'unsigned char *' to nolang=CCERR: line 107: illegal imp
- func_021BA764.c..func_021BA7BC.c: c99=CCERR: line 92: illegal implicit conversion from 'unsigned char *' to | line 92: 'struct  *' | line 97: illegal implicit conversion from 'unsigned char *' to nolang=CCERR: line 92: illegal implici
- func_021BA78C.c..func_021BA7BC.c: c99=CCERR: line 62: illegal implicit conversion from 'unsigned char *' to | line 62: 'struct  *' | line 69: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 62: illegal implicit conv
- func_021BA7CC.c..func_021BA810.c: c99=DIFF nolang=DIFF
- func_021BA7D8.c..func_021BA810.c: c99=DIFF nolang=DIFF
- func_021BA7F8.c..func_021BA810.c: c99=DIFF nolang=DIFF

Members, in address order:

- `func_021BA660.c`
- `ov099_func_021BA674.c`
- `ov099_func_021BA6DC.c`
- `func_021BA78C.c`
- `func_021BA7D8.c`
- `func_021BA7F8.c`
- `func_021BA810.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BA594.c` again.
