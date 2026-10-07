# btl_calc.c (ov093)

Translation unit 021D6E04..021D7908, 59 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`btl_calc.c` is blocked by:

- ov093_func_021D6E04.c..ov093_func_021D78E4.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D6EE8.c); global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D701C.c); global g_021F3CB0 declared two ways (src/matched
- ov093_func_021D6E04.c..func_021D7324.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D6EE8.c); global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D701C.c); global g_021F3CB0 declared two ways (src/matched
- ov093_func_021D6E04.c..ov093_func_021D7040.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D6EE8.c); global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D701C.c); global g_021F3CB0 declared two ways (src/matched
- ov093_func_021D6EA0.c..ov093_func_021D7040.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D6EE8.c); global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D701C.c); global g_021F3CB0 declared two ways (src/matched
- ov093_func_021D6EA0.c..ov093_func_021D6EE8.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D6EE8.c)
- ov093_func_021D6EAC.c..ov093_func_021D6EE8.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D6EE8.c)
- func_021D6F08.c..ov093_func_021D7040.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D7040.c)
- ov093_func_021D701C.c..ov093_func_021D7040.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D7040.c)
- func_021D7090.c..func_021D7324.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D713C.c); global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D7240.c)
- func_021D70DC.c..func_021D7324.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D713C.c); global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D7240.c)
- ov093_func_021D713C.c..func_021D7324.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D7240.c)
- ov093_func_021D713C.c..ov093_func_021D7240.c: global g_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D7240.c)
- ov093_func_021D732C.c..ov093_func_021D78E4.c: type struct NodeList differs between members (src/matched/ov/ov093_func_021D7360.c); type struct NodeList differs between members (src/matched/ov/ov093_func_021D7394.c); type struct NodeList differs b
- ov093_func_021D732C.c..ov093_func_021D75A8.c: type struct NodeList differs between members (src/matched/ov/ov093_func_021D7360.c); type struct NodeList differs between members (src/matched/ov/ov093_func_021D7394.c); type struct NodeList differs b
- ov093_func_021D732C.c..ov093_func_021D7474.c: type struct NodeList differs between members (src/matched/ov/ov093_func_021D7360.c); type struct NodeList differs between members (src/matched/ov/ov093_func_021D7394.c); type struct NodeList differs b
- ov093_func_021D73D4.c..ov093_func_021D7474.c: global data_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D7438.c); type struct NodeList differs between members (src/matched/ov/ov093_func_021D7474.c)
- ov093_func_021D73D4.c..ov093_func_021D7404.c: c99=CCERR: line 56: struct/union/enum/class tag 'Node' redefined | line 75: illegal implicit conversion from 'struct Node *' to | line 75: 'struct  *' nolang=CCERR: line 56: struct/union/enum/class ta
- ov093_func_021D7438.c..ov093_func_021D7474.c: global data_021F3CB0 declared two ways (src/matched/ov/ov093_func_021D7474.c)
- ov093_func_021D7494.c..ov093_func_021D75A8.c: global g_021F3ECC declared two ways (src/matched/ov/ov093_func_021D74F8.c); global g_021F3ECC declared two ways (src/matched/ov/ov093_func_021D7540.c); global g_021F3ECC declared two ways (src/matched
- ov093_func_021D75EC.c..ov093_func_021D78E4.c: global g_021F3ECC declared two ways (src/matched/ov/ov093_func_021D7630.c); global g_021F3ECC declared two ways (src/matched/ov/ov093_func_021D7674.c); global g_021F3ECC declared two ways (src/matched
- ov093_func_021D75EC.c..ov093_func_021D778C.c: global g_021F3ECC declared two ways (src/matched/ov/ov093_func_021D7630.c); prototype of func_021D77C4 differs between members (src/matched/ov/ov093_func_021D7630.c); global g_021F3ECC declared two wa
- ov093_func_021D76BC.c..ov093_func_021D778C.c: global g_021F3ECC declared two ways (src/matched/ov/ov093_func_021D7704.c); prototype of func_021D77E8 differs between members (src/matched/ov/ov093_func_021D7704.c); global g_021F3ECC declared two wa
- ov093_func_021D76BC.c..ov093_func_021D7704.c: global g_021F3ECC declared two ways (src/matched/ov/ov093_func_021D7704.c); prototype of func_021D77E8 differs between members (src/matched/ov/ov093_func_021D7704.c)

Members, in address order:

- `ov093_func_021D6EA0.c`
- `ov093_func_021D6EAC.c`
- `ov093_func_021D6EE8.c`
- `ov093_func_021D701C.c`
- `ov093_func_021D7040.c`
- `ov093_func_021D713C.c`
- `ov093_func_021D7240.c`
- `ov093_func_021D73D4.c`
- `ov093_func_021D7404.c`
- `ov093_func_021D7438.c`
- `ov093_func_021D7474.c`
- `ov093_func_021D76BC.c`
- `ov093_func_021D7704.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names btl_calc.c` again.
