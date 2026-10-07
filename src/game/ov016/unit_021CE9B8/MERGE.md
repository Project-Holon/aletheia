# unit_021CE9B8.c (ov016)

Translation unit 021CE9B8..021CEF20, 11 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021CE9B8.c` is blocked by:

- func_021CE9B8.c..ov016_func_021CEEE8.c: global g_021DE63C declared two ways (src/matched/ov_sdk/ov016_func_021CEB54.c); global g_021DE63C declared two ways (src/matched/ov_sdk/ov016_func_021CEC24.c); global g_021DE63C declared two ways (src
- func_021CE9B8.c..ov016_func_021CEC24.c: global g_021DE63C declared two ways (src/matched/ov_sdk/ov016_func_021CEB54.c); global g_021DE63C declared two ways (src/matched/ov_sdk/ov016_func_021CEC24.c)
- ov016_func_021CE9E8.c..ov016_func_021CEC24.c: global g_021DE63C declared two ways (src/matched/ov_sdk/ov016_func_021CEB54.c); global g_021DE63C declared two ways (src/matched/ov_sdk/ov016_func_021CEC24.c)
- ov016_func_021CEC9C.c..ov016_func_021CEEE8.c: global g_021DE63C declared two ways (src/matched/ov_sdk/ov016_func_021CECC8.c); global g_021DE63C declared two ways (src/matched/ov_sdk/ov016_func_021CEE10.c); global g_021DE63C declared two ways (src
- ov016_func_021CEC9C.c..ov016_func_021CED30.c: global g_021DE63C declared two ways (src/matched/ov_sdk/ov016_func_021CECC8.c)
- ov016_func_021CEDC4.c..ov016_func_021CEEE8.c: global g_021DE63C declared two ways (src/matched/ov_sdk/ov016_func_021CEEE8.c)

Members, in address order:

- `ov016_func_021CE9E8.c`
- `ov016_func_021CEC9C.c`
- `ov016_func_021CEDC4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021CE9B8.c` again.
