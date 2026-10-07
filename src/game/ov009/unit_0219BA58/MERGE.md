# unit_0219BA58.c (ov009)

Translation unit 0219BA58..0219D114, 16 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0219BA58.c` is blocked by:

- ov009_func_0219BA58.c..ov009_func_0219CE58.c: global g_021A7C90 declared two ways (src/matched/ov_sdk/ov009_func_0219BED8.c); prototype of func_0219B660 differs between members (src/matched/ov_sdk/ov009_func_0219BED8.c); prototype of func_0217D25
- ov009_func_0219BA58.c..ov009_func_0219C154.c: global g_021A7C90 declared two ways (src/matched/ov_sdk/ov009_func_0219BED8.c); prototype of func_0219B660 differs between members (src/matched/ov_sdk/ov009_func_0219BED8.c)
- ov009_func_0219BA58.c..ov009_func_0219BB54.c: c99=CCERR: line 44: struct/union/enum/class tag 'qr2_implementation_s' redefined | line 55: struct/union/enum/class tag 'qr2_implementation_s' redefined | line 63: identifier 'qr2_implementation_s' re
- ov009_func_0219BAB4.c..ov009_func_0219BB54.c: c99=CCERR: line 43: struct/union/enum/class tag 'qr2_implementation_s' redefined | line 51: identifier 'qr2_implementation_s' redeclared | line 51: was declared as: 'struct qr2_implementation_s' nolan
- ov009_func_0219BC2C.c..ov009_func_0219C154.c: global g_021A7C90 declared two ways (src/matched/ov_sdk/ov009_func_0219BED8.c); prototype of func_0219B660 differs between members (src/matched/ov_sdk/ov009_func_0219BED8.c)
- ov009_func_0219BC2C.c..ov009_func_0219BE80.c: c99=CCERR: line 22: the file '../arm9_sdk/libc/string.h' cannot be opened | line 84: struct/union/enum/class tag 'qr2_buffer_s' redefined nolang=CCERR: line 22: the file '../arm9_sdk/libc/string.h' ca
- ov009_func_0219BED8.c..ov009_func_0219C154.c: c99=CCERR: line 70: struct/union/enum/class tag 'qr2_buffer_s' redefined | line 75: struct/union/enum/class tag 'qr2_keybuffer_s' redefined | line 80: struct/union/enum/class tag 'qr2_implementation_s
- ov009_func_0219C3A4.c..ov009_func_0219CE58.c: prototype of func_0219BA84 differs between members (src/matched/ov_sdk/ov009_func_0219CDBC.c); prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov009_func_0219CDBC.c); prototype 
- ov009_func_0219C3A4.c..ov009_func_0219C724.c: c99=CCERR: line 78: struct/union/enum/class tag 'qr2_implementation_s' redefined | line 113: struct/union/enum/class tag 'SOCInAddr' redefined | line 124: struct/union/enum/class tag 'qr2_ipverify_inf
- ov009_func_0219C3A4.c..ov009_func_0219C554.c: c99=CCERR: line 47: struct/union/enum/class tag 'qr2_implementation_s' redefined | line 107: 'client_message_keys' is not a member of class 'struct qr2_implementation_s' | line 110: 'cur_message_key' 
- ov009_func_0219C5B8.c..ov009_func_0219C724.c: c99=CCERR: line 77: struct/union/enum/class tag 'SOCInAddr' redefined | line 81: struct/union/enum/class tag 'SOCSockAddrIn' redefined | line 88: struct/union/enum/class tag 'qr2_ipverify_info_s' rede
- ov009_func_0219C77C.c..ov009_func_0219CE58.c: prototype of func_0219BA84 differs between members (src/matched/ov_sdk/ov009_func_0219CDBC.c); prototype of func_0217D254 differs between members (src/matched/ov_sdk/ov009_func_0219CDBC.c); prototype 
- ov009_func_0219C77C.c..ov009_func_0219C7C0.c: c99=CCERR: line 70: struct/union/enum/class tag 'qr2_implementation_s' redefined | line 150: 'entries' is not a member of class 'struct qr2_implementation_s' | line 151: expression syntax error nolang
- ov009_func_0219CDBC.c..ov009_func_0219CE58.c: c99=CCERR: line 68: struct/union/enum/class tag 'qr2_buffer_s' redefined | line 73: struct/union/enum/class tag 'qr2_implementation_s' redefined | line 93: identifier 'qr2_implementation_s' redeclared

Members, in address order:

- `ov009_func_0219BAB4.c`
- `ov009_func_0219BB54.c`
- `ov009_func_0219BC2C.c`
- `ov009_func_0219BE80.c`
- `ov009_func_0219BED8.c`
- `ov009_func_0219C154.c`
- `ov009_func_0219C3A4.c`
- `ov009_func_0219C554.c`
- `ov009_func_0219C5B8.c`
- `ov009_func_0219C724.c`
- `ov009_func_0219C77C.c`
- `ov009_func_0219C7C0.c`
- `ov009_func_0219CDBC.c`
- `ov009_func_0219CE58.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0219BA58.c` again.
