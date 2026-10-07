# unit_021BF520.c (ov114)

Translation unit 021BF520..021BFB90, 15 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BF520.c` is blocked by:

- ov114_func_021BF520.c..ov114_func_021BFB20.c: global g_021D3B20 declared two ways (src/matched/ov_sdk/ov114_func_021BF57C.c); global g_021D3B20 declared two ways (src/matched/ov_sdk/ov114_func_021BFA08.c); prototype of func_0205A1B0 differs betwe
- ov114_func_021BF6C4.c..ov114_func_021BFB20.c: prototype of func_0205A1B0 differs between members (src/matched/ov_sdk/ov114_func_021BFA70.c); type typedef Init differs between members (src/matched/ov_sdk/ov114_func_021BFB20.c)
- ov114_func_021BF6C4.c..ov114_func_021BF8C0.c: c99=CCERR: line 81: illegal implicit conversion from 'int' to | line 81: 'char *' nolang=CCERR: line 81: illegal implicit conversion from 'int' to | line 81: 'char *'
- ov114_func_021BF6C4.c..ov114_func_021BF6EC.c: c99=CCERR: line 68: illegal implicit conversion from 'int' to | line 68: 'char *' nolang=CCERR: line 68: illegal implicit conversion from 'int' to | line 68: 'char *'

Members, in address order:

- `ov114_func_021BF6C4.c`
- `ov114_func_021BF6EC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BF520.c` again.
