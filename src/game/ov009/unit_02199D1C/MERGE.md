# unit_02199D1C.c (ov009)

Translation unit 02199D1C..0219AEB4, 13 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02199D1C.c` is blocked by:

- ov009_func_02199D1C.c..ov009_func_0219AB8C.c: global g_021AE698 declared two ways (src/matched/ov_sdk/ov009_func_0219A4A4.c); prototype of gsDebugFormat differs between members (src/matched/ov_sdk/ov009_func_0219A52C.c); prototype of func_021994F
- ov009_func_02199D1C.c..ov009_func_0219A054.c: c99=CCERR: line 109: struct/union/enum/class tag '_NATNegotiator' redefined | line 120: struct/union/enum/class tag '_NATNegotiator' redefined | line 140: identifier 'NATNegotiator' redeclared nolang=
- ov009_func_02199FB4.c..ov009_func_0219A054.c: c99=CCERR: line 71: struct/union/enum/class tag '_NATNegotiator' redefined nolang=CCERR: line 71: struct/union/enum/class tag '_NATNegotiator' redefined
- ov009_func_0219A4A4.c..ov009_func_0219AB8C.c: prototype of func_021994F0 differs between members (src/matched/ov_sdk/ov009_func_0219A7AC.c); prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov009_func_0219AB8C.c)
- ov009_func_0219A4A4.c..ov009_func_0219A620.c: c99=CCERR: line 110: identifier 'NATNegotiator' redeclared | line 110: was declared as: 'struct NATNegotiator' | line 110: now declared as: 'struct _NATNegotiator' nolang=CCERR: line 110: identifier '
- ov009_func_0219A52C.c..ov009_func_0219A620.c: c99=CCERR: line 96: identifier 'NATNegotiator' redeclared | line 96: was declared as: 'struct NATNegotiator' | line 96: now declared as: 'struct _NATNegotiator' nolang=CCERR: line 96: identifier 'NATN
- ov009_func_0219A7AC.c..ov009_func_0219AB8C.c: prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov009_func_0219AB8C.c)
- ov009_func_0219A7AC.c..ov009_func_0219A968.c: c99=CCERR: line 68: struct/union/enum/class tag '_NATNegotiator' redefined | line 79: identifier 'NATNegotiator' redeclared | line 79: was declared as: 'struct _NATNegotiator' nolang=CCERR: line 68: s
- ov009_func_0219AA08.c..ov009_func_0219AB8C.c: c99=CCERR: line 35: the file '../arm9_sdk/libc/string.h' cannot be opened | line 104: identifier 'NATNegotiator' redeclared | line 104: was declared as: 'struct NATNegotiator' nolang=CCERR: line 35: t

Members, in address order:

- `ov009_func_02199FB4.c`
- `ov009_func_0219A4A4.c`
- `ov009_func_0219A52C.c`
- `ov009_func_0219A620.c`
- `ov009_func_0219A7AC.c`
- `ov009_func_0219A968.c`
- `ov009_func_0219AA08.c`
- `ov009_func_0219AB8C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02199D1C.c` again.
