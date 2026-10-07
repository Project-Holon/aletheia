# unit_0219DC2C.c (ov009)

Translation unit 0219DC2C..0219DF30, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0219DC2C.c` is blocked by:

- ov009_func_0219DC2C.c..ov009_func_0219DF04.c: type struct _SBServerFIFO differs between members (src/matched/ov_sdk/ov009_func_0219DDB8.c); type struct _SBServerFIFO differs between members (src/matched/ov_sdk/ov009_func_0219DE48.c); prototype of
- ov009_func_0219DC2C.c..ov009_func_0219DE48.c: type struct _SBServerFIFO differs between members (src/matched/ov_sdk/ov009_func_0219DDB8.c); type struct _SBServerFIFO differs between members (src/matched/ov_sdk/ov009_func_0219DE48.c); prototype of
- ov009_func_0219DDB8.c..ov009_func_0219DE48.c: type struct _SBServerFIFO differs between members (src/matched/ov_sdk/ov009_func_0219DE48.c); prototype of FIFOGetFirst differs between members (src/matched/ov_sdk/ov009_func_0219DE48.c)

Members, in address order:

- `ov009_func_0219DC2C.c`
- `ov009_func_0219DDB8.c`
- `ov009_func_0219DE48.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0219DC2C.c` again.
