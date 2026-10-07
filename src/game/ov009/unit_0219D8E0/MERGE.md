# unit_0219D8E0.c (ov009)

Translation unit 0219D8E0..0219DC24, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0219D8E0.c` is blocked by:

- ov009_func_0219D8E0.c..ov009_func_0219DB90.c: prototype of func_0219D5C4 differs between members (src/matched/ov_sdk/ov009_func_0219D9D8.c); type struct _SBServerFIFO differs between members (src/matched/ov_sdk/ov009_func_0219DB90.c)
- ov009_func_0219D928.c..ov009_func_0219DB90.c: prototype of func_0219D5C4 differs between members (src/matched/ov_sdk/ov009_func_0219D9D8.c)
- ov009_func_0219D9D8.c..ov009_func_0219DB90.c: c99=CCERR: line 73: struct/union/enum/class tag '_SBServer' redefined | line 88: struct/union/enum/class tag '_SBServerFIFO' redefined | line 94: struct/union/enum/class tag '_SBQueryEngine' redefined

Members, in address order:

- `ov009_func_0219D928.c`
- `ov009_func_0219D9D8.c`
- `ov009_func_0219DB90.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0219D8E0.c` again.
