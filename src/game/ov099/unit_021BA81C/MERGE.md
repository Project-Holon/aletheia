# unit_021BA81C.c (ov099)

Translation unit 021BA81C..021BB954, 30 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BA81C.c` is blocked by:

- func_021BA81C.c..ov099_func_021BB918.c: prototype of func_0201C6B4 differs between members (src/matched/ov/ov099_func_021BA978.c); prototype of func_020450F0 differs between members (src/matched/ov/ov099_func_021BAB04.c); prototype of func_
- func_021BA81C.c..func_021BAD50.c: prototype of func_0201C6B4 differs between members (src/matched/ov/ov099_func_021BA978.c); prototype of func_020450F0 differs between members (src/matched/ov/ov099_func_021BAB04.c); prototype of func_
- func_021BA81C.c..ov099_func_021BA8EC.c: c99=CCERR: line 156: illegal implicit conversion from 'char *' to | line 156: 'struct  *' nolang=CCERR: line 156: illegal implicit conversion from 'char *' to | line 156: 'struct  *'
- ov099_func_021BA874.c..ov099_func_021BA8EC.c: c99=CCERR: line 115: illegal implicit conversion from 'char *' to | line 115: 'struct  *' nolang=CCERR: line 115: illegal implicit conversion from 'char *' to | line 115: 'struct  *'
- func_021BA8D4.c..ov099_func_021BA8EC.c: c99=CCERR: line 66: illegal implicit conversion from 'char *' to | line 66: 'struct  *' nolang=CCERR: line 66: illegal implicit conversion from 'char *' to | line 66: 'struct  *'
- ov099_func_021BA928.c..func_021BAD50.c: prototype of func_021BA8D4 differs between members (src/matched/ov/ov099_func_021BAB04.c); prototype of func_020450F0 differs between members (src/matched/ov/ov099_func_021BAB04.c); prototype of func_
- ov099_func_021BAB04.c..func_021BAD50.c: prototype of func_020450F0 differs between members (src/matched/ov/ov099_func_021BAC24.c)
- ov099_func_021BAC24.c..func_021BAD50.c: c99=CCERR: line 111: illegal implicit conversion from 'int' to | line 111: 'char *' nolang=CCERR: line 111: illegal implicit conversion from 'int' to | line 111: 'char *'
- ov099_func_021BAD74.c..ov099_func_021BB918.c: prototype of func_021BDD48 differs between members (src/matched/ov/ov099_func_021BAEDC.c); prototype of func_020450F0 differs between members (src/matched/ov/ov099_func_021BB050.c); prototype of func_
- ov099_func_021BAD74.c..ov099_func_021BB2B0.c: prototype of func_021BDD48 differs between members (src/matched/ov/ov099_func_021BAEDC.c); prototype of func_020450F0 differs between members (src/matched/ov/ov099_func_021BB050.c); prototype of func_
- ov099_func_021BAD74.c..ov099_func_021BB050.c: prototype of func_021BDD48 differs between members (src/matched/ov/ov099_func_021BAEDC.c); prototype of func_020450F0 differs between members (src/matched/ov/ov099_func_021BB050.c); prototype of func_
- ov099_func_021BB2F0.c..ov099_func_021BB918.c: prototype of func_02009864 differs between members (src/matched/ov/ov099_func_021BB374.c); prototype of func_02009864 differs between members (src/matched/ov/ov099_func_021BB528.c); prototype of func_
- ov099_func_021BB2F0.c..ov099_func_021BB460.c: prototype of func_02009864 differs between members (src/matched/ov/ov099_func_021BB374.c)

Members, in address order:

- `func_021BA8D4.c`
- `ov099_func_021BA8EC.c`
- `ov099_func_021BAC24.c`
- `func_021BAD50.c`
- `ov099_func_021BAD74.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BA81C.c` again.
