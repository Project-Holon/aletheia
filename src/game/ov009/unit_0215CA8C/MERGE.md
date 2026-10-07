# unit_0215CA8C.c (ov009)

Translation unit 0215CA8C..0215CD3C, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0215CA8C.c` is blocked by:

- ov009_func_0215CA8C.c..ov009_func_0215CD24.c: type typedef alloc_0215CB24 differs between members (src/matched/ov_sdk/ov009_func_0215CB24.c); global g_021AA440 declared two ways (src/matched/ov_sdk/ov009_func_0215CCA0.c)
- ov009_func_0215CA8C.c..ov009_func_0215CB24.c: type typedef alloc_0215CB24 differs between members (src/matched/ov_sdk/ov009_func_0215CB24.c)
- ov009_func_0215CAE4.c..ov009_func_0215CB24.c: type typedef alloc_0215CB24 differs between members (src/matched/ov_sdk/ov009_func_0215CB24.c)

Members, in address order:

- `ov009_func_0215CA8C.c`
- `ov009_func_0215CAE4.c`
- `ov009_func_0215CB24.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0215CA8C.c` again.
