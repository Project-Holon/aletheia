# tcbl.c (arm9)

Parts merged by lane arm9_lane17 (greedy, address order then reverse): tcbl_p01.c, tcbl_p02.c, tcbl_p03.c, tcbl_p04.c, tcbl_p05.c, tcbl_p06.c

Members still separate in this folder: sub_02030FC8.c

Blockers seen by the greedy pass (merge of the running file with the next file failed):

- tcbl_p04.c FAIL {'c99': "CCERR: line 593: illegal implicit conversion from 'struct Node_020306F0 *' to | line 593: 'struct Node_02030C44 *'", 'nolang': "CCERR: line 5
- tcbl_p05.c FAIL {'c99': "CCERR: line 125: illegal implicit conversion from 'struct Node_02030CB0 *' to | line 125: 'struct Node_02030C44 *'", 'nolang': "CCERR: line 1
- tcbl_p06.c FAIL {'c99': "CCERR: line 111: illegal implicit conversion from 'struct Node_02030CB0 *' to | line 111: 'unsigned int'", 'nolang': "CCERR: line 111: illega
- sub_02030FC8.c FAIL {'c99': "CCERR: line 322: identifier 'sub_02030F50(struct Tcbl_02030FC8 *, struct TcblNode *)' redeclared as 'void (struct Tcbl_02030D28 *, struct Tcb
- tcbl_p09.c FAIL {'c99': "CCERR: line 97: identifier 'sub_02030FC8(struct Tcbl_0203101C *)' redeclared as 'void (struct Tcbl *)' | line 89: identifier 'sub_02030FC8(st
- tcbl_p10.c FAIL {'c99': "CCERR: line 196: illegal implicit conversion from 'struct TcblNode *' to | line 196: 'struct TcblNode_020310C4 *' | line 212: illegal implici

c99=DIFF means the merge changes the generated code (shared strings, inlining); settings means another compiler.
Other failures are struct or prototype views that need unifying (check field offsets first).
