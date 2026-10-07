# unit_02176DEC.c (ov009)

Translation unit 02176DEC..02177EC8, 35 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02176DEC.c` is blocked by:

- ov009_func_02176DEC.c..ov009_func_02177E88.c: global g_021AB180 declared two ways (src/matched/ov_sdk/ov009_func_02177138.c); global g_021AB180 declared two ways (src/matched/ov_sdk/ov009_func_02177160.c); global g_021AB180 declared two ways (src
- ov009_func_02176DEC.c..ov009_func_021772F8.c: global g_021AB180 declared two ways (src/matched/ov_sdk/ov009_func_02177138.c); global g_021AB180 declared two ways (src/matched/ov_sdk/ov009_func_02177160.c); global g_021AB180 declared two ways (src
- ov009_func_02176DEC.c..ov009_func_02177138.c: global g_021AB180 declared two ways (src/matched/ov_sdk/ov009_func_02177138.c)
- ov009_func_02176DEC.c..ov009_func_02176EB0.c: c99=CCERR: line 112: illegal implicit conversion from 'int' to | line 112: 'void *' nolang=CCERR: line 112: illegal implicit conversion from 'int' to | line 112: 'void *'
- ov009_func_02176E90.c..ov009_func_02176EB0.c: c99=CCERR: line 75: illegal implicit conversion from 'int' to | line 75: 'void *' nolang=CCERR: line 75: illegal implicit conversion from 'int' to | line 75: 'void *'
- ov009_func_02176FD4.c..ov009_func_02177138.c: global g_021AB180 declared two ways (src/matched/ov_sdk/ov009_func_02177138.c)
- ov009_func_02177340.c..ov009_func_02177E88.c: prototype of OS_GetTick differs between members (src/matched/ov_sdk/ov009_func_02177748.c); prototype of gt2Send differs between members (src/matched/ov_sdk/ov009_func_02177848.c); prototype of DWCi_S
- ov009_func_021777C0.c..ov009_func_02177E88.c: prototype of gt2Send differs between members (src/matched/ov_sdk/ov009_func_02177848.c); prototype of DWCi_SetError differs between members (src/matched/ov_sdk/ov009_func_0217793C.c); prototype of DWC
- ov009_func_02177C1C.c..ov009_func_02177E88.c: prototype of DWCs_GetTransConnection differs between members (src/matched/ov_sdk/ov009_func_02177E88.c)
- ov009_func_02177DCC.c..ov009_func_02177E88.c: prototype of DWCs_GetTransConnection differs between members (src/matched/ov_sdk/ov009_func_02177E88.c)

Members, in address order:

- `ov009_func_02176E90.c`
- `ov009_func_02176EB0.c`
- `ov009_func_02177DCC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02176DEC.c` again.
