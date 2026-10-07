# unit_021C2464.c (ov114)

Translation unit 021C2464..021C3A38, 18 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C2464.c` is blocked by:

- ov114_func_021C2464.c..ov114_func_021C3834.c: prototype of func_0217EAE0 differs between members (src/matched/ov_sdk/ov114_func_021C24B4.c); prototype of func_02184200 differs between members (src/matched/ov_sdk/ov114_func_021C26B8.c); prototype 
- ov114_func_021C2464.c..ov114_func_021C29AC.c: prototype of func_0217EAE0 differs between members (src/matched/ov_sdk/ov114_func_021C24B4.c); prototype of func_02184200 differs between members (src/matched/ov_sdk/ov114_func_021C26B8.c)
- ov114_func_021C2464.c..ov114_func_021C2584.c: prototype of func_0217EAE0 differs between members (src/matched/ov_sdk/ov114_func_021C24B4.c)
- ov114_func_021C25C8.c..ov114_func_021C29AC.c: prototype of func_02184200 differs between members (src/matched/ov_sdk/ov114_func_021C26B8.c)
- ov114_func_021C26B8.c..ov114_func_021C29AC.c: c99=CCERR: line 28: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 28: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov114_func_021C2A3C.c..ov114_func_021C3834.c: prototype of func_021BFCEC differs between members (src/matched/ov_sdk/ov114_func_021C2DB0.c); prototype of func_021C00FC differs between members (src/matched/ov_sdk/ov114_func_021C2DB0.c); prototype 
- ov114_func_021C2A3C.c..ov114_func_021C2C28.c: c99=CCERR: line 234: illegal implicit conversion from 'struct GHIPostState_021C2BB0 *' to | line 234: 'struct  *' nolang=CCERR: line 234: illegal implicit conversion from 'struct GHIPostState_021C2BB0
- ov114_func_021C2DB0.c..ov114_func_021C3834.c: prototype of func_021C07B8 differs between members (src/matched/ov_sdk/ov114_func_021C2F10.c); prototype of func_021C07B8 differs between members (src/matched/ov_sdk/ov114_func_021C304C.c); prototype 
- ov114_func_021C2DB0.c..ov114_func_021C2F10.c: prototype of func_021C07B8 differs between members (src/matched/ov_sdk/ov114_func_021C2F10.c)
- ov114_func_021C304C.c..ov114_func_021C3834.c: prototype of func_021C07B8 differs between members (src/matched/ov_sdk/ov114_func_021C3218.c); prototype of func_021C011C differs between members (src/matched/ov_sdk/ov114_func_021C3834.c); prototype 
- ov114_func_021C3218.c..ov114_func_021C3834.c: prototype of func_021C011C differs between members (src/matched/ov_sdk/ov114_func_021C3834.c); prototype of func_021C00FC differs between members (src/matched/ov_sdk/ov114_func_021C3834.c); prototype 

Members, in address order:

- `ov114_func_021C26B8.c`
- `ov114_func_021C2DB0.c`
- `ov114_func_021C2F10.c`
- `ov114_func_021C304C.c`
- `ov114_func_021C3218.c`
- `ov114_func_021C3834.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C2464.c` again.
