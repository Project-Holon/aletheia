# scrcmd_musical.c (ov010)

Translation unit 0215D34C..0215EC54, 62 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`scrcmd_musical.c` is blocked by:

- ov010_func_0215D34C.c..ov010_func_0215EC2C.c: prototype of func_0201210C differs between members (src/matched/ov/ov010_func_0215D468.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215D468.c); prototype of func_
- ov010_func_0215D34C.c..ov010_func_0215E358.c: prototype of func_0201210C differs between members (src/matched/ov/ov010_func_0215D468.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215D468.c); prototype of func_
- ov010_func_0215D34C.c..ov010_func_0215DEF0.c: prototype of func_0201210C differs between members (src/matched/ov/ov010_func_0215D468.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215D468.c); prototype of func_
- ov010_func_0215D34C.c..ov010_func_0215DADC.c: prototype of func_0201210C differs between members (src/matched/ov/ov010_func_0215D468.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215D468.c); prototype of func_
- ov010_func_0215D34C.c..ov010_func_0215D504.c: prototype of func_0201210C differs between members (src/matched/ov/ov010_func_0215D468.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215D468.c); prototype of func_
- ov010_func_0215DF6C.c..ov010_func_0215E358.c: prototype of func_021CD688 differs between members (src/matched/ov/ov010_func_0215E010.c); prototype of func_021FC804 differs between members (src/matched/ov/ov010_func_0215E010.c); prototype of func_
- ov010_func_0215DF6C.c..ov010_func_0215E130.c: prototype of func_021CD688 differs between members (src/matched/ov/ov010_func_0215E010.c); prototype of func_021FC804 differs between members (src/matched/ov/ov010_func_0215E010.c); prototype of func_
- func_0215E068.c..ov010_func_0215E130.c: prototype of func_02156BAC differs between members (src/matched/ov/func_0215E0B0.c)
- func_0215E068.c..func_0215E0B0.c: prototype of func_02156BAC differs between members (src/matched/ov/func_0215E0B0.c)
- func_0215E184.c..ov010_func_0215E358.c: c99=CCERR: line 240: object 'func_0215E334(void *)' redefined nolang=CCERR: line 240: object 'func_0215E334(void *)' redefined

Members, in address order:

- `ov010_func_0215D34C.c`
- `func_0215E068.c`
- `func_0215E0B0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names scrcmd_musical.c` again.
