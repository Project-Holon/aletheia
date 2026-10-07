# unit_02193FF4.c (ov009)

Translation unit 02193FF4..02194AD8, 21 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02193FF4.c` is blocked by:

- ov009_func_02193FF4.c..ov009_func_02194A78.c: prototype of func_02184208 differs between members (src/matched/ov_sdk/ov009_func_0219451C.c); prototype of func_02184208 differs between members (src/matched/ov_sdk/ov009_func_021946F4.c); prototype 
- ov009_func_02193FF4.c..ov009_func_02194614.c: prototype of func_02184208 differs between members (src/matched/ov_sdk/ov009_func_0219451C.c)
- ov009_func_02194308.c..ov009_func_02194614.c: c99=CCERR: line 123: function call 'func_02194308(char *, int)' does not match | line 123: 'func_02194308(char *)' nolang=CCERR: line 123: function call 'func_02194308(char *, int)' does not match | l
- ov009_func_02194308.c..ov009_func_021943A4.c: c99=CCERR: line 88: function call 'func_02194308(char *, int)' does not match | line 88: 'func_02194308(char *)' nolang=CCERR: line 88: function call 'func_02194308(char *, int)' does not match | line
- ov009_func_021946F4.c..ov009_func_02194A78.c: prototype of func_021937D0 differs between members (src/matched/ov_sdk/ov009_func_021947C0.c); prototype of func_021937D0 differs between members (src/matched/ov_sdk/ov009_func_02194834.c)
- ov009_func_021946F4.c..ov009_func_02194834.c: prototype of func_021937D0 differs between members (src/matched/ov_sdk/ov009_func_021947C0.c); prototype of func_021937D0 differs between members (src/matched/ov_sdk/ov009_func_02194834.c)
- ov009_func_02194754.c..ov009_func_02194834.c: prototype of func_021937D0 differs between members (src/matched/ov_sdk/ov009_func_021947C0.c); prototype of func_021937D0 differs between members (src/matched/ov_sdk/ov009_func_02194834.c)

Members, in address order:

- `ov009_func_02194308.c`
- `ov009_func_021943A4.c`
- `ov009_func_02194754.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02193FF4.c` again.
