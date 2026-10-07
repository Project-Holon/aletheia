# unit_0217956C.c (ov009)

Translation unit 0217956C..0217A880, 25 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217956C.c` is blocked by:

- ov009_func_0217956C.c..ov009_func_0217A808.c: prototype of func_0217A0D4 differs between members (src/matched/ov_sdk/ov009_func_02179DA0.c); prototype of func_02094B20 differs between members (src/matched/ov_sdk/ov009_func_02179E60.c); prototype 
- ov009_func_0217956C.c..ov009_func_02179E60.c: prototype of func_0217A0D4 differs between members (src/matched/ov_sdk/ov009_func_02179DA0.c); prototype of func_02094B20 differs between members (src/matched/ov_sdk/ov009_func_02179E60.c)
- ov009_func_021798E4.c..ov009_func_02179E60.c: prototype of func_02094B20 differs between members (src/matched/ov_sdk/ov009_func_02179E60.c)
- ov009_func_02179F3C.c..ov009_func_0217A808.c: type typedef DWCHttpParseResult differs between members (src/matched/ov_sdk/ov009_func_0217A484.c); prototype of func_02094B20 differs between members (src/matched/ov_sdk/ov009_func_0217A484.c)
- ov009_func_02179F3C.c..ov009_func_0217A15C.c: c99=CCERR: line 88: illegal implicit conversion from 'struct DWCHttp *' to | line 88: 'char *' | line 117: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 88: illegal implicit conve
- ov009_func_02179F3C.c..ov009_func_0217A0C8.c: prototype of func_0217A15C differs between members (src/matched/ov_sdk/ov009_func_0217A044.c)
- ov009_func_0217A1FC.c..ov009_func_0217A808.c: type typedef DWCHttpParseResult differs between members (src/matched/ov_sdk/ov009_func_0217A484.c); prototype of func_02094B20 differs between members (src/matched/ov_sdk/ov009_func_0217A484.c)
- ov009_func_0217A1FC.c..ov009_func_0217A484.c: prototype of func_02094B20 differs between members (src/matched/ov_sdk/ov009_func_0217A484.c)
- ov009_func_0217A344.c..ov009_func_0217A484.c: c99=CCERR: line 157: illegal implicit conversion from 'struct DWCHttp_0217A484 *' to | line 157: 'struct DWCHttp_0217A344 *' | line 185: illegal implicit conversion from 'struct DWCHttp_0217A484 *' to

Members, in address order:

- `ov009_func_02179F3C.c`
- `ov009_func_0217A1FC.c`
- `ov009_func_0217A344.c`
- `ov009_func_0217A484.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217956C.c` again.
