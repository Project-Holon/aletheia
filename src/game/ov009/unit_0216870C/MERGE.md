# unit_0216870C.c (ov009)

Translation unit 0216870C..0216A1F4, 37 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0216870C.c` is blocked by:

- ov009_func_0216870C.c..ov009_func_0216A020.c: global g_021AA860 declared two ways (src/matched/ov_sdk/ov009_func_021689BC.c); prototype of DWC_GetGsProfileId differs between members (src/matched/ov_sdk/ov009_func_02168FF0.c); prototype of DWCi_Ge
- ov009_func_0216870C.c..ov009_func_021690D0.c: global g_021AA860 declared two ways (src/matched/ov_sdk/ov009_func_021689BC.c); prototype of DWC_GetGsProfileId differs between members (src/matched/ov_sdk/ov009_func_02168FF0.c)
- ov009_func_0216870C.c..ov009_func_02168D7C.c: global g_021AA860 declared two ways (src/matched/ov_sdk/ov009_func_021689BC.c)
- ov009_func_0216870C.c..ov009_func_02168864.c: c99=CCERR: line 26: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 26: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_0216870C.c..ov009_func_02168724.c: c99=CCERR: line 24: the file '../arm9_sdk/libc/string.h' cannot be opened nolang=CCERR: line 24: the file '../arm9_sdk/libc/string.h' cannot be opened
- ov009_func_021688FC.c..ov009_func_02168D7C.c: global g_021AA860 declared two ways (src/matched/ov_sdk/ov009_func_021689BC.c)
- ov009_func_021689BC.c..ov009_func_02168D7C.c: global g_021AA860 declared two ways (src/matched/ov_sdk/ov009_func_02168D7C.c)
- ov009_func_02169174.c..ov009_func_0216A020.c: prototype of func_020591CC differs between members (src/matched/ov_sdk/ov009_func_021696B0.c); prototype of func_0205915C differs between members (src/matched/ov_sdk/ov009_func_021696B0.c); prototype 
- ov009_func_02169174.c..ov009_func_021696B0.c: prototype of func_020591CC differs between members (src/matched/ov_sdk/ov009_func_021696B0.c); prototype of func_0205915C differs between members (src/matched/ov_sdk/ov009_func_021696B0.c)
- ov009_func_02169174.c..ov009_func_02169294.c: c99=CCERR: line 63: illegal use of incomplete struct/union/class 'struct Work' | line 64: illegal use of incomplete struct/union/class 'struct Work' | line 65: illegal use of incomplete struct/union/c
- ov009_func_021692C4.c..ov009_func_021696B0.c: prototype of func_020591CC differs between members (src/matched/ov_sdk/ov009_func_021696B0.c); prototype of func_0205915C differs between members (src/matched/ov_sdk/ov009_func_021696B0.c)
- ov009_func_0216959C.c..ov009_func_021696B0.c: prototype of func_020591CC differs between members (src/matched/ov_sdk/ov009_func_021696B0.c); prototype of func_0205915C differs between members (src/matched/ov_sdk/ov009_func_021696B0.c)
- ov009_func_021695F0.c..ov009_func_021696B0.c: prototype of func_020591CC differs between members (src/matched/ov_sdk/ov009_func_021696B0.c); prototype of func_0205915C differs between members (src/matched/ov_sdk/ov009_func_021696B0.c)
- ov009_func_021697D8.c..ov009_func_0216A020.c: prototype of DWC_GetFriendDataType differs between members (src/matched/ov_sdk/ov009_func_02169BB0.c); prototype of DWC_IsBuddyFriendData differs between members (src/matched/ov_sdk/ov009_func_02169BB
- ov009_func_021697D8.c..ov009_func_02169BB0.c: prototype of DWC_GetFriendDataType differs between members (src/matched/ov_sdk/ov009_func_02169BB0.c); prototype of DWC_IsBuddyFriendData differs between members (src/matched/ov_sdk/ov009_func_02169BB
- ov009_func_021698C0.c..ov009_func_02169BB0.c: prototype of DWC_GetFriendDataType differs between members (src/matched/ov_sdk/ov009_func_02169BB0.c); prototype of DWC_IsBuddyFriendData differs between members (src/matched/ov_sdk/ov009_func_02169BB
- ov009_func_02169934.c..ov009_func_02169BB0.c: prototype of DWC_GetFriendDataType differs between members (src/matched/ov_sdk/ov009_func_02169BB0.c); prototype of DWC_IsBuddyFriendData differs between members (src/matched/ov_sdk/ov009_func_02169BB
- ov009_func_02169E18.c..ov009_func_0216A020.c: prototype of func_020591CC differs between members (src/matched/ov_sdk/ov009_func_0216A020.c); prototype of func_0205912C differs between members (src/matched/ov_sdk/ov009_func_0216A020.c)

Members, in address order:

- `ov009_func_0216870C.c`
- `ov009_func_02168724.c`
- `ov009_func_021689BC.c`
- `ov009_func_0216959C.c`
- `ov009_func_021695F0.c`
- `ov009_func_021696B0.c`
- `ov009_func_021698C0.c`
- `ov009_func_02169934.c`
- `ov009_func_02169BB0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0216870C.c` again.
