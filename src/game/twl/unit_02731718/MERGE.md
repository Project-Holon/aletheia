# unit_02731718.c (twl)

Parts: p01 (arm, 02731718), p02 (thumb, 02731754), p03 (arm, 02731774..02731BF8), p04 (arm, 02731BF8..02732648), p05 (arm, 02732648..02732B70), p06 (arm, 02732B70..).

- p01|p02 and p02|p03: ISA change arm/thumb/arm, a real file boundary.
- p03|p04: func_02731AF0 (264 bytes) is an empty stand-in at the end of p03.
- p04|p05: func_027323A8 (672 bytes) is an empty stand-in at the end of p04.
- p05|p06: func_02732944 (288), func_02732A64 (12), func_02732A70 (256) are empty stand-ins.
- p01 status is MATCH: its pool word data_02732FA8 (a flag at 0x02732FA8) has no witness, so one relocation stays unresolved. Rewritten from an empty stand-in in lane 055 (typed C, byte exact).

