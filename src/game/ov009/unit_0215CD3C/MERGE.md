# unit_0215CD3C.c (ov009)

Translation unit 0215CD3C..0215D070, 13 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0215CD3C.c` is blocked by:

- ov009_func_0215CD3C.c..ov009_func_0215CFC0.c: global g_021AA480 declared two ways (src/matched/ov_sdk/ov009_func_0215CDD0.c); global g_021A1CD8 declared two ways (src/matched/ov_sdk/ov009_func_0215CDD0.c); global g_021AA484 declared two ways (src
- ov009_func_0215CD3C.c..ov009_func_0215CE9C.c: global g_021AA480 declared two ways (src/matched/ov_sdk/ov009_func_0215CDD0.c); global g_021A1CD8 declared two ways (src/matched/ov_sdk/ov009_func_0215CDD0.c); global g_021AA484 declared two ways (src
- ov009_func_0215CD3C.c..ov009_func_0215CE14.c: global g_021AA480 declared two ways (src/matched/ov_sdk/ov009_func_0215CDD0.c); global g_021A1CD8 declared two ways (src/matched/ov_sdk/ov009_func_0215CDD0.c)
- ov009_func_0215CEB0.c..ov009_func_0215CFC0.c: prototype of func_02085E50 differs between members (src/matched/ov_sdk/ov009_func_0215CFC0.c); prototype of func_02085DBC differs between members (src/matched/ov_sdk/ov009_func_0215CFC0.c)
- ov009_func_0215CF88.c..ov009_func_0215CFC0.c: prototype of func_0215CF14 differs between members (src/matched/ov_sdk/ov009_func_0215CFA8.c)

Members, in address order:

- `ov009_func_0215CD3C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0215CD3C.c` again.
