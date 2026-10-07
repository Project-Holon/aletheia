# unit_021F1B3C.c (ov107)

Translation unit 021F1B3C..021F2F1C, 18 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F1B3C.c` is blocked by:

- ov107_func_021F1B3C.c..ov107_func_021F2F04.c: global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F1D80.c); global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F2200.c); global g_021F6FA0 declared two ways (src
- ov107_func_021F1B3C.c..ov107_func_021F26C0.c: global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F1D80.c); global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F2200.c); global g_021F6FA0 declared two ways (src
- ov107_func_021F1D0C.c..ov107_func_021F26C0.c: global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F1D80.c); global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F2200.c); global g_021F6FA0 declared two ways (src
- ov107_func_021F1D80.c..ov107_func_021F26C0.c: global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F2200.c); global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F26C0.c)
- ov107_func_021F2200.c..ov107_func_021F26C0.c: global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F26C0.c)
- ov107_func_021F276C.c..ov107_func_021F2F04.c: prototype of func_021F6890 differs between members (src/matched/ov_sdk/ov107_func_021F27A8.c); prototype of func_021F3C80 differs between members (src/matched/ov_sdk/ov107_func_021F27A8.c); global mbc
- ov107_func_021F276C.c..ov107_func_021F2A44.c: prototype of func_021F6890 differs between members (src/matched/ov_sdk/ov107_func_021F27A8.c); prototype of func_021F3C80 differs between members (src/matched/ov_sdk/ov107_func_021F27A8.c); global mbc
- ov107_func_021F276C.c..ov107_func_021F27A8.c: prototype of func_021F6890 differs between members (src/matched/ov_sdk/ov107_func_021F27A8.c); prototype of func_021F3C80 differs between members (src/matched/ov_sdk/ov107_func_021F27A8.c)
- ov107_func_021F2CBC.c..ov107_func_021F2F04.c: global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F2E58.c)
- ov107_func_021F2CBC.c..ov107_func_021F2E58.c: global g_021F6FA0 declared two ways (src/matched/ov_sdk/ov107_func_021F2E58.c)

Members, in address order:

- `ov107_func_021F1D80.c`
- `ov107_func_021F2200.c`
- `ov107_func_021F26C0.c`
- `ov107_func_021F276C.c`
- `ov107_func_021F27A8.c`
- `ov107_func_021F2CBC.c`
- `ov107_func_021F2E58.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F1B3C.c` again.
