# unit_0217576C.c (ov009)

Translation unit 0217576C..02176978, 41 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217576C.c` is blocked by:

- ov009_func_0217576C.c..ov009_func_0217695C.c: prototype of func_020870D0 differs between members (src/matched/ov_sdk/ov009_func_02175F1C.c); prototype of DWCi_GetMatchCnt differs between members (src/matched/ov_sdk/ov009_func_02176870.c); prototy
- ov009_func_0217576C.c..ov009_func_02176164.c: prototype of func_02176344 differs between members (src/matched/ov_sdk/ov009_func_02175D10.c); prototype of func_020870D0 differs between members (src/matched/ov_sdk/ov009_func_02175F1C.c); prototype 
- ov009_func_0217576C.c..ov009_func_02175F3C.c: prototype of func_02176344 differs between members (src/matched/ov_sdk/ov009_func_02175D10.c); prototype of func_020870D0 differs between members (src/matched/ov_sdk/ov009_func_02175F1C.c)
- ov009_func_0217576C.c..ov009_func_02175C64.c: c99=CCERR: line 67: struct/union/enum/class tag 'DWCstNodeInfo' redefined nolang=CCERR: line 67: struct/union/enum/class tag 'DWCstNodeInfo' redefined
- ov009_func_0217576C.c..ov009_func_021758C4.c: c99=CCERR: line 58: struct/union/enum/class tag 'DWCstNodeInfo' redefined | line 73: struct/union/enum/class tag 'DWCstMatchControl' redefined nolang=CCERR: line 58: struct/union/enum/class tag 'DWCst
- ov009_func_02175D10.c..ov009_func_02175F3C.c: prototype of func_020870D0 differs between members (src/matched/ov_sdk/ov009_func_02175F1C.c)
- ov009_func_02175F4C.c..ov009_func_02176164.c: prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_0217604C.c); prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_021760FC.c)
- ov009_func_02175F4C.c..ov009_func_02175FE4.c: c99=CCERR: line 38: struct/union/enum/class tag 'NNThinkGlobal' redefined nolang=CCERR: line 38: struct/union/enum/class tag 'NNThinkGlobal' redefined
- ov009_func_02175F4C.c..ov009_func_02175F84.c: c99=CCERR: line 35: struct/union/enum/class tag 'NNThinkGlobal' redefined nolang=CCERR: line 35: struct/union/enum/class tag 'NNThinkGlobal' redefined
- ov009_func_0217601C.c..ov009_func_02176164.c: prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_0217604C.c); prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_021760FC.c)
- ov009_func_02176254.c..ov009_func_0217695C.c: prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_0217637C.c); prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_021763AC.c); prototype 
- ov009_func_02176254.c..ov009_func_02176554.c: prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_0217637C.c); prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_021763AC.c); prototype 
- ov009_func_02176254.c..ov009_func_021763AC.c: prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_0217637C.c); prototype of func_02175F3C differs between members (src/matched/ov_sdk/ov009_func_021763AC.c)
- ov009_func_02176358.c..ov009_func_021763AC.c: c99=CCERR: line 36: identifier 'func_02175F3C()' redeclared as 'int ()' | line 28: identifier 'func_02175F3C()' was originally declared as 'char * ()' nolang=CCERR: line 36: identifier 'func_02175F3C(

Members, in address order:

- `ov009_func_0217576C.c`
- `ov009_func_021758C4.c`
- `ov009_func_02175F4C.c`
- `ov009_func_02175F84.c`
- `ov009_func_02176358.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217576C.c` again.
