# unit_021BBEC0.c (ov114)

Translation unit 021BBEC0..021BE648, 26 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BBEC0.c` is blocked by:

- ov114_func_021BBEC0.c..ov114_func_021BE4D4.c: prototype of func_021BEBE0 differs between members (src/matched/ov_sdk/ov114_func_021BC160.c); prototype of func_021BEF3C differs between members (src/matched/ov_sdk/ov114_func_021BC740.c); prototype 
- ov114_func_021BBEC0.c..ov114_func_021BC9F0.c: prototype of func_021BEBE0 differs between members (src/matched/ov_sdk/ov114_func_021BC160.c); prototype of func_021BEF3C differs between members (src/matched/ov_sdk/ov114_func_021BC740.c); prototype 
- ov114_func_021BBEC0.c..ov114_func_021BC2FC.c: prototype of func_021BEBE0 differs between members (src/matched/ov_sdk/ov114_func_021BC160.c)
- ov114_func_021BC098.c..ov114_func_021BC2FC.c: prototype of func_021BEBE0 differs between members (src/matched/ov_sdk/ov114_func_021BC160.c)
- ov114_func_021BC384.c..ov114_func_021BC9F0.c: prototype of func_021BEF3C differs between members (src/matched/ov_sdk/ov114_func_021BC740.c); prototype of func_021BEF48 differs between members (src/matched/ov_sdk/ov114_func_021BC924.c); prototype 
- ov114_func_021BC504.c..ov114_func_021BC9F0.c: prototype of func_021BEF48 differs between members (src/matched/ov_sdk/ov114_func_021BC924.c); prototype of func_021BEF3C differs between members (src/matched/ov_sdk/ov114_func_021BC9F0.c); prototype 
- ov114_func_021BC924.c..ov114_func_021BC9F0.c: prototype of func_021BEF48 differs between members (src/matched/ov_sdk/ov114_func_021BC9F0.c); prototype of func_021BC384 differs between members (src/matched/ov_sdk/ov114_func_021BC9F0.c)
- ov114_func_021BCB74.c..ov114_func_021BE4D4.c: type typedef ReqInfo differs between members (src/matched/ov_sdk/ov114_func_021BCF24.c); prototype of NHTTPi_GetThreadInfoP differs between members (src/matched/ov_sdk/ov114_func_021BCF24.c); prototyp
- ov114_func_021BCB74.c..ov114_func_021BD430.c: type typedef ReqInfo differs between members (src/matched/ov_sdk/ov114_func_021BCF24.c); prototype of NHTTPi_GetPostContentlength differs between members (src/matched/ov_sdk/ov114_func_021BCF24.c); pr
- ov114_func_021BCB74.c..ov114_func_021BD220.c: type typedef ReqList differs between members (src/matched/ov_sdk/ov114_func_021BCF24.c); prototype of NHTTPi_GetPostContentlength differs between members (src/matched/ov_sdk/ov114_func_021BCF24.c); pr
- ov114_func_021BD270.c..ov114_func_021BD430.c: prototype of func_021BEF58 differs between members (src/matched/ov_sdk/ov114_func_021BD3B8.c); prototype of func_021BEFD8 differs between members (src/matched/ov_sdk/ov114_func_021BD3B8.c); type typed
- ov114_func_021BD3B8.c..ov114_func_021BD430.c: type typedef ReqInfo differs between members (src/matched/ov_sdk/ov114_func_021BD430.c)
- ov114_func_021BD548.c..ov114_func_021BE4D4.c: prototype of func_021BEF3C differs between members (src/matched/ov_sdk/ov114_func_021BD6DC.c); prototype of func_021BA884 differs between members (src/matched/ov_sdk/ov114_func_021BD6DC.c); type typed
- ov114_func_021BD548.c..ov114_func_021BD7E8.c: prototype of func_021BEF3C differs between members (src/matched/ov_sdk/ov114_func_021BD6DC.c); prototype of func_021BA884 differs between members (src/matched/ov_sdk/ov114_func_021BD6DC.c); type typed
- ov114_func_021BD6DC.c..ov114_func_021BD7E8.c: type typedef ReqList differs between members (src/matched/ov_sdk/ov114_func_021BD7E8.c)
- ov114_func_021BDB68.c..ov114_func_021BE4D4.c: type typedef ReqInfo differs between members (src/matched/ov_sdk/ov114_func_021BDFF8.c); prototype of NHTTPi_GetThreadInfoP differs between members (src/matched/ov_sdk/ov114_func_021BDFF8.c); type typ
- ov114_func_021BDB68.c..ov114_func_021BDD34.c: c99=CCERR: line 42: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 42: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov114_func_021BDFF8.c..ov114_func_021BE4D4.c: type typedef ReqList differs between members (src/matched/ov_sdk/ov114_func_021BE4D4.c)

Members, in address order:

- `ov114_func_021BC098.c`
- `ov114_func_021BC924.c`
- `ov114_func_021BC9F0.c`
- `ov114_func_021BCB74.c`
- `ov114_func_021BD270.c`
- `ov114_func_021BD3B8.c`
- `ov114_func_021BD430.c`
- `ov114_func_021BD548.c`
- `ov114_func_021BD6DC.c`
- `ov114_func_021BD7E8.c`
- `ov114_func_021BDB68.c`
- `ov114_func_021BDD34.c`
- `ov114_func_021BDFF8.c`
- `ov114_func_021BE4D4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BBEC0.c` again.
