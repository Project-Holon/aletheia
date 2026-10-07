# unit_021DD25C.c (ov175)

Translation unit 021DD25C..021DD2CC, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DD25C.c` is blocked by:

- ov175_func_021DD25C.c..ov175_func_021DD290.c: c99=CCERR: line 18: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 18: the file '../arm9_sdk/libc/string.h' cannot be opened

Members, in address order:

- `ov175_func_021DD25C.c`
- `ov175_func_021DD290.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DD25C.c` again.
