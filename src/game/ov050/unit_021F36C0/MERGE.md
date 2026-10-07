# unit_021F36C0.c (ov050)

Translation unit 021F36C0..021F3894, 11 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F36C0.c` is blocked by:

- ov050_func_021F36C0.c..ov050_func_021F3890.c: prototype of func_02188D2C differs between members (src/matched/ov/ov050_func_021F37B8.c); prototype of func_021BE4B4 differs between members (src/matched/ov/ov050_func_021F37B8.c); prototype of func_
- ov050_func_021F36C0.c..ov050_func_021F3744.c: c99=CCERR: line 54: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 38: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 54: ident
- ov050_func_021F3708.c..ov050_func_021F3744.c: c99=CCERR: line 32: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 22: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 32: ident
- ov050_func_021F3758.c..ov050_func_021F3890.c: prototype of func_02188D2C differs between members (src/matched/ov/ov050_func_021F37B8.c); prototype of func_021BE4B4 differs between members (src/matched/ov/ov050_func_021F37B8.c); prototype of func_
- ov050_func_021F3758.c..ov050_func_021F37B8.c: prototype of func_02188D2C differs between members (src/matched/ov/ov050_func_021F37B8.c); prototype of func_021BE4B4 differs between members (src/matched/ov/ov050_func_021F37B8.c); prototype of func_
- ov050_func_021F3788.c..ov050_func_021F37B8.c: prototype of func_02188D2C differs between members (src/matched/ov/ov050_func_021F37B8.c); prototype of func_021BE4B4 differs between members (src/matched/ov/ov050_func_021F37B8.c); prototype of func_
- ov050_func_021F3808.c..ov050_func_021F3890.c: prototype of func_02188D2C differs between members (src/matched/ov/ov050_func_021F383C.c)

Members, in address order:

- `ov050_func_021F3708.c`
- `ov050_func_021F3758.c`
- `ov050_func_021F3788.c`
- `ov050_func_021F37B8.c`
- `ov050_func_021F3808.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F36C0.c` again.
