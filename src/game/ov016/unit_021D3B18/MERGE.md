# unit_021D3B18.c (ov016)

Translation unit 021D3B18..021D486C, 20 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D3B18.c` is blocked by:

- ov016_func_021D3B18.c..ov016_func_021D4854.c: global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D3BF8.c); global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D3CD0.c); global g_021DE668 declared two ways (src
- ov016_func_021D3B18.c..ov016_func_021D41F0.c: global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D3BF8.c); global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D3CD0.c); global g_021DE668 declared two ways (src
- ov016_func_021D3DC0.c..ov016_func_021D41F0.c: global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D4148.c); global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D41F0.c)
- ov016_func_021D4138.c..ov016_func_021D41F0.c: global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D41F0.c)
- ov016_func_021D4148.c..ov016_func_021D41F0.c: global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D41F0.c)
- ov016_func_021D4214.c..ov016_func_021D4854.c: global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D43C8.c); global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D45A4.c); global g_021DE668 declared two ways (src
- ov016_func_021D4214.c..func_021D4574.c: global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D43C8.c)
- ov016_func_021D45A4.c..ov016_func_021D4854.c: global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D45E0.c); global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D4624.c); global g_021DE668 declared two ways (src
- ov016_func_021D45A4.c..ov016_func_021D45E0.c: global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D45E0.c)
- ov016_func_021D4624.c..ov016_func_021D4854.c: global g_021DE668 declared two ways (src/matched/ov_sdk/ov016_func_021D4770.c)

Members, in address order:

- `ov016_func_021D4138.c`
- `ov016_func_021D4148.c`
- `ov016_func_021D41F0.c`
- `ov016_func_021D45A4.c`
- `ov016_func_021D45E0.c`
- `ov016_func_021D4624.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D3B18.c` again.
