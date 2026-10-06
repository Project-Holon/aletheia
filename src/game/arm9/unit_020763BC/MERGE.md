# unit_020763BC.c (arm9)

Parts merged by lane arm9_lane17 (greedy, address order then reverse): unit_020763BC_p01.c

Members still separate in this folder: CARDi_IdentifyBackupCore2.c, func_020763BC.c, func_020763F0.c, func_02076540.c

Blockers seen by the greedy pass (merge of the running file with the next file failed):

- func_020763F0.c FAIL {'c99': "CCERR: line 139: illegal use of incomplete struct/union/class 'struct CARDiCommandArg_020763BC' | line 165: illegal use of incomplete struct/
- func_02076540.c FAIL {'c99': "CCERR: line 129: struct/union/enum/class tag 'CARDiCommon' redefined | line 153: identifier 'CARDiCommon' redeclared | line 153: was declared
- CARDi_IdentifyBackupCore2.c FAIL {'c99': "CCERR: line 121: struct/union/enum/class tag 'CARDiCommon' redefined | line 123: identifier 'CARDiCommon' redeclared | line 123: was declared
- unit_020763BC_p01.c FAIL {'c99': "CCERR: line 133: warning: identifier 'CARDiCommon_020763BC' redeclared | line 382: illegal implicit conversion from 'struct CARDiCommon_02076

c99=DIFF means the merge changes the generated code (shared strings, inlining); settings means another compiler.
Other failures are struct or prototype views that need unifying (check field offsets first).
