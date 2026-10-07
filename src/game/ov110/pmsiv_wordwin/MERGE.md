# pmsiv_wordwin.c (ov110)

Translation unit 021BEB78..021C025C, 81 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`pmsiv_wordwin.c` is blocked by:

- ov110_func_021BEB78.c..ov110_func_021C022C.c: prototype of func_021BD7A0 differs between members (src/matched/ov/ov110_func_021BF53C.c); prototype of func_021BD7A0 differs between members (src/matched/ov/ov110_func_021BF608.c); prototype of func_
- ov110_func_021BF758.c..ov110_func_021C022C.c: prototype of func_0204B404 differs between members (src/matched/ov/ov110_func_021BFDB0.c); prototype of func_0204B404 differs between members (src/matched/ov/ov110_func_021BFE24.c); prototype of func_
- ov110_func_021BF758.c..ov110_func_021BF9F0.c: c99=CCERR: line 222: illegal implicit conversion from 'unsigned char *' to | line 222: 'struct  *' nolang=CCERR: line 222: illegal implicit conversion from 'unsigned char *' to | line 222: 'struct  *'
- ov110_func_021BF7FC.c..ov110_func_021BF9F0.c: c99=CCERR: line 159: illegal implicit conversion from 'unsigned char *' to | line 159: 'struct  *' nolang=CCERR: line 159: illegal implicit conversion from 'unsigned char *' to | line 159: 'struct  *'
- ov110_func_021BF844.c..ov110_func_021BF9F0.c: c99=CCERR: line 122: illegal implicit conversion from 'unsigned char *' to | line 122: 'struct  *' nolang=CCERR: line 122: illegal implicit conversion from 'unsigned char *' to | line 122: 'struct  *'
- ov110_func_021BF8F4.c..ov110_func_021BF9F0.c: c99=CCERR: line 79: illegal implicit conversion from 'unsigned char *' to | line 79: 'struct  *' nolang=CCERR: line 79: illegal implicit conversion from 'unsigned char *' to | line 79: 'struct  *'
- ov110_func_021BFA40.c..ov110_func_021C022C.c: prototype of func_0204B404 differs between members (src/matched/ov/ov110_func_021BFDB0.c); prototype of func_0204B404 differs between members (src/matched/ov/ov110_func_021BFE24.c); prototype of func_
- ov110_func_021BFA40.c..ov110_func_021BFD94.c: c99=CCERR: line 173: identifier 'outside(@enum$2_try_pmsiv_wordwin_c, @enum$1_try_pmsiv_wordwin_c)' redeclared as 'void (int, int)' | line 132: identifier 'outside(@enum$2_try_pmsiv_wordwin_c, @enum$1
- ov110_func_021BFA40.c..ov110_func_021BFBA0.c: c99=CCERR: line 133: identifier 'outside(@enum$2_try_pmsiv_wordwin_c, @enum$1_try_pmsiv_wordwin_c)' redeclared as 'void (int, int)' | line 92: identifier 'outside(@enum$2_try_pmsiv_wordwin_c, @enum$1_
- ov110_func_021BFDB0.c..ov110_func_021C022C.c: prototype of func_0204B404 differs between members (src/matched/ov/ov110_func_021BFE24.c); prototype of func_0204B404 differs between members (src/matched/ov/ov110_func_021C00AC.c)
- ov110_func_021BFDB0.c..ov110_func_021BFF60.c: prototype of func_0204B404 differs between members (src/matched/ov/ov110_func_021BFE24.c)
- ov110_func_021BFDB0.c..ov110_func_021BFE24.c: prototype of func_0204B404 differs between members (src/matched/ov/ov110_func_021BFE24.c)

Members, in address order:

- `ov110_func_021BF8F4.c`
- `ov110_func_021BFDB0.c`
- `ov110_func_021BFE24.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names pmsiv_wordwin.c` again.
