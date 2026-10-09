# unit_0216870C (ov009)

The TU is split into 9 parts in address order. Every part is byte-exact (checked).
The greedy merge (neighbour into running file, both member orders, type policies rename/first/last)
stops at these boundaries. Each part is the largest run that merges; the next part fails to join it:

- before unit_0216870C_p02.c: CCERR: line 226: not a struct/union/class
- before unit_0216870C_p03.c: CCERR: line 205: illegal operands 'struct FriendGlobal' + 'int' | line 207: illegal operands 'struct FriendGlobal' + 'int' | line 208: illegal operands
- before unit_0216870C_p04.c: DIFF
- before unit_0216870C_p05.c: CCERR: line 125: struct/union/enum/class tag 'FriendCtl' redefined | line 129: identifier 'FriendCtl' redeclared | line 129: was declared as: 'struct F
- before unit_0216870C_p06.c: CCERR: line 68: undefined identifier 'u64' | line 89: identifier 'u64' redeclared | line 89: was declared as: 'int'
- before unit_0216870C_p07.c: CCERR: line 279: identifier 's_bNeedCloseStatsConnection' redeclared as 'int' | line 149: identifier 's_bNeedCloseStatsConnection' was originally decla
- before unit_0216870C_p08.c: CCERR: line 182: 'field0' is not a member of class 'struct ' | line 188: 'userName' is not a member of class 'struct ' | line 192: 'field4' is not a me
- before unit_0216870C_p09.c: CCERR: line 255: 'field0' is not a member of class 'struct ' | line 261: 'userName' is not a member of class 'struct ' | line 265: 'field4' is not a me

The blockers are struct views of one object that differ between parts (field names and
offsets are not yet unified), plus prototypes with different argument lists. A later struct pass
should give each object one definition, then rerun the greedy merge.

Parts:

- `unit_0216870C_p01.c`
- `unit_0216870C_p02.c`
- `unit_0216870C_p03.c`
- `unit_0216870C_p04.c`
- `unit_0216870C_p05.c`
- `unit_0216870C_p06.c`
- `unit_0216870C_p07.c`
- `unit_0216870C_p08.c`
- `unit_0216870C_p09.c`

Round 3 (r3_ov01): p03 and p06 verify MATCH (status fixed); all parts contiguous.
