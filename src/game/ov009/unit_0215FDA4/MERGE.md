# unit_0215FDA4 (ov009)

The TU is split into 18 parts in address order. Every part is byte-exact (checked).
The greedy merge (neighbour into running file, both member orders, type policies rename/first/last)
stops at these boundaries. Each part is the largest run that merges; the next part fails to join it:

- before unit_0215FDA4_p02.c: CCERR: line 71: 'field_5a' is not a member of class 'struct CPSSslSession' | line 72: 'field_58' is not a member of class 'struct CPSSslSession' | line
- before unit_0215FDA4_p03.c: CCERR: line 42: struct/union/enum/class tag 'CPSSslSession' redefined | line 130: illegal implicit conversion from 'struct CPSSslSession *' to | line 1
- before unit_0215FDA4_p04.c: CCERR: line 494: 'sig' is not a member of class 'struct CPSSslConnection' | line 504: 'sig' is not a member of class 'struct CPSSslConnection' | line 5
- before unit_0215FDA4_p05.c: CCERR: line 138: 'f5af' is not a member of class 'struct CPSSslConnection' | line 140: 'f45c' is not a member of class 'struct CPSSslConnection' | line
- before unit_0215FDA4_p06.c: CCERR: line 72: struct/union/enum/class tag 'CPSSslConnection' redefined | line 85: identifier 'CPSSslConnection' redeclared | line 85: was declared as
- before unit_0215FDA4_p07.c: CCERR: line 53: struct/union/enum/class tag 'CPSSslConnection' redefined | line 84: identifier 'CPSSslConnection' redeclared | line 84: was declared as
- before unit_0215FDA4_p08.c: CCERR: line 151: function call 'func_02160E0C(int, unsigned char)' does not match | line 151: 'func_02160E0C(int)' | line 182: function call 'func_0216
- before unit_0215FDA4_p09.c: CCERR: line 67: struct/union/enum/class tag '_CPSSslConnection' redefined | line 80: undefined identifier 'CPSCipherCtx' | line 87: undefined identifie
- before unit_0215FDA4_p10.c: CCERR: line 46: undefined identifier 'u8' | line 47: undefined identifier 'u16' | line 58: identifier 'u8' redeclared
- before unit_0215FDA4_p11.c: CCERR: line 67: undefined identifier 'u8' | line 68: undefined identifier 'u16' | line 79: identifier 'u8' redeclared
- before unit_0215FDA4_p12.c: CCERR: line 194: 'f455' is not a member of class 'struct _CPSSslConnection' | line 200: 'f455' is not a member of class 'struct _CPSSslConnection' | li
- before unit_0215FDA4_p13.c: CCERR: line 98: struct/union/enum/class tag '_CPSSoc' redefined | line 194: 'client_random' is not a member of class 'struct CPSSslConnection' | line 1
- before unit_0215FDA4_p14.c: CCERR: line 127: 'resumed' is not a member of class 'struct CPSSslConnection' | line 130: 'resumed' is not a member of class 'struct CPSSslConnection' 
- before unit_0215FDA4_p15.c: CCERR: line 87: 'state' is not a member of class 'struct CPSSoc' | line 91: 'f455' is not a member of class 'struct CPSSslConnection' | line 92: 'f1d4'
- before unit_0215FDA4_p16.c: CCERR: line 34: undefined identifier 'CPSSslConnection' | line 44: identifier 'CPSSslConnection' redeclared | line 44: was declared as: 'int'
- before unit_0215FDA4_p17.c: CCERR: line 134: 'buf' is not a member of class 'struct CPSSslConnection' | line 136: 'buf' is not a member of class 'struct CPSSslConnection' | line 1
- before unit_0215FDA4_p18.c: CCERR: line 79: struct/union/enum/class tag 'CPSSslSession' redefined | line 142: 'state' is not a member of class 'struct CPSSoc' | line 255: 'f455' i

The blockers are struct views of one object that differ between parts (field names and
offsets are not yet unified), plus prototypes with different argument lists. A later struct pass
should give each object one definition, then rerun the greedy merge.

Parts:

- `unit_0215FDA4_p01.c`
- `unit_0215FDA4_p02.c`
- `unit_0215FDA4_p03.c`
- `unit_0215FDA4_p04.c`
- `unit_0215FDA4_p05.c`
- `unit_0215FDA4_p06.c`
- `unit_0215FDA4_p07.c`
- `unit_0215FDA4_p08.c`
- `unit_0215FDA4_p09.c`
- `unit_0215FDA4_p10.c`
- `unit_0215FDA4_p11.c`
- `unit_0215FDA4_p12.c`
- `unit_0215FDA4_p13.c`
- `unit_0215FDA4_p14.c`
- `unit_0215FDA4_p15.c`
- `unit_0215FDA4_p16.c`
- `unit_0215FDA4_p17.c`
- `unit_0215FDA4_p18.c`
