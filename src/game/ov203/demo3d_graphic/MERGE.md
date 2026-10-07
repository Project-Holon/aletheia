# demo3d_graphic.c (ov203)

Translation unit 021BDDD8..021BE9A4, 44 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`demo3d_graphic.c` is blocked by:

- ov203_func_021BDDD8.c..ov203_func_021BE990.c: prototype of func_02082BCC differs between members (src/matched/ov/ov203_func_021BDFC0.c); global d_021BFC24 declared two ways (src/matched/ov/ov203_func_021BE02C.c); prototype of func_02082BCC differ
- ov203_func_021BDDD8.c..ov203_func_021BE12C.c: prototype of func_02082BCC differs between members (src/matched/ov/ov203_func_021BDFC0.c); global d_021BFC24 declared two ways (src/matched/ov/ov203_func_021BE02C.c); prototype of func_02082BCC differ
- ov203_func_021BDFC0.c..ov203_func_021BE12C.c: global d_021BFC24 declared two ways (src/matched/ov/ov203_func_021BE02C.c); prototype of func_02082BCC differs between members (src/matched/ov/ov203_func_021BE084.c); prototype of func_02082BCC differ
- ov203_func_021BDFC0.c..ov203_func_021BE084.c: global d_021BFC24 declared two ways (src/matched/ov/ov203_func_021BE02C.c); prototype of func_02082BCC differs between members (src/matched/ov/ov203_func_021BE084.c)
- ov203_func_021BDFC0.c..ov203_func_021BE02C.c: global d_021BFC24 declared two ways (src/matched/ov/ov203_func_021BE02C.c)
- ov203_func_021BE13C.c..ov203_func_021BE990.c: c99=CCERR: line 180: struct/union/enum/class tag 'Config' redefined | line 365: illegal implicit conversion from 'struct Context *' to | line 365: 'struct Context_021BE63C *' nolang=CCERR: line 180: s
- ov203_func_021BE13C.c..ov203_func_021BE79C.c: c99=CCERR: line 175: struct/union/enum/class tag 'Config' redefined | line 323: illegal implicit conversion from 'struct Context *' to | line 323: 'struct Context_021BE63C *' nolang=CCERR: line 175: s
- ov203_func_021BE538.c..ov203_func_021BE79C.c: c99=CCERR: line 84: struct/union/enum/class tag 'Config' redefined | line 176: 'hour' is not a member of class 'struct Config' nolang=CCERR: line 84: struct/union/enum/class tag 'Config' redefined | l
- ov203_func_021BE638.c..ov203_func_021BE79C.c: c99=CCERR: line 61: struct/union/enum/class tag 'Config' redefined | line 103: 'hour' is not a member of class 'struct Config' nolang=CCERR: line 61: struct/union/enum/class tag 'Config' redefined | l
- ov203_func_021BE63C.c..ov203_func_021BE79C.c: c99=CCERR: line 59: struct/union/enum/class tag 'Config' redefined nolang=CCERR: line 59: struct/union/enum/class tag 'Config' redefined

Members, in address order:

- `ov203_func_021BDFC0.c`
- `ov203_func_021BE02C.c`
- `ov203_func_021BE638.c`
- `ov203_func_021BE63C.c`
- `ov203_func_021BE79C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names demo3d_graphic.c` again.
