# btl_net.c (ov093)

Translation unit 021D3A20..021D5E38, 172 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`btl_net.c` is blocked by:

- ov093_func_021D3A20.c..ov093_func_021D5DC0.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4230.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4254.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D3A20.c..ov093_func_021D4A0C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4230.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4254.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D3F98.c..ov093_func_021D4A0C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4230.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4254.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D3F98.c..ov093_func_021D450C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4230.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4254.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D4294.c..ov093_func_021D450C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4330.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4394.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D4294.c..func_021D43E0.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4330.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4394.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D4294.c..ov093_func_021D4330.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4330.c)
- ov093_func_021D4394.c..func_021D43E0.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D43B8.c); global d_021F3B88 declared two ways (src/matched/ov/func_021D43E0.c)
- func_021D440C.c..ov093_func_021D450C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4438.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D446C.c); global d_021F3B88 declared two ways (src/matched
- func_021D440C.c..ov093_func_021D446C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4438.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D446C.c)
- ov093_func_021D4438.c..ov093_func_021D446C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D446C.c)
- ov093_func_021D44CC.c..ov093_func_021D450C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D450C.c)
- ov093_func_021D4558.c..ov093_func_021D4A0C.c: global d_021F3B88 declared two ways (src/matched/ov/func_021D45B8.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D45FC.c); global d_021F3B88 declared two ways (src/matched/ov/ov
- ov093_func_021D4558.c..ov093_func_021D47A4.c: global d_021F3B88 declared two ways (src/matched/ov/func_021D45B8.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D45FC.c); global d_021F3B88 declared two ways (src/matched/ov/ov
- ov093_func_021D4558.c..ov093_func_021D4674.c: global d_021F3B88 declared two ways (src/matched/ov/func_021D45B8.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D45FC.c); global d_021F3B88 declared two ways (src/matched/ov/ov
- ov093_func_021D45FC.c..ov093_func_021D4674.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4648.c)
- ov093_func_021D4680.c..ov093_func_021D47A4.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D46B0.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D46FC.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D4680.c..ov093_func_021D46B0.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D46B0.c)
- ov093_func_021D46FC.c..ov093_func_021D47A4.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4784.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D47A4.c)
- ov093_func_021D4784.c..ov093_func_021D47A4.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D47A4.c)
- ov093_func_021D4800.c..ov093_func_021D4A0C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4838.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4898.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D4800.c..ov093_func_021D48CC.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4838.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4898.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D4838.c..ov093_func_021D48CC.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4898.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D48CC.c)
- ov093_func_021D4908.c..ov093_func_021D4A0C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D49B0.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D49CC.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D4908.c..ov093_func_021D49B0.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D49B0.c)
- func_021D4954.c..ov093_func_021D49B0.c: c99=DIFF nolang=DIFF
- func_021D4A64.c..ov093_func_021D5DC0.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4AF4.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4B18.c); global d_021F3B88 declared two ways (src/matched
- func_021D4A64.c..ov093_func_021D54F4.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4AF4.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4B18.c); global d_021F3B88 declared two ways (src/matched
- func_021D4A64.c..ov093_func_021D5150.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4AF4.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4B18.c); global d_021F3B88 declared two ways (src/matched
- func_021D4A64.c..ov093_func_021D4C6C.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4AF4.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4B18.c); global d_021F3B88 declared two ways (src/matched
- func_021D4A64.c..ov093_func_021D4B58.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4AF4.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4B18.c); global d_021F3B88 declared two ways (src/matched
- ov093_func_021D4AF4.c..ov093_func_021D4B58.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4B18.c); global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4B58.c)
- ov093_func_021D4B18.c..ov093_func_021D4B58.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4B58.c)
- ov093_func_021D4B98.c..ov093_func_021D4C6C.c: c99=DIFF nolang=DIFF
- ov093_func_021D4C84.c..ov093_func_021D5150.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4CEC.c); prototype of func_021D5244 differs between members (src/matched/ov/ov093_func_021D50B4.c)
- ov093_func_021D4C84.c..ov093_func_021D4D64.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4CEC.c)
- ov093_func_021D4C84.c..ov093_func_021D4CEC.c: global d_021F3B88 declared two ways (src/matched/ov/ov093_func_021D4CEC.c)
- ov093_func_021D4D84.c..ov093_func_021D5150.c: prototype of func_021D5244 differs between members (src/matched/ov/ov093_func_021D50B4.c)
- ov093_func_021D4D84.c..ov093_func_021D4F84.c: c99=CCERR: line 87: struct/union/enum/class tag 'S' redefined | line 179: 'f08' is not a member of class 'struct S' | line 182: 'f13c' is not a member of class 'struct S' nolang=CCERR: line 87: struct
- func_021D51CC.c..ov093_func_021D54F4.c: type struct Work differs between members (src/matched/ov/ov093_func_021D54F4.c)
- func_021D51CC.c..func_021D53C0.c: c99=CCERR: line 121: illegal implicit conversion from 'struct S_021D51DC *' to | line 121: 'struct S_021D5208 *' | line 128: illegal implicit conversion from 'struct S_021D51DC *' to nolang=CCERR: lin
- func_021D51CC.c..ov093_func_021D52B4.c: c99=CCERR: line 73: illegal implicit conversion from 'struct S_021D51DC *' to | line 73: 'struct S_021D5208 *' | line 80: illegal implicit conversion from 'struct S_021D51DC *' to nolang=CCERR: line 7

Members, in address order:

- `ov093_func_021D4294.c`
- `ov093_func_021D4330.c`
- `ov093_func_021D4394.c`
- `func_021D440C.c`
- `ov093_func_021D4438.c`
- `ov093_func_021D446C.c`
- `ov093_func_021D44CC.c`
- `ov093_func_021D45FC.c`
- `ov093_func_021D4680.c`
- `ov093_func_021D46B0.c`
- `ov093_func_021D46FC.c`
- `ov093_func_021D4784.c`
- `ov093_func_021D47A4.c`
- `ov093_func_021D4838.c`
- `ov093_func_021D4908.c`
- `func_021D4954.c`
- `ov093_func_021D49B0.c`
- `ov093_func_021D4AF4.c`
- `ov093_func_021D4B18.c`
- `ov093_func_021D4B58.c`
- `ov093_func_021D4C84.c`
- `ov093_func_021D4CEC.c`
- `ov093_func_021D4D84.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names btl_net.c` again.
