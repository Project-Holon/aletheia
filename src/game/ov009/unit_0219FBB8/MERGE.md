# unit_0219FBB8.c (ov009)

Translation unit 0219FBB8..021A0A1C, 20 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0219FBB8.c` is blocked by:

- ov009_func_0219FBB8.c..ov009_func_021A08E8.c: global g_021A8230 declared two ways (src/matched/ov_sdk/ov009_func_0219FFD4.c); prototype of func_02184200 differs between members (src/matched/ov_sdk/ov009_func_021A060C.c)
- ov009_func_0219FBB8.c..ov009_func_021A0238.c: prototype of func_021A02E0 differs between members (src/matched/ov_sdk/ov009_func_0219FFD4.c); global g_021A8230 declared two ways (src/matched/ov_sdk/ov009_func_0219FFD4.c)
- ov009_func_0219FBB8.c..ov009_func_0219FDB8.c: c99=CCERR: line 30: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 30: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0219FBB8.c..ov009_func_0219FCF0.c: c99=CCERR: line 30: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 30: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0219FE10.c..ov009_func_021A0238.c: prototype of func_021A02E0 differs between members (src/matched/ov_sdk/ov009_func_0219FFD4.c)
- ov009_func_0219FF30.c..ov009_func_021A0238.c: prototype of func_021A02E0 differs between members (src/matched/ov_sdk/ov009_func_0219FFD4.c)
- ov009_func_0219FFD4.c..ov009_func_021A0238.c: c99=CCERR: line 30: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 30: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_021A027C.c..ov009_func_021A08E8.c: prototype of func_02184200 differs between members (src/matched/ov_sdk/ov009_func_021A060C.c)
- ov009_func_021A027C.c..ov009_func_021A0414.c: c99=CCERR: line 90: illegal implicit conversion from 'struct SBL_021A02E0 *' to | line 90: 'struct SBL_021A027C *' | line 98: illegal implicit conversion from 'struct SBL *' to nolang=CCERR: line 90: 
- ov009_func_021A027C.c..ov009_func_021A02E0.c: c99=CCERR: line 68: illegal implicit conversion from 'struct SBL_021A02E0 *' to | line 68: 'struct SBL_021A027C *' nolang=CCERR: line 68: illegal implicit conversion from 'struct SBL_021A02E0 *' to | 
- ov009_func_021A0440.c..ov009_func_021A08E8.c: prototype of func_02184200 differs between members (src/matched/ov_sdk/ov009_func_021A060C.c)
- ov009_func_021A0440.c..ov009_func_021A04C4.c: c99=CCERR: line 38: illegal implicit conversion from 'const char *' to | line 38: 'char *' | line 43: illegal implicit conversion from 'const char *' to nolang=CCERR: line 38: illegal implicit convers
- ov009_func_021A059C.c..ov009_func_021A08E8.c: c99=CCERR: line 35: the file '../arm9_sdk/libc/string.h' cannot be opened | line 224: illegal implicit conversion from 'struct SBServerList_021A08E8 *' to | line 224: 'struct SBServerList_021A060C *' 
- ov009_func_021A060C.c..ov009_func_021A08E8.c: c99=CCERR: line 36: the file '../arm9_sdk/libc/string.h' cannot be opened | line 201: illegal implicit conversion from 'struct SBServerList_021A08E8 *' to | line 201: 'struct SBServerList_021A060C *' 

Members, in address order:

- `ov009_func_0219FBB8.c`
- `ov009_func_0219FCF0.c`
- `ov009_func_0219FF30.c`
- `ov009_func_0219FFD4.c`
- `ov009_func_021A0238.c`
- `ov009_func_021A027C.c`
- `ov009_func_021A02E0.c`
- `ov009_func_021A0440.c`
- `ov009_func_021A04C4.c`
- `ov009_func_021A059C.c`
- `ov009_func_021A060C.c`
- `ov009_func_021A08E8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0219FBB8.c` again.
