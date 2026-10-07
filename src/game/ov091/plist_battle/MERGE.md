# plist_battle.c (ov091)

Translation unit 021B8DB4..021BEA48, 168 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`plist_battle.c` is blocked by:

- ov091_func_021B8DB4.c..ov091_func_021BE9BC.c: prototype of func_0201C7D0 differs between members (src/matched/ov/ov091_func_021B9DC0.c); prototype of func_0204B09C differs between members (src/matched/ov/ov091_func_021BB0C4.c); global d_021BEC6D 
- ov091_func_021B8DB4.c..ov091_func_021BB7D8.c: prototype of func_0201C7D0 differs between members (src/matched/ov/ov091_func_021B9DC0.c); prototype of func_021BDBF8 differs between members (src/matched/ov/ov091_func_021BA0A8.c); prototype of func_
- ov091_func_021B8DB4.c..ov091_func_021BA60C.c: prototype of func_0201C7D0 differs between members (src/matched/ov/ov091_func_021B9DC0.c); prototype of func_021BDBF8 differs between members (src/matched/ov/ov091_func_021BA0A8.c); prototype of func_
- ov091_func_021BA624.c..ov091_func_021BB7D8.c: prototype of func_021B9CF4 differs between members (src/matched/ov/ov091_func_021BAF28.c); prototype of func_0204B09C differs between members (src/matched/ov/ov091_func_021BB0C4.c); global d_021BEC6D 
- ov091_func_021BA624.c..ov091_func_021BB2C0.c: prototype of func_021BB554 differs between members (src/matched/ov/ov091_func_021BAE94.c); prototype of func_0204B09C differs between members (src/matched/ov/ov091_func_021BB0C4.c); global d_021BEC6D 
- ov091_func_021BAAE4.c..ov091_func_021BB2C0.c: prototype of func_021BB554 differs between members (src/matched/ov/ov091_func_021BAE94.c); global d_021BEC74 declared two ways (src/matched/ov/ov091_func_021BB1A0.c); global d_021BEC75 declared two wa
- ov091_func_021BAAE4.c..ov091_func_021BAFA0.c: prototype of func_021BB554 differs between members (src/matched/ov/ov091_func_021BAE94.c)
- ov091_func_021BB050.c..ov091_func_021BB2C0.c: global d_021BEC74 declared two ways (src/matched/ov/ov091_func_021BB1A0.c); global d_021BEC75 declared two ways (src/matched/ov/ov091_func_021BB1A0.c); prototype of func_0204B09C differs between membe
- ov091_func_021BB7E8.c..ov091_func_021BE9BC.c: prototype of func_0201C724 differs between members (src/matched/ov/ov091_func_021BC6CC.c); prototype of func_020450F0 differs between members (src/matched/ov/ov091_func_021BD218.c); prototype of func_
- ov091_func_021BB7E8.c..ov091_func_021BC5CC.c: c99=CCERR: line 723: illegal implicit conversion from 'unsigned char *' to | line 723: 'unsigned short *' | line 759: illegal implicit conversion from 'unsigned char *' to nolang=CCERR: line 723: ille
- ov091_func_021BBBA0.c..ov091_func_021BC5CC.c: prototype of func_021BB97C differs between members (src/matched/ov/ov091_func_021BC350.c)
- ov091_func_021BC1B4.c..ov091_func_021BC5CC.c: prototype of func_021BB97C differs between members (src/matched/ov/ov091_func_021BC350.c)
- ov091_func_021BC2C8.c..ov091_func_021BC5CC.c: prototype of func_021BB97C differs between members (src/matched/ov/ov091_func_021BC350.c)
- ov091_func_021BC350.c..ov091_func_021BC5CC.c: prototype of func_021BB97C differs between members (src/matched/ov/ov091_func_021BC548.c); prototype of func_021BB97C differs between members (src/matched/ov/ov091_func_021BC5CC.c)
- ov091_func_021BC628.c..ov091_func_021BE9BC.c: prototype of func_0201C724 differs between members (src/matched/ov/ov091_func_021BD05C.c); prototype of func_020450F0 differs between members (src/matched/ov/ov091_func_021BD218.c); prototype of func_
- ov091_func_021BC628.c..ov091_func_021BD504.c: prototype of func_0201C724 differs between members (src/matched/ov/ov091_func_021BD05C.c); prototype of func_020450F0 differs between members (src/matched/ov/ov091_func_021BD218.c)
- ov091_func_021BCEAC.c..ov091_func_021BD504.c: prototype of func_020450F0 differs between members (src/matched/ov/ov091_func_021BD218.c)
- ov091_func_021BD59C.c..ov091_func_021BE9BC.c: prototype of func_0201C158 differs between members (src/matched/ov/ov091_func_021BE874.c)
- ov091_func_021BDC5C.c..ov091_func_021BE9BC.c: prototype of func_0201C158 differs between members (src/matched/ov/ov091_func_021BE874.c)

Members, in address order:

- `ov091_func_021BC350.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names plist_battle.c` again.
