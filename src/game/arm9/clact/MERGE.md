# clact.c (arm9)

Translation unit 0204A48C..0204E5E8, 201 functions, confidence weak (tools/tuboundary.py).

Merged so far: `clact_p01.c` covers 0204A48C..0204BD3C (all of the first 103 functions)
as one file, verified EXACT. The shared object behind g_02146A74 now has one `struct Sys`
(with `struct Owner`, `Slot`, `Slot2`, `Entry3`, `Bank`, `Actor`, `Obj`, `Sub`, `Ctl`,
`Pt`, `Pair`); other per-function struct views that differ were renamed `Name_ADDR`.

Left: `clact_p02.c` .. `clact_p17.c` (address order) and the member files in this folder
(0204BD3C..0204E4C0). To continue, append them to `clact_p01.c` in address order:
- `struct Obj` (f80/f98/f9c view in clact_p02, 0xa0 bytes, allocated by func_0204B034)
  is a different object from the canonical `struct Obj` (two `Sub` windows); in
  clact_p01.c the 0xa0 one is `Obj_0204B034`. Unify it with the p02 view.
- `struct Sys` needs `unk_f0`/`unk_f2`/`unk_f4` field names used by func_0204BFC4 and
  func_0204BFF4 (offsets 0xf0..0xf4 already exist as `unk_f0[2]`, `unk_0f4`).
- func_0204C214.c members (clact_p0x): `struct A`/`C`/`M` views differ.
- redeclared prototypes with different struct types: func_0204C718, sub_0204C8E4,
  func_0204CB44, sub_0204CED8, sub_0204CFDC, gUnk_020A1394, sub_0204D3C4.
- g_02146A78 declared two ways (func_0204E180).
- c99=DIFF (merging changes the code, keep separate): func_0204C060.c
  (with func_0204BFF4.c), func_0204D4C4.c..func_0204D54C.c.

- `func_0204C024.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_0204C040.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `unit_0204D494.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_0204D4B4.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_0204D500.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_0204D53C.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
