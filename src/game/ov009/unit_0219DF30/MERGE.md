# unit_0219DF30.c (ov009)

Translation unit 0219DF30..0219E1EC, 11 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0219DF30.c` is blocked by:

- ov009_func_0219DF30.c..ov009_func_0219E1B8.c: prototype of gsifree differs between members (src/matched/ov_sdk/ov009_func_0219DFF8.c)
- ov009_func_0219DF30.c..ov009_func_0219DFC0.c: c99=CCERR: line 62: object 'KeyValHashKey()' redefined nolang=CCERR: line 62: object 'KeyValHashKey()' redefined
- ov009_func_0219DFF8.c..ov009_func_0219E1B8.c: c99=CCERR: line 34: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 34: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0219E0C0.c..ov009_func_0219E1B8.c: c99=CCERR: line 26: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 26: the file '../arm9_sdk/libc/string.h' cannot be opened

Members, in address order:

- `ov009_func_0219E0C0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0219DF30.c` again.
