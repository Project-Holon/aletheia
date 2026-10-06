# gf_overlay.c (arm9)

Parts merged by lane arm9_lane17 (greedy, address order then reverse): gf_overlay_p01.c

Members still separate in this folder: sub_02034768.c

Blockers seen by the greedy pass (merge of the running file with the next file failed):

- gf_overlay_p01.c FAIL {'c99': "CCERR: line 180: illegal implicit conversion from 'struct Console' to | line 180: 'const struct Bmp *'", 'nolang': "CCERR: line 180: illegal 

c99=DIFF means the merge changes the generated code (shared strings, inlining); settings means another compiler.
Other failures are struct or prototype views that need unifying (check field offsets first).
