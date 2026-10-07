# field_g3dobj.c (ov021)

Translation unit 021C5FA8..021C6C70, 46 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`field_g3dobj.c` is blocked by:

- ov021_func_021C5FA8.c..ov021_func_021C6BB4.c: c99=CCERR: line 843: illegal implicit conversion from 'unsigned char *' to | line 843: 'struct  *' | line 849: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 843: illegal implicit 
- ov021_func_021C5FA8.c..ov021_func_021C6628.c: prototype of func_021C69B4 differs between members (src/matched/ov/ov021_func_021C6590.c)
- ov021_func_021C5FA8.c..ov021_func_021C622C.c: c99=DIFF nolang=DIFF
- ov021_func_021C6054.c..ov021_func_021C622C.c: c99=DIFF nolang=DIFF
- ov021_func_021C6054.c..ov021_func_021C60B8.c: c99=DIFF nolang=DIFF
- ov021_func_021C62F0.c..ov021_func_021C6628.c: prototype of func_021C69B4 differs between members (src/matched/ov/ov021_func_021C6590.c)
- func_021C6534.c..ov021_func_021C6628.c: c99=CCERR: line 109: illegal implicit conversion from 'unsigned int' to | line 109: 'struct  *' nolang=CCERR: line 109: illegal implicit conversion from 'unsigned int' to | line 109: 'struct  *'
- func_021C6534.c..func_021C6574.c: c99=CCERR: line 61: illegal implicit conversion from 'unsigned int' to | line 61: 'struct  *' nolang=CCERR: line 61: illegal implicit conversion from 'unsigned int' to | line 61: 'struct  *'
- ov021_func_021C6538.c..func_021C6574.c: c99=CCERR: line 54: illegal implicit conversion from 'unsigned int' to | line 54: 'struct  *' nolang=CCERR: line 54: illegal implicit conversion from 'unsigned int' to | line 54: 'struct  *'

Members, in address order:

- `ov021_func_021C6054.c`
- `func_021C6534.c`
- `ov021_func_021C6538.c`
- `func_021C6574.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names field_g3dobj.c` again.
