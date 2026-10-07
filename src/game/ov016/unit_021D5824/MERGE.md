# unit_021D5824.c (ov016)

Translation unit 021D5824..021D5FE8, 15 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D5824.c` is blocked by:

- ov016_func_021D5824.c..func_021D5FC4.c: global g_021DE680 declared two ways (src/matched/ov_sdk/ov016_func_021D5904.c); type typedef TextCanvas differs between members (src/matched/ov_sdk/ov016_func_021D5950.c); global g_021DE680 declared t
- ov016_func_021D5824.c..ov016_func_021D5C48.c: global g_021DE680 declared two ways (src/matched/ov_sdk/ov016_func_021D5904.c); global g_021DE680 declared two ways (src/matched/ov_sdk/ov016_func_021D5950.c); global g_021DE680 declared two ways (src
- func_021D5A2C.c..ov016_func_021D5C48.c: global g_021DE680 declared two ways (src/matched/ov_sdk/ov016_func_021D5BC0.c); global g_021DE680 declared two ways (src/matched/ov_sdk/ov016_func_021D5C48.c)
- ov016_func_021D5BC0.c..ov016_func_021D5C48.c: global g_021DE680 declared two ways (src/matched/ov_sdk/ov016_func_021D5C48.c)
- func_021D5CA8.c..func_021D5FC4.c: type typedef TextCanvas differs between members (src/matched/ov_sdk/ov016_func_021D5DB0.c); global g_021DE680 declared two ways (src/matched/ov_sdk/ov016_func_021D5DB0.c); type typedef TextCanvas diff
- func_021D5CA8.c..ov016_func_021D5DB0.c: type typedef TextCanvas differs between members (src/matched/ov_sdk/ov016_func_021D5DB0.c); global g_021DE680 declared two ways (src/matched/ov_sdk/ov016_func_021D5DB0.c)

Members, in address order:

- `ov016_func_021D5BC0.c`
- `ov016_func_021D5C48.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D5824.c` again.
