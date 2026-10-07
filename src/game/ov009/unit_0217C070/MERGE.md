# unit_0217C070.c (ov009)

Translation unit 0217C070..0217C690, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217C070.c` is blocked by:

- ov009_func_0217C070.c..ov009_func_0217C448.c: global g_021ACEF4 declared two ways (src/matched/ov_sdk/ov009_func_0217C104.c); type typedef alloc_0217C144 differs between members (src/matched/ov_sdk/ov009_func_0217C144.c); prototype of func_02082B
- ov009_func_0217C070.c..ov009_func_0217C104.c: global g_021ACEF4 declared two ways (src/matched/ov_sdk/ov009_func_0217C104.c)
- ov009_func_0217C144.c..ov009_func_0217C448.c: type typedef alloc_0217C144 differs between members (src/matched/ov_sdk/ov009_func_0217C144.c); global g_021ACEF4 declared two ways (src/matched/ov_sdk/ov009_func_0217C384.c)
- ov009_func_0217C384.c..ov009_func_0217C448.c: global g_021ACEF4 declared two ways (src/matched/ov_sdk/ov009_func_0217C448.c)

Members, in address order:

- `ov009_func_0217C070.c`
- `ov009_func_0217C104.c`
- `ov009_func_0217C144.c`
- `ov009_func_0217C384.c`
- `ov009_func_0217C448.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217C070.c` again.
