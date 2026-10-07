# unit_021C7768.c (ov016)

Translation unit 021C7768..021C7CA0, 9 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C7768.c` is blocked by:

- ov016_func_021C7768.c..ov016_func_021C7C74.c: global g_021DE5E4 declared two ways (src/matched/ov_sdk/ov016_func_021C77F4.c); global g_021DE5E4 declared two ways (src/matched/ov_sdk/ov016_func_021C78A0.c); global g_021DE5E4 declared two ways (src
- ov016_func_021C7768.c..ov016_func_021C7960.c: global g_021DE5E4 declared two ways (src/matched/ov_sdk/ov016_func_021C77F4.c); global g_021DE5E4 declared two ways (src/matched/ov_sdk/ov016_func_021C78A0.c); global g_021DE5E4 declared two ways (src
- ov016_func_021C78A0.c..ov016_func_021C7960.c: global g_021DE5E4 declared two ways (src/matched/ov_sdk/ov016_func_021C7960.c)
- ov016_func_021C79B4.c..ov016_func_021C7C74.c: global g_021DE5E4 declared two ways (src/matched/ov_sdk/ov016_func_021C7A0C.c); global g_021DE5E4 declared two ways (src/matched/ov_sdk/ov016_func_021C7B34.c)

Members, in address order:

- `ov016_func_021C78A0.c`
- `ov016_func_021C7960.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C7768.c` again.
