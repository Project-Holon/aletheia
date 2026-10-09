# eventdata_system (ov010)

Round 3 (lane r3_ov03): the greedy merge with the call-argument harmonizer was re-run; the parts below are what is left. Every part verifies byte-exact on its own.

15 parts (was 20). The last part still holds 6 verified parts that did not merge (see the part
headers). Boundaries left: stand-in bodies that call func_02082BCC, func_02162358, func_02161E78,
func_02082D44, func_021630F4, func_021631C0, func_021634D8, func_021636C8, func_02163994,
func_02163A08, func_02163E34, func_02163E58, func_0216D80C, func_0216D818, func_0216D824,
func_0216D89C with int arguments where the callee takes a pointer or with fewer or more
arguments than the definition; struct Box / Sub (three local copies with different field names);
TrigCell / Payload typedefs defined in one part only; fx32 declared twice. Rewrite the stand-in
bodies in plain C with the definition's prototype, check EXACT alone, then merge. Keep hash signs
out of comments (they break the merge tool's prototype extraction).

Parts: eventdata_system_p01.c, eventdata_system_p02.c, eventdata_system_p03.c, eventdata_system_p04.c, eventdata_system_p05.c, eventdata_system_p06.c, eventdata_system_p07.c, eventdata_system_p08.c, eventdata_system_p09.c, eventdata_system_p10.c, eventdata_system_p11.c, eventdata_system_p12.c, eventdata_system_p13.c, eventdata_system_p14.c, eventdata_system_p15.c
