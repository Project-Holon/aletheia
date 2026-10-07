# field_fog.c (ov021)

Translation unit 0219F058..021A1144, 127 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`field_fog.c` is blocked by:

- ov021_func_0219F058.c..ov021_func_021A10E0.c: prototype of func_0216D6F0 differs between members (src/matched/ov/ov021_func_0219F5C8.c); prototype of func_0216E3C4 differs between members (src/matched/ov/ov021_func_0219F990.c); prototype of func_
- ov021_func_0219F058.c..func_021A0244.c: prototype of func_0216D6F0 differs between members (src/matched/ov/ov021_func_0219F5C8.c); prototype of func_0216E3C4 differs between members (src/matched/ov/ov021_func_0219F990.c); prototype of func_
- ov021_func_0219F058.c..ov021_func_0219FB2C.c: prototype of func_0219FFD4 differs between members (src/matched/ov/ov021_func_0219F490.c); prototype of func_0219FFD4 differs between members (src/matched/ov/ov021_func_0219F52C.c); prototype of func_
- ov021_func_0219F52C.c..ov021_func_0219FB2C.c: prototype of func_0216D6F0 differs between members (src/matched/ov/ov021_func_0219F5C8.c); prototype of func_0219FFD4 differs between members (src/matched/ov/ov021_func_0219F634.c); prototype of func_
- ov021_func_0219F52C.c..ov021_func_0219F870.c: prototype of func_0216D6F0 differs between members (src/matched/ov/ov021_func_0219F5C8.c); prototype of func_0219FFD4 differs between members (src/matched/ov/ov021_func_0219F634.c); prototype of func_
- ov021_func_0219F52C.c..func_0219F628.c: prototype of func_0216D6F0 differs between members (src/matched/ov/ov021_func_0219F5C8.c)
- ov021_func_0219F52C.c..ov021_func_0219F5C8.c: prototype of func_0216D6F0 differs between members (src/matched/ov/ov021_func_0219F5C8.c)
- func_0219FB48.c..func_021A0244.c: prototype of func_0216D6F0 differs between members (src/matched/ov/ov021_func_021A00E0.c); prototype of func_021A0250 differs between members (src/matched/ov/func_021A0244.c)
- func_0219FB48.c..ov021_func_021A0084.c: c99=CCERR: line 170: illegal use of type 'void' | line 366: illegal use of type 'void' nolang=CCERR: line 170: illegal use of type 'void' | line 366: illegal use of type 'void'
- ov021_func_0219FE64.c..ov021_func_021A0084.c: c99=CCERR: line 136: illegal use of type 'void' nolang=CCERR: line 136: illegal use of type 'void'
- ov021_func_021A00E0.c..func_021A0244.c: prototype of func_021A0250 differs between members (src/matched/ov/func_021A0244.c)
- ov021_func_021A00E0.c..func_021A01B4.c: c99=DIFF nolang=DIFF
- ov021_func_021A00E0.c..ov021_func_021A0140.c: c99=DIFF nolang=DIFF
- ov021_func_021A00E0.c..ov021_func_021A0104.c: c99=DIFF nolang=DIFF
- func_021A0250.c..ov021_func_021A10E0.c: global d_021D872C declared two ways (src/matched/ov/ov021_func_021A0D68.c); prototype of func_021A0EE4 differs between members (src/matched/ov/func_021A0F30.c); global d_021D872C declared two ways (sr
- func_021A0250.c..ov021_func_021A0818.c: c99=CCERR: line 232: illegal implicit conversion from 'unsigned int' to | line 232: 'struct  *' | line 351: illegal implicit conversion from 'unsigned char *' to nolang=CCERR: line 232: illegal implic
- func_021A0250.c..ov021_func_021A03CC.c: c99=CCERR: line 137: illegal implicit conversion from 'unsigned int' to | line 137: 'struct  *' nolang=CCERR: line 137: illegal implicit conversion from 'unsigned int' to | line 137: 'struct  *'
- ov021_func_021A03D0.c..ov021_func_021A0818.c: c99=CCERR: line 164: illegal implicit conversion from 'unsigned char *' to | line 164: 'struct  *' | line 169: illegal implicit conversion from 'unsigned char *' to nolang=CCERR: line 164: illegal imp
- ov021_func_021A065C.c..ov021_func_021A0818.c: c99=CCERR: line 154: illegal implicit conversion from 'unsigned char *' to | line 154: 'struct  *' nolang=CCERR: line 154: illegal implicit conversion from 'unsigned char *' to | line 154: 'struct  *'
- func_021A07B0.c..ov021_func_021A0818.c: c99=CCERR: line 53: illegal implicit conversion from 'unsigned char *' to | line 53: 'struct  *' nolang=CCERR: line 53: illegal implicit conversion from 'unsigned char *' to | line 53: 'struct  *'
- ov021_func_021A0860.c..ov021_func_021A10E0.c: global d_021D872C declared two ways (src/matched/ov/ov021_func_021A0D68.c); prototype of func_021A0EE4 differs between members (src/matched/ov/func_021A0F30.c); global d_021D872C declared two ways (sr
- ov021_func_021A0860.c..ov021_func_021A0D68.c: global d_021D872C declared two ways (src/matched/ov/ov021_func_021A0D68.c)
- ov021_func_021A0B4C.c..ov021_func_021A0D68.c: global d_021D872C declared two ways (src/matched/ov/ov021_func_021A0D68.c)
- ov021_func_021A0CE4.c..ov021_func_021A0D68.c: global d_021D872C declared two ways (src/matched/ov/ov021_func_021A0D68.c)
- ov021_func_021A0E58.c..ov021_func_021A10E0.c: prototype of func_021A0EE4 differs between members (src/matched/ov/ov021_func_021A0F40.c); prototype of func_021A0EE4 differs between members (src/matched/ov/func_021A0F7C.c); prototype of func_020092
- ov021_func_021A0E58.c..func_021A0F90.c: prototype of func_021A0EE4 differs between members (src/matched/ov/ov021_func_021A0F40.c); prototype of func_021A0EE4 differs between members (src/matched/ov/func_021A0F7C.c)
- func_021A0F30.c..func_021A0F90.c: prototype of func_021A0EE4 differs between members (src/matched/ov/ov021_func_021A0F40.c); prototype of func_021A0EE4 differs between members (src/matched/ov/func_021A0F7C.c)
- func_021A0F30.c..ov021_func_021A0F40.c: prototype of func_021A0EE4 differs between members (src/matched/ov/ov021_func_021A0F40.c)
- func_021A0F94.c..ov021_func_021A10E0.c: prototype of func_02009200 differs between members (src/matched/ov/ov021_func_021A10E0.c)
- ov021_func_021A0FE8.c..ov021_func_021A10E0.c: prototype of func_02009200 differs between members (src/matched/ov/ov021_func_021A10E0.c)
- ov021_func_021A10C0.c..ov021_func_021A10E0.c: c99=DIFF nolang=DIFF

Members, in address order:

- `ov021_func_0219F52C.c`
- `ov021_func_0219F5C8.c`
- `ov021_func_021A00E0.c`
- `ov021_func_021A0104.c`
- `func_021A0F30.c`
- `ov021_func_021A0F40.c`
- `ov021_func_021A10C0.c`
- `ov021_func_021A10E0.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names field_fog.c` again.
