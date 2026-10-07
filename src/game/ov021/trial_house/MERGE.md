# trial_house.c (ov021)

Translation unit 021CEDA0..021D1164, 122 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`trial_house.c` is blocked by:

- ov021_func_021CEDA0.c..ov021_func_021D10A8.c: type typedef N differs between members (src/matched/ov/ov021_func_021CEE78.c); global d_021DB834 declared two ways (src/matched/ov/ov021_func_021CFB1C.c); prototype of func_021AC1B8 differs between me
- ov021_func_021CEDA0.c..ov021_func_021CFF78.c: type typedef N differs between members (src/matched/ov/ov021_func_021CEE78.c); type typedef Row differs between members (src/matched/ov/ov021_func_021CFB1C.c)
- ov021_func_021CEDA0.c..func_021CF54C.c: type typedef N differs between members (src/matched/ov/ov021_func_021CEE78.c)
- ov021_func_021CEDA0.c..ov021_func_021CF1AC.c: type typedef N differs between members (src/matched/ov/ov021_func_021CEE78.c)
- ov021_func_021CF0F4.c..ov021_func_021CF1AC.c: c99=DIFF nolang=DIFF
- ov021_func_021CF164.c..ov021_func_021CF1AC.c: c99=DIFF nolang=DIFF
- ov021_func_021CF220.c..func_021CF54C.c: c99=DIFF nolang=DIFF
- ov021_func_021CF220.c..func_021CF3DC.c: c99=DIFF nolang=DIFF
- ov021_func_021CF32C.c..func_021CF3DC.c: c99=DIFF nolang=DIFF
- ov021_func_021CF560.c..ov021_func_021CFF78.c: c99=CCERR: line 725: illegal implicit conversion from 'unsigned short *' to | line 725: 'struct  *' | line 736: illegal implicit conversion from 'unsigned int' to nolang=CCERR: line 725: illegal impli
- ov021_func_021CFA88.c..ov021_func_021CFF78.c: c99=CCERR: line 264: illegal implicit conversion from 'unsigned short *' to | line 264: 'struct  *' | line 275: illegal implicit conversion from 'unsigned int' to nolang=CCERR: line 264: illegal impli
- ov021_func_021CFA88.c..ov021_func_021CFC80.c: c99=CCERR: line 217: illegal implicit conversion from 'unsigned short *' to | line 217: 'struct  *' | line 228: illegal implicit conversion from 'unsigned int' to nolang=CCERR: line 217: illegal impli
- ov021_func_021CFBA8.c..ov021_func_021CFC80.c: c99=CCERR: line 130: illegal implicit conversion from 'unsigned int' to | line 130: 'void *' nolang=CCERR: line 130: illegal implicit conversion from 'unsigned int' to | line 130: 'void *'
- ov021_func_021CFC4C.c..ov021_func_021CFC80.c: c99=CCERR: line 68: illegal implicit conversion from 'unsigned int' to | line 68: 'void *' nolang=CCERR: line 68: illegal implicit conversion from 'unsigned int' to | line 68: 'void *'
- ov021_func_021CFFDC.c..ov021_func_021D10A8.c: prototype of func_021AC1B8 differs between members (src/matched/ov/ov021_func_021D0568.c); prototype of func_021ABFA8 differs between members (src/matched/ov/ov021_func_021D05D8.c); prototype of func_
- ov021_func_021CFFDC.c..ov021_func_021D0610.c: prototype of func_021AC1B8 differs between members (src/matched/ov/ov021_func_021D0568.c); prototype of func_021ABFA8 differs between members (src/matched/ov/ov021_func_021D05D8.c)
- ov021_func_021D0328.c..ov021_func_021D0610.c: prototype of func_021AC1B8 differs between members (src/matched/ov/ov021_func_021D0568.c); prototype of func_021ABFA8 differs between members (src/matched/ov/ov021_func_021D05D8.c)
- func_021D0634.c..ov021_func_021D10A8.c: prototype of func_020072CC differs between members (src/matched/ov/ov021_func_021D0B58.c); prototype of func_02082BCC differs between members (src/matched/ov/ov021_func_021D0DB0.c); prototype of func_
- func_021D0634.c..ov021_func_021D0A48.c: c99=CCERR: line 226: illegal implicit conversion from 'struct S *' to | line 226: 'struct S_021D06E0 *' | line 295: illegal implicit conversion from 'struct S_021D0750 *' to nolang=CCERR: line 226: il
- func_021D0634.c..ov021_func_021D07FC.c: c99=CCERR: line 158: illegal implicit conversion from 'struct S *' to | line 158: 'struct S_021D06E0 *' | line 227: illegal implicit conversion from 'struct S_021D0750 *' to nolang=CCERR: line 158: il
- ov021_func_021D072C.c..ov021_func_021D07FC.c: c99=CCERR: line 114: illegal implicit conversion from 'struct S_021D0750 *' to | line 114: 'struct S_021D07FC *' | line 123: illegal implicit conversion from 'struct S_021D0750 *' to nolang=CCERR: lin
- ov021_func_021D072C.c..ov021_func_021D0750.c: c99=DIFF nolang=DIFF
- ov021_func_021D0A74.c..ov021_func_021D10A8.c: prototype of func_020072CC differs between members (src/matched/ov/ov021_func_021D0DB0.c); prototype of func_020073D8 differs between members (src/matched/ov/ov021_func_021D0DB0.c); prototype of func_
- ov021_func_021D0C58.c..ov021_func_021D10A8.c: prototype of func_020072CC differs between members (src/matched/ov/ov021_func_021D10A8.c); prototype of func_020073D8 differs between members (src/matched/ov/ov021_func_021D10A8.c); prototype of func_

Members, in address order:

- `ov021_func_021CFC4C.c`
- `ov021_func_021CFC80.c`
- `ov021_func_021D072C.c`
- `ov021_func_021D0750.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names trial_house.c` again.
