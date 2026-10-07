# unit_021CFEBC.c (ov016)

Translation unit 021CFEBC..021D0034, 6 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021CFEBC.c` is blocked by:

- ov016_func_021CFEBC.c..func_021D0014.c: global g_021DE648 declared two ways (src/matched/ov_sdk/ov016_func_021CFF80.c)
- ov016_func_021CFEBC.c..func_021CFFAC.c: global g_021DE648 declared two ways (src/matched/ov_sdk/ov016_func_021CFF80.c)

Members, in address order:

- `ov016_func_021CFEBC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021CFEBC.c` again.
