# unit_0219AEB4.c (ov009)

Translation unit 0219AEB4..0219B7FC, 14 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0219AEB4.c` is blocked by:

- ov009_func_0219AEB4.c..ov009_func_0219B73C.c: global current_rec declared two ways (src/matched/ov_sdk/ov009_func_0219B170.c); global current_rec declared two ways (src/matched/ov_sdk/ov009_func_0219B1AC.c); global current_rec declared two ways (
- ov009_func_0219AEB4.c..ov009_func_0219B350.c: global current_rec declared two ways (src/matched/ov_sdk/ov009_func_0219B170.c); global current_rec declared two ways (src/matched/ov_sdk/ov009_func_0219B1AC.c); global current_rec declared two ways (
- ov009_func_0219AEB4.c..ov009_func_0219B170.c: global current_rec declared two ways (src/matched/ov_sdk/ov009_func_0219B170.c)
- ov009_func_0219B134.c..ov009_func_0219B170.c: global current_rec declared two ways (src/matched/ov_sdk/ov009_func_0219B170.c)
- ov009_func_0219B1AC.c..ov009_func_0219B350.c: global current_rec declared two ways (src/matched/ov_sdk/ov009_func_0219B1E8.c)
- ov009_func_0219B1AC.c..ov009_func_0219B1E8.c: global current_rec declared two ways (src/matched/ov_sdk/ov009_func_0219B1E8.c)
- ov009_func_0219B490.c..ov009_func_0219B73C.c: c99=CCERR: line 45: the file '../arm9_sdk/libc/string.h' cannot be opened | line 61: struct/union/enum/class tag 'qr2_implementation_s' redefined | line 90: struct/union/enum/class tag 'SOCHostEnt' re
- ov009_func_0219B490.c..ov009_func_0219B5EC.c: c99=CCERR: line 49: struct/union/enum/class tag 'qr2_implementation_s' redefined nolang=CCERR: line 49: struct/union/enum/class tag 'qr2_implementation_s' redefined
- ov009_func_0219B628.c..ov009_func_0219B73C.c: c99=CCERR: line 28: the file '../arm9_sdk/libc/string.h' cannot be opened | line 47: struct/union/enum/class tag 'SOCHostEnt' redefined nolang=CCERR: line 28: the file '../arm9_sdk/libc/string.h' cann
- ov009_func_0219B6CC.c..ov009_func_0219B73C.c: c99=CCERR: line 24: the file '../arm9_sdk/libc/string.h' cannot be opened | line 38: struct/union/enum/class tag 'SOCHostEnt' redefined nolang=CCERR: line 24: the file '../arm9_sdk/libc/string.h' cann

Members, in address order:

- `ov009_func_0219AEB4.c`
- `ov009_func_0219B134.c`
- `ov009_func_0219B170.c`
- `ov009_func_0219B1AC.c`
- `ov009_func_0219B1E8.c`
- `ov009_func_0219B490.c`
- `ov009_func_0219B6CC.c`
- `ov009_func_0219B73C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0219AEB4.c` again.
