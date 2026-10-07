# unit_021E0504.c (ov175)

Translation unit 021E0504..021E06DC, 3 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E0504.c` is blocked by:

- ov175_func_021E0504.c..ov175_func_021E05AC.c: c99=CCERR: line 22: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 22: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov175_func_021E054C.c..ov175_func_021E05AC.c: c99=CCERR: line 23: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 23: the file '../arm9_sdk/libc/string.h' cannot be opened

Members, in address order:

- `ov175_func_021E0504.c`
- `ov175_func_021E054C.c`
- `ov175_func_021E05AC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E0504.c` again.
