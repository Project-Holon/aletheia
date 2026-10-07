# unit_02199394.c (ov009)

Translation unit 02199394..02199CE8, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02199394.c` is blocked by:

- ov009_func_02199394.c..ov009_func_02199BE4.c: global g_021AE698 declared two ways (src/matched/ov_sdk/ov009_func_021995E4.c); prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov009_func_0219972C.c); global g_021AE698 declare
- ov009_func_02199394.c..ov009_func_021995E4.c: global g_021AE698 declared two ways (src/matched/ov_sdk/ov009_func_021995E4.c)
- ov009_func_021994F0.c..ov009_func_021995E4.c: c99=CCERR: line 92: identifier 'NATNegotiator' redeclared | line 92: was declared as: 'struct _NATNegotiator' | line 92: now declared as: 'struct NATNegotiator' nolang=CCERR: line 92: identifier 'NATN
- ov009_func_0219972C.c..ov009_func_02199BE4.c: global g_021AE698 declared two ways (src/matched/ov_sdk/ov009_func_02199BE4.c)

Members, in address order:

- `ov009_func_02199394.c`
- `ov009_func_021994F0.c`
- `ov009_func_021995E4.c`
- `ov009_func_0219972C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02199394.c` again.
