# unit_02168454.c (ov009)

Translation unit 02168454..0216870C, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02168454.c` is blocked by:

- ov009_func_02168454.c..ov009_func_021686E0.c: c99=CCERR: line 28: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 28: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_021684CC.c..ov009_func_021686E0.c: c99=CCERR: line 24: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 24: the file '../arm9_sdk/libc/string.h' cannot be opened

Members, in address order:

- `ov009_func_021684CC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02168454.c` again.
