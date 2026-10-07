# unit_021F36C0.c (ov060)

Translation unit 021F36C0..021F39F4, 12 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F36C0.c` is blocked by:

- ov060_func_021F36C0.c..ov060_func_021F399C.c: prototype of func_021BE4B4 differs between members (src/matched/ov/ov060_func_021F3850.c); prototype of func_021BE480 differs between members (src/matched/ov/ov060_func_021F3880.c); prototype of func_
- ov060_func_021F36C0.c..ov060_func_021F37E4.c: c99=CCERR: line 157: identifier 'func_021897BC(char *, int)' redeclared as 'void * (void *, int)' | line 71: identifier 'func_021897BC(char *, int)' was originally declared as 'int * (char *, int)' no
- ov060_func_021F37B8.c..ov060_func_021F37E4.c: c99=CCERR: line 59: identifier 'func_021897BC(char *, int)' redeclared as 'void * (void *, int)' | line 36: identifier 'func_021897BC(char *, int)' was originally declared as 'int * (char *, int)' nol

Members, in address order:

- `ov060_func_021F37B8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F36C0.c` again.
