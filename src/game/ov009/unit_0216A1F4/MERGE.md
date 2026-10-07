# unit_0216A1F4.c (ov009)

Translation unit 0216A1F4..0216AB20, 16 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0216A1F4.c` is blocked by:

- ov009_func_0216A1F4.c..ov009_func_0216AAE0.c: global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A278.c); global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A2B0.c); global g_021AA874 declared two ways (src
- ov009_func_0216A1F4.c..ov009_func_0216A460.c: global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A278.c); global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A2B0.c); global g_021AA874 declared two ways (src
- ov009_func_0216A1F4.c..ov009_func_0216A39C.c: global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A278.c); global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A2B0.c); global g_021AA874 declared two ways (src
- ov009_func_0216A2B0.c..ov009_func_0216A39C.c: global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A39C.c)
- ov009_func_0216A4D4.c..ov009_func_0216AAE0.c: global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A68C.c); global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A6F4.c); global g_021AA874 declared two ways (src
- ov009_func_0216A4D4.c..ov009_func_0216A838.c: global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A68C.c); global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A6F4.c); global g_021AA874 declared two ways (src
- ov009_func_0216A4D4.c..ov009_func_0216A68C.c: global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A68C.c)
- ov009_func_0216A6F4.c..ov009_func_0216A838.c: global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216A838.c); prototype of func_020596C8 differs between members (src/matched/ov_sdk/ov009_func_0216A838.c)
- ov009_func_0216A8F4.c..ov009_func_0216AAE0.c: global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216AA70.c); global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216AA9C.c); global g_021AA874 declared two ways (src
- ov009_func_0216A8F4.c..ov009_func_0216AA70.c: global g_021AA874 declared two ways (src/matched/ov_sdk/ov009_func_0216AA70.c)

Members, in address order:

- `ov009_func_0216A2B0.c`
- `ov009_func_0216A39C.c`
- `ov009_func_0216A4D4.c`
- `ov009_func_0216A68C.c`
- `ov009_func_0216A6F4.c`
- `ov009_func_0216A838.c`
- `ov009_func_0216A8F4.c`
- `ov009_func_0216AA70.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0216A1F4.c` again.
