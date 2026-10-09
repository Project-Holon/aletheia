# unit_02731718.c (twl)

Parts: p01 (arm, 02731718), p02 (thumb, 02731754), p03 (arm, 02731774..02732648), p04 (arm, 02732648..02732B70), p05 (arm, 02732B70..).

- p01|p02 and p02|p03: ISA change arm/thumb/arm, a real file boundary.
- p03 now holds the old p03 and p04. func_02731AF0 was written as real C in lane r5t01 (264 bytes, EXACT, struct NetWork).
- p03|p04: func_027323A8 (672 bytes, ARM, the last function of p03) is still an empty stand-in. It is a real function (calls func_021657C8 and other helpers); it has not been written yet.
- p04|p05: func_02732944 (288 bytes), func_02732A64 (12) and func_02732A70 (256) are empty stand-ins. func_02732A64 and func_02732A70 look like one function split by the symbol table: 02732A64 is `push {r4, lr}; mov r4, r0; bl 0x021657C8` and 02732A70 continues with `ldrh r1, [r4, #2]`. Together they are one 268-byte function at 02732A64. Writing it as C means dropping the func_02732A70 entry.
- p01 status is MATCH: its pool word data_02732FA8 (a flag at 0x02732FA8) has no witness, so one relocation stays unresolved. Rewritten from an empty stand-in in lane 055 (typed C, byte exact).
