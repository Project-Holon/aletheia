# unit_0215D6C8.c (ov009)

Translation unit 0215D6C8..0215E024, 13 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0215D6C8.c` is blocked by:

- ov009_func_0215D6C8.c..ov009_func_0215DF08.c: prototype of SOCLi_CreateCommandPacket differs between members (src/matched/ov_sdk/ov009_func_0215DD28.c); prototype of SOCLi_ExecCommandPacketInRecvPipe differs between members (src/matched/ov_sdk/ov
- ov009_func_0215D6C8.c..ov009_func_0215DAA8.c: c99=CCERR: line 200: illegal implicit conversion from 'char *' to | line 200: 'struct  *' | line 218: illegal implicit conversion from 'struct  *' to nolang=CCERR: line 200: illegal implicit conversio
- ov009_func_0215D6C8.c..ov009_func_0215D898.c: c99=CCERR: line 133: illegal implicit conversion from 'char *' to | line 133: 'struct  *' nolang=CCERR: line 133: illegal implicit conversion from 'char *' to | line 133: 'struct  *'
- ov009_func_0215D7FC.c..ov009_func_0215D898.c: c99=CCERR: line 54: illegal implicit conversion from 'char *' to | line 54: 'struct  *' nolang=CCERR: line 54: illegal implicit conversion from 'char *' to | line 54: 'struct  *'
- ov009_func_0215D92C.c..ov009_func_0215DAA8.c: c99=CCERR: line 112: illegal implicit conversion from 'struct SOCLSocket *' to | line 112: 'struct  *' nolang=CCERR: line 112: illegal implicit conversion from 'struct SOCLSocket *' to | line 112: 'st
- ov009_func_0215DB0C.c..ov009_func_0215DF08.c: type typedef Socket differs between members (src/matched/ov_sdk/ov009_func_0215DD88.c)

Members, in address order:

- `ov009_func_0215D6C8.c`
- `ov009_func_0215D7FC.c`
- `ov009_func_0215D898.c`
- `ov009_func_0215D92C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0215D6C8.c` again.
