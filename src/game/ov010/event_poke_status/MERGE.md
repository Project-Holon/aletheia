# event_poke_status.c (ov010)

Translation unit 0215932C..0215B488, 194 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`event_poke_status.c` is blocked by:

- ov010_func_0215932C.c..ov010_func_0215B464.c: prototype of func_0201137C differs between members (src/matched/ov/func_0215942C.c); prototype of func_0201137C differs between members (src/matched/ov/func_0215944C.c); prototype of func_0201137C dif
- ov010_func_0215932C.c..func_0215A4B4.c: prototype of func_0201137C differs between members (src/matched/ov/func_0215942C.c); prototype of func_0201137C differs between members (src/matched/ov/func_0215944C.c); prototype of func_0201137C dif
- ov010_func_0215932C.c..func_02159AE8.c: prototype of func_0201137C differs between members (src/matched/ov/func_0215942C.c); prototype of func_0201137C differs between members (src/matched/ov/func_0215944C.c); prototype of func_0201137C dif
- ov010_func_0215932C.c..func_021596E8.c: prototype of func_0201137C differs between members (src/matched/ov/func_0215942C.c); prototype of func_0201137C differs between members (src/matched/ov/func_0215944C.c); prototype of func_0201137C dif
- ov010_func_0215932C.c..func_0215944C.c: prototype of func_0201137C differs between members (src/matched/ov/func_0215942C.c); prototype of func_0201137C differs between members (src/matched/ov/func_0215944C.c)
- ov010_func_0215932C.c..ov010_func_021593B8.c: c99=CCERR: line 79: function call 'func_0215932C(unsigned int, unsigned int, int, int)' does not match | line 79: 'func_0215932C(unsigned int, unsigned int)' nolang=CCERR: line 79: function call 'func
- func_0215946C.c..func_021596E8.c: prototype of func_0201137C differs between members (src/matched/ov/func_0215948C.c); prototype of func_0201137C differs between members (src/matched/ov/func_021594B0.c); prototype of func_0201134C dif
- func_0215946C.c..func_021595A0.c: prototype of func_0201137C differs between members (src/matched/ov/func_0215948C.c); prototype of func_0201137C differs between members (src/matched/ov/func_021594B0.c)
- func_0215946C.c..func_021594B0.c: prototype of func_0201137C differs between members (src/matched/ov/func_0215948C.c); prototype of func_0201137C differs between members (src/matched/ov/func_021594B0.c)
- func_02159B10.c..func_0215A4B4.c: prototype of func_020307B0 differs between members (src/matched/ov/func_02159DEC.c); global d_02170FB0 declared two ways (src/matched/ov/ov010_func_02159E8C.c); global d_02170FB0 declared two ways (sr
- func_02159B10.c..ov010_func_02159E00.c: prototype of func_020307B0 differs between members (src/matched/ov/func_02159DEC.c)
- ov010_func_02159C20.c..ov010_func_02159E00.c: c99=CCERR: line 152: function call 'func_02159C2C(int, int, int)' does not match | line 152: 'func_02159C2C(int, int, int, int)' | line 188: illegal implicit conversion from 'struct Obj *' to nolang=C
- ov010_func_02159C20.c..ov010_func_02159D04.c: c99=CCERR: line 126: function call 'func_02159C2C(int, int, int)' does not match | line 126: 'func_02159C2C(int, int, int, int)' nolang=CCERR: line 126: function call 'func_02159C2C(int, int, int)' do
- ov010_func_02159C20.c..func_02159C48.c: c99=CCERR: line 77: function call 'func_02159C2C(int, int, int)' does not match | line 77: 'func_02159C2C(int, int, int, int)' nolang=CCERR: line 77: function call 'func_02159C2C(int, int, int)' does 
- func_02159C2C.c..func_02159C48.c: c99=CCERR: line 71: function call 'func_02159C2C(int, int, int)' does not match | line 71: 'func_02159C2C(int, int, int, int)' nolang=CCERR: line 71: function call 'func_02159C2C(int, int, int)' does 
- ov010_func_02159E60.c..func_0215A4B4.c: global d_02170FB0 declared two ways (src/matched/ov/ov010_func_02159E8C.c); global d_02170FB0 declared two ways (src/matched/ov/ov010_func_02159F04.c); global d_02170FEC declared two ways (src/matched
- ov010_func_02159E60.c..ov010_func_0215A048.c: global d_02170FB0 declared two ways (src/matched/ov/ov010_func_02159E8C.c); global d_02170FB0 declared two ways (src/matched/ov/ov010_func_02159F04.c); global d_02170FEC declared two ways (src/matched
- ov010_func_02159E60.c..func_02159F80.c: global d_02170FB0 declared two ways (src/matched/ov/ov010_func_02159E8C.c); global d_02170FB0 declared two ways (src/matched/ov/ov010_func_02159F04.c)
- ov010_func_02159E60.c..ov010_func_02159F04.c: global d_02170FB0 declared two ways (src/matched/ov/ov010_func_02159E8C.c); global d_02170FB0 declared two ways (src/matched/ov/ov010_func_02159F04.c)
- ov010_func_02159E8C.c..ov010_func_02159F04.c: global d_02170FB0 declared two ways (src/matched/ov/ov010_func_02159F04.c)
- func_02159F84.c..ov010_func_0215A048.c: global d_02170FEC declared two ways (src/matched/ov/ov010_func_02159FE0.c); global d_02170FEC declared two ways (src/matched/ov/ov010_func_0215A014.c)
- func_0215A4C8.c..ov010_func_0215B464.c: prototype of func_020307B0 differs between members (src/matched/ov/func_0215A5A4.c); prototype of func_020127A4 differs between members (src/matched/ov/ov010_func_0215AD7C.c); prototype of func_020141
- func_0215A4C8.c..func_0215AA4C.c: prototype of func_020307B0 differs between members (src/matched/ov/func_0215A5A4.c)
- func_0215A4C8.c..ov010_func_0215A630.c: prototype of func_020307B0 differs between members (src/matched/ov/func_0215A5A4.c)
- func_0215A4C8.c..func_0215A5D4.c: prototype of func_020307B0 differs between members (src/matched/ov/func_0215A5A4.c)
- func_0215A554.c..func_0215A5D4.c: prototype of func_020307B0 differs between members (src/matched/ov/func_0215A5A4.c)
- func_0215A554.c..func_0215A5A4.c: prototype of func_020307B0 differs between members (src/matched/ov/func_0215A5A4.c)
- ov010_func_0215A63C.c..func_0215AA4C.c: c99=CCERR: line 199: identifier 'func_0215A690(int *)' redeclared as 'int (char *)' | line 193: identifier 'func_0215A690(int *)' was originally declared as 'int (int *)' | line 200: identifier 'func_
- ov010_func_0215A63C.c..func_0215A738.c: c99=CCERR: line 60: identifier 'func_0215A690(int *)' redeclared as 'int (char *)' | line 54: identifier 'func_0215A690(int *)' was originally declared as 'int (int *)' | line 61: identifier 'func_021
- ov010_func_0215A678.c..func_0215A738.c: c99=CCERR: line 49: identifier 'func_0215A690(int *)' redeclared as 'int (char *)' | line 43: identifier 'func_0215A690(int *)' was originally declared as 'int (int *)' | line 50: identifier 'func_021
- ov010_func_0215A678.c..ov010_func_0215A690.c: c99=CCERR: line 35: identifier 'func_0215A690(int *)' redeclared as 'int (char *)' | line 29: identifier 'func_0215A690(int *)' was originally declared as 'int (int *)' | line 100: identifier 'func_02
- ov010_func_0215A684.c..ov010_func_0215A690.c: c99=CCERR: line 34: identifier 'func_0215A690(int *)' redeclared as 'int (char *)' | line 28: identifier 'func_0215A690(int *)' was originally declared as 'int (int *)' | line 93: identifier 'func_021
- func_0215A6AC.c..func_0215A738.c: c99=DIFF nolang=DIFF
- func_0215AA50.c..ov010_func_0215B464.c: prototype of func_020127A4 differs between members (src/matched/ov/ov010_func_0215AD7C.c); prototype of func_02014184 differs between members (src/matched/ov/ov010_func_0215ADCC.c); prototype of func_
- func_0215AA50.c..ov010_func_0215AEE8.c: prototype of func_020127A4 differs between members (src/matched/ov/ov010_func_0215AD7C.c); prototype of func_02014184 differs between members (src/matched/ov/ov010_func_0215ADCC.c); prototype of func_
- func_0215AC1C.c..ov010_func_0215AEE8.c: prototype of func_020127A4 differs between members (src/matched/ov/ov010_func_0215AD7C.c); prototype of func_02014184 differs between members (src/matched/ov/ov010_func_0215ADCC.c); prototype of func_
- func_0215AD50.c..ov010_func_0215AEE8.c: prototype of func_02014184 differs between members (src/matched/ov/ov010_func_0215ADCC.c); prototype of func_020127A4 differs between members (src/matched/ov/ov010_func_0215AE34.c)
- func_0215AD50.c..ov010_func_0215ADCC.c: prototype of func_02014184 differs between members (src/matched/ov/ov010_func_0215ADCC.c)
- ov010_func_0215AD7C.c..ov010_func_0215ADCC.c: prototype of func_02014184 differs between members (src/matched/ov/ov010_func_0215ADCC.c)

Members, in address order:

- `func_0215946C.c`
- `ov010_func_02159C20.c`
- `func_02159C2C.c`
- `func_02159C48.c`
- `ov010_func_02159E60.c`
- `ov010_func_02159E8C.c`
- `ov010_func_02159F04.c`
- `func_0215A554.c`
- `ov010_func_0215A678.c`
- `ov010_func_0215A684.c`
- `ov010_func_0215A690.c`
- `func_0215A6AC.c`
- `func_0215AD50.c`
- `ov010_func_0215AD7C.c`
- `ov010_func_0215ADCC.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names event_poke_status.c` again.
