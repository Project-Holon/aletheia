# wifilogin_disp.c (ov115)

Translation unit 021D42A8..021D6328, 87 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`wifilogin_disp.c` is blocked by:

- ov115_func_021D42A8.c..ov115_func_021D630C.c: global d_021D65D0 declared two ways (src/matched/ov/ov115_func_021D4BFC.c); prototype of func_0203C968 differs between members (src/matched/ov/ov115_func_021D4BFC.c); prototype of func_02082BCC differ
- ov115_func_021D42A8.c..ov115_func_021D57D0.c: prototype of func_021D5C70 differs between members (src/matched/ov/ov115_func_021D4430.c); prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D45D0.c); prototype of func_
- ov115_func_021D42A8.c..ov115_func_021D48A4.c: prototype of func_021D5C70 differs between members (src/matched/ov/ov115_func_021D4430.c); prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D45D0.c); prototype of func_
- ov115_func_021D42A8.c..ov115_func_021D4474.c: prototype of func_021D5C70 differs between members (src/matched/ov/ov115_func_021D4430.c)
- ov115_func_021D4360.c..ov115_func_021D4474.c: prototype of func_021D5C70 differs between members (src/matched/ov/ov115_func_021D4430.c)
- ov115_func_021D43F4.c..ov115_func_021D4474.c: prototype of func_021D5C70 differs between members (src/matched/ov/ov115_func_021D4430.c)
- ov115_func_021D4510.c..ov115_func_021D48A4.c: prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D4644.c); prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D47C4.c); prototype of func_
- ov115_func_021D4510.c..ov115_func_021D4644.c: prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D4644.c)
- ov115_func_021D45D0.c..ov115_func_021D4644.c: prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D4644.c)
- ov115_func_021D460C.c..ov115_func_021D4644.c: prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D4644.c)
- ov115_func_021D46CC.c..ov115_func_021D48A4.c: prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D47C4.c); prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D48A4.c)
- ov115_func_021D4910.c..ov115_func_021D57D0.c: prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D493C.c); prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D497C.c); prototype of func_
- ov115_func_021D4910.c..ov115_func_021D4D10.c: prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D493C.c); prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D497C.c); prototype of func_
- ov115_func_021D4910.c..ov115_func_021D4AB0.c: prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D493C.c); prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D497C.c); prototype of func_
- ov115_func_021D4910.c..ov115_func_021D493C.c: prototype of func_021D5D3C differs between members (src/matched/ov/ov115_func_021D493C.c)
- ov115_func_021D4B3C.c..ov115_func_021D4D10.c: global d_021D65D0 declared two ways (src/matched/ov/ov115_func_021D4BFC.c)
- ov115_func_021D4D38.c..ov115_func_021D57D0.c: global d_021D65E4 declared two ways (src/matched/ov/ov115_func_021D57D0.c); prototype of func_020056A0 differs between members (src/matched/ov/ov115_func_021D57D0.c)
- ov115_func_021D4D38.c..ov115_func_021D4FA4.c: c99=CCERR: line 77: struct/union/enum/class tag 'BgTemplate' redefined | line 210: illegal implicit conversion from 'struct  *' to | line 210: 'const struct BgTemplate *' nolang=CCERR: line 77: struct
- ov115_func_021D4E04.c..ov115_func_021D4FA4.c: c99=CCERR: line 54: struct/union/enum/class tag 'BgTemplate' redefined | line 134: illegal implicit conversion from 'struct  *' to | line 134: 'const struct BgTemplate *' nolang=CCERR: line 54: struct
- ov115_func_021D4E58.c..ov115_func_021D4FA4.c: c99=CCERR: line 44: struct/union/enum/class tag 'BgTemplate' redefined | line 100: illegal implicit conversion from 'struct  *' to | line 100: 'const struct BgTemplate *' nolang=CCERR: line 44: struct
- ov115_func_021D580C.c..ov115_func_021D630C.c: global d_021D663C declared two ways (src/matched/ov/ov115_func_021D5FA0.c); global d_021D663C declared two ways (src/matched/ov/ov115_func_021D5FC4.c)
- ov115_func_021D5EA8.c..ov115_func_021D630C.c: global d_021D663C declared two ways (src/matched/ov/ov115_func_021D5FA0.c); global d_021D663C declared two ways (src/matched/ov/ov115_func_021D5FC4.c)
- ov115_func_021D613C.c..ov115_func_021D630C.c: prototype of func_021D6134 differs between members (src/matched/ov/ov115_func_021D6198.c)
- ov115_func_021D613C.c..ov115_func_021D61D8.c: prototype of func_021D6134 differs between members (src/matched/ov/ov115_func_021D6198.c)
- ov115_func_021D6198.c..ov115_func_021D61D8.c: prototype of func_021D6134 differs between members (src/matched/ov/ov115_func_021D61B8.c)
- ov115_func_021D61B8.c..ov115_func_021D61D8.c: c99=CCERR: line 36: identifier 'func_021D6134(void *, int, int)' redeclared as 'void (void *, void (*)(unsigned char *), int)' | line 29: identifier 'func_021D6134(void *, int, int)' was originally de
- ov115_func_021D61FC.c..ov115_func_021D630C.c: c99=CCERR: line 77: identifier 'func_021D6134(void *, int, int)' redeclared as 'void (void *, void (*)(unsigned char *), int)' | line 48: identifier 'func_021D6134(void *, int, int)' was originally de
- ov115_func_021D6294.c..ov115_func_021D630C.c: c99=CCERR: line 39: identifier 'func_021D6134(void *, int, int)' redeclared as 'void (void *, void (*)(unsigned char *), int)' | line 33: identifier 'func_021D6134(void *, int, int)' was originally de

Members, in address order:

- `ov115_func_021D43F4.c`
- `ov115_func_021D45D0.c`
- `ov115_func_021D460C.c`
- `ov115_func_021D4644.c`
- `ov115_func_021D4910.c`
- `ov115_func_021D493C.c`
- `ov115_func_021D4E04.c`
- `ov115_func_021D4E58.c`
- `ov115_func_021D4FA4.c`
- `ov115_func_021D6198.c`
- `ov115_func_021D61B8.c`
- `ov115_func_021D61D8.c`
- `ov115_func_021D6294.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names wifilogin_disp.c` again.
