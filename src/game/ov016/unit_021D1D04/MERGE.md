# unit_021D1D04.c (ov016)

Translation unit 021D1D04..021D298C, 19 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D1D04.c` is blocked by:

- func_021D1D04.c..ov016_func_021D28E4.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D1E54.c); global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D1E9C.c); global g_021DE65C declared two ways (src
- func_021D1D04.c..ov016_func_021D22AC.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D1E54.c); global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D1E9C.c); global g_021DE65C declared two ways (src
- func_021D1D04.c..ov016_func_021D1E9C.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D1E54.c); global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D1E9C.c)
- ov016_func_021D1E54.c..ov016_func_021D1E9C.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D1E9C.c)
- ov016_func_021D1F6C.c..ov016_func_021D22AC.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D200C.c); global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D20E8.c); global g_021DE65C declared two ways (src
- ov016_func_021D1F6C.c..ov016_func_021D200C.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D200C.c)
- ov016_func_021D20E8.c..ov016_func_021D22AC.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D21CC.c); global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D22AC.c)
- ov016_func_021D21CC.c..ov016_func_021D22AC.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D22AC.c)
- ov016_func_021D2314.c..ov016_func_021D28E4.c: prototype of DWCi_MOV_MBP_ChangeState differs between members (src/matched/ov_sdk/ov016_func_021D240C.c); global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D2450.c); type typedef D
- ov016_func_021D2314.c..func_021D276C.c: prototype of DWCi_MOV_MBP_ChangeState differs between members (src/matched/ov_sdk/ov016_func_021D240C.c); global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D2450.c)
- func_021D2780.c..ov016_func_021D28E4.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D27EC.c); global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D28E4.c)
- ov016_func_021D27EC.c..ov016_func_021D28E4.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D28B4.c); global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D28E4.c)
- ov016_func_021D28B4.c..ov016_func_021D28E4.c: global g_021DE65C declared two ways (src/matched/ov_sdk/ov016_func_021D28E4.c)

Members, in address order:

- `ov016_func_021D1E54.c`
- `ov016_func_021D1E9C.c`
- `ov016_func_021D1F6C.c`
- `ov016_func_021D200C.c`
- `ov016_func_021D20E8.c`
- `ov016_func_021D21CC.c`
- `ov016_func_021D22AC.c`
- `ov016_func_021D27EC.c`
- `ov016_func_021D28B4.c`
- `ov016_func_021D28E4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D1D04.c` again.
