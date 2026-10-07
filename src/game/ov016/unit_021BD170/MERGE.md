# unit_021BD170.c (ov016)

Translation unit 021BD170..021BD3CC, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BD170.c` is blocked by:

- ov016_func_021BD170.c..ov016_func_021BD310.c: prototype of func_021C0EC8 differs between members (src/matched/ov_sdk/ov016_func_021BD310.c)
- ov016_func_021BD170.c..ov016_func_021BD214.c: c99=CCERR: line 28: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 28: the file '../arm9_sdk/libc/string.h' cannot be opened

Members, in address order:

- `ov016_func_021BD170.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BD170.c` again.
