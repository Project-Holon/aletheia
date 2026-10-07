# fldeff_ripple.c (ov021)

Translation unit 021C3670..021C48A0, 60 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`fldeff_ripple.c` is blocked by:

- ov021_func_021C3670.c..ov021_func_021C484C.c: prototype of func_02005728 differs between members (src/matched/ov/func_021C4078.c); prototype of func_02034AC4 differs between members (src/matched/ov/ov021_func_021C474C.c); prototype of func_021F36
- ov021_func_021C3670.c..ov021_func_021C3E64.c: c99=CCERR: line 288: illegal implicit conversion from 'struct  *' to | line 288: 'unsigned int' | line 304: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 288: illegal implicit con
- ov021_func_021C3670.c..ov021_func_021C3ADC.c: c99=CCERR: line 271: illegal implicit conversion from 'struct  *' to | line 271: 'unsigned int' nolang=CCERR: line 271: illegal implicit conversion from 'struct  *' to | line 271: 'unsigned int'
- ov021_func_021C38F4.c..ov021_func_021C3ADC.c: c99=CCERR: line 107: illegal implicit conversion from 'struct  *' to | line 107: 'unsigned int' nolang=CCERR: line 107: illegal implicit conversion from 'struct  *' to | line 107: 'unsigned int'
- ov021_func_021C3F60.c..ov021_func_021C484C.c: prototype of func_02005728 differs between members (src/matched/ov/func_021C4078.c); prototype of func_02034AC4 differs between members (src/matched/ov/ov021_func_021C474C.c); prototype of func_021F36
- ov021_func_021C3F60.c..ov021_func_021C4504.c: prototype of func_02005728 differs between members (src/matched/ov/func_021C4078.c)
- ov021_func_021C3F60.c..ov021_func_021C4084.c: prototype of func_02005728 differs between members (src/matched/ov/func_021C4078.c)
- ov021_func_021C4024.c..ov021_func_021C4084.c: c99=CCERR: line 45: illegal use of type 'void' | line 59: illegal use of type 'void' nolang=CCERR: line 45: illegal use of type 'void' | line 59: illegal use of type 'void'
- ov021_func_021C452C.c..ov021_func_021C484C.c: prototype of func_02034AC4 differs between members (src/matched/ov/ov021_func_021C474C.c); prototype of func_021F36C0 differs between members (src/matched/ov/ov021_func_021C474C.c)
- ov021_func_021C46F8.c..ov021_func_021C484C.c: prototype of func_02034AC4 differs between members (src/matched/ov/ov021_func_021C474C.c); prototype of func_021F36C0 differs between members (src/matched/ov/ov021_func_021C474C.c)
- ov021_func_021C46F8.c..ov021_func_021C47B4.c: prototype of func_021F36C0 differs between members (src/matched/ov/ov021_func_021C474C.c)
- ov021_func_021C46F8.c..ov021_func_021C474C.c: prototype of func_021F36C0 differs between members (src/matched/ov/ov021_func_021C474C.c)

Members, in address order:

- `ov021_func_021C46F8.c`
- `ov021_func_021C474C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names fldeff_ripple.c` again.
