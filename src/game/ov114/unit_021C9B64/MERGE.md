# unit_021C9B64.c (ov114)

Translation unit 021C9B64..021CA494, 10 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C9B64.c` is blocked by:

- ov114_func_021C9B64.c..ov114_func_021CA470.c: global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021C9D9C.c); type typedef callback differs between members (src/matched/ov_sdk/ov114_func_021C9EE4.c); prototype of func_02094860 dif
- ov114_func_021C9B64.c..ov114_func_021CA0A0.c: global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021C9D9C.c); prototype of func_02094860 differs between members (src/matched/ov_sdk/ov114_func_021C9EE4.c); global g_021CF7AC declare
- ov114_func_021C9B64.c..ov114_func_021C9D9C.c: global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021C9D9C.c)
- ov114_func_021C9EE4.c..ov114_func_021CA0A0.c: c99=CCERR: line 78: identifier 'Session' redeclared | line 78: was declared as: 'struct ' | line 78: now declared as: 'struct ' nolang=CCERR: line 78: identifier 'Session' redeclared | line 78: was de
- ov114_func_021CA188.c..ov114_func_021CA470.c: global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021CA1B4.c); global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021CA240.c)
- ov114_func_021CA188.c..ov114_func_021CA1B4.c: global g_021CF7AC declared two ways (src/matched/ov_sdk/ov114_func_021CA1B4.c)
- ov114_func_021CA228.c..ov114_func_021CA470.c: c99=CCERR: line 148: illegal implicit conversion from 'int (*)(unsigned int *, int)' to | line 148: 'int (*)(unsigned long *, int)' nolang=CCERR: line 148: illegal implicit conversion from 'int (*)(un
- ov114_func_021CA240.c..ov114_func_021CA470.c: c99=CCERR: line 134: illegal implicit conversion from 'int (*)(unsigned int *, int)' to | line 134: 'int (*)(unsigned long *, int)' nolang=CCERR: line 134: illegal implicit conversion from 'int (*)(un

Members, in address order:

- `ov114_func_021C9B64.c`
- `ov114_func_021C9D9C.c`
- `ov114_func_021C9EE4.c`
- `ov114_func_021CA188.c`
- `ov114_func_021CA1B4.c`
- `ov114_func_021CA228.c`
- `ov114_func_021CA240.c`
- `ov114_func_021CA470.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C9B64.c` again.
