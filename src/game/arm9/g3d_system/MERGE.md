# g3d_system (arm9)

Translation unit 02046440..0204A48C (confidence weak, tools/tuboundary.py).

All 170 functions are merged into 4 files. The files end at linker veneers: a veneer
is not part of any source file, so a file cannot continue across it.

- `g3d_system_p01.c`: 02046440..02046C88, ends at veneer_02046C88.
- `g3d_system_p02.c`: 02046C94..02047964, ends at veneer_02047964.
- `g3d_system_p03.c`: 02047970..02048C4C, ends at veneer_02048C4C.
- `g3d_system_p04.c`: 02048C58..0204A48C.

Notes for the later struct pass:

- g_02146A5C is one global read through about 13 partial views. In p01 and p02 it is
  declared `void *` and every use casts to the view of that member. In p03 it is a
  `struct G3dSys { void *obj; u32 f4; u32 f8; }` (the 12-byte view that func_02047C8C
  needs). The struct view cannot be used in p01: the pointer-style code there changes
  register allocation when the global is a struct member (func_02046AFC, func_02046B40).
- struct Rec (p02), struct RecC4-like Ctx (p03), Util/Setup/Owner (p03) and
  ArcFile/ArcHandle (p04) were unified by hand; the 0x48-byte FSFile local in p04 is
  `struct ArcFile`, the 0x50-byte archive view is `struct ArcHandle`.
