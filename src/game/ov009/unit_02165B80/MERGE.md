# unit_02165B80 (ov009)

The TU is split into 3 parts in address order. Every part is byte-exact (checked).
The greedy merge (neighbour into running file, both member orders, type policies rename/first/last)
stops at these boundaries. Each part is the largest run that merges; the next part fails to join it:

- before unit_02165B80_p02.c: CCERR: line 102: 'bssDesc' is not a member of class 'struct WCMApList' | line 119: 'apListLock' is not a member of class 'struct WCMWork' | line 121: '
- before unit_02165B80_p03.c: CCERR: line 79: struct/union/enum/class tag 'WCMBssDesc' redefined | line 84: undefined identifier 'WMGameInfo' | line 87: struct/union/enum/class tag 

The blockers are struct views of one object that differ between parts (field names and
offsets are not yet unified), plus prototypes with different argument lists. A later struct pass
should give each object one definition, then rerun the greedy merge.

Parts:

- `unit_02165B80_p01.c`
- `unit_02165B80_p02.c`
- `unit_02165B80_p03.c`

Round 3 (r3_ov01) notes:
- p01 | p02 is a 12-byte linker veneer at 0x02165CA0..0x02165CAC (no function covers it): real file boundary.
- p02 | p03 are contiguous (0x02165E98); the blocker is only the WCMWork / WCMApList / WCMBssDesc struct views (suffix-named copies _02165B80, _02165CAC, _02165D04, _02165DCC). p03 now verifies MATCH (status fixed).
