# unit_021C6000.c (ov111)

Translation unit 021C6000..021C75E4, 37 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C6000.c` is blocked by:

- ov111_func_021C6000.c..ov111_func_021C7504.c: prototype of func_0201EFA4 differs between members (src/matched/ov/ov111_func_021C6A84.c); prototype of func_0204A6C8 differs between members (src/matched/ov/ov111_func_021C7504.c); prototype of func_
- ov111_func_021C6000.c..ov111_func_021C6BD4.c: prototype of func_0201EFA4 differs between members (src/matched/ov/ov111_func_021C6A84.c)
- ov111_func_021C6000.c..ov111_func_021C63B8.c: c99=CCERR: line 308: illegal implicit conversion from 'struct  *' to | line 308: 'struct  *' | line 309: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 308: illegal implicit conver
- ov111_func_021C6000.c..ov111_func_021C61EC.c: c99=CCERR: line 224: illegal implicit conversion from 'struct  *' to | line 224: 'struct  *' nolang=CCERR: line 224: illegal implicit conversion from 'struct  *' to | line 224: 'struct  *'
- ov111_func_021C60CC.c..ov111_func_021C61EC.c: c99=CCERR: line 153: illegal implicit conversion from 'struct  *' to | line 153: 'struct  *' nolang=CCERR: line 153: illegal implicit conversion from 'struct  *' to | line 153: 'struct  *'
- ov111_func_021C628C.c..ov111_func_021C63B8.c: c99=CCERR: line 201: illegal implicit conversion from 'struct  *' to | line 201: 'struct  *' | line 205: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 201: illegal implicit conver
- ov111_func_021C636C.c..ov111_func_021C63B8.c: c99=CCERR: line 117: illegal implicit conversion from 'struct  *' to | line 117: 'struct  *' | line 121: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 117: illegal implicit conver
- ov111_func_021C6380.c..ov111_func_021C63B8.c: c99=CCERR: line 103: illegal implicit conversion from 'struct  *' to | line 103: 'struct  *' | line 107: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 103: illegal implicit conver
- ov111_func_021C67E8.c..ov111_func_021C6BD4.c: prototype of func_0201EFA4 differs between members (src/matched/ov/ov111_func_021C6A84.c)
- ov111_func_021C6954.c..ov111_func_021C6BD4.c: prototype of func_0201EFA4 differs between members (src/matched/ov/ov111_func_021C6A84.c)
- ov111_func_021C6C38.c..ov111_func_021C7504.c: prototype of func_0204A6C8 differs between members (src/matched/ov/ov111_func_021C7504.c); prototype of func_0204ABF0 differs between members (src/matched/ov/ov111_func_021C7504.c); prototype of func_
- ov111_func_021C7098.c..ov111_func_021C7504.c: c99=CCERR: line 675: illegal implicit conversion from 'struct  *' to | line 675: 'struct  *' | line 676: function call 'func_021C72C8(struct  *)' does not match nolang=CCERR: line 675: illegal implici
- ov111_func_021C7098.c..ov111_func_021C7208.c: c99=CCERR: line 334: illegal implicit conversion from 'struct  *' to | line 334: 'struct  *' | line 370: illegal implicit conversion from 'void (void *, struct  *)' to nolang=CCERR: line 334: illegal 

Members, in address order:

- `ov111_func_021C60CC.c`
- `ov111_func_021C61EC.c`
- `ov111_func_021C636C.c`
- `ov111_func_021C6380.c`
- `ov111_func_021C63B8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C6000.c` again.
