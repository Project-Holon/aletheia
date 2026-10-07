# unit_0220BC70.c (ov198)

Translation unit 0220BC70..0220F060, 82 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0220BC70.c` is blocked by:

- ov198_func_0220BC70.c..ov198_func_0220EFD8.c: prototype of func_020452E8 differs between members (src/matched/ov/ov198_func_0220BE04.c); prototype of func_0201C724 differs between members (src/matched/ov/ov198_func_0220C0D0.c); prototype of func_
- ov198_func_0220BC70.c..ov198_func_0220D988.c: prototype of func_020452E8 differs between members (src/matched/ov/ov198_func_0220BE04.c); prototype of func_0201C724 differs between members (src/matched/ov/ov198_func_0220C0D0.c); prototype of func_
- ov198_func_0220BC70.c..ov198_func_0220C714.c: prototype of func_020452E8 differs between members (src/matched/ov/ov198_func_0220BE04.c); prototype of func_0201C724 differs between members (src/matched/ov/ov198_func_0220C0D0.c); prototype of func_
- ov198_func_0220BC70.c..ov198_func_0220C16C.c: prototype of func_020452E8 differs between members (src/matched/ov/ov198_func_0220BE04.c); prototype of func_0201C724 differs between members (src/matched/ov/ov198_func_0220C0D0.c)
- ov198_func_0220BE04.c..ov198_func_0220C16C.c: prototype of func_0201C724 differs between members (src/matched/ov/ov198_func_0220C0D0.c)
- ov198_func_0220BEB8.c..ov198_func_0220C16C.c: prototype of func_0201C724 differs between members (src/matched/ov/ov198_func_0220C0D0.c)
- ov198_func_0220C0D0.c..ov198_func_0220C16C.c: prototype of func_0201C724 differs between members (src/matched/ov/ov198_func_0220C16C.c)
- ov198_func_0220D9B4.c..ov198_func_0220EFD8.c: prototype of func_0220D3B4 differs between members (src/matched/ov/ov198_func_0220DF20.c); prototype of func_0220D218 differs between members (src/matched/ov/ov198_func_0220DF20.c); prototype of func_
- ov198_func_0220E584.c..ov198_func_0220EFD8.c: prototype of func_0204B878 differs between members (src/matched/ov/ov198_func_0220EA30.c); global d_02211D34 declared two ways (src/matched/ov/ov198_func_0220EC2C.c); global d_02211D34 declared two wa
- ov198_func_0220E584.c..ov198_func_0220E974.c: c99=CCERR: line 174: illegal implicit conversion from 'char *' to | line 174: 'struct  *' nolang=CCERR: line 174: illegal implicit conversion from 'char *' to | line 174: 'struct  *'
- ov198_func_0220E9A0.c..ov198_func_0220EFD8.c: global d_02211D34 declared two ways (src/matched/ov/ov198_func_0220EC2C.c); global d_02211D34 declared two ways (src/matched/ov/ov198_func_0220ECCC.c); global d_02211D68 declared two ways (src/matched
- ov198_func_0220E9A0.c..ov198_func_0220EBCC.c: c99=CCERR: line 96: illegal implicit conversion from 'char *' to | line 96: 'struct  *' | line 97: illegal implicit conversion from 'char *' to nolang=CCERR: line 96: illegal implicit conversion from 
- ov198_func_0220EA68.c..ov198_func_0220EBCC.c: c99=CCERR: line 68: illegal implicit conversion from 'char *' to | line 68: 'struct  *' | line 69: illegal implicit conversion from 'char *' to nolang=CCERR: line 68: illegal implicit conversion from 
- ov198_func_0220EC2C.c..ov198_func_0220EFD8.c: global d_02211D34 declared two ways (src/matched/ov/ov198_func_0220ECCC.c); global d_02211D68 declared two ways (src/matched/ov/ov198_func_0220ECCC.c); prototype of func_0220E9A0 differs between membe
- ov198_func_0220EC2C.c..ov198_func_0220ED54.c: global d_02211D34 declared two ways (src/matched/ov/ov198_func_0220ECCC.c); global d_02211D68 declared two ways (src/matched/ov/ov198_func_0220ECCC.c); prototype of func_0220E9A0 differs between membe
- ov198_func_0220ECCC.c..ov198_func_0220ED54.c: global d_02211D34 declared two ways (src/matched/ov/ov198_func_0220ED54.c); prototype of func_0220E9A0 differs between members (src/matched/ov/ov198_func_0220ED54.c)
- ov198_func_0220EE44.c..ov198_func_0220EFD8.c: global d_02211D34 declared two ways (src/matched/ov/ov198_func_0220EECC.c); global d_02211D34 declared two ways (src/matched/ov/ov198_func_0220EFD8.c)
- ov198_func_0220EECC.c..ov198_func_0220EFD8.c: global d_02211D34 declared two ways (src/matched/ov/ov198_func_0220EFD8.c)

Members, in address order:

- `ov198_func_0220BEB8.c`
- `ov198_func_0220C0D0.c`
- `ov198_func_0220C16C.c`
- `ov198_func_0220EA68.c`
- `ov198_func_0220EC2C.c`
- `ov198_func_0220ECCC.c`
- `ov198_func_0220ED54.c`
- `ov198_func_0220EE44.c`
- `ov198_func_0220EECC.c`
- `ov198_func_0220EFD8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0220BC70.c` again.
