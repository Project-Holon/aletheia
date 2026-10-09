# irc_ranking (ov106): merge status

Files left (address order):

- irc_ranking_p01.c: func_021B7560 to func_021B8FB8 (55 functions)
- irc_ranking_p02.c: func_021B8FC4 to func_021B91A8 (7 functions)
- irc_ranking_p03.c: func_021B9298 to func_021B93E4 (7 functions)

Boundaries and reasons:

Boundary 1 (0x021B8FC4): part 1 calls func_021B8408(u8 *, s16 delta) with an int value (the result of func_021B913C and -pair.y). The definition has an s16 parameter, so the merged build adds two extend instructions (+8 bytes). The original callers have none. Boundary 2 (0x021B9298): merged build differs at the end of func_021B9198 and the alignment of the next function (the original has two bytes of padding there that the merge does not reproduce). Both boundaries are likely real file boundaries. Merged inside parts: func_021B80AC (u32 f(u8 *p) { return (u32)p; }), func_021B8D90 gets its unused second parameter, one Spring struct.

Every file above verifies EXACT or MATCH with tools/match.py.

Round 3 note (lane r3_ov08): p01+p02 also needs casts at the calls of func_021B8FD0 / func_021B913C (struct pointer parameters, callers pass u8 *). Trying delta as int in func_021B8408 (instead of s16) moved func_021B7984 by 4 bytes, so the original callee type is not plain int either; unresolved.
