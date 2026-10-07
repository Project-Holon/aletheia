# unit_021BFB90.c (ov114)

Translation unit 021BFB90..021C0244, 11 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BFB90.c` is blocked by:

- ov114_func_021BFB90.c..ov114_func_021C011C.c: prototype of ghiAppendDataToBuffer differs between members (src/matched/ov_sdk/ov114_func_021C00C0.c)
- ov114_func_021BFB90.c..ov114_func_021BFCEC.c: c99=CCERR: line 110: illegal implicit conversion from 'unsigned int *' to | line 110: 'struct  *' | line 170: illegal implicit conversion from 'struct GHIBuffer_021BFCEC *' to nolang=CCERR: line 110: 
- ov114_func_021BFB90.c..ov114_func_021BFBD0.c: c99=CCERR: line 71: illegal implicit conversion from 'unsigned int *' to | line 71: 'struct  *' nolang=CCERR: line 71: illegal implicit conversion from 'unsigned int *' to | line 71: 'struct  *'
- ov114_func_021BFDEC.c..ov114_func_021C011C.c: prototype of func_021BFB90 differs between members (src/matched/ov_sdk/ov114_func_021C0004.c); prototype of ghiAppendDataToBuffer differs between members (src/matched/ov_sdk/ov114_func_021C00C0.c)
- ov114_func_021BFDEC.c..ov114_func_021C0004.c: prototype of func_021BFB90 differs between members (src/matched/ov_sdk/ov114_func_021C0004.c)

Members, in address order:

- `ov114_func_021BFB90.c`
- `ov114_func_021BFBD0.c`
- `ov114_func_021BFDEC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BFB90.c` again.
