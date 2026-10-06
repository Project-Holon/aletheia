# unit_02078C40.c (arm9)

Parts merged by lane arm9_lane17 (greedy, address order then reverse): unit_02078C40_p01.c, unit_02078C40_p02.c, unit_02078C40_p03.c

Members still separate in this folder: func_02078D34.c, func_02078EB0.c

Blockers seen by the greedy pass (merge of the running file with the next file failed):

- func_02078D34.c FAIL {'c99': "CCERR: line 264: identifier 'FSiOverlayContext' redeclared as 'struct FSiOverlayContextType_02078C40' | line 206: identifier 'FSiOverlayConte
- func_02078EB0.c FAIL {'c99': "CCERR: line 193: illegal implicit conversion from 'struct FSOverlayInfo_02078EB0 *' to | line 193: 'struct FSOverlayInfo_02078D34 *'", 'nolan
- unit_02078C40_p02.c FAIL {'c99': "CCERR: line 235: illegal implicit conversion from 'struct FSOverlayInfo_02078C40 *' to | line 235: 'struct FSOverlayInfo_02078EB0 *'", 'nolan
- unit_02078C40_p03.c FAIL {'c99': "CCERR: line 234: identifier 'func_02079164()' redeclared as 'void (struct Iter020792B8_02078C40 *)' | line 120: identifier 'func_02079164()' 

c99=DIFF means the merge changes the generated code (shared strings, inlining); settings means another compiler.
Other failures are struct or prototype views that need unifying (check field offsets first).
