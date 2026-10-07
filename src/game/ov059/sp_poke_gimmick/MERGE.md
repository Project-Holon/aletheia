# sp_poke_gimmick.c (ov059)

Translation unit 021F36C0..021F3D9C, 17 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`sp_poke_gimmick.c` is blocked by:

- ov059_func_021F36C0.c..ov059_func_021F3CFC.c: prototype of func_021BE760 differs between members (src/matched/ov/ov059_func_021F3794.c); prototype of func_021BE674 differs between members (src/matched/ov/ov059_func_021F3794.c); prototype of func_
- ov059_func_021F36C0.c..ov059_func_021F3980.c: prototype of func_021BE760 differs between members (src/matched/ov/ov059_func_021F3794.c); prototype of func_021BE674 differs between members (src/matched/ov/ov059_func_021F3794.c); prototype of func_
- ov059_func_021F36C0.c..ov059_func_021F3794.c: prototype of func_021BE760 differs between members (src/matched/ov/ov059_func_021F3794.c); prototype of func_021BE674 differs between members (src/matched/ov/ov059_func_021F3794.c); prototype of func_
- ov059_func_021F3788.c..ov059_func_021F3794.c: c99=CCERR: line 47: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 32: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 47: ident
- ov059_func_021F3840.c..ov059_func_021F3980.c: c99=CCERR: line 74: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 42: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 74: ident
- ov059_func_021F3840.c..ov059_func_021F385C.c: c99=CCERR: line 38: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 21: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 38: ident
- ov059_func_021F39AC.c..ov059_func_021F3CFC.c: prototype of func_021BE674 differs between members (src/matched/ov/ov059_func_021F3CB8.c); prototype of func_021BE674 differs between members (src/matched/ov/ov059_func_021F3CFC.c)
- ov059_func_021F39AC.c..ov059_func_021F3B40.c: c99=CCERR: line 74: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 56: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 74: ident
- ov059_func_021F39AC.c..ov059_func_021F39B8.c: c99=CCERR: line 70: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 55: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 70: ident

Members, in address order:

- `ov059_func_021F3788.c`
- `ov059_func_021F3794.c`
- `ov059_func_021F3840.c`
- `ov059_func_021F385C.c`
- `ov059_func_021F39AC.c`
- `ov059_func_021F39B8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names sp_poke_gimmick.c` again.
