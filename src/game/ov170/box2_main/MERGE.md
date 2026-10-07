# box2_main.c (ov170)

Translation unit 021DC9E0..021E002C, 101 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`box2_main.c` is blocked by:

- ov170_func_021DC9E0.c..ov170_func_021DFA30.c: prototype of func_02031348 differs between members (src/matched/ov/func_021DF348.c); prototype of func_021EC08C differs between members (src/matched/ov/ov170_func_021DF43C.c)
- ov170_func_021DC9E0.c..ov170_func_021DE158.c: c99=CCERR: line 991: illegal implicit conversion from 'unsigned char *' to | line 991: 'void **' | line 1433: illegal implicit conversion from 'char *' to nolang=CCERR: line 991: illegal implicit conv
- func_021DD3DC.c..ov170_func_021DE158.c: prototype of func_021DD25C differs between members (src/matched/ov/ov170_func_021DD810.c)
- func_021DD3DC.c..func_021DD8A8.c: prototype of func_021DD25C differs between members (src/matched/ov/ov170_func_021DD810.c)
- ov170_func_021DD8D0.c..ov170_func_021DE158.c: c99=CCERR: line 476: illegal implicit conversion from 'char *' to | line 476: 'unsigned char *' | line 481: illegal implicit conversion from 'char *' to nolang=CCERR: line 476: illegal implicit conver
- ov170_func_021DDE20.c..ov170_func_021DE158.c: c99=CCERR: line 211: illegal implicit conversion from 'char *' to | line 211: 'unsigned char *' | line 216: illegal implicit conversion from 'char *' to nolang=CCERR: line 211: illegal implicit conver
- ov170_func_021DDFD4.c..ov170_func_021DE158.c: prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE158.c)
- func_021DE120.c..ov170_func_021DE158.c: prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE158.c)
- ov170_func_021DE428.c..ov170_func_021DFA30.c: prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE530.c); prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE5F8.c); prototype of func_
- ov170_func_021DE428.c..func_021DEDCC.c: prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE530.c); prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE5F8.c)
- ov170_func_021DE428.c..ov170_func_021DE980.c: prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE530.c); prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE5F8.c)
- ov170_func_021DE428.c..func_021DE720.c: prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE530.c); prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE5F8.c)
- ov170_func_021DE428.c..ov170_func_021DE5C8.c: prototype of func_021DDEFC differs between members (src/matched/ov/ov170_func_021DE530.c)
- ov170_func_021DEDD8.c..ov170_func_021DFA30.c: prototype of func_02031348 differs between members (src/matched/ov/func_021DF348.c)
- ov170_func_021DEDD8.c..ov170_func_021DF144.c: c99=CCERR: line 176: illegal implicit conversion from 'int' to | line 176: 'char *' nolang=CCERR: line 176: illegal implicit conversion from 'int' to | line 176: 'char *'
- func_021DF1BC.c..ov170_func_021DFA30.c: prototype of func_02031348 differs between members (src/matched/ov/func_021DF348.c)
- func_021DF348.c..ov170_func_021DFA30.c: prototype of func_02031348 differs between members (src/matched/ov/ov170_func_021DF38C.c)
- func_021DF348.c..ov170_func_021DF38C.c: prototype of func_02031348 differs between members (src/matched/ov/ov170_func_021DF38C.c)

Members, in address order:

- `func_021DE120.c`
- `ov170_func_021DE158.c`
- `ov170_func_021DE428.c`
- `func_021DF348.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names box2_main.c` again.
