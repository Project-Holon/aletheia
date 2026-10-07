# unit_021F36C0.c (ov064)

Translation unit 021F36C0..021F3BD8, 11 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F36C0.c` is blocked by:

- ov064_func_021F36C0.c..ov064_func_021F3BAC.c: c99=CCERR: line 173: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 88: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 173: ide
- ov064_func_021F36C0.c..ov064_func_021F384C.c: c99=CCERR: line 143: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 65: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 143: ide
- ov064_func_021F37AC.c..ov064_func_021F384C.c: c99=CCERR: line 81: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 57: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 81: ident

Members, in address order:

- `ov064_func_021F37AC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F36C0.c` again.
