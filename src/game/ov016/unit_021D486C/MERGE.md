# unit_021D486C.c (ov016)

Translation unit 021D486C..021D4B60, 5 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D486C.c` is blocked by:

- ov016_func_021D486C.c..ov016_func_021D4B50.c: global g_021DE66C declared two ways (src/matched/ov_sdk/ov016_func_021D4A94.c)
- ov016_func_021D486C.c..ov016_func_021D4A20.c: c99=CCERR: line 75: struct/union/enum/class tag 'FSArchive' redefined | line 79: struct/union/enum/class tag 'tagMEMARCHIVE' redefined nolang=CCERR: line 75: struct/union/enum/class tag 'FSArchive' re

Members, in address order:

- `ov016_func_021D486C.c`
- `ov016_func_021D4A20.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D486C.c` again.
