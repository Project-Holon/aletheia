# unit_021C2CDC.c (ov172)

Translation unit 021C2CDC..021C4B9C, 10 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C2CDC.c` is blocked by:

- ov172_func_021C2CDC.c..ov172_func_021C3DF4.c: global g_021CADF0 declared two ways (src/matched/ov_sdk/ov172_func_021C3160.c); global g_021CADF0 declared two ways (src/matched/ov_sdk/ov172_func_021C3620.c); global g_021CADF0 declared two ways (src
- ov172_func_021C2E1C.c..ov172_func_021C3DF4.c: global g_021CADF0 declared two ways (src/matched/ov_sdk/ov172_func_021C3620.c); global g_021CADF0 declared two ways (src/matched/ov_sdk/ov172_func_021C3A28.c)
- ov172_func_021C3620.c..ov172_func_021C3DF4.c: global g_021CADF0 declared two ways (src/matched/ov_sdk/ov172_func_021C3A28.c)
- ov172_func_021C3A28.c..ov172_func_021C3DF4.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov172_func_021C3620.c`
- `ov172_func_021C3A28.c`
- `ov172_func_021C3DF4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C2CDC.c` again.
