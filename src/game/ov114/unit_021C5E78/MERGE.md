# unit_021C5E78.c (ov114)

Translation unit 021C5E78..021C78DC, 31 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C5E78.c` is blocked by:

- ov114_func_021C5E78.c..ov114_func_021C78C4.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C5EBC.c); global g_021D3BD8 declared two ways (src/matched/ov_sdk/ov114_func_021C5EBC.c); prototype of func_021C7A18 differs betwe
- ov114_func_021C5E78.c..ov114_func_021C659C.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C5EBC.c); global g_021D3BD8 declared two ways (src/matched/ov_sdk/ov114_func_021C5EBC.c); prototype of func_021C7A18 differs betwe
- ov114_func_021C5E78.c..ov114_func_021C60AC.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C5EBC.c); global g_021D3BD8 declared two ways (src/matched/ov_sdk/ov114_func_021C5EBC.c)
- ov114_func_021C5E78.c..ov114_func_021C5F90.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C5EBC.c); global g_021D3BD8 declared two ways (src/matched/ov_sdk/ov114_func_021C5EBC.c)
- ov114_func_021C60C8.c..ov114_func_021C659C.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C6348.c); global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C64E0.c)
- ov114_func_021C60C8.c..ov114_func_021C6348.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C6348.c)
- ov114_func_021C62FC.c..ov114_func_021C6348.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C6348.c)
- ov114_func_021C666C.c..ov114_func_021C78C4.c: prototype of freeHttpParam differs between members (src/matched/ov_sdk/ov114_func_021C6C0C.c); global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C6C0C.c); global g_021D3B9C declare
- ov114_func_021C666C.c..ov114_func_021C6C0C.c: prototype of freeHttpParam differs between members (src/matched/ov_sdk/ov114_func_021C6C0C.c); global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C6C0C.c)
- ov114_func_021C68BC.c..ov114_func_021C6C0C.c: prototype of freeHttpParam differs between members (src/matched/ov_sdk/ov114_func_021C6C0C.c); global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C6C0C.c)
- ov114_func_021C70D4.c..ov114_func_021C78C4.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C7124.c); global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C73C0.c); global g_021D3B9C declared two ways (src
- ov114_func_021C70D4.c..ov114_func_021C757C.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C7124.c); global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C73C0.c); global g_021D3B9C declared two ways (src
- ov114_func_021C70D4.c..ov114_func_021C7124.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C7124.c)
- ov114_func_021C73C0.c..ov114_func_021C757C.c: global g_021D3B9C declared two ways (src/matched/ov_sdk/ov114_func_021C757C.c)

Members, in address order:

- `ov114_func_021C5E78.c`
- `ov114_func_021C62FC.c`
- `ov114_func_021C6348.c`
- `ov114_func_021C70D4.c`
- `ov114_func_021C7124.c`
- `ov114_func_021C73C0.c`
- `ov114_func_021C757C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C5E78.c` again.
