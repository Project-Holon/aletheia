# unit_021A0A24.c (ov009)

Translation unit 021A0A24..021A1928, 11 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021A0A24.c` is blocked by:

- ov009_func_021A0A24.c..ov009_func_021A1804.c: prototype of func_02184144 differs between members (src/matched/ov_sdk/ov009_func_021A0E30.c); prototype of func_0219F8B0 differs between members (src/matched/ov_sdk/ov009_func_021A0E30.c); prototype 
- ov009_func_021A0A24.c..ov009_func_021A1254.c: prototype of func_02184144 differs between members (src/matched/ov_sdk/ov009_func_021A0E30.c); prototype of func_0219F8B0 differs between members (src/matched/ov_sdk/ov009_func_021A0E30.c); prototype 
- ov009_func_021A0A24.c..ov009_func_021A0E30.c: prototype of func_02184144 differs between members (src/matched/ov_sdk/ov009_func_021A0E30.c); prototype of func_0219F8B0 differs between members (src/matched/ov_sdk/ov009_func_021A0E30.c)
- ov009_func_021A0F0C.c..ov009_func_021A1254.c: prototype of func_0219F6C8 differs between members (src/matched/ov_sdk/ov009_func_021A1254.c)
- ov009_func_021A10D4.c..ov009_func_021A1254.c: prototype of func_0219F6C8 differs between members (src/matched/ov_sdk/ov009_func_021A1254.c)
- ov009_func_021A12DC.c..ov009_func_021A1804.c: prototype of func_0219FAAC differs between members (src/matched/ov_sdk/ov009_func_021A153C.c); prototype of func_0219F6C8 differs between members (src/matched/ov_sdk/ov009_func_021A1804.c)
- ov009_func_021A12DC.c..ov009_func_021A153C.c: prototype of func_0219FAAC differs between members (src/matched/ov_sdk/ov009_func_021A153C.c)
- ov009_func_021A13D0.c..ov009_func_021A153C.c: c99=CCERR: line 147: illegal implicit conversion from 'struct SBL *' to | line 147: 'struct  *' nolang=CCERR: line 147: illegal implicit conversion from 'struct SBL *' to | line 147: 'struct  *'
- ov009_func_021A1620.c..ov009_func_021A1804.c: c99=CCERR: line 30: the file '../arm9_sdk/libc/string.h' cannot be opened | line 66: identifier 'SBServerList' redeclared | line 66: was declared as: 'struct ' nolang=CCERR: line 30: the file '../arm9
- ov009_func_021A174C.c..ov009_func_021A1804.c: c99=CCERR: line 28: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 28: the file '../arm9_sdk/libc/string.h' cannot be opened

Members, in address order:

- `ov009_func_021A0A24.c`
- `ov009_func_021A0E30.c`
- `ov009_func_021A0F0C.c`
- `ov009_func_021A10D4.c`
- `ov009_func_021A1254.c`
- `ov009_func_021A12DC.c`
- `ov009_func_021A13D0.c`
- `ov009_func_021A153C.c`
- `ov009_func_021A1620.c`
- `ov009_func_021A174C.c`
- `ov009_func_021A1804.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021A0A24.c` again.
