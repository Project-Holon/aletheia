# eventdata_system (ov010)

Round 10 (lane w10c): 15 parts reduced to 10. Merged: old p01+p02, p04+p05 (func_02162408 rewritten as typed C), p06+p07..; stand-ins rewritten as typed C: func_02161E60, func_02161F54, func_02161F74, func_02161FF0, func_02162008, func_0216210C (unused arg kept, callers pass one), func_021620A0, func_021621E8, func_021622F4, func_02162358, func_021623BC, func_02162408, func_02162438, func_02162694.

Boundaries left (every part EXACT alone):
- p01|p02 (and p02|p03): struct Sub / Box have different views: f0/f2 u16 in func_02162BCC (p02) but s16 in the p01 and p03 functions (a canonical Sub with u16 f0/f2 breaks p01 and p03 by a few bytes; s16 breaks p02). Needs a per-function look at which accesses cast.
- p03|p04, p04|p05, p05|p06, p06|p07, p07|p08: stand-ins calling func_021634D8, func_021636C8, func_02163994, func_02163A08, func_02163E34 and friends with int arguments or a wrong argument count (about 200 goto-style bodies in p04..p06 still to rewrite).
- p09|p10: DIFF, prototype of func_02163A08 differs.

Parts: eventdata_system_p01.c, eventdata_system_p02.c, eventdata_system_p03.c, eventdata_system_p04.c, eventdata_system_p05.c, eventdata_system_p06.c, eventdata_system_p07.c, eventdata_system_p08.c, eventdata_system_p09.c, eventdata_system_p10.c
