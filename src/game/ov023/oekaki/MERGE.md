# oekaki.c (ov023)

Translation unit 021841E0..02184D30, 24 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`oekaki.c` is blocked by:

- ov023_func_021841E0.c..ov023_func_02184C48.c: prototype of func_02082B0C differs between members (src/matched/ov/ov023_func_021844D8.c); global d_02186ACC declared two ways (src/matched/ov/ov023_func_02184C48.c)
- ov023_func_021841E0.c..ov023_func_0218456C.c: prototype of func_02082B0C differs between members (src/matched/ov/ov023_func_021844D8.c)
- ov023_func_02184454.c..ov023_func_0218456C.c: c99=DIFF nolang=DIFF
- ov023_func_021844D8.c..ov023_func_0218456C.c: c99=DIFF nolang=DIFF
- ov023_func_02184674.c..ov023_func_02184C48.c: global d_02186ACC declared two ways (src/matched/ov/ov023_func_02184C48.c)

Members, in address order:

- `ov023_func_021844D8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names oekaki.c` again.
