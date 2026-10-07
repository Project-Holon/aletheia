# unit_021F36C0.c (ov049)

Translation unit 021F36C0..021F3868, 5 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F36C0.c` is blocked by:

- ov049_func_021F36C0.c..ov049_func_021F3864.c: c99=CCERR: line 72: function call 'func_021F3864(void *, unsigned char *)' does not match | line 72: 'func_021F3864()' | line 78: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' nola
- ov049_func_021F3708.c..ov049_func_021F3864.c: c99=CCERR: line 58: identifier 'func_02188D2C(int *)' redeclared as 'void * (void *)' | line 46: identifier 'func_02188D2C(int *)' was originally declared as 'int (int *)' nolang=CCERR: line 58: ident

Members, in address order:

- `ov049_func_021F3708.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F36C0.c` again.
