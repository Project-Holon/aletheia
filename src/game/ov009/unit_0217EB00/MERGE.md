# unit_0217EB00.c (ov009)

Translation unit 0217EB00..0217F0B4, 22 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217EB00.c` is blocked by:

- ov009_func_0217EB00.c..ov009_func_0217F038.c: c99=CCERR: line 43: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 43: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0217EB00.c..ov009_func_0217ECA4.c: c99=CCERR: line 25: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 25: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0217EBB0.c..ov009_func_0217ECA4.c: c99=CCERR: line 23: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 23: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0217EC60.c..ov009_func_0217ECA4.c: c99=CCERR: line 21: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 21: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0217EC90.c..ov009_func_0217ECA4.c: c99=CCERR: line 19: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 19: the file '../arm9_sdk/libc/string.h' cannot be opened

Members, in address order:

- `ov009_func_0217EC60.c`
- `ov009_func_0217EC90.c`
- `ov009_func_0217ECA4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217EB00.c` again.
