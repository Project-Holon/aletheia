# psel.c (ov223)

Translation unit 021B95A0..021BB450, 59 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`psel.c` is blocked by:

- ov223_func_021B95A0.c..ov223_func_021BB424.c: prototype of func_0204E720 differs between members (src/matched/ov/ov223_func_021B9674.c); prototype of func_0204E6F4 differs between members (src/matched/ov/ov223_func_021B9674.c); prototype of func_
- ov223_func_021B95A0.c..ov223_func_021BA878.c: prototype of func_0204E720 differs between members (src/matched/ov/ov223_func_021B9674.c); prototype of func_0204E6F4 differs between members (src/matched/ov/ov223_func_021B9674.c); prototype of func_
- ov223_func_021B95A0.c..ov223_func_021B99A0.c: prototype of func_0204E720 differs between members (src/matched/ov/ov223_func_021B9674.c); prototype of func_0204E6F4 differs between members (src/matched/ov/ov223_func_021B9674.c); prototype of func_
- ov223_func_021B9A6C.c..ov223_func_021BA878.c: global table declared two ways (src/matched/ov/ov223_func_021B9B80.c); prototype of func_021BC52C differs between members (src/matched/ov/ov223_func_021B9C58.c)
- ov223_func_021B9A6C.c..ov223_func_021B9C58.c: global table declared two ways (src/matched/ov/ov223_func_021B9B80.c); prototype of func_021BC52C differs between members (src/matched/ov/ov223_func_021B9C58.c)
- ov223_func_021B9B4C.c..ov223_func_021B9C58.c: global table declared two ways (src/matched/ov/ov223_func_021B9B80.c); prototype of func_021BC52C differs between members (src/matched/ov/ov223_func_021B9C58.c)
- ov223_func_021B9B4C.c..ov223_func_021B9B80.c: global table declared two ways (src/matched/ov/ov223_func_021B9B80.c)
- ov223_func_021B9C00.c..ov223_func_021B9C58.c: prototype of func_021BC52C differs between members (src/matched/ov/ov223_func_021B9C58.c)
- ov223_func_021BA8D0.c..ov223_func_021BB424.c: prototype of func_02041570 differs between members (src/matched/ov/ov223_func_021BAD68.c)
- ov223_func_021BA8D0.c..ov223_func_021BADFC.c: prototype of func_02041570 differs between members (src/matched/ov/ov223_func_021BAD68.c)
- ov223_func_021BA8D0.c..ov223_func_021BAB74.c: c99=CCERR: line 143: function call 'func_021BAA84(char *, int)' does not match | line 143: 'func_021BAA84(char *)' nolang=CCERR: line 143: function call 'func_021BAA84(char *, int)' does not match | l
- ov223_func_021BAA5C.c..ov223_func_021BAB74.c: c99=CCERR: line 63: function call 'func_021BAA84(char *, int)' does not match | line 63: 'func_021BAA84(char *)' nolang=CCERR: line 63: function call 'func_021BAA84(char *, int)' does not match | line
- ov223_func_021BAA5C.c..ov223_func_021BAA84.c: c99=CCERR: line 39: function call 'func_021BAA84(char *, int)' does not match | line 39: 'func_021BAA84(char *)' nolang=CCERR: line 39: function call 'func_021BAA84(char *, int)' does not match | line

Members, in address order:

- `ov223_func_021B9B4C.c`
- `ov223_func_021B9B80.c`
- `ov223_func_021B9C00.c`
- `ov223_func_021B9C58.c`
- `ov223_func_021BAA5C.c`
- `ov223_func_021BAA84.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names psel.c` again.
