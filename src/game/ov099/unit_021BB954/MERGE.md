# unit_021BB954.c (ov099)

Translation unit 021BB954..021BCF9C, 59 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BB954.c` is blocked by:

- ov099_func_021BB954.c..ov099_func_021BCF6C.c: prototype of func_021BAC24 differs between members (src/matched/ov/func_021BB9C8.c); prototype of func_021BAC24 differs between members (src/matched/ov/func_021BB9F4.c); prototype of func_021BAC24 dif
- ov099_func_021BB954.c..ov099_func_021BC544.c: prototype of func_021BAC24 differs between members (src/matched/ov/func_021BB9C8.c); prototype of func_021BAC24 differs between members (src/matched/ov/func_021BB9F4.c); prototype of func_021BAC24 dif
- ov099_func_021BB954.c..ov099_func_021BC06C.c: prototype of func_021BAC24 differs between members (src/matched/ov/func_021BB9C8.c); prototype of func_021BAC24 differs between members (src/matched/ov/func_021BB9F4.c); prototype of func_021BAC24 dif
- ov099_func_021BB954.c..ov099_func_021BBC34.c: prototype of func_021BAC24 differs between members (src/matched/ov/func_021BB9C8.c); prototype of func_021BAC24 differs between members (src/matched/ov/func_021BB9F4.c); prototype of func_021BAC24 dif
- ov099_func_021BB954.c..func_021BB9F4.c: prototype of func_021BAC24 differs between members (src/matched/ov/func_021BB9C8.c); prototype of func_021BAC24 differs between members (src/matched/ov/func_021BB9F4.c)
- ov099_func_021BBD0C.c..ov099_func_021BC06C.c: c99=CCERR: line 171: illegal implicit conversion from 'char *' to | line 171: 'struct  *' nolang=CCERR: line 171: illegal implicit conversion from 'char *' to | line 171: 'struct  *'
- func_021BC090.c..ov099_func_021BC544.c: prototype of func_0203D1E8 differs between members (src/matched/ov/ov099_func_021BC228.c); prototype of func_0203D378 differs between members (src/matched/ov/ov099_func_021BC228.c); prototype of func_
- func_021BC090.c..ov099_func_021BC228.c: prototype of func_0203D1E8 differs between members (src/matched/ov/ov099_func_021BC228.c); prototype of func_0203D378 differs between members (src/matched/ov/ov099_func_021BC228.c); prototype of func_
- ov099_func_021BC14C.c..ov099_func_021BC228.c: prototype of func_0203D1E8 differs between members (src/matched/ov/ov099_func_021BC228.c); prototype of func_0203D378 differs between members (src/matched/ov/ov099_func_021BC228.c); prototype of func_
- func_021BC29C.c..ov099_func_021BC544.c: prototype of func_021BA928 differs between members (src/matched/ov/func_021BC43C.c); prototype of func_021BA928 differs between members (src/matched/ov/func_021BC4A8.c); prototype of func_021BA858 dif
- func_021BC29C.c..ov099_func_021BC468.c: prototype of func_021BA928 differs between members (src/matched/ov/func_021BC43C.c)
- func_021BC4A8.c..ov099_func_021BC544.c: prototype of func_021BA928 differs between members (src/matched/ov/ov099_func_021BC51C.c)
- ov099_func_021BC5FC.c..ov099_func_021BCF6C.c: prototype of func_021BA928 differs between members (src/matched/ov/ov099_func_021BC6B0.c); prototype of func_0201C6C4 differs between members (src/matched/ov/ov099_func_021BC958.c); prototype of func_
- ov099_func_021BC5FC.c..ov099_func_021BCB70.c: prototype of func_021BA928 differs between members (src/matched/ov/ov099_func_021BC6B0.c); prototype of func_0201C6C4 differs between members (src/matched/ov/ov099_func_021BC958.c); prototype of func_
- ov099_func_021BC5FC.c..func_021BC850.c: prototype of func_021BA928 differs between members (src/matched/ov/ov099_func_021BC6B0.c)
- ov099_func_021BC6F4.c..func_021BC850.c: c99=DIFF nolang=DIFF
- ov099_func_021BCB8C.c..ov099_func_021BCF6C.c: global d_021C3A30 declared two ways (src/matched/ov/ov099_func_021BCC58.c); prototype of func_020362DC differs between members (src/matched/ov/ov099_func_021BCDB0.c); prototype of func_021BBEB4 differ
- ov099_func_021BCB8C.c..ov099_func_021BCCB8.c: global d_021C3A30 declared two ways (src/matched/ov/ov099_func_021BCC58.c)
- ov099_func_021BCBD8.c..ov099_func_021BCCB8.c: c99=CCERR: line 50: identifier 'func_021BCC4C(char *)' redeclared as 'void (void *)' | line 49: identifier 'func_021BCC4C(char *)' was originally declared as 'unsigned long (char *)' | line 95: identi
- ov099_func_021BCBD8.c..func_021BCC4C.c: c99=CCERR: line 38: identifier 'func_021BCC4C(char *)' redeclared as 'void (void *)' | line 37: identifier 'func_021BCC4C(char *)' was originally declared as 'unsigned long (char *)' | line 81: identi

Members, in address order:

- `ov099_func_021BB954.c`
- `ov099_func_021BCBD8.c`
- `func_021BCC4C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BB954.c` again.
