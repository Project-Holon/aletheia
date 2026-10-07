# mystery_util.c (ov121)

Translation unit 021D9624..021DD980, 120 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`mystery_util.c` is blocked by:

- ov121_func_021D9624.c..ov121_func_021DD24C.c: global d_021DF598 declared two ways (src/matched/ov/ov121_func_021D9790.c); global d_021DF598 declared two ways (src/matched/ov/ov121_func_021D97C8.c); prototype of func_02082BCC differs between membe
- ov121_func_021D9624.c..ov121_func_021DA854.c: global d_021DF598 declared two ways (src/matched/ov/ov121_func_021D9790.c); global d_021DF598 declared two ways (src/matched/ov/ov121_func_021D97C8.c); prototype of func_02082BCC differs between membe
- ov121_func_021D9624.c..ov121_func_021D9B9C.c: global d_021DF598 declared two ways (src/matched/ov/ov121_func_021D9790.c); global d_021DF598 declared two ways (src/matched/ov/ov121_func_021D97C8.c); prototype of func_02082BCC differs between membe
- ov121_func_021D9624.c..ov121_func_021D98C0.c: global d_021DF598 declared two ways (src/matched/ov/ov121_func_021D9790.c); global d_021DF598 declared two ways (src/matched/ov/ov121_func_021D97C8.c); prototype of func_02082BCC differs between membe
- ov121_func_021D9BC0.c..ov121_func_021DA854.c: prototype of func_020457B0 differs between members (src/matched/ov/ov121_func_021D9D4C.c); global d_021DFBA0 declared two ways (src/matched/ov/ov121_func_021DA1BC.c); prototype of func_02082BCC differ
- ov121_func_021DA280.c..ov121_func_021DA854.c: global d_021DF76C declared two ways (src/matched/ov/ov121_func_021DA6D0.c); global d_021DFBA0 declared two ways (src/matched/ov/ov121_func_021DA854.c); prototype of func_02082BCC differs between membe
- ov121_func_021DA3EC.c..ov121_func_021DA854.c: global d_021DF76C declared two ways (src/matched/ov/ov121_func_021DA6D0.c); global d_021DFBA0 declared two ways (src/matched/ov/ov121_func_021DA854.c); prototype of func_02082BCC differs between membe
- ov121_func_021DA890.c..ov121_func_021DD24C.c: global d_020A1B38 declared two ways (src/matched/ov/ov121_func_021DAB50.c); prototype of func_02061CA4 differs between members (src/matched/ov/ov121_func_021DAB50.c); prototype of func_0200A348 differ
- ov121_func_021DA890.c..ov121_func_021DBC08.c: global d_020A1B38 declared two ways (src/matched/ov/ov121_func_021DAB50.c); prototype of func_02061CA4 differs between members (src/matched/ov/ov121_func_021DAB50.c); prototype of func_0200A348 differ
- ov121_func_021DAAA4.c..ov121_func_021DBC08.c: global d_020A1B38 declared two ways (src/matched/ov/ov121_func_021DAB50.c); prototype of func_02061CA4 differs between members (src/matched/ov/ov121_func_021DAB50.c); prototype of func_0200A348 differ
- ov121_func_021DAAA4.c..ov121_func_021DB018.c: prototype of func_02061CA4 differs between members (src/matched/ov/ov121_func_021DAB50.c); prototype of func_0200A348 differs between members (src/matched/ov/ov121_func_021DAE1C.c)
- ov121_func_021DAAA4.c..ov121_func_021DAC18.c: c99=CCERR: line 104: identifier 'blend(int, unsigned short, unsigned short)' redeclared as 'unsigned short (unsigned short, unsigned short, short)' | line 87: identifier 'blend(int, unsigned short, un
- ov121_func_021DB3E8.c..ov121_func_021DBC08.c: global d_021DF86E declared two ways (src/matched/ov/ov121_func_021DB938.c)
- ov121_func_021DBCC8.c..ov121_func_021DD24C.c: prototype of func_02020E60 differs between members (src/matched/ov/ov121_func_021DBF9C.c); global data_021DF86E declared two ways (src/matched/ov/ov121_func_021DC4F0.c); prototype of func_02082BCC dif
- ov121_func_021DBCC8.c..ov121_func_021DC02C.c: prototype of func_02020E60 differs between members (src/matched/ov/ov121_func_021DBF9C.c)
- ov121_func_021DBCC8.c..ov121_func_021DBF08.c: c99=CCERR: line 109: illegal implicit conversion from 'struct Item *' to | line 109: 'char *' nolang=CCERR: line 109: illegal implicit conversion from 'struct Item *' to | line 109: 'char *'

Members, in address order:

- `ov121_func_021DAAA4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names mystery_util.c` again.
