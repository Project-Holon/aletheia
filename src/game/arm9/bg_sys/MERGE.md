# bg_sys.c (arm9)

Translation unit 0203EF5C..020432E4, 106 functions, confidence weak (tools/tuboundary.py).

Merged into five parts (bg_sys_p01..p05.c, all EXACT). Two members cannot
join them:

- `func_0203F0A8.c`: built with compiler 1.2, the parts use 1.1p1.
- `sub_02040820.c`: Thumb code, built without --lang c99.

Part boundaries inside the ARM range come from prototype clashes. The caller
side declares narrower or wider argument types than the definition has, and
mwcc adds or drops a mask on every call:

- p03 (0x02040860..) and p05 (0x020426A0..): p03 calls func_020426A0,
  func_020428E8, func_02042B24 (declared with u32 arguments there) while
  p05 defines them with u8 arguments.
- p04 (0x020414AC..0x0204269F) and p03: func_020414C4 calls func_02040B94,
  which p03 defines with a u8 first argument.
- p04 and p05: func_02040EE0 and func_02040F84 are declared with different
  argument widths in p04 (calls) and p05 (calls) than the definitions in p03.

Merged parts share one `struct BgSys` (header, eight 0x2c-byte `struct Bg`
records, then the arena pointers and base tables). The former per-function
views (Slot, Entry, BgLayer, Channel, Screen_*) are replaced by it.
