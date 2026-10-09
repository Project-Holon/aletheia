# unit_02187010 (ov009)

Merge lane ov_lane004: tools/greedy merge with type policies (rename, first, last; both function orders) left 5 parts.

Parts, in address order:

- `unit_02187010_p01.c`
- `unit_02187010_p02.c`
- `unit_02187010_p03.c`
- `unit_02187010_p04.c`
- `unit_02187010_p05.c`

Boundaries that did not merge (first compiler error, from the last attempt):

- before `ov009_func_02187D60.c`: {'c99': "CCERR: line 135: undefined identifier 'GPIBuffer' | line 160: undefined identifier 'GPIProfileList' | line 186: identifier 'GPIBuffer' redeclared", 'no
- before `unit_02187010_p02.c`: {'c99': "CCERR: line 139: struct/union/enum/class tag 'GPICallback' redefined | line 142: identifier 'GPICallback' redeclared | line 142: was declared as: 'stru
- before `ov009_func_021890E0.c`: {'c99': "CCERR: line 87: undefined identifier 'GPIPeerOp' | line 103: identifier 'GPIPeerOp' redeclared | line 103: was declared as: 'int'", 'nolang': "CCERR: l
- before `ov009_func_02189300.c`: {'c99': "CCERR: line 33: undefined identifier 'GPIBuddyStatus' | line 34: undefined identifier 'GPIBuddyStatusInfo' | line 49: identifier 'GPIBuddyStatus' redec

To merge: give each named struct, global and prototype one declaration (check field offsets agree), then re-run the verify.
