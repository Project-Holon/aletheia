# unit_0215F650.c (ov009)

Translation unit 0215F650..0215FC80, 14 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0215F650.c` is blocked by:

- ov009_func_0215F650.c..ov009_func_0215FBCC.c: type typedef alloc_0215F8FC differs between members (src/matched/ov_sdk/ov009_func_0215F8FC.c); global g_021AA4BC declared two ways (src/matched/ov_sdk/ov009_func_0215F8FC.c)
- ov009_func_0215F8D0.c..ov009_func_0215FBCC.c: type typedef alloc_0215F8FC differs between members (src/matched/ov_sdk/ov009_func_0215F8FC.c); global g_021AA4BC declared two ways (src/matched/ov_sdk/ov009_func_0215F8FC.c)
- ov009_func_0215F8D0.c..ov009_func_0215FA9C.c: type typedef alloc_0215F8FC differs between members (src/matched/ov_sdk/ov009_func_0215F8FC.c); global g_021AA4BC declared two ways (src/matched/ov_sdk/ov009_func_0215F8FC.c)
- ov009_func_0215F8FC.c..ov009_func_0215FA9C.c: type typedef alloc_0215F8FC differs between members (src/matched/ov_sdk/ov009_func_0215F8FC.c)
- no verified entry for 0215FA90

Members, in address order:

- `ov009_func_0215F8D0.c`
- `ov009_func_0215F8FC.c`
- `ov009_func_0215FA9C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0215F650.c` again.
