# unit_02180410 (ov009)

Merge lane ov_lane004: tools/greedy merge with type policies (rename, first, last; both function orders) left 14 parts.

Parts, in address order:

- `unit_02180410_p01.c`
- `unit_02180410_p02.c`
- `unit_02180410_p03.c`
- `unit_02180410_p04.c`
- `unit_02180410_p05.c`
- `unit_02180410_p06.c`
- `unit_02180410_p07.c`
- `unit_02180410_p08.c`
- `unit_02180410_p09.c`
- `unit_02180410_p10.c`
- `unit_02180410_p11.c`
- `unit_02180410_p12.c`
- `unit_02180410_p13.c`
- `unit_02180410_p14.c`

Boundaries that did not merge (first compiler error, from the last attempt):

- before `unit_02180410_p02.c`: {'c99': "CCERR: line 49: struct/union/enum/class tag 'GSUdpRemotePeer' redefined", 'nolang': "CCERR: line 49: struct/union/enum/class tag 'GSUdpRemotePeer' rede
- before `unit_02180410_p03.c`: {'c99': "CCERR: line 78: struct/union/enum/class tag 'GSUdpMsgHandler' redefined | line 82: identifier 'GSUdpMsgHandler' redeclared | line 82: was declared as:
- before `ov009_func_02180BFC.c`: {'c99': "CCERR: line 67: struct/union/enum/class tag 'GSUdpMsgHandler' redefined | line 77: identifier 'GSUdpMsgHandler' redeclared | line 77: was declared as:
- before `ov009_func_02180C94.c`: {'c99': "CCERR: line 84: struct/union/enum/class tag 'GSUdpMsgHandler' redefined | line 88: identifier 'GSUdpMsgHandler' redeclared | line 88: was declared as:
- before `ov009_func_02180E48.c`: {'c99': "CCERR: line 117: illegal implicit conversion from 'char *' to | line 117: 'struct GSUdpEngineObject *'", 'nolang': "CCERR: line 117: illegal implicit c
- before `ov009_func_02180E58.c`: {'c99': "CCERR: line 152: illegal operands 'void *' + 'int'", 'nolang': "CCERR: line 152: illegal operands 'void *' + 'int'"}
- before `ov009_func_02181010.c`: {'c99': "CCERR: line 64: struct/union/enum/class tag 'GSUdpMsgHandler' redefined | line 74: identifier 'GSUdpMsgHandler' redeclared | line 74: was declared as:
- before `ov009_func_021810CC.c`: {'c99': "CCERR: line 85: struct/union/enum/class tag 'GSUdpMsgHandler' redefined | line 89: identifier 'GSUdpMsgHandler' redeclared | line 89: was declared as:
- before `ov009_func_021814EC.c`: {'c99': "CCERR: line 74: struct/union/enum/class tag 'GSUdpEngineObject' redefined", 'nolang': "CCERR: line 74: struct/union/enum/class tag 'GSUdpEngineObject'
- before `ov009_func_021815C8.c`: {'c99': "CCERR: line 69: struct/union/enum/class tag 'GSUdpEngineObject' redefined | line 149: 'fieldC' is not a member of class 'struct GSUdpEngineObject' | li
- before `ov009_func_02181748.c`: {'c99': "CCERR: line 52: struct/union/enum/class tag 'GSUdpMsgHandler' redefined | line 62: identifier 'GSUdpMsgHandler' redeclared | line 62: was declared as:
- before `ov009_func_02181828.c`: {'c99': "CCERR: line 41: struct/union/enum/class tag 'GSUdpEngineObject' redefined | line 81: illegal implicit conversion from 'struct GSUdpEngineObject *' to |
- before `ov009_func_021818EC.c`: {'c99': "CCERR: line 53: struct/union/enum/class tag 'GSUdpEngineObject' redefined | line 112: 'fieldC' is not a member of class 'struct GSUdpEngineObject' | li

To merge: give each named struct, global and prototype one declaration (check field offsets agree), then re-run the verify.
