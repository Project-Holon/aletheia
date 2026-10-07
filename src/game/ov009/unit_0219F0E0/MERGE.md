# unit_0219F0E0.c (ov009)

Translation unit 0219F0E0..0219FB64, 21 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0219F0E0.c` is blocked by:

- ov009_func_0219F0E0.c..ov009_func_0219FAAC.c: global g_021A8230 declared two ways (src/matched/ov_sdk/ov009_func_0219F40C.c); global g_021A8230 declared two ways (src/matched/ov_sdk/ov009_func_0219F48C.c); prototype of func_0209ABF8 differs betwe
- ov009_func_0219F0E0.c..ov009_func_0219F738.c: global g_021A8230 declared two ways (src/matched/ov_sdk/ov009_func_0219F40C.c); global g_021A8230 declared two ways (src/matched/ov_sdk/ov009_func_0219F48C.c); prototype of func_0209ABF8 differs betwe
- ov009_func_0219F768.c..ov009_func_0219FAAC.c: prototype of func_02184208 differs between members (src/matched/ov_sdk/ov009_func_0219F7C4.c); prototype of func_0219DF64 differs between members (src/matched/ov_sdk/ov009_func_0219F9A8.c)
- ov009_func_0219F768.c..ov009_func_0219F830.c: prototype of func_02184208 differs between members (src/matched/ov_sdk/ov009_func_0219F7C4.c)
- ov009_func_0219F7C4.c..ov009_func_0219F830.c: prototype of func_02184208 differs between members (src/matched/ov_sdk/ov009_func_0219F830.c)
- ov009_func_0219F7D8.c..ov009_func_0219F830.c: c99=CCERR: line 60: illegal implicit conversion from 'struct SBL_0219F830 *' to | line 60: 'struct SBL_0219F7D8 *' nolang=CCERR: line 60: illegal implicit conversion from 'struct SBL_0219F830 *' to | 
- ov009_func_0219F888.c..ov009_func_0219FAAC.c: prototype of func_0219DF64 differs between members (src/matched/ov_sdk/ov009_func_0219F9A8.c)

Members, in address order:

- `ov009_func_0219F7C4.c`
- `ov009_func_0219F7D8.c`
- `ov009_func_0219F830.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0219F0E0.c` again.
