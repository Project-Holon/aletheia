# unit_021D6F9C.c (ov016)

Translation unit 021D6F9C..021D7200, 3 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D6F9C.c` is blocked by:

- ov016_func_021D6F9C.c..ov016_func_021D71C0.c: global g_021DE6AC declared two ways (src/matched/ov_sdk/ov016_func_021D705C.c); global g_021DE6AC declared two ways (src/matched/ov_sdk/ov016_func_021D71C0.c)
- ov016_func_021D705C.c..ov016_func_021D71C0.c: global g_021DE6AC declared two ways (src/matched/ov_sdk/ov016_func_021D71C0.c)

Members, in address order:

- `ov016_func_021D6F9C.c`
- `ov016_func_021D705C.c`
- `ov016_func_021D71C0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D6F9C.c` again.
