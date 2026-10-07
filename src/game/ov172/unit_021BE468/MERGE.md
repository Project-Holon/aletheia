# unit_021BE468.c (ov172)

Translation unit 021BE468..021C0370, 10 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BE468.c` is blocked by:

- ov172_func_021BE468.c..ov172_func_021BFFC4.c: global g_021C88F0 declared two ways (src/matched/ov_sdk/ov172_func_021BF0B0.c); global g_021C88F0 declared two ways (src/matched/ov_sdk/ov172_func_021BF610.c); global bcode2 declared two ways (src/mat
- ov172_func_021BE468.c..ov172_func_021BF15C.c: global g_021C88F0 declared two ways (src/matched/ov_sdk/ov172_func_021BF0B0.c)
- ov172_func_021BE468.c..ov172_func_021BE5C4.c: c99=DIFF nolang=DIFF
- ov172_func_021BF1E0.c..ov172_func_021BFFC4.c: global bcode2 declared two ways (src/matched/ov_sdk/ov172_func_021BFFC4.c)
- ov172_func_021BF690.c..ov172_func_021BFFC4.c: global bcode2 declared two ways (src/matched/ov_sdk/ov172_func_021BFFC4.c)
- ov172_func_021BFA68.c..ov172_func_021BFFC4.c: global bcode2 declared two ways (src/matched/ov_sdk/ov172_func_021BFFC4.c)

Members, in address order:

- `ov172_func_021BE468.c`
- `ov172_func_021BE5C4.c`
- `ov172_func_021BF690.c`
- `ov172_func_021BFA68.c`
- `ov172_func_021BFFC4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BE468.c` again.
