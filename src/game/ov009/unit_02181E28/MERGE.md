# unit_02181E28.c (ov009)

Translation unit 02181E28..02183F68, 38 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02181E28.c` is blocked by:

- ov009_func_02181E28.c..ov009_func_02183EE0.c: prototype of strchr differs between members (src/matched/ov_sdk/ov009_func_02182414.c); prototype of gsiXmlUtilWriteXmlSafeString differs between members (src/matched/ov_sdk/ov009_func_02182B68.c); pr
- ov009_func_02181E28.c..ov009_func_02183210.c: prototype of strchr differs between members (src/matched/ov_sdk/ov009_func_02182414.c); prototype of gsiXmlUtilWriteString differs between members (src/matched/ov_sdk/ov009_func_02182A2C.c); prototype
- ov009_func_02181E28.c..ov009_func_02182AC0.c: prototype of strchr differs between members (src/matched/ov_sdk/ov009_func_02182414.c)
- ov009_func_02181E28.c..ov009_func_02182554.c: prototype of strchr differs between members (src/matched/ov_sdk/ov009_func_02182414.c)
- ov009_func_02181E28.c..ov009_func_02181E80.c: c99=CCERR: line 27: the file '../arm9_sdk/libc/strncmp/string.h' cannot be opened nolang=CCERR: line 27: the file '../arm9_sdk/libc/strncmp/string.h' cannot be opened
- ov009_func_02182414.c..ov009_func_02182554.c: c99=CCERR: line 31: struct/union/enum/class tag 'GSIXmlString' redefined | line 88: 'length' is not a member of class 'struct GSIXmlString' | line 93: 'string' is not a member of class 'struct GSIXmlS
- ov009_func_02182B68.c..ov009_func_02183210.c: prototype of gsiXmlUtilWriteString differs between members (src/matched/ov_sdk/ov009_func_02182D78.c); prototype of gsiXmlUtilWriteString differs between members (src/matched/ov_sdk/ov009_func_02182DF
- ov009_func_02182E90.c..ov009_func_02183210.c: prototype of gsiXmlUtilWriteString differs between members (src/matched/ov_sdk/ov009_func_02182FF8.c); prototype of sprintf differs between members (src/matched/ov_sdk/ov009_func_021830D0.c)
- ov009_func_0218325C.c..ov009_func_02183EE0.c: prototype of strlen differs between members (src/matched/ov_sdk/ov009_func_0218335C.c)
- ov009_func_0218372C.c..ov009_func_02183EE0.c: c99=CCERR: line 514: illegal implicit conversion from 'struct GSIXmlElement_02183EE0 *' to | line 514: 'struct GSIXmlString *' nolang=CCERR: line 514: illegal implicit conversion from 'struct GSIXmlEl
- ov009_func_02183BA4.c..ov009_func_02183EE0.c: c99=CCERR: line 228: illegal implicit conversion from 'struct GSIXmlElement *' to | line 228: 'struct GSIXmlString *' nolang=CCERR: line 228: illegal implicit conversion from 'struct GSIXmlElement *' 
- ov009_func_02183D98.c..ov009_func_02183EE0.c: c99=CCERR: line 125: illegal implicit conversion from 'struct GSIXmlElement *' to | line 125: 'struct GSIXmlString *' nolang=CCERR: line 125: illegal implicit conversion from 'struct GSIXmlElement *' 

Members, in address order:

- `ov009_func_02181E28.c`
- `ov009_func_02181E80.c`
- `ov009_func_02182414.c`
- `ov009_func_02182554.c`
- `ov009_func_02183D98.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02181E28.c` again.
