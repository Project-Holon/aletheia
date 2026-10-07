# unit_0216AB20.c (ov009)

Translation unit 0216AB20..0216C858, 47 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0216AB20.c` is blocked by:

- ov009_func_0216AB20.c..ov009_func_0216C82C.c: type struct DWCstGlobal differs between members (src/matched/ov_sdk/ov009_func_0216AE88.c); type struct DWCstGlobal differs between members (src/matched/ov_sdk/ov009_func_0216B408.c); prototype of MI_
- ov009_func_0216AB20.c..ov009_func_0216BB54.c: type struct DWCstGlobal differs between members (src/matched/ov_sdk/ov009_func_0216AE88.c); type struct DWCstGlobal differs between members (src/matched/ov_sdk/ov009_func_0216B408.c); prototype of MI_
- ov009_func_0216AB20.c..ov009_func_0216B7E0.c: type struct DWCstGlobal differs between members (src/matched/ov_sdk/ov009_func_0216AE88.c); type struct DWCstGlobal differs between members (src/matched/ov_sdk/ov009_func_0216B408.c)
- ov009_func_0216AB20.c..ov009_func_0216B1E0.c: type struct DWCstGlobal differs between members (src/matched/ov_sdk/ov009_func_0216AE88.c)
- ov009_func_0216BB6C.c..ov009_func_0216C82C.c: global g_021AA8A0 declared two ways (src/matched/ov_sdk/ov009_func_0216BBCC.c); global g_021AA8A0 declared two ways (src/matched/ov_sdk/ov009_func_0216BBDC.c); global g_021AA8A0 declared two ways (src
- ov009_func_0216BB6C.c..ov009_func_0216BE00.c: global g_021AA8A0 declared two ways (src/matched/ov_sdk/ov009_func_0216BBCC.c); global g_021AA8A0 declared two ways (src/matched/ov_sdk/ov009_func_0216BBDC.c); global g_021AA8A0 declared two ways (src
- ov009_func_0216BB6C.c..ov009_func_0216BC2C.c: global g_021AA8A0 declared two ways (src/matched/ov_sdk/ov009_func_0216BBCC.c); global g_021AA8A0 declared two ways (src/matched/ov_sdk/ov009_func_0216BBDC.c)
- ov009_func_0216BEA4.c..ov009_func_0216C82C.c: global g_021AA878 declared two ways (src/matched/ov_sdk/ov009_func_0216C7A8.c)
- ov009_func_0216BEA4.c..ov009_func_0216C0C4.c: c99=CCERR: line 36: the file '../arm9_sdk/libc/string.h' cannot be opened | line 56: struct/union/enum/class tag 'DwcState' redefined | line 79: identifier 'DwcState' redeclared nolang=CCERR: line 36:
- ov009_func_0216BFB8.c..ov009_func_0216C0C4.c: c99=CCERR: line 30: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 30: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0216C08C.c..ov009_func_0216C0C4.c: c99=CCERR: line 27: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 27: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0216C230.c..ov009_func_0216C82C.c: global g_021AA878 declared two ways (src/matched/ov_sdk/ov009_func_0216C7A8.c)
- ov009_func_0216C230.c..ov009_func_0216C7A8.c: global g_021AA878 declared two ways (src/matched/ov_sdk/ov009_func_0216C7A8.c)
- ov009_func_0216C788.c..ov009_func_0216C7A8.c: c99=DIFF nolang=DIFF
- no verified entry for 0216C224, 0216C79C

Members, in address order:

- `ov009_func_0216BFB8.c`
- `ov009_func_0216C08C.c`
- `ov009_func_0216C0C4.c`
- `ov009_func_0216C230.c`
- `ov009_func_0216C788.c`
- `ov009_func_0216C7A8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0216AB20.c` again.
