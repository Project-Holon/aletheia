# unit_021D657C.c (ov016)

Translation unit 021D657C..021D6C78, 12 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D657C.c` is blocked by:

- ov016_func_021D657C.c..ov016_func_021D6BC8.c: global g_021DE688 declared two ways (src/matched/ov_sdk/ov016_func_021D668C.c); global g_021DE688 declared two ways (src/matched/ov_sdk/ov016_func_021D6B64.c); global g_021DE688 declared two ways (src
- ov016_func_021D657C.c..func_021D68E4.c: global g_021DE688 declared two ways (src/matched/ov_sdk/ov016_func_021D668C.c)
- ov016_func_021D657C.c..func_021D6824.c: global g_021DE688 declared two ways (src/matched/ov_sdk/ov016_func_021D668C.c)
- func_021D696C.c..ov016_func_021D6BC8.c: global g_021DE688 declared two ways (src/matched/ov_sdk/ov016_func_021D6BC8.c)
- ov016_func_021D6B04.c..ov016_func_021D6BC8.c: global g_021DE688 declared two ways (src/matched/ov_sdk/ov016_func_021D6BC8.c)
- ov016_func_021D6B64.c..ov016_func_021D6BC8.c: global g_021DE688 declared two ways (src/matched/ov_sdk/ov016_func_021D6BC8.c)

Members, in address order:

- `ov016_func_021D657C.c`
- `ov016_func_021D6B04.c`
- `ov016_func_021D6B64.c`
- `ov016_func_021D6BC8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D657C.c` again.
