# unit_021C9858.c (ov114)

Translation unit 021C9858..021C9B60, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C9858.c` is blocked by:

- ov114_func_021C9858.c..ov114_func_021C99D0.c: global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021C98E0.c); global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021C99D0.c)
- ov114_func_021C98A4.c..ov114_func_021C99D0.c: global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021C98E0.c); global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021C99D0.c)
- ov114_func_021C98E0.c..ov114_func_021C99D0.c: global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021C99D0.c)

Members, in address order:

- `ov114_func_021C98A4.c`
- `ov114_func_021C98E0.c`
- `ov114_func_021C99D0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C9858.c` again.
