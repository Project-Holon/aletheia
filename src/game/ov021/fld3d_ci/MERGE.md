# fld3d_ci.c (ov021)

Translation unit 021C1988..021C3670, 77 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`fld3d_ci.c` is blocked by:

- ov021_func_021C1988.c..ov021_func_021C360C.c: prototype of func_0204E720 differs between members (src/matched/ov/ov021_func_021C2B5C.c); prototype of func_0204E720 differs between members (src/matched/ov/ov021_func_021C2B98.c); prototype of func_
- ov021_func_021C1988.c..ov021_func_021C2B1C.c: c99=CCERR: line 583: illegal implicit conversion from 'unsigned int' to | line 583: 'unsigned char *' | line 835: illegal implicit conversion from 'int' to nolang=CCERR: line 583: illegal implicit con
- ov021_func_021C1988.c..ov021_func_021C1E7C.c: c99=CCERR: line 406: illegal implicit conversion from 'unsigned int' to | line 406: 'unsigned char *' nolang=CCERR: line 406: illegal implicit conversion from 'unsigned int' to | line 406: 'unsigned c
- ov021_func_021C1988.c..func_021C1AD0.c: c99=CCERR: line 191: illegal implicit conversion from 'unsigned int' to | line 191: 'unsigned char *' nolang=CCERR: line 191: illegal implicit conversion from 'unsigned int' to | line 191: 'unsigned c
- func_021C1A84.c..func_021C1AD0.c: c99=CCERR: line 83: illegal implicit conversion from 'unsigned int' to | line 83: 'unsigned char *' nolang=CCERR: line 83: illegal implicit conversion from 'unsigned int' to | line 83: 'unsigned char 
- ov021_func_021C21B4.c..ov021_func_021C2B1C.c: c99=CCERR: line 361: illegal implicit conversion from 'char *' to | line 361: 'struct  *' | line 598: illegal implicit conversion from 'struct Obj *' to nolang=CCERR: line 361: illegal implicit conver
- ov021_func_021C21B4.c..ov021_func_021C2734.c: c99=CCERR: line 251: illegal implicit conversion from 'char *' to | line 251: 'struct  *' nolang=CCERR: line 251: illegal implicit conversion from 'char *' to | line 251: 'struct  *'
- ov021_func_021C2B5C.c..ov021_func_021C360C.c: prototype of func_0204E720 differs between members (src/matched/ov/ov021_func_021C2B98.c); prototype of func_0204E720 differs between members (src/matched/ov/ov021_func_021C2CF4.c); prototype of func_
- ov021_func_021C2B5C.c..func_021C31FC.c: prototype of func_020124E8 differs between members (src/matched/ov/ov021_func_021C2D68.c)
- ov021_func_021C2B5C.c..ov021_func_021C2EDC.c: prototype of func_020124E8 differs between members (src/matched/ov/ov021_func_021C2D68.c)
- ov021_func_021C2CF4.c..ov021_func_021C2EDC.c: prototype of func_020124E8 differs between members (src/matched/ov/ov021_func_021C2D68.c)
- ov021_func_021C2CF4.c..ov021_func_021C2D68.c: prototype of func_020124E8 differs between members (src/matched/ov/ov021_func_021C2D68.c)
- ov021_func_021C3204.c..ov021_func_021C360C.c: prototype of func_0200BCB8 differs between members (src/matched/ov/func_021C340C.c); prototype of func_0200BC2C differs between members (src/matched/ov/ov021_func_021C3490.c); prototype of func_0200BC
- ov021_func_021C3204.c..ov021_func_021C33E0.c: c99=CCERR: line 119: function call 'func_021C3248()' does not match | line 119: 'func_021C3248(void *)' nolang=CCERR: line 119: function call 'func_021C3248()' does not match | line 119: 'func_021C324
- ov021_func_021C3204.c..ov021_func_021C32BC.c: c99=CCERR: line 78: function call 'func_021C3248()' does not match | line 78: 'func_021C3248(void *)' nolang=CCERR: line 78: function call 'func_021C3248()' does not match | line 78: 'func_021C3248(vo
- ov021_func_021C3204.c..func_021C3248.c: c99=CCERR: line 52: function call 'func_021C3248()' does not match | line 52: 'func_021C3248(void *)' nolang=CCERR: line 52: function call 'func_021C3248()' does not match | line 52: 'func_021C3248(vo
- func_021C3400.c..ov021_func_021C360C.c: prototype of func_0200BC2C differs between members (src/matched/ov/ov021_func_021C3490.c); prototype of func_0200BC2C differs between members (src/matched/ov/ov021_func_021C34C4.c); prototype of func_
- func_021C3400.c..func_021C34B4.c: prototype of func_0200BC2C differs between members (src/matched/ov/ov021_func_021C3490.c)
- ov021_func_021C341C.c..func_021C34B4.c: prototype of func_0200BC2C differs between members (src/matched/ov/ov021_func_021C3490.c)

Members, in address order:

- `ov021_func_021C2CF4.c`
- `ov021_func_021C2D68.c`
- `ov021_func_021C3204.c`
- `func_021C3248.c`
- `ov021_func_021C341C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names fld3d_ci.c` again.
