# unit_021C7BA0.c (ov114)

Translation unit 021C7BA0..021C940C, 23 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C7BA0.c` is blocked by:

- ov114_func_021C7BA0.c..ov114_func_021C93D0.c: global d_021D3D2C declared two ways (src/matched/ov/ov114_func_021C866C.c); global d_021D3D2C declared two ways (src/matched/ov_sdk/ov114_func_021C86A8.c); global d_021D3D28 declared two ways (src/mat
- ov114_func_021C7BA0.c..ov114_func_021C8978.c: global d_021D3D2C declared two ways (src/matched/ov/ov114_func_021C866C.c); global d_021D3D2C declared two ways (src/matched/ov_sdk/ov114_func_021C86A8.c); global d_021D3D28 declared two ways (src/mat
- ov114_func_021C7BA0.c..ov114_func_021C86A8.c: global d_021D3D2C declared two ways (src/matched/ov/ov114_func_021C866C.c); global d_021D3D2C declared two ways (src/matched/ov_sdk/ov114_func_021C86A8.c)
- ov114_func_021C7BA0.c..ov114_func_021C7C1C.c: c99=CCERR: line 53: identifier 'd_021D3D2C' redeclared as 'struct ' | line 52: identifier 'd_021D3D2C' was originally declared as 'unsigned int[]' | line 78: not a struct/union/class nolang=CCERR: lin
- ov114_func_021C86B8.c..ov114_func_021C8978.c: global d_021D3D40 declared two ways (src/matched/ov/ov114_func_021C8770.c); prototype of func_021C9EE4 differs between members (src/matched/ov/ov114_func_021C8770.c); global d_021D3D2C declared two wa
- ov114_func_021C86B8.c..ov114_func_021C87FC.c: global d_021D3D40 declared two ways (src/matched/ov/ov114_func_021C8770.c); prototype of func_021C9EE4 differs between members (src/matched/ov/ov114_func_021C8770.c); global d_021D3D2C declared two wa
- ov114_func_021C8770.c..ov114_func_021C87FC.c: global d_021D3D40 declared two ways (src/matched/ov/ov114_func_021C87FC.c); prototype of func_021C9EE4 differs between members (src/matched/ov/ov114_func_021C87FC.c)
- ov114_func_021C89F0.c..ov114_func_021C93D0.c: global d_021D3D28 declared two ways (src/matched/ov/ov114_func_021C8BC4.c); global d_021D3D2C declared two ways (src/matched/ov/ov114_func_021C8BC4.c); global d_021CF634 declared two ways (src/matched
- ov114_func_021C89F0.c..ov114_func_021C8DA0.c: global d_021D3D28 declared two ways (src/matched/ov/ov114_func_021C8BC4.c); global d_021D3D2C declared two ways (src/matched/ov/ov114_func_021C8BC4.c); global d_021CF634 declared two ways (src/matched
- ov114_func_021C89F0.c..ov114_func_021C8BC4.c: global d_021D3D28 declared two ways (src/matched/ov/ov114_func_021C8BC4.c); global d_021D3D2C declared two ways (src/matched/ov/ov114_func_021C8BC4.c); global d_021CF634 declared two ways (src/matched
- ov114_func_021C8B18.c..ov114_func_021C8BC4.c: global d_021D3D28 declared two ways (src/matched/ov/ov114_func_021C8BC4.c); global d_021D3D2C declared two ways (src/matched/ov/ov114_func_021C8BC4.c); global d_021CF634 declared two ways (src/matched
- ov114_func_021C8C68.c..ov114_func_021C8DA0.c: global d_021D3D40 declared two ways (src/matched/ov/ov114_func_021C8D14.c)
- ov114_func_021C8E18.c..ov114_func_021C93D0.c: global d_021D4084 declared two ways (src/matched/ov/ov114_func_021C8FA8.c)
- ov114_func_021C8FA8.c..ov114_func_021C93D0.c: global d_021D4084 declared two ways (src/matched/ov/ov114_func_021C93D0.c)

Members, in address order:

- `ov114_func_021C7BA0.c`
- `ov114_func_021C7C1C.c`
- `ov114_func_021C86B8.c`
- `ov114_func_021C8770.c`
- `ov114_func_021C87FC.c`
- `ov114_func_021C89F0.c`
- `ov114_func_021C8B18.c`
- `ov114_func_021C8BC4.c`
- `ov114_func_021C8C68.c`
- `ov114_func_021C8FA8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C7BA0.c` again.
