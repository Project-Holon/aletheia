# scrcmd_proc.c (ov010)

Translation unit 0215B488..0215D34C, 84 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`scrcmd_proc.c` is blocked by:

- ov010_func_0215B488.c..ov010_func_0215D2A4.c: prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215BBD0.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215BD2C.c); prototype of func_
- ov010_func_0215B488.c..ov010_func_0215C5B0.c: prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215BBD0.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215BD2C.c); prototype of func_
- ov010_func_0215BBD0.c..ov010_func_0215C5B0.c: prototype of func_02159B10 differs between members (src/matched/ov/func_0215BCA0.c); prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215BCE8.c); prototype of func_02159B
- ov010_func_0215C0D0.c..ov010_func_0215C5B0.c: prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215C200.c); prototype of func_0202F190 differs between members (src/matched/ov/ov010_func_0215C40C.c)
- ov010_func_0215C0D0.c..ov010_func_0215C2D0.c: prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215C200.c)
- ov010_func_0215C180.c..ov010_func_0215C2D0.c: prototype of func_02159B10 differs between members (src/matched/ov/ov010_func_0215C200.c)
- func_0215C5EC.c..ov010_func_0215D2A4.c: prototype of func_0215897C differs between members (src/matched/ov/func_0215C610.c); prototype of func_020307B0 differs between members (src/matched/ov/func_0215C870.c); prototype of func_02188D50 dif
- func_0215C5EC.c..ov010_func_0215CD80.c: prototype of func_0215897C differs between members (src/matched/ov/func_0215C610.c); prototype of func_020307B0 differs between members (src/matched/ov/func_0215C870.c)
- func_0215C5EC.c..func_0215C870.c: prototype of func_0215897C differs between members (src/matched/ov/func_0215C610.c); prototype of func_020307B0 differs between members (src/matched/ov/func_0215C870.c)
- func_0215C5EC.c..func_0215C6F0.c: prototype of func_0215897C differs between members (src/matched/ov/func_0215C610.c)
- func_0215C5EC.c..func_0215C610.c: prototype of func_0215897C differs between members (src/matched/ov/func_0215C610.c)
- ov010_func_0215C700.c..func_0215C870.c: prototype of func_020307B0 differs between members (src/matched/ov/func_0215C870.c)
- ov010_func_0215C7C4.c..func_0215C870.c: prototype of func_020307B0 differs between members (src/matched/ov/func_0215C870.c)

Members, in address order:

- `ov010_func_0215C180.c`
- `func_0215C5EC.c`
- `func_0215C610.c`
- `ov010_func_0215C7C4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names scrcmd_proc.c` again.
