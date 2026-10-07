# beacon_detail_gra.c (ov216)

Translation unit 021BBD80..021BDAD8, 75 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`beacon_detail_gra.c` is blocked by:

- ov216_func_021BBD80.c..ov216_func_021BDAA0.c: global d_021BDC28 declared two ways (src/matched/ov/ov216_func_021BCAB8.c); global d_021BDD8A declared two ways (src/matched/ov/ov216_func_021BD07C.c); prototype of func_02082BCC differs between membe
- ov216_func_021BBD80.c..ov216_func_021BCAF0.c: global d_021BDC28 declared two ways (src/matched/ov/ov216_func_021BCAB8.c)
- ov216_func_021BBD80.c..ov216_func_021BC43C.c: c99=CCERR: line 254: illegal implicit conversion from 'void *' to | line 254: 'int' nolang=CCERR: line 254: illegal implicit conversion from 'void *' to | line 254: 'int'
- ov216_func_021BC454.c..ov216_func_021BCAF0.c: global d_021BDC28 declared two ways (src/matched/ov/ov216_func_021BCAB8.c)
- ov216_func_021BC454.c..ov216_func_021BC70C.c: c99=CCERR: line 201: illegal implicit conversion from 'struct  *' to | line 201: 'struct  *' | line 224: illegal implicit conversion from 'struct Window *' to nolang=CCERR: line 201: illegal implicit 
- ov216_func_021BC650.c..ov216_func_021BC70C.c: prototype of func_021BC5C4 differs between members (src/matched/ov/ov216_func_021BC70C.c); prototype of func_021BC614 differs between members (src/matched/ov/ov216_func_021BC70C.c)
- ov216_func_021BC6D8.c..ov216_func_021BC70C.c: prototype of func_021BC5C4 differs between members (src/matched/ov/ov216_func_021BC70C.c)

Members, in address order:

- `ov216_func_021BC6D8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names beacon_detail_gra.c` again.
