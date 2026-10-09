# unit_02166880 (ov009)

The TU is split into 7 parts in address order. Every part is byte-exact (checked).
The greedy merge (neighbour into running file, both member orders, type policies rename/first/last)
stops at these boundaries. Each part is the largest run that merges; the next part fails to join it:

- before unit_02166880_p02.c: CCERR: line 58: struct/union/enum/class tag 'WCMWork' redefined | line 215: 'wmSysBuf' is not a member of class 'struct ' | line 242: 'wmState' is not 
- before unit_02166880_p03.c: CCERR: line 60: struct/union/enum/class tag 'WCMWork' redefined | line 190: 'flag' is not a member of class 'struct WCMWork' | line 192: 'flag' is not 
- before unit_02166880_p04.c: CCERR: line 54: undefined identifier 'WCMPrivacyDesc' | line 86: identifier 'WCMPrivacyDesc' redeclared | line 86: was declared as: 'int'
- before unit_02166880_p05.c: CCERR: line 49: undefined identifier 'WMScanExParam' | line 77: identifier 'WMScanExParam' redeclared | line 77: was declared as: 'int'
- before unit_02166880_p06.c: CCERR: line 39: struct/union/enum/class tag 'WCMWork' redefined | line 56: identifier 'WCMWork' redeclared | line 56: was declared as: 'struct WCMWork'
- before unit_02166880_p07.c: CCERR: line 75: struct/union/enum/class tag 'WCMWork' redefined | line 92: identifier 'WCMWork' redeclared | line 92: was declared as: 'struct WCMWork'

The blockers are struct views of one object that differ between parts (field names and
offsets are not yet unified), plus prototypes with different argument lists. A later struct pass
should give each object one definition, then rerun the greedy merge.

Parts:

- `unit_02166880_p01.c`
- `unit_02166880_p02.c`
- `unit_02166880_p03.c`
- `unit_02166880_p04.c`
- `unit_02166880_p05.c`
- `unit_02166880_p06.c`
- `unit_02166880_p07.c`
