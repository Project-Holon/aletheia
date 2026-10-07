# unit_02194EC4.c (ov009)

Translation unit 02194EC4..02195590, 10 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02194EC4.c` is blocked by:

- ov009_func_02194EC4.c..ov009_func_021954F4.c: prototype of func_02197FDC differs between members (src/matched/ov_sdk/ov009_func_0219500C.c); prototype of func_02197FDC differs between members (src/matched/ov_sdk/ov009_func_021950B4.c); prototype 
- ov009_func_02194EC4.c..ov009_func_02195158.c: prototype of gti2CloseSocket differs between members (src/matched/ov_sdk/ov009_func_02195158.c)
- ov009_func_0219500C.c..ov009_func_02195158.c: c99=CCERR: line 38: struct/union/enum/class tag 'Conn' redefined | line 45: identifier 'Conn' redeclared | line 45: was declared as: 'struct Conn' nolang=CCERR: line 38: struct/union/enum/class tag 'C
- ov009_func_021951E8.c..ov009_func_021954F4.c: prototype of func_02197FDC differs between members (src/matched/ov_sdk/ov009_func_02195278.c); type typedef FilterCb differs between members (src/matched/ov_sdk/ov009_func_02195340.c); prototype of fu
- ov009_func_021951E8.c..ov009_func_02195278.c: c99=CCERR: line 35: struct/union/enum/class tag 'Conn' redefined | line 42: identifier 'Conn' redeclared | line 42: was declared as: 'struct Conn' nolang=CCERR: line 35: struct/union/enum/class tag 'C
- ov009_func_02195340.c..ov009_func_021954F4.c: prototype of func_02197FDC differs between members (src/matched/ov_sdk/ov009_func_02195408.c); prototype of func_02197FDC differs between members (src/matched/ov_sdk/ov009_func_021954F4.c)
- ov009_func_02195408.c..ov009_func_021954F4.c: prototype of func_02197FDC differs between members (src/matched/ov_sdk/ov009_func_021954F4.c)

Members, in address order:

- `ov009_func_0219500C.c`
- `ov009_func_021951E8.c`
- `ov009_func_02195278.c`
- `ov009_func_02195340.c`
- `ov009_func_02195408.c`
- `ov009_func_021954F4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02194EC4.c` again.
