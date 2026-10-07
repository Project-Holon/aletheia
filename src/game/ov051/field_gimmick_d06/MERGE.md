# field_gimmick_d06.c (ov051)

Translation unit 021F36C0..021F3D94, 21 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`field_gimmick_d06.c` is blocked by:

- ov051_func_021F36C0.c..ov051_func_021F3D6C.c: prototype of func_0200B3A4 differs between members (src/matched/ov/ov051_func_021F3868.c); prototype of func_02188C80 differs between members (src/matched/ov/ov051_func_021F3958.c); prototype of func_
- ov051_func_021F36C0.c..ov051_func_021F39F8.c: prototype of func_0200B3A4 differs between members (src/matched/ov/ov051_func_021F3868.c); prototype of func_02188C80 differs between members (src/matched/ov/ov051_func_021F3958.c)
- ov051_func_021F36C0.c..ov051_func_021F3718.c: c99=CCERR: line 40: identifier 'func_021F36C0(int)' redeclared as 'void * (int)' | line 35: identifier 'func_021F36C0(int)' was originally declared as 'const struct  * (int)' | line 47: identifier 'fu
- ov051_func_021F36C0.c..ov051_func_021F36E0.c: c99=CCERR: line 33: identifier 'func_021F36C0(int)' redeclared as 'void * (int)' | line 28: identifier 'func_021F36C0(int)' was originally declared as 'const struct  * (int)' | line 40: identifier 'fu
- ov051_func_021F36F8.c..ov051_func_021F3718.c: c99=CCERR: line 33: identifier 'func_021F36F8(int)' redeclared as 'void * (int)' | line 28: identifier 'func_021F36F8(int)' was originally declared as 'const struct  * (int)' | line 40: identifier 'fu
- ov051_func_021F3730.c..ov051_func_021F39F8.c: prototype of func_0200B3A4 differs between members (src/matched/ov/ov051_func_021F3868.c); prototype of func_02188C80 differs between members (src/matched/ov/ov051_func_021F3958.c)
- ov051_func_021F3730.c..ov051_func_021F3868.c: prototype of func_0200B3A4 differs between members (src/matched/ov/ov051_func_021F3868.c)
- ov051_func_021F3AB4.c..ov051_func_021F3D6C.c: prototype of func_02188CD0 differs between members (src/matched/ov/ov051_func_021F3B88.c); prototype of func_021C9064 differs between members (src/matched/ov/ov051_func_021F3B88.c); prototype of func_
- ov051_func_021F3AB4.c..ov051_func_021F3C84.c: prototype of func_02188CD0 differs between members (src/matched/ov/ov051_func_021F3B88.c); prototype of func_021C9064 differs between members (src/matched/ov/ov051_func_021F3B88.c); prototype of func_

Members, in address order:

- `ov051_func_021F36C0.c`
- `ov051_func_021F36E0.c`
- `ov051_func_021F36F8.c`
- `ov051_func_021F3718.c`
- `ov051_func_021F3730.c`
- `ov051_func_021F3868.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names field_gimmick_d06.c` again.
