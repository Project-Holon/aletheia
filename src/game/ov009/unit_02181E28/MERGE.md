# unit_02181E28 (ov009)

Merge lane ov_lane004: tools/greedy merge with type policies (rename, first, last; both function orders) left 5 parts.

Parts, in address order:

- `unit_02181E28_p01.c`
- `unit_02181E28_p02.c`
- `unit_02181E28_p03.c`
- `unit_02181E28_p04.c`
- `unit_02181E28_p05.c`

Boundaries that did not merge (first compiler error, from the last attempt):

- before `ov009_func_02182414.c`: {'c99': "CCERR: line 86: 'mData' is not a member of class 'struct GSIXmlString' | line 87: 'mLen' is not a member of class 'struct GSIXmlString' | line 97: 'mLe
- before `ov009_func_02182554.c`: {'c99': "CCERR: line 29: struct/union/enum/class tag 'GSIXmlString' redefined", 'nolang': "CCERR: line 29: struct/union/enum/class tag 'GSIXmlString' redefined"
- before `ov009_func_02183D98.c`: {'c99': "CCERR: line 221: identifier 'gsiXmlUtilTagMatches(char *, void *)' redeclared as 'int (char *, struct GSIXmlString *)' | line 182: identifier 'gsiXmlUt
- before `unit_02181E28_p08.c`: {'c99': "CCERR: line 114: identifier 'gsiXmlUtilTagMatches(char *, void *)' redeclared as 'int (char *, struct GSIXmlString *)' | line 55: identifier 'gsiXmlUti

To merge: give each named struct, global and prototype one declaration (check field offsets agree), then re-run the verify.
