# unit_021E10CC.c (ov175)

Translation unit 021E10CC..021E2290, 26 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021E10CC.c` is blocked by:

- ov175_func_021E10CC.c..ov175_func_021E216C.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E11F0.c); global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E1340.c); global g_021E5334 declared two ways (src
- ov175_func_021E10CC.c..ov175_func_021E1830.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E11F0.c); global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E1340.c); global g_021E5334 declared two ways (src
- ov175_func_021E10CC.c..ov175_func_021E1434.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E11F0.c); global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E1340.c); global g_021E5334 declared two ways (src
- ov175_func_021E10CC.c..ov175_func_021E1340.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E11F0.c); global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E1340.c)
- ov175_func_021E13BC.c..ov175_func_021E1434.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E1434.c)
- ov175_func_021E1454.c..ov175_func_021E1830.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E1464.c); global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E1540.c); global g_021E5334 declared two ways (src
- ov175_func_021E1454.c..ov175_func_021E1540.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E1464.c); global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E1540.c)
- ov175_func_021E1618.c..ov175_func_021E1830.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E16F0.c); global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E1830.c)
- ov175_func_021E191C.c..ov175_func_021E216C.c: global g_021E47B0 declared two ways (src/matched/ov_sdk/ov175_func_021E1F18.c); global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E214C.c); global g_021E5334 declared two ways (src
- ov175_func_021E1F18.c..ov175_func_021E216C.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E216C.c)
- ov175_func_021E20D4.c..ov175_func_021E216C.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E216C.c)
- ov175_func_021E214C.c..ov175_func_021E216C.c: global g_021E5334 declared two ways (src/matched/ov_sdk/ov175_func_021E216C.c)

Members, in address order:

- `ov175_func_021E10CC.c`
- `ov175_func_021E13BC.c`
- `ov175_func_021E1454.c`
- `ov175_func_021E214C.c`
- `ov175_func_021E216C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021E10CC.c` again.
