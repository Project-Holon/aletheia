# pms_input_view.c (ov110)

Translation unit 021B95A0..021BB224, 93 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`pms_input_view.c` is blocked by:

- ov110_func_021B95A0.c..ov110_func_021BB214.c: global d_021C1C88 declared two ways (src/matched/ov/ov110_func_021B99F0.c); prototype of func_02024810 differs between members (src/matched/ov/ov110_func_021B99F0.c); prototype of func_02030734 differ
- ov110_func_021B95A0.c..ov110_func_021BA8C4.c: global d_021C1C88 declared two ways (src/matched/ov/ov110_func_021B99F0.c); prototype of func_02024810 differs between members (src/matched/ov/ov110_func_021B99F0.c)
- ov110_func_021B95A0.c..ov110_func_021B9BEC.c: global d_021C1C88 declared two ways (src/matched/ov/ov110_func_021B99F0.c); prototype of func_02024810 differs between members (src/matched/ov/ov110_func_021B99F0.c)
- ov110_func_021B95A0.c..ov110_func_021B999C.c: c99=CCERR: line 86: illegal implicit conversion from 'char *' to | line 86: 'struct  *' nolang=CCERR: line 86: illegal implicit conversion from 'char *' to | line 86: 'struct  *'
- ov110_func_021B95A0.c..ov110_func_021B96C0.c: c99=CCERR: line 66: illegal implicit conversion from 'char *' to | line 66: 'struct  *' nolang=CCERR: line 66: illegal implicit conversion from 'char *' to | line 66: 'struct  *'
- ov110_func_021B99A4.c..ov110_func_021B9BEC.c: prototype of func_02024810 differs between members (src/matched/ov/ov110_func_021B99F0.c)
- ov110_func_021B99A4.c..ov110_func_021B9A48.c: prototype of func_02024810 differs between members (src/matched/ov/ov110_func_021B99F0.c)
- ov110_func_021BA958.c..ov110_func_021BB214.c: prototype of func_021BF784 differs between members (src/matched/ov/ov110_func_021BABAC.c); prototype of func_021BB6A0 differs between members (src/matched/ov/ov110_func_021BAE94.c); prototype of func_
- ov110_func_021BAC78.c..ov110_func_021BB214.c: prototype of func_02045B38 differs between members (src/matched/ov/ov110_func_021BAEDC.c); prototype of func_02045C04 differs between members (src/matched/ov/ov110_func_021BAF4C.c)
- ov110_func_021BAF7C.c..ov110_func_021BB214.c: c99=CCERR: line 135: illegal implicit conversion from 'unsigned char *' to | line 135: 'struct  *' nolang=CCERR: line 135: illegal implicit conversion from 'unsigned char *' to | line 135: 'struct  *'
- ov110_func_021BAF7C.c..ov110_func_021BB054.c: c99=CCERR: line 105: illegal implicit conversion from 'unsigned char *' to | line 105: 'struct  *' nolang=CCERR: line 105: illegal implicit conversion from 'unsigned char *' to | line 105: 'struct  *'
- ov110_func_021BAFE4.c..ov110_func_021BB054.c: c99=CCERR: line 88: illegal implicit conversion from 'unsigned char *' to | line 88: 'struct  *' nolang=CCERR: line 88: illegal implicit conversion from 'unsigned char *' to | line 88: 'struct  *'
- ov110_func_021BB00C.c..ov110_func_021BB054.c: c99=CCERR: line 82: illegal implicit conversion from 'unsigned char *' to | line 82: 'struct  *' nolang=CCERR: line 82: illegal implicit conversion from 'unsigned char *' to | line 82: 'struct  *'

Members, in address order:

- `ov110_func_021BAFE4.c`
- `ov110_func_021BB00C.c`
- `ov110_func_021BB054.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names pms_input_view.c` again.
