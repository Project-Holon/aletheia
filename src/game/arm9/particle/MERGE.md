# particle.c (arm9)

Parts merged by lane arm9_lane17 (greedy, address order then reverse): particle_p01.c, particle_p02.c, particle_p03.c, particle_p04.c, particle_p05.c, particle_p06.c, particle_p07.c, particle_p08.c, particle_p09.c, particle_p10.c

Members still separate in this folder: none

Blockers seen by the greedy pass (merge of the running file with the next file failed):

- func_02050084.c FAIL {'c99': 'DIFF', 'nolang': 'DIFF'}
- particle_p04.c FAIL {'c99': "CCERR: line 183: illegal implicit conversion from 'void' to | line 183: 'int'", 'nolang': "CCERR: line 183: illegal implicit conversion from 
- particle_p05.c FAIL {'c99': "CCERR: line 168: illegal implicit conversion from 'int' to | line 168: 'struct AreaMan *'", 'nolang': "CCERR: line 168: illegal implicit conv
- particle_p06.c FAIL {'c99': "CCERR: line 167: struct/union/enum/class tag 'Owner' redefined | line 173: struct/union/enum/class tag 'Entry' redefined | line 350: illegal 
- particle_p07.c FAIL {'c99': "CCERR: line 297: identifier 'func_02050984(int)' redeclared as 'void (*)() (unsigned int)' | line 111: identifier 'func_02050984(int)' was or
- particle_p08.c FAIL {'c99': "CCERR: line 124: identifier 'func_02050A00(struct Ent *, struct Cmd *)' redeclared as 'int (struct Ent_02050A00 *, struct Cmd *)' | line 74: 
- particle_p10.c FAIL {'c99': "CCERR: line 234: illegal implicit conversion from 'struct Ctx *' to | line 234: 'unsigned int *' | line 254: illegal implicit conversion from
- particle_p12.c FAIL {'c99': 'DIFF', 'nolang': 'DIFF'}
- func_02051380.c FAIL {'c99': "CCERR: line 122: illegal implicit conversion from 'void *' to | line 122: 'unsigned int'", 'nolang': "CCERR: line 122: illegal implicit conve

c99=DIFF means the merge changes the generated code (shared strings, inlining); settings means another compiler.
Other failures are struct or prototype views that need unifying (check field offsets first).
