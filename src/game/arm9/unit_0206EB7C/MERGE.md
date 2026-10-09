# unit_0206EB7C (arm9)

Round 4 state: 3 files remain, all byte-exact, compiler ../2.0/sp2p2, -O4,p, c99. Every member is EXACT under sp2p2 (func_0206ECE0 group and func_0206F4C8 need it, the rest build under both sp2 and sp2p2; func_0206EB7C also under 1.1p1). `-proc arm946e` is the default, so the flags are written as -O4,p everywhere. No uncovered code between files.

- `unit_0206EB7C_p01.c`: func_0206EB7C, func_0206EBB8, func_0206EC50
- `unit_0206EB7C_p02.c`: func_0206ECE0 .. func_0206F6B0 (six functions)
- `unit_0206EB7C_p03.c`: func_0206F844, func_0206FC5C, func_0206FFA0

Blockers (struct or helper conflicts only):
- p01 | p02: two static helpers both named `entry_of` with different struct parameters ("object redefined"). Needs one canonical struct and one helper.
- p02 | p03: func_0206F844 uses fields cnt04 and f08 of an object that the earlier parts view through an anonymous struct. Needs one named struct by offset.
