# unit_021C3A38.c (ov114)

Translation unit 021C3A38..021C569C, 18 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021C3A38.c` is blocked by:

- ov114_func_021C3A38.c..ov114_func_021C5430.c: prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C3D10.c); prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C3E10.c); prototype 
- ov114_func_021C3A38.c..ov114_func_021C4764.c: prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C3D10.c); prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C3E10.c); prototype 
- ov114_func_021C3A38.c..ov114_func_021C3E10.c: prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C3D10.c); prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C3E10.c)
- ov114_func_021C3A38.c..ov114_func_021C3BAC.c: c99=CCERR: line 52: struct/union/enum/class tag 'GHIConnection' redefined | line 69: identifier 'GHIConnection' redeclared | line 69: was declared as: 'struct GHIConnection' nolang=CCERR: line 52: str
- ov114_func_021C3D10.c..ov114_func_021C3E10.c: prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C3E10.c)
- ov114_func_021C3EC0.c..ov114_func_021C4764.c: prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C4150.c); prototype of func_021C011C differs between members (src/matched/ov_sdk/ov114_func_021C4384.c); prototype 
- ov114_func_021C3EC0.c..ov114_func_021C4150.c: prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C4150.c)
- ov114_func_021C4384.c..ov114_func_021C4764.c: prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C4684.c); prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C4764.c)
- ov114_func_021C4684.c..ov114_func_021C4764.c: prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C4764.c)
- ov114_func_021C4830.c..ov114_func_021C5430.c: prototype of func_021BFCEC differs between members (src/matched/ov_sdk/ov114_func_021C4B18.c); prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C4B18.c); prototype 
- ov114_func_021C4830.c..ov114_func_021C4BD8.c: prototype of func_021BFCEC differs between members (src/matched/ov_sdk/ov114_func_021C4B18.c); prototype of func_021C02C8 differs between members (src/matched/ov_sdk/ov114_func_021C4B18.c)
- ov114_func_021C4830.c..ov114_func_021C492C.c: c99=CCERR: line 165: illegal implicit conversion from 'struct GHIConnection_021C492C *' to | line 165: 'struct GHIConnection_021C4830 *' nolang=CCERR: line 165: illegal implicit conversion from 'struc
- ov114_func_021C4C00.c..ov114_func_021C5430.c: c99=CCERR: line 282: illegal implicit conversion from 'struct GHIConnection_021C4C50 *' to | line 282: 'struct  *' | line 306: illegal implicit conversion from 'struct GHIConnection_021C4C50 *' to nol
- ov114_func_021C4C00.c..ov114_func_021C4C50.c: c99=CCERR: line 90: illegal implicit conversion from 'struct GHIConnection_021C4C50 *' to | line 90: 'struct  *' | line 114: illegal implicit conversion from 'struct GHIConnection_021C4C50 *' to nolan

Members, in address order:

- `ov114_func_021C3A38.c`
- `ov114_func_021C3BAC.c`
- `ov114_func_021C3D10.c`
- `ov114_func_021C3E10.c`
- `ov114_func_021C3EC0.c`
- `ov114_func_021C4150.c`
- `ov114_func_021C4384.c`
- `ov114_func_021C4684.c`
- `ov114_func_021C4764.c`
- `ov114_func_021C4830.c`
- `ov114_func_021C492C.c`
- `ov114_func_021C4C00.c`
- `ov114_func_021C4C50.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021C3A38.c` again.
