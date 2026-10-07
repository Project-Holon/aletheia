# unit_021DD2D4.c (ov175)

Translation unit 021DD2D4..021DD56C, 11 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021DD2D4.c` is blocked by:

- ov175_func_021DD2D4.c..ov175_func_021DD4D8.c: global g_021E4B88 declared two ways (src/matched/ov_sdk/ov175_func_021DD420.c); global g_021E4C08 declared two ways (src/matched/ov_sdk/ov175_func_021DD4D8.c)
- ov175_func_021DD2D4.c..ov175_func_021DD3A8.c: c99=CCERR: line 72: illegal implicit conversion from 'int' to | line 72: 'struct SAKEInternal *' | line 78: illegal implicit conversion from 'int' to nolang=CCERR: line 72: illegal implicit conversion
- ov175_func_021DD3D0.c..ov175_func_021DD4D8.c: global g_021E4B88 declared two ways (src/matched/ov_sdk/ov175_func_021DD420.c); global g_021E4C08 declared two ways (src/matched/ov_sdk/ov175_func_021DD4D8.c)
- ov175_func_021DD420.c..ov175_func_021DD4D8.c: global g_021E4C08 declared two ways (src/matched/ov_sdk/ov175_func_021DD4D8.c)
- ov175_func_021DD4B0.c..ov175_func_021DD4D8.c: global g_021E4C08 declared two ways (src/matched/ov_sdk/ov175_func_021DD4D8.c)
- no verified entry for 021DD560

Members, in address order:

- `ov175_func_021DD420.c`
- `ov175_func_021DD4B0.c`
- `ov175_func_021DD4D8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021DD2D4.c` again.
