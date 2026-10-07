# pokemontrade_3d.c (ov119)

Translation unit 021DEA24..021E5430, 225 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`pokemontrade_3d.c` is blocked by:

- ov119_func_021DEA24.c..ov119_func_021E53F8.c: prototype of func_020362DC differs between members (src/matched/ov/ov119_func_021DEB34.c); prototype of func_02045CAC differs between members (src/matched/ov/ov119_func_021DEBA0.c); prototype of func_
- ov119_func_021DEA24.c..ov119_func_021E194C.c: prototype of func_020362DC differs between members (src/matched/ov/ov119_func_021DEB34.c); prototype of func_02045CAC differs between members (src/matched/ov/ov119_func_021DEBA0.c); prototype of func_
- ov119_func_021E198C.c..ov119_func_021E53F8.c: prototype of func_02045CAC differs between members (src/matched/ov/ov119_func_021E1A44.c); prototype of func_0201C7A4 differs between members (src/matched/ov/ov119_func_021E1A44.c); prototype of func_
- ov119_func_021E198C.c..ov119_func_021E3758.c: prototype of func_0201C7A4 differs between members (src/matched/ov/ov119_func_021E1A44.c); prototype of func_0201C7A4 differs between members (src/matched/ov/ov119_func_021E1AA8.c); prototype of func_
- ov119_func_021E198C.c..ov119_func_021E2BD0.c: prototype of func_020450F0 differs between members (src/matched/ov/ov119_func_021E272C.c)
- ov119_func_021E198C.c..ov119_func_021E2438.c: c99=CCERR: line 407: illegal implicit conversion from 'int' to | line 407: 'void *' | line 412: illegal implicit conversion from 'int' to nolang=CCERR: line 407: illegal implicit conversion from 'int'
- ov119_func_021E1D68.c..ov119_func_021E2438.c: c99=CCERR: line 267: illegal implicit conversion from 'int' to | line 267: 'void *' | line 272: illegal implicit conversion from 'int' to nolang=CCERR: line 267: illegal implicit conversion from 'int'
- ov119_func_021E2070.c..ov119_func_021E2438.c: c99=CCERR: line 149: illegal implicit conversion from 'int' to | line 149: 'void *' | line 154: illegal implicit conversion from 'int' to nolang=CCERR: line 149: illegal implicit conversion from 'int'
- ov119_func_021E2070.c..ov119_func_021E2140.c: c99=CCERR: line 62: illegal implicit conversion from 'int' to | line 62: 'void *' | line 67: illegal implicit conversion from 'int' to nolang=CCERR: line 62: illegal implicit conversion from 'int' to 
- ov119_func_021E2C3C.c..ov119_func_021E3758.c: prototype of func_02087A3C differs between members (src/matched/ov/ov119_func_021E3004.c); prototype of func_020056BC differs between members (src/matched/ov/ov119_func_021E3004.c); global d_021E81C0 
- ov119_func_021E2C3C.c..ov119_func_021E31FC.c: prototype of func_02087A3C differs between members (src/matched/ov/ov119_func_021E3004.c); prototype of func_020056BC differs between members (src/matched/ov/ov119_func_021E3004.c); global d_021E81C0 
- ov119_func_021E37D8.c..ov119_func_021E53F8.c: global d_021E8144 declared two ways (src/matched/ov/ov119_func_021E3A40.c); prototype of func_020307B0 differs between members (src/matched/ov/ov119_func_021E3B2C.c); global d_021E7D40 declared two wa
- ov119_func_021E37D8.c..ov119_func_021E42B4.c: global d_021E8144 declared two ways (src/matched/ov/ov119_func_021E3A40.c); prototype of func_020307B0 differs between members (src/matched/ov/ov119_func_021E3B2C.c); global d_021E7D40 declared two wa
- ov119_func_021E37D8.c..ov119_func_021E3E40.c: global d_021E8144 declared two ways (src/matched/ov/ov119_func_021E3A40.c); prototype of func_020307B0 differs between members (src/matched/ov/ov119_func_021E3B2C.c)
- ov119_func_021E37D8.c..ov119_func_021E3B2C.c: global d_021E8144 declared two ways (src/matched/ov/ov119_func_021E3A40.c); prototype of func_020307B0 differs between members (src/matched/ov/ov119_func_021E3B2C.c)
- ov119_func_021E38D8.c..ov119_func_021E3B2C.c: global d_021E8144 declared two ways (src/matched/ov/ov119_func_021E3A40.c)
- ov119_func_021E4324.c..ov119_func_021E53F8.c: prototype of func_02082D44 differs between members (src/matched/ov/ov119_func_021E5098.c); prototype of func_021D8B0C differs between members (src/matched/ov/ov119_func_021E51A4.c); prototype of func_
- ov119_func_021E4AA4.c..ov119_func_021E53F8.c: prototype of func_02082D44 differs between members (src/matched/ov/ov119_func_021E5098.c); prototype of func_021D8B0C differs between members (src/matched/ov/ov119_func_021E51A4.c); prototype of func_

Members, in address order:

- `ov119_func_021E2070.c`
- `ov119_func_021E2140.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names pokemontrade_3d.c` again.
