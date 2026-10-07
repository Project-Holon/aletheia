# unit_021E2290.c (ov175)

Translation unit 021E2290..021E26B8, 4 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E2290.c` is blocked by:

- ov175_func_021E2290.c..ov175_func_021E2510.c: global g_021E53BC declared two ways (src/matched/ov_sdk/ov175_func_021E2510.c)
- ov175_func_021E2354.c..ov175_func_021E2510.c: c99=CCERR: line 54: the file '../arm9_sdk/libc/string.h' cannot be opened | line 110: identifier 'WSIRequestData' redeclared | line 110: was declared as: 'struct ' nolang=CCERR: line 54: the file '../

Members, in address order:

- `ov175_func_021E2354.c`
- `ov175_func_021E2510.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E2290.c` again.
