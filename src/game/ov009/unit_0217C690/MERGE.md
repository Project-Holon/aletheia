# unit_0217C690.c (ov009)

Translation unit 0217C690..0217CA20, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217C690.c` is blocked by:

- ov009_func_0217C690.c..ov009_func_0217C900.c: global g_021ACF7C declared two ways (src/matched/ov_sdk/ov009_func_0217C750.c); global g_021ACF7C declared two ways (src/matched/ov_sdk/ov009_func_0217C848.c); global g_021ACF7C declared two ways (src
- ov009_func_0217C690.c..ov009_func_0217C704.c: c99=CCERR: line 27: struct/union/enum/class tag 'SOCSockAddrIn' redefined nolang=CCERR: line 27: struct/union/enum/class tag 'SOCSockAddrIn' redefined
- ov009_func_0217C750.c..ov009_func_0217C900.c: global g_021ACF7C declared two ways (src/matched/ov_sdk/ov009_func_0217C848.c); global g_021ACF7C declared two ways (src/matched/ov_sdk/ov009_func_0217C900.c)
- ov009_func_0217C848.c..ov009_func_0217C900.c: global g_021ACF7C declared two ways (src/matched/ov_sdk/ov009_func_0217C900.c)

Members, in address order:

- `ov009_func_0217C690.c`
- `ov009_func_0217C704.c`
- `ov009_func_0217C750.c`
- `ov009_func_0217C848.c`
- `ov009_func_0217C900.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217C690.c` again.
