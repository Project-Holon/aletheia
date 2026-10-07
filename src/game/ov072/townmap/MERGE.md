# townmap.c (ov072)

Translation unit 021B95A0..021BBB48, 105 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`townmap.c` is blocked by:

- ov072_func_021B95A0.c..ov072_func_021BBB3C.c: global d_021BBB78 declared two ways (src/matched/ov/ov072_func_021BA5B0.c); prototype of func_0204B84C differs between members (src/matched/ov/ov072_func_021BA86C.c); prototype of func_0204B84C differ
- ov072_func_021B95A0.c..ov072_func_021BAE44.c: prototype of func_021BB220 differs between members (src/matched/ov/ov072_func_021B99E8.c); global d_021BBB78 declared two ways (src/matched/ov/ov072_func_021BA5B0.c); prototype of func_0204B84C differ
- ov072_func_021B95A0.c..ov072_func_021BA450.c: prototype of func_021BB220 differs between members (src/matched/ov/ov072_func_021B99E8.c)
- ov072_func_021B95A0.c..ov072_func_021B9E38.c: prototype of func_021BB220 differs between members (src/matched/ov/ov072_func_021B99E8.c)
- ov072_func_021B95A0.c..ov072_func_021B9944.c: c99=CCERR: line 261: illegal implicit conversion from 'char *' to | line 261: 'struct Callback *' nolang=CCERR: line 261: illegal implicit conversion from 'char *' to | line 261: 'struct Callback *'
- ov072_func_021BA488.c..ov072_func_021BAE44.c: c99=CCERR: line 318: illegal implicit conversion from 'char *' to | line 318: 'struct  *' | line 355: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 318: illegal implicit conversio
- ov072_func_021BA488.c..ov072_func_021BA7A4.c: c99=CCERR: line 212: illegal implicit conversion from 'struct  *' to | line 212: 'struct  *' | line 255: illegal implicit conversion from 'char *' to nolang=CCERR: line 212: illegal implicit conversio
- ov072_func_021BA638.c..ov072_func_021BA7A4.c: c99=CCERR: line 120: illegal implicit conversion from 'char *' to | line 120: 'struct  *' nolang=CCERR: line 120: illegal implicit conversion from 'char *' to | line 120: 'struct  *'
- ov072_func_021BA638.c..ov072_func_021BA6A8.c: c99=CCERR: line 84: illegal implicit conversion from 'char *' to | line 84: 'struct  *' nolang=CCERR: line 84: illegal implicit conversion from 'char *' to | line 84: 'struct  *'
- ov072_func_021BA7D4.c..ov072_func_021BAE44.c: prototype of func_021BA774 differs between members (src/matched/ov/ov072_func_021BAA90.c)
- ov072_func_021BAA90.c..ov072_func_021BAE44.c: prototype of func_021BA774 differs between members (src/matched/ov/ov072_func_021BACB0.c); prototype of func_021BA774 differs between members (src/matched/ov/ov072_func_021BAD84.c); prototype of func_
- ov072_func_021BAA90.c..ov072_func_021BAD10.c: prototype of func_021BA774 differs between members (src/matched/ov/ov072_func_021BACB0.c)
- ov072_func_021BAE9C.c..ov072_func_021BBB3C.c: prototype of func_0201C7A4 differs between members (src/matched/ov/ov072_func_021BB448.c); prototype of func_0204B84C differs between members (src/matched/ov/ov072_func_021BB4B4.c); global d_021BBC28 
- ov072_func_021BAE9C.c..ov072_func_021BB5E0.c: prototype of func_0201C7A4 differs between members (src/matched/ov/ov072_func_021BB448.c); prototype of func_0204B84C differs between members (src/matched/ov/ov072_func_021BB4B4.c)
- ov072_func_021BAE9C.c..ov072_func_021BB204.c: c99=CCERR: line 234: illegal implicit conversion from 'struct  *' to | line 234: 'struct  *' | line 277: illegal implicit conversion from 'unsigned int *' to nolang=CCERR: line 234: illegal implicit c
- ov072_func_021BB0B4.c..ov072_func_021BB204.c: c99=CCERR: line 127: illegal implicit conversion from 'unsigned int *' to | line 127: 'struct  *' nolang=CCERR: line 127: illegal implicit conversion from 'unsigned int *' to | line 127: 'struct  *'
- ov072_func_021BB220.c..ov072_func_021BB5E0.c: c99=CCERR: line 214: illegal implicit conversion from 'unsigned int *' to | line 214: 'struct  *' nolang=CCERR: line 214: illegal implicit conversion from 'unsigned int *' to | line 214: 'struct  *'
- ov072_func_021BB5EC.c..ov072_func_021BBB3C.c: global d_021BBC28 declared two ways (src/matched/ov/ov072_func_021BB820.c); global d_021BBC28 declared two ways (src/matched/ov/ov072_func_021BB968.c)
- ov072_func_021BB820.c..ov072_func_021BBB3C.c: c99=CCERR: line 75: struct/union/enum/class tag 'Ent' redefined | line 173: 'tmpl' is not a member of class 'struct Ent' nolang=CCERR: line 75: struct/union/enum/class tag 'Ent' redefined | line 173: 
- ov072_func_021BB820.c..ov072_func_021BBAFC.c: c99=CCERR: line 72: struct/union/enum/class tag 'Ent' redefined | line 160: 'tmpl' is not a member of class 'struct Ent' nolang=CCERR: line 72: struct/union/enum/class tag 'Ent' redefined | line 160: 
- ov072_func_021BB820.c..ov072_func_021BB9B0.c: c99=CCERR: line 50: struct/union/enum/class tag 'Ent' redefined | line 95: 'tmpl' is not a member of class 'struct Ent' nolang=CCERR: line 50: struct/union/enum/class tag 'Ent' redefined | line 95: 't

Members, in address order:

- `ov072_func_021BA638.c`
- `ov072_func_021BAA90.c`
- `ov072_func_021BB820.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names townmap.c` again.
