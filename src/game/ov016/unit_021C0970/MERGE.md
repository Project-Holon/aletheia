# unit_021C0970.c (ov016)

Translation unit 021C0970..021C0F60, 15 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C0970.c` is blocked by:

- ov016_func_021C0970.c..ov016_func_021C0F20.c: global g_021DE56C declared two ways (src/matched/ov_sdk/ov016_func_021C0A2C.c)
- ov016_func_021C0970.c..func_021C0E50.c: global g_021DE56C declared two ways (src/matched/ov_sdk/ov016_func_021C0A2C.c)
- ov016_func_021C0970.c..ov016_func_021C0AA8.c: global g_021DE56C declared two ways (src/matched/ov_sdk/ov016_func_021C0A2C.c)
- ov016_func_021C0A2C.c..ov016_func_021C0AA8.c: global g_021DE56C declared two ways (src/matched/ov_sdk/ov016_func_021C0AA8.c)

Members, in address order:

- `ov016_func_021C0970.c`
- `ov016_func_021C0A2C.c`
- `ov016_func_021C0AA8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C0970.c` again.
