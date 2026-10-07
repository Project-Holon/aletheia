# unit_021CEF20.c (ov016)

Translation unit 021CEF20..021CF3B0, 8 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021CEF20.c` is blocked by:

- ov016_func_021CEF20.c..ov016_func_021CF1D4.c: global g_021DE640 declared two ways (src/matched/ov_sdk/ov016_func_021CEF50.c); global g_021DE640 declared two ways (src/matched/ov_sdk/ov016_func_021CEF84.c); global g_021DE640 declared two ways (src
- ov016_func_021CEF20.c..ov016_func_021CF04C.c: global g_021DE640 declared two ways (src/matched/ov_sdk/ov016_func_021CEF50.c); global g_021DE640 declared two ways (src/matched/ov_sdk/ov016_func_021CEF84.c); global g_021DE640 declared two ways (src
- ov016_func_021CEF84.c..ov016_func_021CF04C.c: global g_021DE640 declared two ways (src/matched/ov_sdk/ov016_func_021CF04C.c)
- ov016_func_021CF080.c..ov016_func_021CF1D4.c: global g_021DE640 declared two ways (src/matched/ov_sdk/ov016_func_021CF114.c); global g_021DE640 declared two ways (src/matched/ov_sdk/ov016_func_021CF174.c); global g_021DE640 declared two ways (src
- ov016_func_021CF174.c..ov016_func_021CF1D4.c: global g_021DE640 declared two ways (src/matched/ov_sdk/ov016_func_021CF1D4.c)

Members, in address order:

- `ov016_func_021CEF84.c`
- `ov016_func_021CF04C.c`
- `ov016_func_021CF174.c`
- `ov016_func_021CF1D4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021CEF20.c` again.
