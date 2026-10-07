# unit_02183B60.c (ov020)

Translation unit 02183B60..02184C78, 28 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02183B60.c` is blocked by:

- ov020_func_02183B60.c..ov020_func_02184BF8.c: prototype of func_021BE92C differs between members (src/matched/ov/ov020_func_02183DE4.c); prototype of func_02082AC0 differs between members (src/matched/ov/ov020_func_02183F5C.c)
- ov020_func_02183B60.c..ov020_func_021841C0.c: prototype of func_021BE92C differs between members (src/matched/ov/ov020_func_02183DE4.c); prototype of func_02082AC0 differs between members (src/matched/ov/ov020_func_02183F5C.c)
- ov020_func_02183B60.c..ov020_func_02183D68.c: c99=CCERR: line 174: function call 'func_02183D68(int, int)' does not match | line 174: 'func_02183D68(int)' nolang=CCERR: line 174: function call 'func_02183D68(int, int)' does not match | line 174: 
- ov020_func_02183B60.c..ov020_func_02183B90.c: prototype of func_02183D68 differs between members (src/matched/ov/ov020_func_02183B90.c)
- ov020_func_02183B6C.c..ov020_func_02183B90.c: prototype of func_02183D68 differs between members (src/matched/ov/ov020_func_02183B90.c)

Members, in address order:

- `ov020_func_02183B60.c`
- `ov020_func_02183B6C.c`
- `ov020_func_02183B90.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02183B60.c` again.
