# unit_0207312C (arm9)

Round 4 state: 4 files remain, all byte-exact, compiler ../2.0/sp2, -O4,p, c99. The old 1.1p1 members (func_020731E0, func_020733DC, func_02073484, func_02073500/548, func_020735EC, func_02073710/760) were proven EXACT under ../2.0/sp2 and joined their neighbours. No uncovered code between files.

- `unit_0207312C_p01.c`: func_0207312C, func_020731E0
- `unit_0207312C_p02.c`: func_02073344, func_020733DC, func_020733E8, func_02073438, func_02073484
- `unit_0207312C_p03.c`: func_020734AC .. func_0207368C (seven functions)
- `unit_0207312C_p04.c`: func_02073710, func_02073760

Blockers: one struct Slot (size 0x24) and its neighbours are described by a different local struct in every part (renamed Slot_0207312C, Slot_02073344, Slot_020734AC, Obj, Node, E by the tool).
- p01 | p02: `struct Slot_02073344[]` passed where `struct Slot_0207312C *` is expected.
- p02 | p03: `struct Slot_020734AC *` versus `struct Slot_02073344 *`.
- p03 | p04: `struct E *` versus `struct Slot *`.
Known layout: Slot has h08 at 0x08, list at 0x0c, f18 at 0x18, f1c at 0x1c, b20 at 0x20; Node has b3d at 0x3d (b3c in Chan at 0x3c, b2c at 0x2c; Chan is 0x44 bytes). A canonical struct by offset (canon36.py) should close all three.
