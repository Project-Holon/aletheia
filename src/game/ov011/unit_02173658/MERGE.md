# unit_02173658.c (ov011)

Translation unit 02173658..02173CB0, 23 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02173658.c` is blocked by:

- ov011_func_02173658.c..ov011_func_02173C6C.c: c99=CCERR: line 165: function call 'func_021736E0(int, int, int, char *, unsigned int)' does not match | line 165: 'func_021736E0(int, int, int, char *)' nolang=CCERR: line 165: function call 'func_02
- ov011_func_02173658.c..ov011_func_021738E4.c: c99=CCERR: line 122: function call 'func_021736E0(int, int, int, char *, unsigned int)' does not match | line 122: 'func_021736E0(int, int, int, char *)' nolang=CCERR: line 122: function call 'func_02
- ov011_func_02173658.c..ov011_func_02173728.c: c99=CCERR: line 80: function call 'func_021736E0(int, int, int, char *, unsigned int)' does not match | line 80: 'func_021736E0(int, int, int, char *)' nolang=CCERR: line 80: function call 'func_02173
- ov011_func_02173658.c..ov011_func_021736D8.c: c99=DIFF nolang=DIFF
- ov011_func_021736E0.c..ov011_func_02173728.c: c99=CCERR: line 56: function call 'func_021736E0(int, int, int, char *, unsigned int)' does not match | line 56: 'func_021736E0(int, int, int, char *)' nolang=CCERR: line 56: function call 'func_02173
- ov011_func_02173758.c..ov011_func_021738E4.c: c99=DIFF nolang=DIFF
- ov011_func_02173758.c..ov011_func_021737CC.c: c99=DIFF nolang=DIFF
- ov011_func_0217392C.c..ov011_func_02173C6C.c: c99=DIFF nolang=DIFF
- ov011_func_0217392C.c..ov011_func_02173AB4.c: c99=DIFF nolang=DIFF
- ov011_func_0217392C.c..ov011_func_021739E0.c: c99=DIFF nolang=DIFF
- ov011_func_02173984.c..ov011_func_021739E0.c: c99=DIFF nolang=DIFF
- ov011_func_02173AE0.c..ov011_func_02173C6C.c: c99=DIFF nolang=DIFF
- ov011_func_02173B9C.c..ov011_func_02173C6C.c: c99=DIFF nolang=DIFF
- ov011_func_02173C04.c..ov011_func_02173C6C.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov011_func_02173658.c`
- `ov011_func_021736D8.c`
- `ov011_func_021736E0.c`
- `ov011_func_02173758.c`
- `ov011_func_0217392C.c`
- `ov011_func_02173984.c`
- `ov011_func_021739E0.c`
- `ov011_func_02173B9C.c`
- `ov011_func_02173C04.c`
- `ov011_func_02173C6C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02173658.c` again.
