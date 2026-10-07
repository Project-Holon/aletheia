# unit_021C569C.c (ov114)

Translation unit 021C569C..021C5E78, 13 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C569C.c` is blocked by:

- ov114_func_021C569C.c..ov114_func_021C5E14.c: global g_021D3B68 declared two ways (src/matched/ov_sdk/ov114_func_021C5724.c); prototype of func_02086028 differs between members (src/matched/ov_sdk/ov114_func_021C58C8.c); global g_021D3B84 declare
- ov114_func_021C569C.c..ov114_func_021C5928.c: global g_021D3B68 declared two ways (src/matched/ov_sdk/ov114_func_021C5724.c); prototype of func_02086028 differs between members (src/matched/ov_sdk/ov114_func_021C58C8.c); global g_021D3B84 declare
- ov114_func_021C5724.c..ov114_func_021C5928.c: prototype of func_021C569C differs between members (src/matched/ov_sdk/ov114_func_021C5928.c); prototype of func_021C56B4 differs between members (src/matched/ov_sdk/ov114_func_021C5928.c)

Members, in address order:

- `ov114_func_021C5724.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C569C.c` again.
