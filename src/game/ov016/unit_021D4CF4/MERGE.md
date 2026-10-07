# unit_021D4CF4.c (ov016)

Translation unit 021D4CF4..021D4FEC, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D4CF4.c` is blocked by:

- ov016_func_021D4CF4.c..func_021D4FE0.c: type typedef CELLPRM differs between members (src/matched/ov_sdk/ov016_func_021D4DC8.c); global g_021DE670 declared two ways (src/matched/ov_sdk/ov016_func_021D4E1C.c); global g_021DE670 declared two 
- ov016_func_021D4E1C.c..func_021D4FE0.c: global g_021DE670 declared two ways (src/matched/ov_sdk/func_021D4F60.c)

Members, in address order:

- `ov016_func_021D4E1C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D4CF4.c` again.
