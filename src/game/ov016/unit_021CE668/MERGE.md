# unit_021CE668.c (ov016)

Translation unit 021CE668..021CE874, 9 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021CE668.c` is blocked by:

- ov016_func_021CE668.c..ov016_func_021CE844.c: global g_021DE630 declared two ways (src/matched/ov_sdk/ov016_func_021CE6C4.c); global g_021DE630 declared two ways (src/matched/ov_sdk/ov016_func_021CE760.c); global g_021DE630 declared two ways (src
- ov016_func_021CE668.c..ov016_func_021CE708.c: global g_021DE630 declared two ways (src/matched/ov_sdk/ov016_func_021CE6C4.c)
- ov016_func_021CE668.c..ov016_func_021CE6C4.c: global g_021DE630 declared two ways (src/matched/ov_sdk/ov016_func_021CE6C4.c)

Members, in address order:

- `ov016_func_021CE668.c`
- `ov016_func_021CE6C4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021CE668.c` again.
