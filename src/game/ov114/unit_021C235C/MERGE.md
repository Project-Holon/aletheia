# unit_021C235C.c (ov114)

Translation unit 021C235C..021C245C, 2 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C235C.c` is blocked by:

- ov114_func_021C235C.c..ov114_func_021C23E4.c: c99=CCERR: line 21: the file '../arm9_sdk/libc/string.h' cannot be opened | line 82: illegal implicit conversion from 'void (struct Obj *)' to | line 82: 'void (*)(void *)' nolang=CCERR: line 21: the 

Members, in address order:

- `ov114_func_021C235C.c`
- `ov114_func_021C23E4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C235C.c` again.
